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
