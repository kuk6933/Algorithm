#include <iostream>
using namespace std;

int arr[101][101];
long long dp[101][101];
int n;

void input() {
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j <=n; j++) {
            cin>>arr[i][j];
        }
    }
}

void cal() {
    dp[1][1] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(arr[i][j]!= 0 && dp[i][j] != 0) {
                if(j+arr[i][j] <= n) {
                    dp[i][j+arr[i][j]]+= dp[i][j];
                }
                if(i+arr[i][j] <= n) {
                    dp[i+arr[i][j]][j] += dp[i][j];
                }
            }
        }
    }
}

void solve() {
    input();
    cal();
    cout<<dp[n][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
