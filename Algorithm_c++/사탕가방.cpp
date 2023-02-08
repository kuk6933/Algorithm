#include<iostream>
#include <cmath>
#include <vector>
using namespace std;
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        long long m;
        long long arr[101];
        cin >> n >> m;
        long long min_num, max_num;
        min_num = 1;
        max_num = 0;
        for(int i =0; i<n; i++) {
            cin>>arr[i];
            if(arr[i] > max_num) {
                max_num = arr[i];
            }
        }
        long long mid=0;
        long long cnt;
        while(min_num <= max_num) {
            mid = (min_num + max_num) / 2;
            cnt = 0;
            for(int i=0; i<n; i++) {
                cnt += arr[i] / mid;
            }
            if(cnt < m) {
                max_num = mid -1;
            } else {
                min_num = mid+1;
            }
        }
        cout<<"#"<<test_case<<" "<< max_num<<"\n";
    }
    return 0;
}