import numpy as np

# Simple finger normalisation, it aligns the finger to the centre of the 
# image using an affine transformation, Elliptic projection which is
# described in the referenced paper is not included,

# Parameters:
#  img   - Input vascular image
#  fvr   - Binary image of the finger region
#  edges - Edges of the finger, first row contains the y-coordinates of 
#          the top edge and the second row contains the y-coordinates of
#          the bottom edge,

# Returns:
#  img - Transformed image
#  fvr - Transformed finger region
#  rot - Rotation in degrees applied by the transformation
#  tr  - Translation in pixels applied in transformation

# Reference:
# Finger-vein authentication based on wide line detector and pattern 
#    normalization
# B. Huang, Y. Dai, R. Li, D. Tang and W. Li
# 20th International Conference on Pattern Recognition (ICPR), 2010 
# doi: 10.1109/ICPR.2010.316

# Author:  Bram Ton <b.t.ton@alumnus.utwente.nl>
# Date:    13th March 2012
# License: Simplified BSD License
def huang_normalise(img, fvr, edges):
    [img_h, img_w] = img.shape
    bl = edges.mean(axis=0) # Base line


    # Fit a straight line through the base line points
    # brob = robustfit(1:img_w, bl);
    # rot = -1 * np.arctan(brob(2)); # Rotation
    # tr = img_h/2 - brob(1); # Translation

    # # Construct the spatial transformation structure for an affine transform
    # tform = maketform('affine',[cos(rot), sin(rot),0;-sin(rot),cos(rot),0;0,tr,1]);

    # # Apply the transformation
    # img = imtransform(img,tform,          'XData',[1 img_w],'YData',[1 img_h]);
    # fvr = imtransform(fvr,tform,'nearest','XData',[1 img_w],'YData',[1 img_h]);

    # rot = rot*(180/pi); # Convert radians to degrees

from lee_region import lee_region
import cv2
from PIL import Image
import matplotlib.pyplot as plt
import os

imgpath1 = "MATLAB/1.png"
img1 = cv2.imread(imgpath1, 0)
region, edges = lee_region(img1, 4, 40)
huang_normalise(img1, region, edges)
