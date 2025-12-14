import Miura.MaximumCurvature as mc
from MATLAB.lee_region import lee_region
import cv2 
from PIL import Image

imgpath = "test_imgs/1.png"
img = cv2.imread(imgpath, 0)
print(type(img))
region, edges = lee_region(img, 4, 40)
max_curvature = mc.MaximumCurvature()
ret = max_curvature(img, region)
