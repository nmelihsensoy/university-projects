inputM = [1 2 3;4 5 6;7 8 9];
kernel = [-1 -2 -1;0 0 0;1 2 1];

disp(conv2(inputM,kernel,'same'));