#include "FileDb.h"
#include "Functions.h"

// <CustomFilters>
CustomFilters::CustomFilters(){
    this->mode = -2;
}

CustomFilters::~CustomFilters(){
    this->sectionInput = "NULL";
    this->sectionOutput = "NULL";
    //cout<<"Filter Destruct: "<<this->mode<<endl;
    
    //delete [] this->bindKey;
    //delete [] this->bindVal;
    //delete [] this->extraBindVal;
    //delete [] this->extraBindVal2;
    
}

void CustomFilters::initFilter(string sectionInputl, int sectionCountl, int lineCountl, int currentSectionIdl){
    this->sectionInput = sectionInputl;
    this->sectionCount = sectionCountl;
    this->lineCount = lineCountl;
    this->currentSectionId = currentSectionIdl;
}

string CustomFilters::getOutput(){
    return this->sectionOutput;
}

void CustomFilters::stringTrade(){
        switch(this->mode){
            case -2:
                this->sectionOutput = this->sectionInput;
            break;
            case -1:
                {
                    if(this->keySize == this->valSize){ 
                        for(int i=0; i<this->keySize; i++){
                            if(this->sectionInput.compare(this->bindKey[i]) == 0){
                                this->sectionOutput = this->bindVal[i];
                            }
                        } 
                    }else if((this->valSize == 1) and (this->keySize > this->valSize)){
                        for(int i=0; i<this->keySize; i++){
                            this->sectionOutput = this->bindVal[0]; 
                        }
                    }
                }
            break;
            case 0:
                    this->sectionOutput = this->extraBindVal[stoi(bindVal[this->lineCount])]; 
            break;
            case 1:
                {
                    this->ss<< this->preSuffix[0] << this->extraBindVal[stoi(bindVal[this->lineCount])] << this->preSuffix[1] << this->extraBindVal2[this->lineCount] << this->preSuffix[2];                
                    this->sectionOutput =  ss.str();
                }
            break;
            case 2:
                {   
                    string val = this->extraBindVal[stoi(bindVal[this->lineCount])];
                    //clearUntilLimiter(val, ",", stoi(this->sectionInput));
                    //this->sectionOutput = val;
                    this->sectionOutput = getTokenByDelimiter(val, ',', fastToInt(this->sectionInput.c_str())); //old
                } 
            break;
            case 3:
                    this->sectionOutput = this->bindVal[stoi(this->sectionInput)];
            break;
            case 4:
                    this->sectionOutput = this->bindVal[this->lineCount];
            break;
    }
}

void CustomFilters::runFilter(){
    if((this->sectionId == this->currentSectionId) and (!this->sectionInput.empty())){
        ss.str("");
        stringTrade();
    }else{
        this->sectionOutput = this->sectionInput;
    }
}

void CustomFilters::setBinding(string *key, int keyS, string *val, int valS){
    this->bindKey = key;
    this->keySize = keyS;
    this->valSize = valS;
    this->bindVal = val;
}

// </CustomFilters>

// <AddListSearch>
void AddListSearch::ekle(string line){
    ofstream writeFile(this->fileName, ios::app | ios::binary);
    writeFile<<line<<endl;
    writeFile.close();
}

bool AddListSearch::isFileExist(){
    ifstream fileRead(this->fileName.c_str(), ios::binary);
    if (fileRead.fail()) {
        fileRead.close();
        return false;
    }
    fileRead.close();
    fileRead.clear();
    return true;
}

void AddListSearch::listele(string *list){
    if(this->isFileExist() == true){
        ifstream readFile(this->fileName.c_str(), ios::binary);
        int lineCount = 0;
        for(string readedLine; getline(readFile, readedLine);) {
            list[lineCount] = readedLine;
            lineCount++; 
        }
        this->dataCount = lineCount;
        readFile.close();
        readFile.clear();
        //readFile.seekg(0, readFile.beg);
    }
}

string AddListSearch::ara(string str){
    return str;
}

// </AddListSearch>

