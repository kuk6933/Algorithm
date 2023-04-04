#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<int> vec;

int main() {
    cin>>n;
    vector<int> v;
    int oper[4];
    int mn= 1000000005;
    int mx = -1000000005;
    for(int i=0; i<n; i++) {
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=0; i<4; i++) {
        cin>>oper[i];
    }
    for(int i=0; i<4; i++) {
        for(int j=0; j<oper[i]; j++) {
            vec.push_back(i);
        }
    };
    sort(vec.begin(), vec.end());
    do {
        stack<int> stk;
        for(int i=v.size()-1; i >=0; i--) {
            stk.push(v[i]);
        }
        for(int i=0; i<vec.size(); i++) {
            int a = stk.top(); stk.pop();
            int b = stk.top(); stk.pop();
            int ans = 0;
            if(vec[i] == 0) {
                ans = a + b;
            } else if (vec[i] == 1) {
                ans = a - b;
            } else if (vec[i] == 2) {
                ans = a * b;
            } else {
                ans = a / b;
            }
            stk.push(ans);
        }
        int result = stk.top(); stk.pop();
        mx = max(result, mx);
        mn = min(result, mn);
    } while(next_permutation(vec.begin(), vec.end()));

    cout<<mx<<"\n"<<mn;

}