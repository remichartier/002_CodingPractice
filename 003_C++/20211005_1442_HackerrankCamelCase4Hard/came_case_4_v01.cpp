#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define OPERATION 0
#define TYPE 2
#define NAME_OFFSET 4
#define SPLIT 'S'
#define COMBINE 'C'
#define METHOD 'M'
#define CLASS 'C'
#define VARIABLE 'V'

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string line, output("");
    bool flag_space = false;
    while(getline(cin,line)){
        output = "";
        if(line[OPERATION] == SPLIT){
            if(line[TYPE] == METHOD){
                // will have to remove the ending ()
                line.pop_back();
                line.pop_back();
                cout << "method line : " << line << endl;
            }             
            for(size_t i=NAME_OFFSET; i<line.size();i++){
                if(isupper(line[i])){
                    if(i != NAME_OFFSET){
                        output.push_back(' ');
                    }
                    output.push_back(tolower(line[i]));
                }
                else{
                    output.push_back(line[i]);    
                }
            }
        }
        if(line[OPERATION] == COMBINE){
            // class --> 1st Char uppercase
            // method --> ending with ()
            // Space --> skip and next char should be Uppercase
            for(size_t i=NAME_OFFSET; i<line.size();i++){
                if((i == NAME_OFFSET) && (line[TYPE] == CLASS)){
                    output.push_back(toupper(line[i]));
                }
                else if(line[i] == ' '){
                    flag_space = true;
                }
                else if(line[i] == '\r'){
                }
                else{
                    if(flag_space){
                        output.push_back(toupper(line[i]));
                        flag_space = false;
                    }
                    else{
                        output.push_back(line[i]);
                    }
                }
            }
            if(line[TYPE] == METHOD){
                output.append("()");
            }
        }
        cout << output << endl;
    }
    return 0;
}
