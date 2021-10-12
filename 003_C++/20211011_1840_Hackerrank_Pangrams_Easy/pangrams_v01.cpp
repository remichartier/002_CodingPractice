#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    vector<bool> letters(26,false);
    int sum(0);
    int index;
    int offset = (int)'a';
    for(size_t i=0; i<s.size(); i++){
        if(s[i] != ' '){
            index = (int)tolower(s.at(i)) - offset;
            cout << "index" << index << endl;
            if(letters[index] == false){
                letters[index] = true;
                sum++;
            }
        }
    }
    
    if(sum != 26){
        return "not pangram";
    }
    
    return "pangram";
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
