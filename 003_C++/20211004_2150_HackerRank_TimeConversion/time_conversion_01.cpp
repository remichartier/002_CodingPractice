#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
     /*
    Sample Input 07:05:45PM
    Sample Output 19:05:45
    */
    // position A or P from AM/PM : 8
    string s_out = s.substr(0,s.size() -2);
    // cout << "s_out = " << s_out << endl;
    int hour = stoi(s.substr(0,2));
    // cout << "hour = " << hour << endl;
    if((s[8] == 'A') && (hour == 12)){
        s_out.replace(0,2,"00");
    }
    if((s[8] == 'P') && (hour != 12)){
        hour += 12;
        s_out.replace(0,2,to_string(hour));
    }
    // reconstruct hour part of s_out
    return s_out;
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
