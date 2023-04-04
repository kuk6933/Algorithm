#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    int dp[16];
    for(int i=0; i<16; i++) {
        dp[i]= 0;
    }

    for(int i=0; i<n; i++) {
        int t,m;
        cin>>t>>m;
        v.push_back(make_pair(t,m));
    }

    int mx = 0;
    for(int i=0; i<=n; i++) {
        dp[i] = max(mx, dp[i]);
        dp[i + v[i].first] = max(dp[i + v[i].first], dp[i] + v[i].second);
        mx = max(dp[i], mx);
    }

    cout<<mx;
}


//int main() {
//    int n;
//    cin>>n;
//    vector<pair<int,int>>v;
//    v.push_back(make_pair(0,0));
//    int dp[17];
//    for(int i=0; i<17; i++) {
//        dp[i]= 0;
//    }
//
//    for(int i=1; i<=n; i++) {
//        int t,m;
//        cin>>t>>m;
//        v.push_back(make_pair(t,m));
//    }
//
//    for(int i=1; i<=n+1; i++) {
//        dp[i+v[i].first] = max(dp[i+v[i].first], dp[i] +v[i].second);
//    }
//    int mx = 0;
//    for(int i=1; i<=n+1; i++) {
//        mx = max(mx, dp[i]);
//    }
//    cout<<mx;
//}