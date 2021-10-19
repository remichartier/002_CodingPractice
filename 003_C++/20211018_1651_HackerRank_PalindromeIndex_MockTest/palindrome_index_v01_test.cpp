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
    while(start < end){
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
        // cout << "1st check palyndrome succeeded --> return -1" << endl;
        return -1;
    }
    // cout << "1st check palyndrome failed" << endl;
    for(size_t i=0; i<s.size(); ++i){
        s1 = s;
        s1.erase(i,1);
        if(is_palindrome(s1)){
            // cout << s1 << " detected as palyndrome --> return " << i << endl;
            return i;
        }
    }
    // cout << "no palyndrome found even if removing any of the characters --> return -1" << endl;
    return -1;
}

int main()
{

    vector<string> s({"aaa", "aba", "baaa", "a", "ba", "abc", "racecar", "dad", "mama",\
    "bcbc", "aaab", "baa", "madam"});
    // vector<string> s({"baaa"});
    vector<int> expected_result({-1,-1,0,-1,0,-1,-1,-1,0,0,3,0,-1});

    for(size_t i=0; i < min(s.size(),expected_result.size()); ++i){
        cout << "palindromeIndex(" << s[i] << ") = " << palindromeIndex(s[i]) <<\
         " expecting result : " << expected_result[i] << endl;
    }
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

// g++ -o main.exe  palindrome_index_v01_test.cpp 

/* to correct : 
./main.exe 
palindromeIndex(aaa) = -1 expecting result : -1
palindromeIndex(aba) = -1 expecting result : -1
palindromeIndex(baaa) = 0 expecting result : 0
palindromeIndex(a) = -1 expecting result : -1
palindromeIndex(ba) = 0 expecting result : 0
palindromeIndex(abc) = -1 expecting result : -1
palindromeIndex(racecar) = -1 expecting result : -1
palindromeIndex(dad) = -1 expecting result : -1
palindromeIndex(mama) = 0 expecting result : 0
palindromeIndex(bcbc) = 0 expecting result : 0
palindromeIndex(aaab) = 3 expecting result : 3
palindromeIndex(baa) = 0 expecting result : 0
palindromeIndex(madam) = -1 expecting result : -1
*/