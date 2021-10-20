#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
/*
    Need solutions with stacks ...

*/

// if opening bracket fill vstack 
// if closing bracket,pop vstack only if top of stack contains
// opposite bracket. Otherwise return NO
// loop accross s characters until reaches end.
// test stack size at the end ...

bool is_openingBracket(char c){
    return (c == '(') || (c == '{')  || (c == '['); 
}
bool is_pairMatched(char top, char c){
    bool ret = (top == '(') && (c == ')');
    ret = ret || ((top == '{') && (c == '}'));
    ret = ret || ((top == '[') && (c == ']'));
    return ret;
}

string isBalanced(string s) {
    vector<char> vect;
    if((s.size() < 2) || (s.size() %2 == 1)) return "NO";
    for(size_t i = 0; i < s.size(); ++i){
        if(is_openingBracket(s[i])) {
            vect.push_back(s[i]);
        }
        else{
            if(vect.empty()){
                return "NO";
            }
            char top = vect.back();
            if(is_pairMatched(top,s[i])){
                vect.pop_back();
            }
            else{
                return "NO";
            }
        }
    }
    if(vect.size()){
        return "NO";
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

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
