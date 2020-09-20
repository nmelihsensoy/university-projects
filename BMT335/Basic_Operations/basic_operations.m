img = imread("image1.jpeg");
gray = rgb2gray(img);
blackWhite = im2bw(gray);
rotated = rot90(gray, 3);
negative = imcomplement(gray);
bright = gray + 40;
for x=1:size(gray, 1)
for y=1:size(gray, 2)
if gray(x,y) < 100
bright2(x,y) = gray(x,y)*0.75;
else
bright2(x,y) = gray(x,y)*1.25;
end
end
end

histEqual = histeq(gray);
shift = imtranslate(gray,[25.3, -10.1],'FillValues',255);
shift = imtranslate(shift,[20, 30],'FillValues',255);
subtracted = imsubtract(gray, histEqual);
detectedEdges = edge(gray, 'prewitt');

figure1=figure('Position', [0, 0, 1400, 600]);

subplot(2,6,1);
imshow(blackWhite);
title("1.");

subplot(2,6,2);
imshow(rotated);
title("2.");

subplot(2,6,3);
imshow(negative);
title("3.");

subplot(2,6,4);
imshow(bright);
title("4.");

subplot(2,6,5);
imshow(bright2);
title("5.");

subplot(2,6,6);
imhist(gray);
title("6.");

subplot(2,6,7);
imshow(histEqual);
title("7.");

subplot(2,6,8);
imshow(shift);
title("8.");

subplot(2,6,9);
imshow(subtracted);
title("9.");

subplot(2,6,10);
imshow(detectedEdges);
title("10.");