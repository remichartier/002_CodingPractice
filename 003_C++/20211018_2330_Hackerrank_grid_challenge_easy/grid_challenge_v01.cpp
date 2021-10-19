#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gridChallenge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY grid as parameter.
 */

string gridChallenge(vector<string> grid) {
     string s1,s2;
    int nb_col = grid[0].size();
    int nb_row = grid.size();
    cout << "nb_row = " << nb_row << ", nb_col = " << nb_col << endl;
    
    for(auto& s: grid){
        //cout << "String to sort : " << s << endl;
        sort(s.begin(),s.end());        
        cout << "String sorted : " << s << endl;
    }
    // strings sorted, now need to check if columns sorted ....
    for(size_t i=0; i < nb_col; ++i){
        s1 = "";
        for(size_t r=0; r < nb_row; ++r){
            s1 += grid[r][i];
        }
        
        s2 = s1;
        sort(s2.begin(),s2.end());
        cout << "overall : " << s1 << " compared to : " << s2 << endl;
        if(s2.compare(s1) != 0){
            cout << "Column " << i << " : " << s1 << " not sorted --> return NO" << endl;
            return "NO";
        }
        else{
            cout << "Column " << i << " : " << s1 << " SORTED" << endl;
        }
    }
    cout << "return YES" << endl;
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);

            grid[i] = grid_item;
        }

        string result = gridChallenge(grid);

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
