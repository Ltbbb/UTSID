function [] = test(img)

img = imread(img);
[rows, columns, numberOfColorChannels] = size(img);
disp(rows);
disp(columns);
disp(numberOfColorChannels);

