
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        string a,b;
        cin>>a>>b;
        vector<vector<int>>v (1001, vector<int>(1001, 0));

        if(a.size() > b.size()) {
            swap(a,b);
        }
        for(int i=1; i<=a.size(); i++) {
            for(int j=1; j<=b.size(); j++) {
                if(a[i-1] == b[j-1]) {
                    v[i][j] = v[i-1][j-1] +1;
                } else {
                    v[i][j] = max(v[i-1][j], v[i][j-1]);
                }
            }
        }
        cout<<"#"<<test_case<<" " << v[a.size()][b.size()]<<"\n";
    }
    return 0;
}