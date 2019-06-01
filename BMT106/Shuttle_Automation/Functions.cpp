#include "Functions.h"

void ltrim(string &s){
    size_t p = s.find_first_not_of(" \t");
    s.erase(0, p);
}

void trim(string &s){
    size_t p = s.find_first_not_of(" \t");
    s.erase(0, p);

    p = s.find_last_not_of(" \t");
    if (string::npos != p)
    s.erase(p+1);
}

int fastToInt(const char *p){
    //http://tinodidriksen.com/uploads/code/cpp/speed-string-to-int.cpp
    int x = 0;
    bool neg = false;
    if (*p == '-') {
        neg = true;
        ++p;
    }
    while (*p >= '0' && *p <= '9') {
        x = (x*10) + (*p - '0');
        ++p;
    }
    if (neg) {
        x = -x;
    }
    return x;
}

string getTokenByDelimiter(string input, char delimiter, int id){
    std::istringstream ss(input);
    std::string token;
    int a=0;
    while(getline(ss, token, delimiter)){
        if(id==a){
            return token;
        }

        a++;
    }
    return "null";
}

void clearUntilLimiter(string &input, string delimiter, int id){
    size_t pos;
    if(id == 0){
        pos = input.find_first_of(delimiter);
        input.erase(pos, input.length());
    }else{
        int a=0;
        while((pos != string::npos) && (a != id)){
            pos = input.find(delimiter);
            input.erase(0, pos+1);
            a++;
        }
    }
}