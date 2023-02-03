#include<iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n,m;
        cin>>n >> m;
        unordered_map<string,bool> hash;
        int ans = 0;
        for(int i=0; i<n; i++) {
            string a;
            cin>>string;
            hash.insert({a, true});
        }
        for(int i=0; i<m; i++) {
            string b;
            cin>>b;
            if(hash.find(b) != hash.end()) {
                ans +=1;
            }
        }
        cout<<"#"<<test_case<<" "<< ans<<"\n";
    }
    return 0;
}