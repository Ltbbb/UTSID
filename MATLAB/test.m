function [] = test()

img = "1.png";
img = imread(img);
[rows, columns, numberOfColorChannels] = size(img);

[region, edges] = lee_region(img, 4, 40);
huang_normalise(img, region, edges);




