# Localise the finger region using Lee's method

# Parameters:
#  img    - Input vascular image
#  mask_h - Height of the mask
#  mask_w - Width of the mask

# Returns:
#  region - Binary mask indicating the finger region
#  edges  - Matrix containing two rows, first row corresponds to the 
#           y-positions of the upper finger edge and the second row
#           corresponds to the y-positions of the lower finger edge.

# Reference:
# Finger vein recognition using minutia-based alignment and local binary
#   pattern-based feature extraction
# E.C. Lee, H.C. Lee and K.R. Park
# International Journal of Imaging Systems and Technology
#   Volume 19, Issue 3, September 2009, Pages 175-178   
# doi: 10.1002/ima.20193

# Author:  Bram Ton <b.t.ton@alumnus.utwente.nl>
# Date:    20th March 2012
# License: Simplified BSD License

import cv2
import math
import numpy as np
import scipy
from PIL import Image

def lee_region(img, mask_h, mask_w): #-> [region, edges]

    [img_h, img_w] = img.shape
    print(img_h)
    print(img_w)

    # Determine lower half starting point
    if img_h % 2 == 0:
        half_img_h = img_h/2
    else:
        half_img_h = math.ceil(img_h/2)
    print(half_img_h)

    # Construct mask for filtering
    mask = np.zeros((mask_h,mask_w));
    print(mask.shape)
    mask[1:int(mask_h/2),:] = -1;    
    mask[int(mask_h/2) + 1:, :] = 1;
    # print(mask)

    # Filter image using mask
    # img_filt = imfilter(img, mask,'replicate');
    # img_filt = scipy.ndimage.filters.convolve(img, mask, mode='nearest')
    img_filt = cv2.filter2D(img, -1, mask)
    #print(img_filt)
    #print(img_filt.shape)
    img_filt_disp = Image.fromarray(img_filt)
    img_filt_disp.show()

    # Upper part of filtred image
    img_filt_up = img_filt[:(half_img_h-1), :];
    # img_filt_up_disp = Image.fromarray(img_filt_up)
    # img_filt_up_disp.show()
    # print(img_filt_up.shape)
    y_up = np.argmax(img_filt_up, axis=0)
    # print(y_up)

    # Lower part of filtred image
    img_filt_lo = img_filt[(half_img_h-1):, :];
    # img_filt_lo_disp = Image.fromarray(img_filt_lo)
    # img_filt_lo_disp.show()
    # print(img_filt_lo.shape)
    y_lo = np.argmin(img_filt_lo, axis=0)
    # print(y_lo)

    # Fill region between upper and lower edges
    # region = np.zeros(img.shape);
    # for i in img_w - 1:
    #     region[y_up(i) : y_lo(i)+size(img_filt_lo,1)][i] = 1;

    # # Save y-position of finger edges
    # edges = np.zeros(2,img_w);
    # edges[1,:] = y_up;
    # edges[2,:] = round(y_lo + len(img_filt_lo[0]));

img = cv2.imread("MATLAB/demo_img_1_comp_comp.png", cv2.IMREAD_GRAYSCALE)
lee_region(img, 4, 40)