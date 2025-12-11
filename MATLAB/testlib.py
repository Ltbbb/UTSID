import os, ctypes, cv2
from ctypes import cdll

# Load the shared library
if os.name == 'nt':
    name = ctypes.util.find_library('lee_region')
    lee_region = ctypes.CDLL("C:/Users/Gebruiker/Documents/Coding/Git/UTSID_repo/UTSID/MATLAB/codegen/dll/lee_region/lee_region.dll")
    # lee_region = cdll.LoadLibrary('lee_region.dll')
else:
    lee_region = ctypes.CDLL('./lee_region.so')

# Call the add function
img = cv2.imread("demo_img_1.png")
result = lee_region.lee_region(img, 4, 40)
print("The result is:", result)