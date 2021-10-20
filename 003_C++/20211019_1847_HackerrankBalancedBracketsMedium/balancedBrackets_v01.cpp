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

bool checkBracketsOrder(int curve, int curly, int square){
    return (curve>=0) && (curly >= 0) && (square >= 0);
}
string isBalanced(string s) {
    int curve(0), curly(0), square(0);
    cout << "testing string : " << s << endl;
    // It contains no unmatched brackets.
    // if size odd --> unbalanced NO
    if(s.size() == 0) return "YES";
    if(s.size() % 2 != 0){
        cout << "substring : " << s << "--> NO" << endl;
        return "NO";
    }
    // checked all types are matched, otherwise --> unbalanced NO
    for(auto c: s){
        if(c == '(') curve++;
        if(c == ')') curve--;
        if(c == '{') curly++;
        if(c == '}') curly--;
        if(c == '[') square++;
        if(c == ']') square--;
    }
    // cout << "curve, curly, square = " << curve << curly << square << endl;
    if((abs(curve) + abs(curly) + abs(square)) != 0){
        cout << "substring : " << s << "--> NO" << endl;
        return "NO";
    }
    
    //The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.
 
    // pick next matched pair of brackets
    size_t start = 0;
    size_t end = 0;
    while(end < s.size()){
        char c = s[end];
        if(c == '(') curve++;
        if(c == ')') curve--;
        if(c == '{') curly++;
        if(c == '}') curly--;
        if(c == '[') square++;
        if(c == ']') square--;
        if (!checkBracketsOrder(curve,curly,square)) return "NO";
        if((abs(curve) + abs(curly) + abs(square)) == 0) break;
        end++;
    }
    
    cout << "start,end" << start << "," << end << endl;
    // if not found matched pair --> "NO"
    if((abs(curve) + abs(curly) + abs(square)) != 0) return "NO";
    
    // define substring s1 and substring s2
    // And go check them separately
    //goes from start + 1 to end -1
    //start = 0, end = 5
    string s1 = s.substr(start +1, end - 1);
    if(isBalanced(s1) == "NO") return "NO";
    
    if(end + 1 < s.size())  {
        string s2 = s.substr(end +1);
        if(isBalanced(s2) == "NO") return "NO";
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
