#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    std::string res = s.substr(0, 8);
    if (s[s.size() - 2] == 'P') {
        res[0] += 1;
        res[1] += 2;
    }
    if (s[0] == '1' && s[1] == '2') {
        if (s[s.size() - 2] == 'P') {
            res[0] = '1';
            res[1] = '2';
        } else {
            res[0] = res[1] = '0';
        }     
    }
   
    return res;
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
