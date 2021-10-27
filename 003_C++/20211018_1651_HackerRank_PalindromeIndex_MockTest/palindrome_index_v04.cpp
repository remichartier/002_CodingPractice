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
#define IS_PALINDROME -1

int is_palindrome(string s){
    int start(0), end(s.size()-1);
    while(start <= end){
        if(s[start] != s[end]){
            //cout << "return " << start << endl;
            return start;
        }
        start++;
        end--;
    }    
    //cout << "return " << IS_PALINDROME << endl;
    return IS_PALINDROME;
}

int palindromeIndex(string s) {
    string s1;
    int start;
    if(s.size() == 0) return -1;
    start = is_palindrome(s);
    if(start == IS_PALINDROME){
        return -1;
    }
    // otherwise, try to test by removing character pos start, or 
    // character position (s.size() -1 - start)
    s1 = s;
    //cout << "s1 " << s1 << endl;
    s1.erase(s1.begin() + start);
    //cout << "check palindrome " << s1 << endl;
    if(is_palindrome(s1) == IS_PALINDROME){
        return start;
    }
    s1 = s;
    //cout << "check palindrome " << s1 << endl;
    s1.erase(s1.begin() + s.size() -1 - start);
    //cout << "check palindrome " << s1 << endl;
    if(is_palindrome(s1) == IS_PALINDROME){
        return s.size() -1 - start;
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