// <DeleteUpdate>
void DeleteUpdate::sil(string line){
    ifstream readFile(this->fileName.c_str(), ios::binary);
    ofstream writeFile(this->tempFileName.c_str(), ios::binary);
    for(string readedLine; getline(readFile, readedLine);) {
        if(line.compare(readedLine) != 0){
            writeFile<<readedLine;
        }
    }
    writeFile.close();
    readFile.close();

    remove(this->fileName.c_str());
    rename(this->tempFileName.c_str(), this->fileName.c_str());
}

void DeleteUpdate::sil(int line_int){
    ifstream readFile(this->fileName.c_str(), ios::binary);
    ofstream writeFile(this->tempFileName.c_str(), ios::binary);

    int lineCount = 0;
    for(string readedLine; getline(readFile, readedLine);) {
        if(lineCount == line_int){
            
        }else{
            writeFile<<readedLine<<endl;
        }
        lineCount++;
    }
    readFile.close();
    writeFile.close();
    
    remove(this->fileName.c_str());
    rename(this->tempFileName.c_str(), this->fileName.c_str());
}

void DeleteUpdate::guncelle(string old_line, string new_line){
    ifstream readFile(this->fileName.c_str(), ios::binary);
    ofstream writeFile(this->fileName.c_str(), ios::binary);

    for(string readedLine; getline(readFile, readedLine);) {
        if(old_line.compare(readedLine) == 0){
            writeFile<<new_line<<endl;
        }else{
            writeFile<<readedLine<<endl;
        }
    }
    readFile.close();
    writeFile.close();
    
    remove(this->fileName.c_str());
    rename(this->tempFileName.c_str(), this->fileName.c_str());
}

void DeleteUpdate::guncelle(int old_line_int, string new_line){
    ifstream readFile(this->fileName.c_str(), ios::binary);
    ofstream writeFile(this->tempFileName.c_str(), ios::binary);

    int lineCount = 0;
    for(string readedLine; getline(readFile, readedLine);) {
        if(lineCount == old_line_int){
            writeFile<<new_line<<endl;
        }else{
            writeFile<<readedLine<<endl;
        }
        lineCount++;
    }
    readFile.close();
    writeFile.close();
    
    remove(this->fileName.c_str());
    rename(this->tempFileName.c_str(), this->fileName.c_str());
}
// </DeleteUpdate>

// <FileDb>
FileDb::FileDb(string fileNamel, string *headlinesl, int *lengthl, int sizel){
    this->fileName = fileNamel;
    this->headlines = headlinesl;
    this->sectionLength = lengthl;
    this->sectionCount = sizel;
    AddListSearch::fileName = fileNamel; 
    DeleteUpdate::fileName = fileNamel;
    this->cacheStatics();
    this->cacheFileContent();
    this->cacheStyledContent();
}

FileDb::~FileDb(){
    //cout<<"FileDb Destruct: "<<this->fileName<<endl;
}

void FileDb::cacheFileContent(){
    AddListSearch::listele(this->cachedFileContent);
}

void FileDb::deleteLine(string line){
    DeleteUpdate::sil(line);
}

void FileDb::deleteLine(int line_int){
    DeleteUpdate::sil(line_int);
}

void FileDb::modifyLine(string old_line, string new_line){
    DeleteUpdate::guncelle(old_line, new_line);
}

void FileDb::modifyLine(int old_line_int, string new_line){
    DeleteUpdate::guncelle(old_line_int, new_line);
}

string FileDb::dbOutput(string *entry){
    stringstream line;
    for(int i=0; i<this->sectionCount; i++){
        if(i==0){
            line<< setw(sectionLength[0]) << "#";
        }else
            line<< setw(this->sectionLength[i]) << entry[i];
    }
    delete [] entry;
    return line.str();
}

void FileDb::addEntry(string *entry){
    AddListSearch::ekle(this->dbOutput(entry));
}

