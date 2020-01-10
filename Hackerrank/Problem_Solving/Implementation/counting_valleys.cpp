#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    bool valley = false;
    int valley_count = 0, level = 0;
    for(int i=0; i<n; i++){
        
        if(level == 0) valley = false;    

        if(s[i] == 'U') level++;
        else level--;

        if(!valley && level<0){
            valley = true;
            valley_count++;
        }
    }
    return valley_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
