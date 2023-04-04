#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int board[9][9];
int n,m;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int main() {
    vector<pair<int,int>> v;
    vector<pair<int,int>> virus;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>board[i][j];
            if(board[i][j] == 0) {
                v.push_back(make_pair(i,j));
            } else if (board[i][j] == 2) {
                virus.push_back(make_pair(i,j));
            }
        }
    }
    int mx = 0;
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            for(int k=j+1; k<v.size(); k++) {
                //bfs돌고
                int tmp[9][9];
                for(int w=0; w<n; w++) {
                    for(int e=0; e<m; e++) {
                        tmp[w][e] = board[w][e];
                    }
                }
                tmp[v[i].first][v[i].second] = 1;
                tmp[v[j].first][v[j].second] = 1;
                tmp[v[k].first][v[k].second] = 1;
                queue<pair<int,int>> q;

                for(int t=0; t<virus.size(); t++) {
                    q.push(virus[t]);
                }
                while(!q.empty()) {
                    auto cur = q.front(); q.pop();
                    for(int d=0; d<4; d++) {
                        int ny = cur.first + dy[d];
                        int nx = cur.second + dx[d];
                        if(ny<0 || nx <0 || ny >= n || nx>=m) continue;
                        if(tmp[ny][nx] == 0) {
                            tmp[ny][nx] = 2;
                            q.push(make_pair(ny,nx));
                        }
                    }
                }
                int cnt= 0;
                for(int w=0; w<n; w++) {
                    for(int e=0; e<m; e++) {
                        if(tmp[w][e] == 0) {
                            cnt++;
                        }
                    }
                }
                mx = max(mx, cnt);
            }
        }
    }
    cout<<mx;
}