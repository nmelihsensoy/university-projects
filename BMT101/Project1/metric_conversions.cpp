/*
 * Author: Nuri Melih Şensoy
 * Console metric conversion app
 *
*/

#include <iostream>
using namespace std;

int main(){

    float inputMeter, returnMM, returnCM, returnDM, returnDAM, returnHM, returnKM;
    int userChoice = 0;
    cout << "Enter length in meter: ";
    cin >> inputMeter;

    cout << "Please make your selection\n";
    cout << "1 - MM\n";
    cout << "2 - CM\n";
    cout << "3 - DM\n";
    cout << "4 - DAM\n";
    cout << "5 - HM\n";\n
    cout << "6 - KM\n";
    cin >> userChoice;

    switch(userChoice){
        case 1:
            returnMM = (inputMeter*1000);
            cout << returnMM <<" mm\n";
        break;
        case 2:
            returnCM = (inputMeter*100);
            cout << returnCM <<" cm\n";
        break;
        case 3:
            returnDM = (inputMeter*10);
            cout << returnDM <<" dm\n";
        break;
        case 4:
            returnDAM = (inputMeter/10);
            cout << returnDM <<" dam\n";
        break;\n
        case 5:
            returnHM = (inputMeter/100);
            cout << returnHM <<" hm\n";
        break;
        case 6:
            returnKM = (inputMeter/1000);
            cout << returnKM <<" km\n";
        break;
    }
}