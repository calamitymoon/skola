import numpy as np
import matplotlib.pyplot as plt
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Dropout
from tensorflow.keras.optimizers import Adam
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import mean_squared_error
from pathlib import Path
import xarray as xr
import sys

sys.stdout.reconfigure(encoding='utf-8')

base_path = Path('nc_soubory/')
files = sorted(list(base_path.glob('*.nc')))
files = files[2478:2578]

data = xr.open_mfdataset(files, combine='nested', concat_dim='id_measurement')

data.load()

all_Z = []
all_T = []
all_raw_TS = []

for i in range(data.dims['id_measurement']):
    data_point = data.isel(id_measurement=i)
    Z = data_point.Z.data
    all_Z.append(Z)
    T = data_point.time.data
    all_T.append(T)
    
    raw_TS = data_point.raw_TS
    tmp = [raw_TS.sel(poly_ch_id=2).values, raw_TS.sel(poly_ch_id=3).values, raw_TS.sel(poly_ch_id=4).values]
    all_raw_TS.append(np.concatenate(tmp))

X = np.column_stack((all_Z, all_T, all_raw_TS))

X2 = X.copy()

# nahrazovani NaN hodnot
for i in range(X2.shape[1]):
    column = X2[:, i]
    nan_indices = np.where(np.isnan(column))[0]
    
    for nan_idx in nan_indices:
        prev_valid = np.nan
        next_valid = np.nan
        
        for j in range(nan_idx - 1, -1, -1):
            if not np.isnan(column[j]):
                prev_valid = column[j]
                break
        
        for j in range(nan_idx + 1, len(column)):
            if not np.isnan(column[j]):
                next_valid = column[j]
                break
        
        if not np.isnan(prev_valid) and not np.isnan(next_valid):
            if nan_idx - j < j - nan_idx:
                column[nan_idx] = prev_valid
            else:
                column[nan_idx] = next_valid
        elif not np.isnan(prev_valid):
            column[nan_idx] = prev_valid
        elif not np.isnan(next_valid):
            column[nan_idx] = next_valid
        X[:, i] = column        

X = X2

scaler = StandardScaler()
X = scaler.fit_transform(X)
X.reshape(-1, 1)

y = data.Te.data[:len(all_Z)]

def handle_nan_values(array):
    for i in range(array.shape[0]):
        if np.isnan(array[i]):
            prev_valid = np.nan
            next_valid = np.nan
            
            for j in range(i - 1, -1, -1):
                if not np.isnan(array[j]):
                    prev_valid = array[j]
                    break
            
            for j in range(i + 1, len(array)):
                if not np.isnan(array[j]):
                    next_valid = array[j]
                    break
            
            if not np.isnan(prev_valid) and not np.isnan(next_valid):
                if i - j < j - i:
                    array[i] = prev_valid
                else:
                    array[i] = next_valid
            elif not np.isnan(prev_valid):
                array[i] = prev_valid
            elif not np.isnan(next_valid):
                array[i] = next_valid

handle_nan_values(y)

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

print(X_train.shape[1])

model = Sequential([
    Dense(128, activation='relu', input_shape=(X_train.shape[1],)),
    Dense(64, activation='relu'),
    Dense(32, activation='relu'),
    Dense(1)
])

model.compile(optimizer='adamw', loss='mse', metrics=['mae'])

history = model.fit(X_train, y_train, epochs=30, batch_size=16, validation_split=0.3, verbose=1)

model.save('./trained_model.keras')

plt.figure(figsize=(8, 6))
plt.plot(history.history['loss'], label='Tréninková ztráta')
plt.plot(history.history['val_loss'], label='Validační ztráta')
plt.title("Ztrátová funkce v jednotlivých epochách")
plt.xlabel("Počet epoch")
plt.ylabel("Ztráta (MSE)")
plt.legend()
plt.show()
