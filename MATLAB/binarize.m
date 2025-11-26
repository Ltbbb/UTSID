function BW =  binarize(img,method,varargin)
% Various binarization methods
% kmeans:
%   Clustering based method
%   Additional parameters:
%     - none
% median:
%   Uses the median value of the image as threshold 
%   Additional parameter:
%     - none
% adaptive:
%   Determines a different threshold per region 
%   Additional parameters:
%     - ws: Window Size, the size of the region
%     - C : Constant value
% otsu:
%   The intraclass variance of the black and white pixels is minimized
%   Additional parameters:
%     - none

optargin = size(varargin,2); % Number of variable arguments

if (strcmp(method,'kmeans') &&  optargin==0)
    md  = median(img(img>0));
    c1  = mean(img(img < md));
    c2  = mean(img(img >= md));    
    
    idx = kmeans(img(:), 2, 'start', [c1;c2]);
    BW = reshape((idx==2), size(img));
elseif (strcmp(method,'kmeans') &&  optargin==1)
    fvr = logical(varargin{1});
    bla = img(fvr);
    %md  = median(bla);
    md  = mean(bla);
    c1  = mean(bla(bla < md));
    c2  = mean(bla(bla >= md));    
    
    idx = kmeans(img(fvr), 2, 'start', [c1;c2]);
    BW = zeros(size(img));
    BW(fvr) = (idx==2);    
elseif (strcmp(method,'median') &&  optargin==0)
    % Only take non-zero values into account for binarization
    md  = median(img(img>0));
    BW = img > md;
elseif (strcmp(method,'median') &&  optargin==1)
    fvr = logical(varargin{1});
    bla = img(fvr);
    % Only take non-zero values into account for binarization
    md  = median(bla(bla>0));
    BW = img > md;    
elseif strcmp(method,'adaptive')
    ws = varargin{1}; % Window Size
    C = varargin{2};  % Constant
    h = fspecial('average', ws);
    img_f = imfilter(img, h, 'replicate');
    BW = img_f - C > img;
elseif strcmp(method,'otsu')
    level = graythresh(img);
    BW = im2bw(img,level);
elseif strcmp(method,'hyst')
    thresh_marker = varargin{1}; % Threshold for marker
    thresh_mask   = varargin{2}; % Threshold for mask
    marker = img > thresh_marker;
    mask   = img > thresh_mask;
    BW = imreconstruct(marker,mask);    
else    
    fprintf('Unknown binarization method specified\n')
end
