from PIL import Image
import os
import matplotlib.pyplot as plt
import numpy as np
import cv2

GUIDE = "V1"
DATA_DIRECTORY = "C:\\Users\\Gebruiker\\OneDrive - University of Twente\\year 4\\Research Project\\Data\\Captures"
CROP_DIRECTORY = "C:\\Users\\Gebruiker\\OneDrive - University of Twente\\year 4\\Research Project\\Data\\Crop"
test_filename = "edwin_L_Index_50_1_0.png"

FULL_DATA_DIRECTORY = os.path.join(DATA_DIRECTORY, GUIDE)
FULL_CROP_DIRECTORY = os.path.join(CROP_DIRECTORY, GUIDE)

def crop_and_rotate(filename):
    # Opens a image in RGB mode
    im = Image.open(os.path.join(FULL_DATA_DIRECTORY, filename))

    #Image cropping
    left = 360
    right = 700
    top = 50
    bottom = 600
    # crop img using points
    im1 = im.crop((left, top, right, bottom))

    #Image rotation
    arr = np.array(im1)
    rotate = np.rot90(arr)
    
    #Histogram equalization
    rotate = cv2.cvtColor(rotate, cv2.COLOR_BGR2GRAY)
    equ = cv2.equalizeHist(rotate)

    #Show images next to each other
    # disp = np.hstack((rotate,equ)) #stacking images side-by-side
    # disp = Image.fromarray(disp)
    # disp.show()
   
    # Save img
    result = Image.fromarray(equ)
    plt.imsave(os.path.join(FULL_CROP_DIRECTORY, filename), result, cmap="grey")

# crop_and_rotate(test_filename)

def batch_ROI(src_directory):
    print(src_directory)
    for file in os.listdir(src_directory):
        filename = os.fsdecode(file)
        crop_and_rotate(filename)
    print("[INFO] Batch ROI determination completed")

batch_ROI(FULL_DATA_DIRECTORY)