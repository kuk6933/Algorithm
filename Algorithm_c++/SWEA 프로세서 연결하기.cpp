#include<iostream>
#include<vector>
using namespace std;

int map[13][13];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int,int>> core;
int maxCore, minLine; // answer
int n;
void dfs(int doneCore ,int coreCnt, int lineCnt) { //지금까지 연결한 코어 개수, 전선 길이

    if(doneCore == core.size()) {
        if(coreCnt > maxCore) {
            maxCore = coreCnt;
            minLine = lineCnt;
        } else if(coreCnt == maxCore) {
            if(minLine > lineCnt) {
                minLine = lineCnt;
            }
        }
        return;
    }

    for(int i=0; i<4; i++) {
        pair<int,int> cur = core[doneCore];
        int nx = cur.first;
        int ny = cur.second;
        vector<pair<int,int>> footprint;
        int line = 0;
        bool flag = false;
        while(1) {
            nx += dx[i];
            ny += dy[i];
            if(map[nx][ny] != 0) {
                break;
            }
            footprint.push_back(make_pair(nx,ny));
            if(nx == 0 || ny == 0 || nx == n-1  || ny == n-1) {
                flag = true;
                break;
            }
        }
        if(flag) {
            for(int i=0; i<footprint.size(); i++) {
                map[footprint[i].first][footprint[i].second] = 1;
            }
            dfs(doneCore+1, coreCnt+1, lineCnt+footprint.size());
            for(int i=0; i<footprint.size(); i++) {
                map[footprint[i].first][footprint[i].second] = 0;
            }
        }
    }
    dfs(doneCore+1, coreCnt, lineCnt);
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        core.clear();
        maxCore = 0;
        minLine = 103;
        cin>>n;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin>>map[i][j];
                if(map[i][j] == 1) {
                    if( i != 0 && j != 0 && i != n-1 && j != n-1) {
                        core.push_back(make_pair(i, j));
                    }
                }
            }
        }

        dfs(0,0,0);
        cout<<"#"<<test_case<<" "<<minLine<<"\n";
    }
    return 0;
}