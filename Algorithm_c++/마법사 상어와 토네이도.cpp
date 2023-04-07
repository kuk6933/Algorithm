#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

//int dy[] = {-1,-1, 0, 1, 1, 1, 0, -1};
//int dx[] = {0, 1, 1, 1 ,0, -1, -1, -1};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

struct EFECT {
    int y,x,percent;
    EFECT(int y, int x, int percent) {
        this->y = y;
        this->x = x;
        this->percent = percent;
    }
};
vector<EFECT> efect[4];

int map[501][501];

int main() {

    int n;
    cin>>n;
    vector<pair<int,int>> remain = {make_pair(-1,0), make_pair(0,1), make_pair(1,0), make_pair(0,-1)};
    efect[0] = {EFECT(-2,0,5),EFECT(-1,-1,10),EFECT(-1,1,10),EFECT(0,-2,2),
                EFECT(0,-1,7),EFECT(0,1,7),EFECT(0,2,2),EFECT(1,-1,1), EFECT(1,1,1)};
    efect[1] = {EFECT(0,2,5),EFECT(-1,1,10),EFECT(1,1,10),EFECT(-2,0,2),
                EFECT(-1,0,7),EFECT(1,0,7),EFECT(2,0,2),EFECT(-1,-1,1), EFECT(1,-1,1)};
    efect[2] = {EFECT(2,0,5),EFECT(1,1,10),EFECT(1,-1,10),EFECT(0,2,2),
                EFECT(0,1,7),EFECT(0,-1,7),EFECT(0,-2,2),EFECT(-1,1,1), EFECT(-1,-1,1)};
    efect[3] = {EFECT(0,-2,5),EFECT(1,-1,10),EFECT(-1,-1,10),EFECT(2,0,2),
                EFECT(1,0,7),EFECT(-1,0,7),EFECT(-2,0,2),EFECT(1,1,1), EFECT(-1,1,1)};
    int sum = 0;
    for(int i =1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>map[i][j];
            sum+=map[i][j];
        }
    }

    int direction = 3;
    pair<int,int> now = make_pair(n/2 +1, n/2+1);
    int how= 1;
    int cnt = 0;
    while(1) {
        if (now.first == 1 && now.second == 1) {
            break;
        }
        if (how < n) {
            if (cnt == 2) {
                cnt = 0;
                how++;
            }
        }

        for (int i = 1; i <= how; i++) {
            if(now.first == 1 && now.second==1) { //(1,N)에서 N만큼 이동할 때 (1,1)에서 멈추게 하기 위함
                break;
            }
            now.first += dy[direction];
            now.second += dx[direction];
            int sand = 0;
            for (int j = 0; j < 9; j++) {//모래 움직임
                if (now.first + efect[direction][j].y <= n && now.first + efect[direction][j].y > 0 &&
                    now.second + efect[direction][j].x <= n && now.second + efect[direction][j].x > 0) {
                    map[now.first + efect[direction][j].y][now.second + efect[direction][j].x] +=
                            floor(map[now.first][now.second] * 0.01 * efect[direction][j].percent);
                }
                sand += floor(map[now.first][now.second] * 0.01* efect[direction][j].percent);
            }

            if (now.first + remain[direction].first <= n && now.first + remain[direction].first > 0 && //남은 모래 a에 넣기
                now.second + remain[direction].second <= n && now.second + remain[direction].second > 0) {
                map[now.first + remain[direction].first][now.second + remain[direction].second] += (
                        map[now.first][now.second] - sand);
            }
            map[now.first][now.second] = 0;
        }
        cnt++;
        direction--;
        if (direction < 0) {
            direction += 4;
        }
    }
    int exist = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            exist += map[i][j];
        }
    }
    cout<<sum - exist;
}