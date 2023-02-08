#include<iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        long long n;
        cin>>n;
        n *= 2;
        long long l = 0;
        long long r = sqrt(n);
        long long m;
        long long ans = 0;
        while(1) {
            if(l > r ) {
                break;
            }
            m = (l+r) / 2;
            if(m*(m+1) == n) {
                ans = m;
                break;
            } else {
                if(n< m*(m+1)) {
                    r = m-1;
                } else {
                    l = m+1;
                }
            }
        }
        if(ans ==0) {
            cout<<"#"<<test_case<<" "<< -1<<"\n";
        } else {
            cout<<"#"<<test_case<<" "<< ans<<"\n";
        }
    }
    return 0;
}