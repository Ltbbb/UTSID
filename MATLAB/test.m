function [] = test()

img = "demo_img_1_comp_comp.png";
img = imread(img);
[rows, columns, numberOfColorChannels] = size(img);

lee_region(img, 4, 40);

