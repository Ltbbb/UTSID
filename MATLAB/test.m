function [] = test()

img = "demo_img_1.png";
img = imread(img);
[rows, columns, numberOfColorChannels] = size(img);
disp(rows);
disp(columns);
disp(numberOfColorChannels);

lee_region(img, 4, 40);

