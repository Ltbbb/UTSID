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

def lee_region(img, mask_h, mask_w): #-> [region, edges]

    im = cv2.imread(img);

    img_h, img_w = im.shape;

    # Determine lower half starting point
    if img_h % 2 == 0:
        half_img_h = img_h/2 + 1;
    else:
        half_img_h = math.ceil(img_h/2);

    # Construct mask for filtering
    mask = np.zeros(mask_h,mask_w);
    mask[1:mask_h/2,:] = -1;    
    mask[mask_h/2 + 1:, :] = 1;

    # Filter image using mask
    img_filt = imfilter(img, mask,'replicate');
    %figure; imshow(img_filt,[])

    # Upper part of filtred image
    img_filt_up = img_filt[1:(half_img_h-1), :];
    [~, y_up] = max(img_filt_up); 

    # Lower part of filtred image
    img_filt_lo = img_filt[half_img_h:, :];
    [~,y_lo] = min(img_filt_lo);

    # Fill region between upper and lower edges
    region = np.zeros(size(img));
    for i in img_w - 1:
        region(y_up(i):y_lo(i)+size(img_filt_lo,1), i) = 1;

    # Save y-position of finger edges
    edges = np.zeros(2,img_w);
    edges[1,:] = y_up;
    edges[2,:] = round(y_lo + size(img_filt_lo,1));