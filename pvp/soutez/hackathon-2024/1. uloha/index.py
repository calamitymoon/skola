import numpy as np
import matplotlib.pyplot as plt
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Dropout
from tensorflow.keras.optimizers import Adam
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error
from pathlib import Path
import xarray as xr
import sys

# Ensure the output encoding is set to UTF-8
sys.stdout.reconfigure(encoding='utf-8')

# Define the base path for the .nc files
base_path = Path('nc_soubory/')
files = sorted(list(base_path.glob('*.nc')))
# files = files[2528:2578]  # Select specific files
files = files[2558:2578]  # Select specific files

# Load the data from the .nc files
data = xr.open_mfdataset(files, combine='nested', concat_dim='id_measurement')
data.load()

all_Z = []
all_T = []
all_raw_TS = []

# Loop through each measurement and ensure Z, T, and raw_TS have the same length
for i in range(data.dims['id_measurement']):
    data_point = data.isel(id_measurement=i)
    Z = data_point.Z.data
    all_Z.append(Z)
    T = data_point.time.data
    all_T.append(T)
    # data_point.raw_TS.sel(poly_ch_id=idecko).plot(label=f'kanál {idecko}')

    raw_TS = data_point.raw_TS
    tmp = [raw_TS.sel(poly_ch_id=2).values, raw_TS.sel(poly_ch_id=3).values, raw_TS.sel(poly_ch_id=4).values]
    all_raw_TS.append(tmp)

    # plt.figure()
    # for idx, channel in enumerate(tmp, start=2):
    #     try:
    #         plt.plot(channel, label=f'kanál {idx}')
    #     except KeyError:
    #         pass  # If the channel is not available in data

    # plt.title(f'Výboj #{data_point.shot.data}, čas {data_point.time.data}, Z={data_point.Z.data:.1f} m, Te={data_point.Te.data:.1f} eV')
    # plt.xlabel('Čas')
    # plt.ylabel('Intenzita')

# Flatten the list of arrays for use as input features
flattened_raw_TS = [np.concatenate(tmp) for tmp in all_raw_TS]

# Prepare the input data X
X = np.column_stack((all_Z, all_T, flattened_raw_TS))

X2 = X.copy()
# Loop through each column in X to handle NaN values
for i in range(X2.shape[1]):
    column = X2[:, i]
    # Find indices of NaN values
    nan_indices = np.where(np.isnan(column))[0]
    
    # Iterate over each NaN and replace with the nearest valid value
    for nan_idx in nan_indices:
        # Find previous and next valid values
        prev_valid = np.nan
        next_valid = np.nan
        
        # Search for the previous valid value
        for j in range(nan_idx - 1, -1, -1):
            if not np.isnan(column[j]):
                prev_valid = column[j]
                break
        
        # Search for the next valid value
        for j in range(nan_idx + 1, len(column)):
            if not np.isnan(column[j]):
                next_valid = column[j]
                break
        
        # Choose the nearest valid value
        if not np.isnan(prev_valid) and not np.isnan(next_valid):
            # Choose the closer one
            if nan_idx - j < j - nan_idx:
                column[nan_idx] = prev_valid
            else:
                column[nan_idx] = next_valid
        elif not np.isnan(prev_valid):
            column[nan_idx] = prev_valid
        elif not np.isnan(next_valid):
            column[nan_idx] = next_valid
            # Collect the cleaned columns back into X2
        X[:, i] = column

# Ensure the target y (Te) matches the number of samples
y = data.Te.data[:len(all_Z)]  # Assuming Te corresponds to Z and has the same number of entries

# Function to handle NaN values in an array
def handle_nan_values(array):
    for i in range(array.shape[0]):
        if np.isnan(array[i]):
            prev_valid = np.nan
            next_valid = np.nan
            
            # Search for the previous valid value
            for j in range(i - 1, -1, -1):
                if not np.isnan(array[j]):
                    prev_valid = array[j]
                    break
            
            # Search for the next valid value
            for j in range(i + 1, len(array)):
                if not np.isnan(array[j]):
                    next_valid = array[j]
                    break
            
            # Choose the nearest valid value
            if not np.isnan(prev_valid) and not np.isnan(next_valid):
                if i - j < j - i:
                    array[i] = prev_valid
                else:
                    array[i] = next_valid
            elif not np.isnan(prev_valid):
                array[i] = prev_valid
            elif not np.isnan(next_valid):
                array[i] = next_valid

# Handle NaN values in y
handle_nan_values(y)

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Define the neural network model with Dropout and L2 regularization
model = Sequential([
    Dense(64, activation='relu', input_shape=(125,)),
    Dense(32, activation='relu'),
    Dense(1)
])

# Compile the model with the Adam optimizer and mean squared error loss
model.compile(optimizer="adamw", loss='mse', metrics=['mae'])

# Train the model
history = model.fit(X_train, y_train, epochs=30, batch_size=16, validation_split=0.3, verbose=1)

# Plot the loss function over epochs
plt.figure(figsize=(8, 6))
plt.plot(history.history['loss'], label='Ztráta trénovanosti')
plt.plot(history.history['val_loss'], label='Ztráta platnosti')
plt.title("Ztrátová funkce v jednotlivých epochách")
plt.xlabel("Počet epoch")
plt.ylabel("Ztráty (MSE)")
plt.legend()
plt.show()
