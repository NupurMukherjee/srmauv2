function ImagePocess()

% read image 
image = imread('TaskImage.png');
imshow(image);

% size of image, ans = 720   960     3
% It's a 720 X 960 matrix with 3 color RGB
[height, width, planes] = size(image)

% isolate RGB image

r = image(:, :, 1);             % red image
g = image(:, :, 2);             % green image
b = image(:, :, 3);             % blue image


% apply the redness calculation
redness = double(r) - max(double(b), double(g));
mask = (redness > 0);
newred = times(redness, mask);
mxr = max(max(newred)); 
mask = (newred > (mxr * 0.7));
figure(2)
imagesc(mask);

% compute centroid of  object
[finalredx finalredy] = computefinalxy(mask);


% apply the greenness calculation
greenness = double(g) - max(double(b), double(r));
mask = (greenness > 0);
newgreen = times(greenness, mask);
mxg = max(max(greenness)); % 135
mask = (newgreen > (mxg * 0.4));
figure(3)
imagesc(mask);

% compute centroid of  object
[finalgreenx finalgreeny] = computefinalxy(mask);

% apply the yellowness calculation
redThresh = 200;
greenThresh = 200;
blueThresh = 100;

mask = (double(r) > redThresh) & (double(g) > greenThresh) & (double(b) < blueThresh);
figure(4)
imagesc(mask);

% compute centroid of  object
[finalyellowx finalyellowy] = computefinalxy(mask);

end

function [finalx finaly] = computefinalxy(mask2)
[szx szy] = size(mask2);
totpt = 0;
for x=1:szx
    for y=1:szy
        if (mask2(x,y) == 1)
            totpt = totpt + 1;
            sx(totpt) = x;
            sy(totpt) = y;
        end
    end
end
% compute mean and std deviation
avgx = mean(sx);    
avgy = mean(sy);
stdx = std(sx);
stdy = std(sy);

% use std deviation to eliminate outlier
stddist = (stdx^2+stdy^2)^0.5;
dist = zeros(1,totpt);
sumx = 0;
sumy = 0;
tot = 0;
for i=1:totpt
    dist(i) = ((sx(i)-avgx)^2 + (sy(i)-avgy)^2)^0.5;    
    if (dist(i)<stddist)
            sumx = sumx + sx(i);
            sumy = sumy + sy(i);
            tot = tot + 1;        
    end
end
if (tot > 0)
    finalx = sumx/tot;
    finaly = sumy/tot;
else
    finalx = -1;
    finaly = -1;
end
end
