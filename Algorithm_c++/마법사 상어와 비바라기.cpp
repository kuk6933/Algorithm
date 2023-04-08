#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dy[] = {-2,0,-1,-1,-1,0,1,1,1};
int dx[] = {-2,-1,-1,0,1,1,1,0,-1};

pair<int,int> around[] = {{-1,-1}, {-1, 1}, {1, 1}, {1, -1} };
//int dy[] = {-1, 0, 1, 0};
//int dx[] = {0, 1, 0, -1};


vector<pair<int,int>> movement;

int tmp[51][51];
int map[51][51];
int cloud[51][51];

int main() {
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>map[i][j];
        }
    }


    for(int i=0; i<m; i++) {
        int d,s;
        cin>>d>>s;
        movement.push_back(make_pair(d,s));
    }

    cloud[n][1] = 1;
    cloud[n][2] = 1;
    cloud[n-1][1] = 1;
    cloud[n-1][2] = 1;

    for(int t=0; t<m; t++) {

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                tmp[i][j] = 0;
            }
        }

        int dir = movement[t].first;
        int speed = movement[t].second;
        speed %= n;

        //구름 움직이기
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                int ny = i+dy[dir]*speed;
                int nx = j+dx[dir]*speed;
                if(ny <=0) ny += n;
                if(nx <=0) nx+=n;
                if(ny>n) ny-=n;
                if(nx>n) nx-=n;
                tmp[ny][nx] = cloud[i][j];
            }
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                cloud[i][j] = tmp[i][j];
            }
        }

        //2단계
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(cloud[i][j]==1) {
                    map[i][j]++;
                }
            }
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {

                if(cloud[i][j]==1) {
                    int cnt= 0;
                    for(int k=0; k<4; k++) {
                        int ny = i + around[k].first;
                        int nx = j + around[k].second;
                        if(ny <=0 || nx <= 0 || ny>n || nx >n) continue;
                        if(map[ny][nx] > 0) {
                            cnt++;
                        }
                    }
                    map[i][j]+= cnt;
                }
            }
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(cloud[i][j] == 1) {
                    cloud[i][j]= 0;
                    continue;
                }
                if(map[i][j]>= 2) {
                    cloud[i][j] = 1;
                    map[i][j] -=2;
                }
            }
        }

    }
    int sum = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(map[i][j]>0) {
                sum+=map[i][j];
            }
        }
    }

    cout<<sum;
}
