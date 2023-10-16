#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>

#define ll long long
using namespace std;

int n,m,T;
int dp[50001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0; i<=n; i++) {
        dp[i] = 500001;
    }

    int cnt = 1;
    while(1) {
        if(cnt*cnt > n) {
            break;
        }
        dp[cnt*cnt] = 1;
        cnt++;
    }

    for(int i=2; i<=n; i++) {
        for(int j=1; j<= sqrt(n); j++) {
            if(i-j*j >= 1) {
                dp[i] = min(dp[i-j*j]+dp[j*j], dp[i]);
            }
        }
    }
    cout<<dp[n];
}
