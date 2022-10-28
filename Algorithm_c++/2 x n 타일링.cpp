//
// Created by ohhyeongseok on 2022/10/28.
//
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> dp(60002);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i=4; i<= n; i++) {
        dp[i] = dp[i-1]%1000000007 + dp[i-2]%1000000007;
    }

    int answer = dp[n] %1000000007;
    return answer;
}