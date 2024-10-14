from pathlib import Path
from matplotlib import pyplot as plt
import xarray as xr
import numpy as np
import sys

sys.stdout.reconfigure(encoding='utf-8')

# Cesta k NC souborům
base_path = Path('nc_soubory/')
files = sorted(list(base_path.glob('*.nc')))
files = files[2576:2578]
print(files)

# Načtení dat ze souborů
data = xr.open_mfdataset(files, combine='nested', concat_dim='id_measurement')
data.load()

# Seřazení dat podle proměnné 'Z'
data_sorted = data.sortby('Z', ascending=True)

# Výpis pole raw_TS ze seřazených dat
raw_ts_values = data_sorted.raw_TS.values
column_names = data_sorted.raw_TS.coords  # Získání jmen sloupců

# Vykreslení průběhu raw_TS pro jednotlivé polychromátory
def plot_raw_TS(data_point):
    """Vykreslení průběhu raw_TS pro jednotlivé polychromátory.
    
    Args:
        data_point (xarray.Dataset): Datový bod s jedním měřením.
    """
    raw_TS = data_point.raw_TS
    
    plt.figure()
    try:
        raw_TS.sel(poly_ch_id=1).plot(label='kanál 1')
    except KeyError:
        pass  # první kanál nemusí být v datech přítomný
    raw_TS.sel(poly_ch_id=2).plot(label='kanál 2')
    raw_TS.sel(poly_ch_id=3).plot(label='kanál 3')
    raw_TS.sel(poly_ch_id=4).plot(label='kanál 4')
    try:
        raw_TS.sel(poly_ch_id=5).plot(label='kanál 5')
    except KeyError:
        pass  # pátý kanál nemusí být v datech přítomný
    plt.title(f'výboj #{data_point.shot.data}, čas {data_point.time.data:d}, Z={data_point.Z.data:.1f} m, Te={data_point.Te.data:.1f} eV')
    plt.legend()
    plt.show()


# Výpis prvních 20 řádků
for row in raw_ts_values[:20, :]:
    formatted_row = []
    for val in row:
        if isinstance(val, (float, int)):  # Pokud je val číslo, přímo ho formátujeme
            formatted_row.append(f"{val:.2f}")
        elif isinstance(val, (np.ndarray, list)) and val.size == 1:  # Pokud je val pole s jednou hodnotou
            formatted_row.append(f"{val.item():.2f}")  # Vytáhneme tu hodnotu
        else:
            formatted_row.append(str(val))  # Pokud nelze formátovat, necháme hodnotu jako je
    print(" | ".join(formatted_row))
    plot_raw_TS(data_sorted.isel(id_measurement=1))