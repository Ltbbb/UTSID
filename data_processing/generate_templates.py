import cv2
import os
import matplotlib.pyplot as plt
from Miura.MaximumCurvature import MaximumCurvature
from Miura.MiuraMatch import MiuraMatch
from MATLAB.lee_region import lee_region

DATA_DIRECTORY = "C:\\Users\\Gebruiker\\OneDrive - University of Twente\\year 4\\Research Project\\Data\\Crop\\V1"
TEMPLATES_DIRECTORY = "C:\\Users\\Gebruiker\\OneDrive - University of Twente\\year 4\\Research Project\\Data\\Templates"
max_curvature = MaximumCurvature()

def generate_template(filename):
    #define imgs
    img = cv2.imread(os.path.join(DATA_DIRECTORY, filename), 0)

    #get both img templates
    mask, _ = lee_region(img, 4, 40)
    mask, _ = lee_region(mask, 4, 40)
    templ = max_curvature(img, mask)
    templ_filename = os.path.join(TEMPLATES_DIRECTORY, filename)
    plt.imsave(templ_filename,templ) #to visualize: cmap = 'grey'

generate_template("edwin_L_Index_50_1_0.png")
# generate_template("max_R_Ring_50_2_5.png")
# generate_template("simay_L_Ring_30_1_4.png")