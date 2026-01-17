import numpy as np
import h5py

arr = np.random.randn(1000)
print(arr)

with h5py.File("data_processing/test.hdf5", "w") as file:
    dset = file.create_dataset("default", data = arr)


with h5py.File("data_processing/test.hdf5", "r") as file:
    data = file['default']

    print(min(data))
    print(max(data))
    print(data[:15])