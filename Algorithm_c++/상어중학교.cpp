#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//int dy[] = {-1,-1, 0, 1, 1, 1, 0, -1};
//int dx[] = {0, 1, 1, 1 ,0, -1, -1, -1};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

struct STAT {
    int y,x;
    int size=0;
    int rainbow=0;
    int color;
};


bool visited[21][21];


int main() {
    int n,m;
    int score = 0;
    int map[21][21];
    int tmp[21][21];
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>map[i][j];
        }
    }
    while(1) {

        STAT biggest;
        biggest.size = -1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                visited[i][j] = false;
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(map[i][j]>=1) {
                    if(visited[i][j]) continue;
                    queue<pair<int,int>> q;
                    STAT b;
                    b.color = map[i][j];
                    b.y = i;
                    b.x = j;
                    b.size = 1;
                    q.push({i,j});
                    visited[i][j] = true;
                    while(!q.empty()) {
                        auto cur = q.front(); q.pop();
                        for(int d=0; d<4; d++) {
                            int ny = cur.first + dy[d];
                            int nx = cur.second + dx[d];
                            if(ny < 0 || nx < 0 || ny >=n || nx >=n ) continue;
                            if(visited[ny][nx]) continue;
                            if(map[ny][nx] == b.color || map[ny][nx] == 0) {
                                if(map[ny][nx] ==0) b.rainbow++;
                                visited[ny][nx] = true;
                                b.size++;
                                q.push({ny,nx});
                            }
                        }
                    }
                    if(b.size<2) continue; //2이상이어야함
                    bool flag= false;
                    if(biggest.size < b.size) {
                        flag = true;
                    } else if(biggest.size == b.size) {
                        if(biggest.rainbow < b.rainbow) {
                            flag = true;
                        } else if(biggest.rainbow== b.rainbow) {
                            if(biggest.y < b.y) {
                                flag = true;
                            } else if(biggest.y == b.y) {
                                if(biggest.x < b.x) {
                                    flag = true;
                                }
                            }
                        }
                    }
                    if(flag) biggest = b;

                    for(int N=0; N<n; N++) {
                        for(int M=0; M<n; M++) {
                            if(map[N][M] == 0 ) {
                                visited[N][M] = false;
                            }
                        }
                    }
                }
            }
        }

        //블록 찾았어
        if(biggest.size == -1) {
            break;
        }
        queue<pair<int,int>> erase_q;
        erase_q.push({biggest.y, biggest.x});
        map[biggest.y][biggest.x] = -2;
        while(!erase_q.empty()) {
            auto cur = erase_q.front(); erase_q.pop();
            for(int d=0; d<4; d++) {
                int ny = cur.first + dy[d];
                int nx = cur.second + dx[d];
                if(ny < 0 || nx < 0 || ny >=n || nx >=n ) continue;
                if(map[ny][nx] == biggest.color || map[ny][nx] == 0) {
                    map[ny][nx] = -2;
                    erase_q.push({ny,nx});
                }
            }
        }
        score += biggest.size * biggest.size;

        for(int i=n-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(map[i][j]== -1) continue;
                int ny = i+1;
                while(1) {
                    if(ny >=n || map[ny][j] != -2) break;
                    map[ny][j]=map[ny-1][j];
                    map[ny-1][j] = -2;
                    ny++;
                }
            }
        }

        for(int c=1; c<=3; c++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    tmp[i][j] = map[n-j-1][i];
                }
            }
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    map[i][j] = tmp[i][j];
                }
            }
        }


        for(int i=n-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(map[i][j]== -1) continue;
                int ny = i+1;
                while(1) {
                    if(ny >=n || map[ny][j] != -2) break;
                    map[ny][j]=map[ny-1][j];
                    map[ny-1][j] = -2;
                    ny++;
                }
            }
        }
    }
    cout<<score;
}