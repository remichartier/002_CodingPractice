#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/* A palindrome is a word, number, phrase, or other sequence of characters
    which reads the same backward as forward, such as madam or racecar
*/


/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

bool is_palindrome(string s){
    int start(0), end(s.size()-1);
    while(start <= end){
        if(s[start] != s[end]){
            return false;
        }
        start++;
        end--;
    }    
    return true;
}

int palindromeIndex(string s) {
    string s1;
    if(is_palindrome(s)){
        return -1;
    }
    for(size_t i=0; i<s.size(); ++i){
        s1 = s;
        s1.erase(i,i);
        if(is_palindrome(s1)){
            return i;
        }
    }
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
