#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> peak[100000];
int sum[100001];
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int l,n;
        cin >> l >> n;


        for (int i = 0; i < n; i++) {
            cin >> peak[i].first >> peak[i].second;
            sum[i + 1] = sum[i] + (peak[i].second - peak[i].first);
        }
        int ans = 0;
        int j = 0;
        for(int i=0; i<n; i++) {
            for(; j<=i && peak[j].first + l <= peak[i].second; j++) {
                int min = peak[j].first + l - peak[i].first;
                if( min > 0) {
                    ans = max(ans, sum[i] - sum[j] + min);
                } else {
                    ans = max(ans, sum[i]- sum[j]);
                }
            }
        }
        if(j < n) {
            ans = max(ans, sum[n]- sum[j]);
        }
        cout << '#' << test_case << ' ' << ans << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
////////////꼭 혼자 다시 풀어보기 