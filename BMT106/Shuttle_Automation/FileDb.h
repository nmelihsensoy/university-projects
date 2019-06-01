#ifndef FILEDB_H
#define FILEDB_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class CustomFilters{
    private:
        // Input Vars
        string sectionInput; // Current section value
        int lineCount; // Current line id
        int sectionCount; // All section count
        int currentSectionId; // Current section id
        //

        string sectionOutput; // Final output
        
        /*
         * Sets final variable by the filter mode.
        */
        void stringTrade();
    public:
        // Filter Vars
        int sectionId; // Section id that wanted to filtered
        int mode; // Filtering mode
        
        string *bindKey; // Key array for binding
        int keySize; // Key array size
        string *bindVal; // Value array for binding
        int valSize; // Value array size

        string *extraBindVal; // Extra value array for binding
        string *extraBindVal2; // Extra value array for binding
        
        stringstream ss; // String variable for if needed
        string *preSuffix; // Custom prefix and suffix
        //
        
        CustomFilters();
        ~CustomFilters();

        /*
         * Sets binding from transmitter side.
        */
        void setBinding(string *key, int keyS, string *val, int valS);

        /*
         * Starts filtering from receiver side.
        */
        void initFilter(string sectionInput, int sectionCount, int lineCount, int currentSectionId);

        /*
         * Returns final output from receiver side.sectionOutput
        */
        string getOutput();

        /*
         * Runs filter from receiver side.
        */
        void runFilter();
};

/*
 * (Unnecessary class)
*/
class AddListSearch{
    protected:
        string fileName; // Database file name
        string tempFileName = "temp.txt"; // Temporary file name for update and delete function 
        void ekle(string line);
        bool isFileExist();
        void listele(string *list);
        int dataCount = 0;
        virtual string ara(string str);
};

/*
 * (Unnecessary class)
*/
class DeleteUpdate{
    protected:
        string fileName; // Database file name
        string tempFileName = "temp.txt"; // Temporary file name for update and delete function 
        //int dataCount = 0;
        void sil(string line);
        void sil(int line_int);
        void guncelle(string old_line, string new_line);
        void guncelle(int old_line_int, string new_line);
};

class FileDb: AddListSearch, DeleteUpdate{
    private:
        // Files Config
        string fileName; // Database file name
        string tempFileName = "temp.txt"; // Temporary file name for update and delete function 
        
        // Cache Vars
        string cachedFileContent[100]; // Stores database file datas
        string styledContent; // Stores datas that ready for printing 
        //int dataCount = 0; // Stores data count inside the file
        
        // Section Vars
        int sectionCount; // Column size
        int *sectionLength; // Column lengths array for every column
        
        // Styling
        string *headlines; // Column headlines
        string headlinesSTR; // Styled column headlines
        string seperatorSTR; // Line seperator
        stringstream outputSTR;  // Styled output stream   
        // 
    public:
        //Filter
        CustomFilters *filter;
        int filterCount;
        //

        FileDb(string fileName, string *headlines, int *length, int size);
        ~FileDb();
        
        /*
         * Checks whether the file is exist
        */
        //bool isFileExist();
        
        /*
         * Gets the inside of the file named value of the FileName and save every line into cachedFileContent
        */
        void cacheFileContent();

        /*
         * Returns the dataCount variable
        */
        int getLineCount();
        
        /*
         * Deletes the wanted line which same as the arguments value
        */
        void deleteLine(string line);
        
        /*
         * Deletes the line by line id
        */
        void deleteLine(int line_int);
        
        /*
         * Modifys the value of the old_line with new_line 
        */
        void modifyLine(string old_line, string new_line);
        
        /*
         * Modifys the value at the wanted line id with new_line 
        */
        void modifyLine(int old_line_int, string new_line);
        
        /*
         * Makes array data ready for database file.
        */
        string dbOutput(string *entry);

        /*
         * Appends new line to the file.Uses sectionLength array for set the sections width.
        */
        void addEntry(string *entry);
        
        /*
         * Handles inputs for every section then makes the data ready for file.After that adds new line or update existing line by the value of the mode;
        */
        void addWithInput(string *questions, string *descriptions, int mode=1);
        
        /*
         * Handles inputs and delete the wanted line inside the file.
        */
        void deleteWithInput(string question);

        /*
         * Returns wanted data by the line and section id
        */
        string getDataByPos(int line, int section);
        
        /*
         * Returns the every section on the line in a array.
        */
        string *getDataByLine(int line);

        /*
         * Returns all the data in the wanted section in a array.
        */
        string *getDataBySection(int section);
        void getDataBySectionStatic(int section, string* test);
        
        /*
         * Returns frequency for wanted id 
        */
        string *getFreqBySectionId(int count, int secId);

        /*
         * Makes ready static content for printing.Headlines and Seperator
        */
        void cacheStatics();

        /*
         * Applies filters to content and saves into the outputSTR
        */
        void cacheStyledContent();

        /*
         * Prints styled content.outputSTR
        */
        void printStyledContent();

        /*
         * Updates cachedFileContent and styledContent both 
        */
        void updateCaches();
        
        /*
         * Returns styled content.Styled content is a printable version of the all data inside the file
        */
        string getStyledContent();

        /*
         * Writes styled content data into wanted file.
        */
        void fileOutput(string fileName);

        /*
        * General list printing
        */
        void printList(int listWidth, string *listItems, int listCount);

        /*
         * (unnecessary functions)
        */
        void yaz(int listWidth, string *listItems, int listCount);
        void yaz();
        string ara(string str);
};

#endif