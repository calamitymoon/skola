import numpy as np
import matplotlib.pyplot as plt
from netCDF4 import Dataset

def display_nc_file(nc_file):
    # Load the .nc file
    dataset = Dataset(nc_file, mode='r')

    # Print file information
    print(f"File: {nc_file}")
    print("Variables:")
    for var_name in dataset.variables:
        print(f" - {var_name}: {dataset.variables[var_name].shape}")

    # Get data from the first variable
    variable_name = list(dataset.variables.keys())[0]  # Get the first variable name
    data = dataset.variables[variable_name][:]  # Load the data

    # Check the shape of the data
    if data.ndim == 3:
        # Option 1: Display a specific slice
        # For example, show the first slice along the second dimension
        data_to_display = data[:, 0, :]  # Change 0 to another index to see other slices

        # Option 2: Average across the second dimension
        # data_to_display = np.mean(data, axis=1)

    elif data.ndim == 2:
        data_to_display = data  # Use the data as is if it's already 2D

    else:
        raise ValueError(f"Unsupported data shape: {data.shape}")

    # Display the data
    plt.figure(figsize=(10, 6))
    plt.imshow(data_to_display, cmap='viridis', aspect='auto')
    plt.colorbar(label=variable_name)
    plt.title(f'Data from {variable_name}')
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.show()

    # Close the dataset
    dataset.close()

# Example usage
if __name__ == "__main__":
    nc_file_path = 'nc_soubory/0.nc'  # Specify the path to your .nc file here
    display_nc_file(nc_file_path)
