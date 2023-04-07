#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;


int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};


int n,q,m;
bool visited[65][65];
int map[65][65];
int tmp_map[65][65];
vector<int> magic;
void rotate(int y, int x, int l) {
    for(int i=0; i<l; i++) {
        for(int j=0; j<l; j++) {
            tmp_map[i][j] = map[y+l-j-1][x+i];
        }
    }
    for(int i=0; i<l; i++) {
        for(int j=0; j<l; j++) {
            map[y+i][x+j] = tmp_map[i][j];
        }
    }
}

int main() {

    cin>>n>>q;
    n = (1 << n);
    for(int i =0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>map[i][j];
        }
    }
    for(int i=0; i<q; i++) {
        int sz;
        cin>>sz;
        magic.push_back(sz);
    }

    for(int t=0; t<magic.size(); t++) {
        m = (1 << magic[t]);

        for(int i=0; i<n; i+= m) {
            for(int j=0; j<n; j+= m) {
                rotate(i,j, m);
            }
        }
        vector<pair<int,int>> hot;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int cnt =0;
                for(int d=0; d<4; d++) {
                    int ny = i+dy[d];
                    int nx = j+dx[d];
                    if(ny <0 || nx <0 || ny >= n || nx >= n) continue;
                    if(map[ny][nx] > 0) cnt++;
                }
                if(cnt <3) {
                    hot.push_back(make_pair(i,j));
                }
            }
        }
        for(int i=0; i<hot.size(); i++) {
            map[hot[i].first][hot[i].second] -= 1;
        }
    }


    int sum = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(map[i][j] >0) {
                sum+= map[i][j];
            }
        }
    }

    int mx = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j] && map[i][j] >= 1) {
                visited[i][j] = true;
                int count = 1;
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()) {
                    auto cur = q.front(); q.pop();
                    for(int d= 0; d<4; d++) {
                        int ny = cur.first + dy[d];
                        int nx = cur.second + dx[d];
                        if(ny <0 || nx <0|| ny >= n || nx >= n) continue;
                        if(visited[ny][nx]) continue;
                        if(map[ny][nx] <=0) continue;
                        visited[ny][nx] = true;
                        q.push({ny,nx});
                        count++;
                    }
                }
                if(mx < count) mx = count;
            }
        }
    }
    cout<<sum<<"\n"<<mx;
}