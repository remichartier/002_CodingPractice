#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// NOTE : HAVE NOT FOUND YET THE RIGHT ALGORITHM ...

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */
/* algo 
   ====
   count = 0
   for each element in q : 
        compare value and (position+1) :
        pass if value <= (position+1)
        if value > (position+1) + 2 :
            print "Too chaotic"
        else
            count += value - (position+1)
            
   print count
   
   test with [1, 2, 3, 5, 4, 6, 7, 8]
   count = 1
   test with [4, 1, 2, 3]
   Too Chaotic
   
   1 2 5 3 7 8 6 4
   detect 5 --> move it back
   1 2 3 5 7 8 6 4 --> 1
   1 2 3 7 5 8 6 4 --> 2
   detect 7 --> move it back
   1 2 3 5 7 8 6 4 --> 3
   1 2 3 5 8 7 6 4 --> 4
   1 2 3 5 8 6 7 4 --> 5
   detect 5
   1 2 3 8 5 6 7 4 --> 6
   
   use bubble ?
   1 2 5 3 7 8 6 4
   1 2 3 5 7 8 6 4 --> 1
   1 2 3 5 7 6 8 4 --> 1
   1 2 3 5 6 7 8 4 --> 1
   and 4 to move back 4 at its position ....
   
*/

void minimumBribes(vector<int> q) {
    int count(0);
    for(size_t i=0; i < q.size(); ++i){
        if(q[i] <= (i + 1)){
            continue;
        }
        if(q[i] > ((i+1) +2)){
            cout << "Too chaotic" << endl;
            return;
        }
        else{
            count += (q[i] - (i +1));
        }
    }
    cout << count << endl;
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split(rtrim(q_temp_temp));

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
