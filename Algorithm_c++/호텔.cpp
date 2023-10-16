#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>

#define ll long long
using namespace std;

int c,n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n;
    int price, people;
    vector<pair<int, int>> vec;
    vector<int> dp;
    dp.resize(c+1);
    for(int i=0; i<n; i++) {
        cin>>price>>people;
        vec.push_back({price, people});
    }
    for(int i=0; i<=c; i++) {
        dp[i] = 213456789;
    }
    sort(vec.begin(), vec.end());
    int mn = 213456789;
    dp[0] = 0;
    for(int i=0; i<=c; i++) {
        for(int j=0; j<vec.size(); j++) {
            if(i+vec[j].second< c) {
                dp[i+vec[j].second] = min(dp[i+vec[j].second], dp[i]+vec[j].first);
            } else {
                mn = min(mn, dp[i]+vec[j].first);
            }
        }
    }
    cout<<mn;
}