void FileDb::addWithInput(string *questions, string *descriptions, int mode){
    string *entry = new string[this->sectionCount]();
    entry[0] = "#"; // first section for id
    string lineId;

    /*
     * Update Mode: if the mode variable equal 0 loop starts from 0 and asks user for id.Thats the update mode
     * Add Mode: if the mode variable equal 1 loop starts from 1 and dont asks user id.Id given by automatically
    */
    for(int i=mode; i<this->sectionCount; i++){ 
        //system(CLEAR);
            if(questions[i].compare("$") == 0){
                entry[i] = descriptions[i];
            }else{
                cout<<descriptions[i]; // print description for section
                cout<<questions[i]; // print question for section

                if(i==0){
                    cin>>lineId;
                }else{
                    //getline(std::cin, entry[i]);
                    cin>>entry[i];
                    if(static_cast<int>(entry[i].length()) > this->sectionLength[i]) // Data overflow protection.If input length bigger than section length dont loops and ask again.
                        i--;
                }  
            }
    }
    
    if(mode == 1) //Add Mode 
        this->addEntry(entry);
    else if(mode == 0) //Update Mode
        this->modifyLine(fastToInt(lineId.c_str()), this->dbOutput(entry));
}

void FileDb::deleteWithInput(string question){
    int lineId;
    cout<<this->styledContent;
    cout<<question;
    cin>>lineId;
    this->deleteLine(lineId);
}

string FileDb::getDataByPos(int line, int section){
    size_t a=0;
    string value;
    for(int i=0; i<this->sectionCount; i++){
        value = this->cachedFileContent[line].substr(a, static_cast<unsigned int>(this->sectionLength[i]));
        a += static_cast<unsigned int>(this->sectionLength[i]);
        if(section == i){
            return value;
        }
    }
    return "NULL";
}

string* FileDb::getDataByLine(int line){
    string *returnLine = new string[this->sectionCount]();
    int a=0;
    string value;
    for(int i=0; i<this->sectionCount; i++){
        value = this->cachedFileContent[line].substr(a, static_cast<unsigned int>(this->sectionLength[i]));
        a += static_cast<unsigned int>(this->sectionLength[i]);
        returnLine[i] = value;
    }
    return returnLine;
}

string* FileDb::getDataBySection(int section){
    string *returnLine = new string[this->getLineCount()]();
    string value;
    int a=0, b, i=0;
    for(b=0; b<section; b++){
        a += this->sectionLength[b];
    }
    while(i < this->getLineCount()){
        value = this->cachedFileContent[i].substr(a, this->sectionLength[section]); 
        
        ltrim(value); 
        returnLine[i] = value;
        i++;
    }
    return returnLine;
}

void FileDb::getDataBySectionStatic(int section, string* test){
    string value;
    int a=0, b, i=0;
    for(b=0; b<section; b++){
            a += this->sectionLength[b];
        }
    while(i < this->getLineCount()){
        value = this->cachedFileContent[i].substr(a, this->sectionLength[section]);
        
        ltrim(value); 
        test[i] = value;
        i++;
    }
}

string* FileDb::getFreqBySectionId(int count, int secId){
    string *returnLine = new string[count]();
    int *returnC = new int[count]();
    for(int i=0; i<count; i++){
        returnC[i] = 0;
    }
    int i=0;
    while(i < this->getLineCount()){
        int a=0;
        string value;
        for(int b=0; b<this->sectionCount; b++){
            value = this->cachedFileContent[i].substr(a, this->sectionLength[b]);

            a += this->sectionLength[b];
            if(b == secId){
               
                ltrim(value);    
                //returnLine[i] = value;
                for(int j=0; j<count; j++){
                    if(fastToInt(value.c_str()) == j){
                        returnC[j]++;
                    }
                }
            }
        }
        i++;
    }
    stringstream ss;
    for(int j=0; j<count; j++){
        ss.str("");
        ss<<returnC[j];
        returnLine[j] = ss.str();
    }
    delete [] returnC;
    return returnLine;
}

