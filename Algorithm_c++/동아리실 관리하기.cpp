#include <iostream>
#include <string>
#define MAX 10000

using namespace std;
long long dp[MAX][16];

int main()
{
    int T;
    cin >> T;
    int test_case;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string str;
        cin >> str;
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<str.size(); i++) { //날짜
            int must = 1 << (str[i]- 'A'); //책임자

            for(int j=1; j<16; j++) {
                if (i == 0) { // 첫날은 A와 책임자
                    if((j & must) != 0 && (j & 1) != 0) {
                        dp[i][j] = 1;
                    }
                } else { // 이틀째 부터는 책임자와 열쇠 가지고 있는 사람
                    if( dp[i-1][j] != 0) {
                        for (int k=1; k<16; k++) {
                            if((j&k) != 0 && (k & must) != 0) {
                                dp[i][k] += dp[i-1][j];
                                dp[i][k] %= 1000000007;
                            }
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for(int i = 1; i<16; i++) {
            ans += dp[str.size()-1][i];
            ans %= 1000000007;
        }
        cout << "#"<< test_case <<" "<< ans <<"\n";
    }
}
