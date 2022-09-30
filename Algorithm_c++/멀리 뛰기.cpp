//
// Created by ohhyeongseok on 2022/09/30.
//
#include <string>
#include <vector>

using namespace std;

int dp[2001];
long long solution(int n) {
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-1]%1234567 + dp[i-2]%1234567;
    }
    return dp[n]%1234567;
}