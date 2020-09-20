function bImg=threshold(rgbImg, val)
bImg = zeros(size(rgbImg, 1), size(rgbImg, 2));
if size(rgbImg, 3) >1
for i=1:size(rgbImg, 1)
    for j=1:size(rgbImg, 2)
        R = rgbImg(i, j, 1);
        G = rgbImg(i, j, 2);
        B = rgbImg(i, j, 3);
        
       if (R/3) + (G/3) + (B/3) > val
            bImg(i,j) = 1;
        else
            bImg(i,j) = 0;
        end 
    end
end
else
    bImg = rgbImg;
end
end