#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>

#define ll long long
using namespace std;


vector<pair<ll, ll>> vec;
vector<ll> dp;
ll n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    dp.push_back(0);
    vec.push_back({0,0});
    cin>>n;
    dp.resize(n+2);
    ll t,p;
    ll ans = 0;
    for(int i=0; i<n; i++) {
        cin>>t>>p;
        vec.push_back({t,p});
    }
    for(int i=1; i<=n; i++) {
        dp[i] = max(dp[i], dp[i-1]);
        if(i+vec[i].first <= n+1) {
            dp[i+vec[i].first] = max(dp[i+vec[i].first], dp[i]+vec[i].second);
        }
    }
    for(int i=1;i<=n+1; i++) {
        if(dp[i] > ans) {
            ans = dp[i];
        }
    }
    cout<<ans;
}