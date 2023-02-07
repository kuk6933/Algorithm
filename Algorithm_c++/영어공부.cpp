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
        vector<int> v(1000001);
        for(int i=0; i<1000001; i++) {
            v[i] = 0;
        }
        int n,p;
        cin>>n>>p;
        int last;
        for(int i=0; i<n; i++) {
            int study;
            cin>>study;
            last = study;
            v[study] = 1;
        }
        int l,r;
        l = 0;
        r = -1;

        int maxDistance = 0;
        int distance = 0;
        while(1) {
            if(r >= last && p == 0) {
                break;
            }
            if(p >= 0) { // 해킹 가능
                r++;
                if(v[r] == 0) {
                    p--;
                }
                distance++;
                if(distance > maxDistance && p >= 0) {
                    maxDistance = distance;
                }
            } else { // 불가
                if(v[l] == 0) {
                    p++;
                }
                l++;
                distance--;
            }
        }
        cout<<"#"<<test_case<<" "<<maxDistance<<"\n";
    }
    return 0;
}