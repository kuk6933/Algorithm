#include<iostream>
#include <vector>
using namespace std;

int ans;
vector<int> Fail(string p) {
    int pSize = p.size();
    vector<int> fail(pSize, 0);
    int j=0;
    for(int i=1; i<pSize; i++) {
        while( j > 0 && p[i] != p[j]) {
            j = fail[j-1];
        }
        if(p[i] == p[j]) {
            fail[i] = ++j;
        }
    }
    return fail;
}

void KMP(string s, string p) {
    vector<int> failure = Fail(p);
    int sSize = s.size();
    int pSize = p.size();
    int j =0;
    for (int i=0; i< sSize; i++) {
        while(j>0 && s[i] != p[j]) {
            j = failure[j-1];
        }
        if(s[i] == p[j]) {
            if(j==pSize-1) {
                ans++;
                j = failure[j];
            } else {
                j++;
            }
        }
    }
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        ans = 0;
        string str, pattern;
        cin>>str;
        cin>>pattern;
        KMP(str, pattern);
        cout<<"#"<<test_case<<" "<<ans<<"\n";
    }
    return 0;
}