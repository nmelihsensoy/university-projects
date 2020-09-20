function imgReturn=diagonal(img)
imgReturn = img;
for i=1:size(img,1)
    for j=1:size(img,2)
        if (i==j)
            imgReturn(i,j,1)=0;
            imgReturn(i,j,2)=0;
            imgReturn(i,j,3)=0;
        elseif (i+j==(size(img,2)+1))
            imgReturn(i,j,1)=0;
            imgReturn(i,j,2)=255;
            imgReturn(i,j,3)=0;
        end
    end
end
end