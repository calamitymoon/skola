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
files = files[2568:2578]  # Select specific files

# Load the data from the .nc files
data = xr.open_mfdataset(files, combine='nested', concat_dim='id_measurement')
data.load()

# Extract the raw time series values and features/target variables from the merged data
raw_ts_values = data.raw_TS.values

# Create a 2D input array with two features
Z = data.Z.data
T = data.time.data
TS = data.raw_TS.values

# print(TS)
# print(TS.shape)

for i in range(1, 6252):
    T = data.isel(id_measurement=i).time.data
    Z = data.isel(id_measurement=i).Z.data
    TS = data.isel(id_measurement=i).poly_ch_id.data
    TS_split = TS.astype(float)
    
    for idecko in TS_split:
        raw_TS = data.isel(id_measurement=i).raw_TS
        raw_TS.sel(poly_ch_id=[idecko]).plot(label=f'kanál {idecko}')

X = np.column_stack((Z, T, raw_TS)) 
y = data.Te.data

# print(X.shape)

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Define the neural network model with Dropout and L2 regularization
model = Sequential([
    Dense(64, activation='relu', input_shape=(2,)),
    Dense(32, activation='relu'),
    Dense(1)
])

# Compile the model with the Adam optimizer and mean squared error loss
model.compile(optimizer="adam", loss='mse', metrics=['mae'])

# Train the model
history = model.fit(X_train, y_train, epochs=30, batch_size=16, validation_split=0.2, verbose=1)

# Plot the loss function over epochs
plt.figure(figsize=(8, 6))
plt.plot(history.history['loss'], label='Training Loss')
plt.plot(history.history['val_loss'], label='Validation Loss')
plt.title("Loss Function Over Epochs")
plt.xlabel("Number of Epochs")
plt.ylabel("Loss (MSE)")
plt.legend()
plt.show()
