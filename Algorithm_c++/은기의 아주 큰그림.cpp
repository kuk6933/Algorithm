#include<iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int ans = 0;
        int h,w,n,m;
        cin>> h>> w>> n>> m;
        vector<vector<char>> p(1001, vector<char>(1001));
        vector<vector<char>> d(1001, vector<char>(1001));
        int pnum = 0;
        int pmul = 1;
        for(int i=0; i< h; i++) {
            for (int j=0; j<w; j++) {
                cin >> p[i][j];
                pnum += p[i][j] * (1 << pmul++);
            }
        }
        for(int i=0; i< n; i++) {
            for (int j=0; j<m; j++) {
                cin >> d[i][j];
            }
        }

        for(int i=0; i<= n-h; i++) {
            for(int j=0; j<= m-w; j++) {
                int dnum = 0;
                int dmul = 1;
                for (int k = 0; k < h; k++) {
                    for (int t = 0; t < w; t++) {
                        dnum += d[i + k][j + t] * (1 << dmul++);
                    }
                }
                if (pnum == dnum) {
                    ans++;
                }
            }
        }
        cout<<"#"<<test_case<<" "<< ans<<"\n";
    }
    return 0;
}