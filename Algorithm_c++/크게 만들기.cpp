#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

#define ll long long
using namespace std;

int N,K;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;

    string s;
    string tmp;
    string ans;
    cin>>s;

    stack<int> stk;
    int i;

    for(i=0; i<s.size(); i++) {
        if(K <= 0) {
            break;
        }
        while(1) {
            if(!stk.empty() && stk.top() < s[i]-'0' && K>0) {
                stk.pop();
                K--;
            } else {
                break;
            }
        }
        stk.push(s[i]-'0');
    }

    while(K>0) {
        stk.pop();
        K--;
    }

    while(!stk.empty()) {
        tmp += to_string(stk.top());
        stk.pop();
    }

    for(int j=tmp.size()-1; j>=0; j--) {
        ans += tmp[j];
    }
    for(int j=i; j<s.size(); j++) {
        ans+=s[j];
    }
    cout<<ans;
}
