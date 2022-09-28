//
// Created by ohhyeongseok on 2022/09/28.
//
#include <string>
#include <vector>

using namespace std;

long long f[100002];
int solution(int n) {
    f[0] = 0;
    f[1] = 1;
    for(int i=2; i<=n; i++) {
        f[i] = (f[i-1] + f[i-2]) % 1234567;
    }
    return f[n]%1234567;
}