void FileDb::cacheStatics(){
    stringstream headlinesSS;
    stringstream seperatorSS;
    for(int i=0; i<sectionCount; i++){
        if(i==0){
            headlinesSS<<'|';
            seperatorSS<<'+';
        }
            
        headlinesSS << setw(this->sectionLength[i]) << left << this->headlines[i] << '|';
        seperatorSS << setw(this->sectionLength[i]+1) << setfill('-') << '+';
    }
    this->headlinesSTR = headlinesSS.str();
    this->seperatorSTR = seperatorSS.str();
}

void FileDb::cacheStyledContent(){
    outputSTR.str(""); // clear stream
    string section; // section value
    int startP=0; // substr begining value
    outputSTR<<this->seperatorSTR<<endl<<this->headlinesSTR<<endl<<this->seperatorSTR<<endl; //Add headlines and seperator to the main string
    for(int lineC=0; lineC<this->getLineCount(); lineC++){ //every line
        //ID Section
        startP = sectionLength[0]; //set beginning point after id section
        this->outputSTR<<'|'<< setw(sectionLength[0]) << left <<lineC<<'|';

        for(int sec=1; sec<this->sectionCount; sec++){ // every section
            section = this->cachedFileContent[lineC].substr(startP, this->sectionLength[sec]); //parse section
            startP += this->sectionLength[sec]; // add starting point to current section length
            ltrim(section);
            
            for(int a=0; a<this->filterCount; a++){ //apply filters
                    this->filter[a].initFilter(section, this->sectionCount, lineC, sec);
                    this->filter[a].runFilter();
                    section = this->filter[a].getOutput();
            }
            
            this->outputSTR<<setw(sectionLength[sec])<<left<<section<<'|'; //set the weight by the sectionLength array and add section value
        }
        this->outputSTR<<endl<<this->seperatorSTR<<endl; // add seperator into every line
    }
    this->styledContent = this->outputSTR.str();
}

void FileDb::printStyledContent(){
    //this->updateCaches();
    //this->cacheFileContent();
    //this->cacheStyledContent();
    cout<<this->styledContent;
}

void FileDb::updateCaches(){
    this->cacheFileContent();
    this->cacheStyledContent();
}

string FileDb::getStyledContent(){
    return this->styledContent;
}

void FileDb::fileOutput(string fileNamel){
    ofstream writeFile;
    writeFile.open(fileNamel, ofstream::out | ios::binary);
    writeFile<<this->styledContent;
    writeFile.close();
}
/**
bool FileDb::isFileExist(){
    return AddListSearch::isFileExist();
}
**/
int FileDb::getLineCount(){
    return this->dataCount;
    //return AddListSearch::dataCount;
}

void FileDb::printList(int listWidth, string *listItems, int listCount){
    //system(CLEAR);
    stringstream seperator;
    stringstream output;

    //Menu Seperator
    seperator<< "+" << setw(listWidth) << setfill('-')<< "-" << "+" <<endl;
    output<<seperator.str();
    if(listItems[0].compare("#") != 0){
        //Menu Title
        output<< "|";
        for(size_t i=0; i<(listWidth-listItems[0].length())/2; i++){
            output<<" ";
        }
        output<< listItems[0];
        for(size_t i=0; i<(listWidth-listItems[0].length())/2; i++){
            output<<" ";
        }
        output<<"|" <<endl<<seperator.str();
    }
    for(int i=1; i<=listCount; i++){
        output<<"|";
        output<< i<< "-" << listItems[i];
        for(int a=listItems[i].length()+2; a < listWidth; a++){
            output<<" ";
        }
        output<<"|"<<endl;
        output<<seperator.str();
    }
    cout<<output.str();
}

void FileDb::yaz(int listWidth, string *listItems, int listCount){
    this->printList(listWidth, listItems, listCount);
}

void FileDb::yaz(){
    this->printStyledContent();
}

string FileDb::ara(string str){
    stringstream ss(this->styledContent);
    string outStr;
    for(string readedLine; getline(ss, readedLine);){
        if(readedLine.find(str) != string::npos)
            outStr += this->seperatorSTR+"\n"+readedLine+"\n"+this->seperatorSTR+"\n";

    }   
    return outStr;
}

// </FileDb>