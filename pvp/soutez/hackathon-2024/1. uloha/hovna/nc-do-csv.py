import numpy as np
import pandas as pd
from netCDF4 import Dataset
import sys

def export_nc_to_csv(nc_file, csv_file):
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
        # Option: Average across the second dimension
        data_to_export = np.mean(data, axis=1)  # Average along the second dimension to reduce it to 2D

    elif data.ndim == 2:
        data_to_export = data  # Use the data as is if it's already 2D

    else:
        raise ValueError(f"Unsupported data shape: {data.shape}")

    # Multiply every number by 1000
    data_to_export *= 1000

    # Convert the numpy array to a DataFrame
    df = pd.DataFrame(data_to_export)

    # Export the DataFrame to a CSV file
    df.to_csv(csv_file, index=False, header=True)
    print(f"Data exported to {csv_file}")

    # Close the dataset
    dataset.close()

# Example usage
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python nc-do-csv.py <nc_file>")
        sys.exit(1)

    nc_file_path = sys.argv[1]  # Get the .nc file path from the command-line argument
    csv_file_path = 'exported_data.csv'  # Specify the desired output CSV file path
    export_nc_to_csv(nc_file_path, csv_file_path)
