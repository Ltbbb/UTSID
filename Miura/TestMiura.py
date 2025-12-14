from Miura.MaximumCurvature import MaximumCurvature
from Miura.MiuraMatch import MiuraMatch
from MATLAB.lee_region import lee_region
import cv2 
from PIL import Image

#create instances of runnable objs
max_curvature = MaximumCurvature()
miura_match = MiuraMatch()

#define imgs
imgpath1 = "test_imgs/1.png"
img1 = cv2.imread(imgpath1, 0)
imgpath2 = "test_imgs/2.png"
img2 = cv2.imread(imgpath2, 0) #NOTE: its important that the img gets read in grayscale

#get both img templates
mask1, _ = lee_region(img1, 4, 40)
templ1 = max_curvature(img1, mask1)
mask2, _ = lee_region(img2, 4, 40)
templ2 = max_curvature(img2, mask2)

#match images
score, _, _ = miura_match.score(templ1, templ2)
print(score)
