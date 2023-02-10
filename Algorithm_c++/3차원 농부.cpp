#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> h;
vector<int> c;
int cnt;
int mn;

void binarySearch(int value) {
    int begin = 0;
    int end = c.size()-1;
    while(begin <= end) {
        int mid = (begin + end) / 2;
        if(abs(value - c[mid]) < mn) {
            mn = abs(value - c[mid]);
            cnt = 1;
        } else if(abs(value - c[mid]) == mn) {
            cnt++;
        }
        if(value < c[mid]) {
            end = mid - 1;
        } else if (value > c[mid]) {
            begin = mid + 1;
        } else {
            break;
        }
    }
}
int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        cnt = 0;
        mn = 100000001;
        h.clear();
        c.clear();
        int n,m,c1,c2;
        cin >> n >> m >> c1 >> c2;

        for(int i=0; i<n; i++) {
            int z;
            cin>>z;
            h.push_back(z);
        }
        for(int i=0; i<m; i++) {
            int z;
            cin>>z;
            c.push_back(z);
        }
        sort(c.begin(), c.end());
        for(int i=0; i<n; i++) {
            binarySearch(h[i]);
        }
        cout<<"#"<<test_case<<" "<<mn + abs(c1 - c2)<<" "<<cnt<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}