#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int visited[102][102];
int dist[101][101];

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

int solution(vector<vector<int> > maps)
{
    queue<pair<int,int>> q;
    q.push({0,0});
    int n = maps.size();
    int m = maps[0].size();

    visited[0][0] = 1;
    dist[0][0] = 1;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx <0 || nx>= n || ny < 0 || ny>= m) {
                continue;
            }
            if(visited[nx][ny] != 0 || maps[nx][ny] == 0) {
                continue;
            }
            visited[nx][ny] = 1;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx,ny});
        }
    }
    if(dist[n-1][m-1] == 0 ) {
        return -1;
    } else {
        return dist[n - 1][m - 1];
    }
}