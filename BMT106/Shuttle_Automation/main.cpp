/*
 * Author: Nuri Melih Sensoy
 * github.com/nmelihsensoy
 * File: "main.cpp"
 * 
 * Shuttle Automation
 *         
*/

#include "FileDb.h"
#include "ConfigTR.h"
#include "Functions.h"
using namespace std;

bool exitProgram = false;
bool delemeMem = false;
bool refreshFilters = false;
void MainMenu();
void Pages(int pageId);

FileDb file_db[5] = {
    {"DB/ShuttleDB.txt", shuttles_headline, shuttles_length, 9},
    {"DB/RoutesDB.txt", routes_headline, routes_length, 3},
    {"DB/PassengersDB.txt", passengers_headline, passengers_length, 4},
    {"DB/VehiclesDB.txt", vehicles_headline, vehicles_length, 4},
    {"DB/DriversDB.txt", drivers_headline, drivers_length, 3}
};

#include "StringsTR.h"
string *questionsARR[] = {shuttles_questions, routes_questions, passengers_questions, vehicles_questions, drivers_questions};
string *descARR[] = {shuttles_desc, routes_desc, passengers_desc, vehicles_desc, drivers_desc};

void Pages(int pageId){
    system(CLEAR);
    file_db[pageId].cacheFileContent();
    file_db[pageId].cacheStyledContent();
    file_db[pageId].yaz();
    file_db[pageId].yaz(20, pageMenuTextEN, 7);
    
    char choicePage;
    choicePage = ' ';
    cout<<choiceQuestion;
    cin>>choicePage;

    system(CLEAR);
    switch(choicePage){
        case '1':
            {
                file_db[pageId].addWithInput(questionsARR[pageId], descARR[pageId], 1);
                exitProgram = true;
                refreshFilters = false;
            }
        break;
        case '2':
            {
                file_db[pageId].addWithInput(questionsARR[pageId], descARR[pageId], 0);
                exitProgram = true;
                refreshFilters = false;
            }
        break;
        case '3':
            {
                file_db[pageId].deleteWithInput(deleteEnterSTR);
                exitProgram = true;
                refreshFilters = false;
            }
        break;
        case '4':
            {   
                string outFileName;
                cout<<outputFileNameSTR;
                cin>>outFileName;
                file_db[pageId].fileOutput(outFileName);
                choicePage = ' ';
            }
        break;
        case '5':
            {
                string findStr;
                cout<<"Aranacak Kelimeyi Giriniz: ";
                cin>>findStr;
                cout<<file_db[pageId].ara(findStr)<<endl;
                cout<<"Cikmak Icin Herhangi Birsey Girin: ";
                cin>>findStr;
            }
        break;
        case '6':
            MainMenu();
        break;
        case '7':
            exitProgram = true;
            delemeMem = true;
        break;
        default:
            MainMenu();
        break;
    }
}

void MainMenu(){
    system(CLEAR);
    char choice;
    file_db[0].cacheFileContent();
    file_db[0].yaz(30, menuTextEN, 6);

    do{
        choice = ' ';
        cout<<choiceQuestion;
        cin>>choice;
    }while((choice<'0') or (choice > '6'));

    if((choice == '6') or (choice == '0')){
        exitProgram = true;
        delemeMem = true;
    }else{
        Pages((choice - '0')-1); 
    }
}

int main(int argc, char **argv){
    while(!refreshFilters){
        
        /** <Shuttle Filters> **/
        string defaultKeyStr[] = {"$"};
        
        string *roadName = file_db[1].getDataBySection(1);
        /*
         * All Seats and Available Seats
        */
        CustomFilters filter[6];
        filter[0].mode = 1;
        filter[0].sectionId = 8;
        string preSufFix[] = {"(", "/", ")"};
        filter[0].preSuffix = preSufFix;
        filter[0].extraBindVal = file_db[3].getDataBySection(2);
        filter[0].extraBindVal2 = file_db[2].getFreqBySectionId(file_db[0].getLineCount() ,2);
        filter[0].setBinding(defaultKeyStr, -1, file_db[0].getDataBySection(6), file_db[0].getLineCount());
        
        /*
         * Status
        */
        filter[1].mode = -1;
        filter[1].sectionId = 1;
        string statusKeySTR[] = {"0", "1"};
        string statusSTR[] = {"Pasif", "Aktif"};
        filter[1].setBinding(statusKeySTR, 2, statusSTR, 2);
        
        /*
         * Type
        */
        filter[2].mode = -1;
        filter[2].sectionId = 2;
        string typeKeySTR[] = {"1", "2", "3"};
        string typeSTR[] = {"Sabah", "Aksam", "Ozel"};
        filter[2].setBinding(typeKeySTR, 3, typeSTR, 3);
        
        /*
         * Route Name
        */
        filter[3].mode = 3;
        filter[3].sectionId = 3;
        filter[3].setBinding(defaultKeyStr, -1, roadName, file_db[1].getLineCount());
        
        /*
         * Car Licence Plate
        */
        filter[4].mode = 3;
        filter[4].sectionId = 5;
        filter[4].setBinding(defaultKeyStr, -1, file_db[3].getDataBySection(3), file_db[3].getLineCount());
        
        /*
         * Driver Name
        */
        filter[5].mode = 3;
        filter[5].sectionId = 6;
        filter[5].setBinding(defaultKeyStr, -1, file_db[4].getDataBySection(1), file_db[4].getLineCount());
        
        file_db[0].filterCount = 6;
        file_db[0].filter = filter;

        /** </Shuttle Filters> **/
        
        /** <Driver Filters> **/
        CustomFilters filter4[1];

        /*
         * Used Shuttle Count
        */
        filter4[0].mode = 4;
        filter4[0].sectionId = 2;
        filter4[0].setBinding(defaultKeyStr, -1, file_db[0].getFreqBySectionId(file_db[4].getLineCount(), 6), file_db[4].getLineCount());
        
        file_db[4].filterCount = 1;
        file_db[4].filter = filter4;
        
        /** </Driver Filters> **/

        /** </Passenger Filters> **/
        CustomFilters filter2[2];

        /*
         * Route Name
        */
        filter2[0].mode = 3;
        filter2[0].sectionId = 2;
        filter2[0].setBinding(defaultKeyStr, 0, roadName, 1);
        
        /*
         * Used Stop on Route
        */
        filter2[1].mode = 2;
        filter2[1].extraBindVal = file_db[1].getDataBySection(2);
        filter2[1].sectionId = 3;
        filter2[1].setBinding(defaultKeyStr, 0, file_db[2].getDataBySection(2), 2);
        
        file_db[2].filterCount = 2;
        file_db[2].filter = filter2;
        /** </Passenger Filters> **/
        
        
        if(delemeMem){
            delete [] filter[0].extraBindVal;
            delete [] filter[0].extraBindVal2;
            delete [] filter[0].bindVal;

            delete [] filter[3].bindVal;
            
            delete [] filter[4].bindVal;
            
            delete [] filter[5].bindVal;

            //
            delete [] filter4[0].bindVal;
            delemeMem = false;
        }
        
        
        refreshFilters = true;
        exitProgram = false;
        while(!exitProgram){
            MainMenu();     
        }
    }

    exit(0);
}