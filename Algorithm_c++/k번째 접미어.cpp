#include <iostream>
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
        int n;
        string str;
        cin>>n >>str;
        vector<string>v;
        string tmp = "";
        for(int i=str.size()-1; i>=0; i--) {
            tmp = str[i] +tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        if(v.size() < n-1) {
            cout<<"#"<<test_case<<" " <<"none"<<"\n";
        } else {
            cout<<"#"<<test_case<<" " <<v[n-1]<<"\n";
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
