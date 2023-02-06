#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    } else {
        return a < b;
    }
}
int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin>>n;
        vector<string> v;
        for(int i=0; i<n; i++) {
            string str;
            cin>> str;
            v.push_back(str);
        }
        sort(v.begin(), v.end(), cmp);
        v.erase(unique(v.begin(),v.end()), v.end());

        cout<<"#"<<test_case <<"\n";
        for(int i=0; i<v.size(); i++) {
            cout<< v[i]<<"\n";
        }
    }
    return 0;
}