#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int mxcnt = 0;
void dfs(int remain, int cnt, vector<vector<int>> dungeons, int i) {
    if(cnt > mxcnt) {
        mxcnt = cnt;
    }
    if( i> dungeons.size()-1) {
        return;
    }
    if(remain >= dungeons[i][0]) {
        dfs(remain- dungeons[i][1], cnt+1, dungeons,i+1 );
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    do {

        cout<<"1";
    } while(next_permutation(dungeons.begin(), dungeons.end()));
    return mxcnt;
}
int main() {

    vector<vector<int>> v = {{80, 20}, {50, 40}, {30, 10}};
    sort(v.begin(), v.end());
    int a = solution(80,v);
    cout<<a;
}
