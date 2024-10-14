from pathlib import Path
from matplotlib import pyplot as plt
import xarray as xr
import sys

sys.stdout.reconfigure(encoding='utf-8')

base_path = Path('nc_soubory/')
files = sorted(list(base_path.glob('*.nc')))
files = files[2576:2578]
print(files)

data = xr.open_mfdataset(files, combine='nested', concat_dim='id_measurement')
data.load()
raw_ts_values = data.raw_TS.values
id_measurement = 1

def plot_raw_TS(data_point):
    """Vykreslení průběhu raw_TS pro jednotlivé polychromátory.
    
    Args:
        data_point (xarray.Dataset): Datový bod s jedním měřením.
    """
    raw_TS = data_point.raw_TS
    
    raw_ts_values = data.raw_TS.values
    id_measurement = 1
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

for i in range(50000000):
    # data_point1 = data.isel(id_measurement=i)
    # data_point2 = data.isel(id_measurement=i+1)
    # Z1 = data_point1.Z.data
    # A1 = data_point1.shot.data
    # Z2 = 0.274
    # A2 = "test"
    # if Z1 == Z2 and A1 != A2:
    #     print(f"výboj {data_point1.shot.data} SHODA Z (Z1={Z1}, Z2={Z2})")

        
    data_point = data.isel(id_measurement=i)
    print(f"poly_ch_id data: {data_point.poly_ch_id.data}")
    print(f"výboj {data_point.shot.data}, čas {data_point.time.data}, Z={data_point.Z.data} m, Te={data_point.Te.data} eV")