#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
#define APPEND 1 //append - Append string  to the end of .
#define DELETE 2 //delete - Delete the last  characters of .
#define PRINT 3  //print - Print the  character of .
#define UNDO 4   //undo - Undo the last (not previously undone) operation of type  or , reverting  to the state it was in prior to that operation.

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s, input;
    vector<string> previous;
    int Q, i(0), k;
    
    // read number of inputs to read
    cin >> input;
    //cout << "Input : " << input << endl;

    Q = stoi(input);
    //cout << "number of lines Q : " << Q << endl;
    while(i<Q){
        //cin >> input;
        getline(cin,input);
        //cout << "Line read : " << input << endl;
        if(input.size() == 0) continue;
        //cout << "Number read : " << int(input[0]) - int('0') << endl;
        switch(int(input[0]) - int('0')){
            case APPEND:
                if(input.size() > 2){
                    previous.push_back(s);
                    s += input.substr(2);
                    //cout << "string s : " << s << ", previous : " << previous.back() << endl;
                }
                break;
            case DELETE:
                if(input.size() > 2){
                    k = stoi(input.substr(2));
                    //cout << "DELETE k = " << k << endl;
                    previous.push_back(s);
                    s.erase(s.end() - k, s.end());
                    //cout << "string s : " << s << ", previous : " << previous.back() << endl;
                }
                break;
            case PRINT:
                if(input.size() > 2){
                    k = stoi(input.substr(2));
                    //cout << "DELETE k = " << k << endl;
                    //cout << "Print character " << k << endl;
                    if( (k -1) < s.size()){
                        cout << s[k-1] << endl;    
                    }
                }
                break;
            case UNDO:
                if(previous.size() != 0){
                    s = previous.back();
                    previous.pop_back();
                    //cout << "string s after UNDO : " << s << endl;
                }
                else{ 
                    //cout << "previous string is empty" << endl;
                }
                break;
        }
        i++;
    }   
    
    
    return 0;
}
