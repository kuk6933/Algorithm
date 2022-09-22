#include <vector>
#include <algorithm>
#define MAX 10002
using namespace std;
int dp[151][151];
int solution(int alp, int cop, vector<vector<int>> problems) {
    int maxAlp = 0;
    int maxCop = 0;
    for(auto p: problems) {
        maxAlp = max(maxAlp, p[0]);
        maxCop = max(maxCop, p[1]);
    }    alp = min(alp, maxAlp);
    cop = min(cop, maxCop);
    for(int i=alp; i<= maxAlp; i++) {
        for(int j=cop; j<=maxCop; j++) {
            dp[i][j] = MAX;
        }
    }
    dp[alp][cop] = 0;
    for (int i = alp; i <=maxAlp; i++) {
        for (int j=cop; j <=maxCop; j++) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
            dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1);

            for(auto p: problems) {
                if(i >=p[0] && j >= p[1]) {
                    int ni = min(i + p[2], maxAlp);
                    int nj = min(j+ p[3], maxCop);
                    dp[ni][nj] = min(dp[ni][nj], dp[i][j]+ p[4]);
                }
            }
        }
    }
    return dp[maxAlp][maxCop];
}
