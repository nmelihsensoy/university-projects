#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    string type = s.substr(8, 9);
    string clock = s.substr(2, 6);
    int hours = stoi(s.substr(0, 2));

    if(type.compare("PM") == 0 && hours != 12){
        hours += 12;
    }else if(type.compare("AM") == 0 && hours == 12){
        hours = 0;
    }

    stringstream ss;
    ss<<std::setfill('0') << std::setw(2) << hours << clock;


    return ss.str();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
