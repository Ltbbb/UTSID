% LISATB 02-12-25
% Taken from demo.m, modified to take two img paths as input

function [score] = demo_slice(img_cap, img_compare)

%LISATB 02-12-25: open imgs from command line
img_cap = imread(img_cap);
img_compare = imread(img_compare);

%params for functions. LISATB 02-12-25
mask_h = 4;
mask_w = 40;
sigma = 5;
cw = 50;
ch = 100;

[region,edgs] = lee_region(img_cap, mask_h, mask_w); % get binary mask and edges of the finger region
[img_cap,region] = huang_normalise(img_cap,region,edgs); % normalize the img using the prev values
img_cap_templ = miura_max_curvature(img_cap,region,sigma); % generate a template img using max curvature
img_cap_veins = binarize(img_cap_templ,'median'); % get the img of the captured veins out of the template

%compare and score correlation
%LISATB 02-12-25: *200 included in score calculation
score = miura_match(double(img_compare), double(img_cap_veins),cw,ch) * 200;
fprintf('Match score: %3.2f%\n', score);