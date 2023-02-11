#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
bool cmp(string a, string b) {
    int sz = min(a.size(), b.size());
    for(int i=0; i<sz; i++) {
        if(a[i] < b[i]) {
            return true;
        } else if (a[i] > b[i]) {
            return false;
        }
    }
    if(a.size() < b.size()) {
        return true;
    }
    return false;
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        string str;
        cin>>n >>str;
        vector<string>v;
        for(int i=1; i<=str.size(); i++) {
            for(int j=0; j<=str.size()-i; j++) {
                v.push_back(str.substr(j,i));
            }
        }
        sort(v.begin(), v.end(), cmp);
        v.erase(unique(v.begin(),v.end()), v.end());

        if(v.size() < n-1) {
            cout<<"#"<<test_case<<" "<<"none"<<"\n";
        } else {
            cout<<"#"<<test_case<<" "<<v[n-1]<<"\n";
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}