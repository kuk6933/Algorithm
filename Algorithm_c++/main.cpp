#include <iostream>
#include <vector>

using namespace std;

//int dy[] = {-1,-1, 0, 1, 1, 1, 0, -1};
//int dx[] = {0, 1, 1, 1 ,0, -1, -1, -1};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

struct PRIORITY {
    int empty = 0;
    int y = 22;
    int x = 22,
    friend_num = 0;
};

struct DESK {
    int empty = 4;
    bool can = true;
    int student=0;
    vector<int> friends;
};



int main() {
    int n;
    DESK classroom[21][21];
    vector<vector<int>> like(401);
    vector<int> line;
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==1 || j==1 || i==n || j== n) {
                classroom[i][j].empty = 3;
            }
            if(i==1 && j==1) {
                classroom[i][j].empty = 2;
            }
            if(i==1 && j==n) {
                classroom[i][j].empty = 2;
            }
            if(i==n && j==1) {
                classroom[i][j].empty = 2;
            }
            if(i==n && j==n) {
                classroom[i][j].empty = 2;
            }
        }
    }

    int from,to;
    for(int i=0; i<n*n; i++) {
        cin>>from;
        line.push_back(from);
        for(int j=0; j<4; j++) {
            cin>>to;
            like[from].push_back(to);
        }
    }


    for(int q=0; q<n*n; q++) {

        int turn = line[q];
        PRIORITY best;
        for(int i=1; i<=n; i++) {
            for(int j=1; j <=n; j++) {
                if(classroom[i][j].can == false) continue;
                int cnt = 0;
                for(int k=0; k<classroom[i][j].friends.size(); k++) {
                    for(int t=0; t<like[turn].size(); t++) {
                        if(classroom[i][j].friends[k] == like[turn][t]) cnt++;
                    }
                }
                bool change = false;
                if(best.friend_num < cnt) {
                    change = true;
                } else if(best.friend_num == cnt) {
                    if(best.empty < classroom[i][j].empty) {
                       change= true;
                    } else if(best.empty == classroom[i][j].empty) {
                        if(best.y > i) {
                            change = true;
                        } else if(best.y ==  i) {
                            if(best.x > j) {
                                change = true;
                            }
                        }
                    }
                }
                if(change) {
                    best.friend_num = cnt;
                    best.y=i;
                    best.x=j;
                    best.empty = classroom[i][j].empty;
                }
            }
        }

        // 자리 fix했어
        classroom[best.y][best.x].can = false;
        classroom[best.y][best.x].student = turn;
        for(int i=0; i<4; i++) {
            int ny = best.y+dy[i];
            int nx = best.x+dx[i];
            if(ny <= 0 || nx <= 0 || ny >n || nx >n)continue;
            classroom[ny][nx].empty -=1;
            classroom[ny][nx].friends.push_back(turn);
        }

    }

    int sum = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int num=0;
            for(int d=0; d<4; d++) {
                for(int k=0; k<classroom[i][j].friends.size(); k++) {
                    if(like[classroom[i][j].student][d] == classroom[i][j].friends[k]) {
                        num++;
                    }
                }
            }
            if(num==1) {
                sum+=1;
            } else if(num==2) {
                sum+=10;
            } else if(num==3) {
                sum+=100;
            } else if(num==4) {
                sum+=1000;
            }
        }
    }

    cout<<sum;
}