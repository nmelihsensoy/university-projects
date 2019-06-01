#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <sstream>
using namespace std;

//Cross platform clear solution
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void ltrim(string &s);
void trim(string &s);
int fastToInt(const char *p); //http://tinodidriksen.com/uploads/code/cpp/speed-string-to-int.cpp
string getTokenByDelimiter(string input, char delimiter, int id=0);
void clearUntilLimiter(string &input, string delimiter, int id=0);
#endif