#include <iostream>
#include <vector>

using namespace std;

//int dy[] = {-1,-1, 0, 1, 1, 1, 0, -1};
//int dx[] = {0, 1, 1, 1 ,0, -1, -1, -1};
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

struct PRIORITY {
    int empty = 0; //현재 가장 적합한 칸의 주위 빈칸 개수
    int y = 22; // 좌표
    int x = 22; //좌표
    int  friend_num = 0; // 친구 숫자
};

struct DESK {
    int empty = 4; //이 자리 주변 빈칸 개수
    bool can = true; //자리에 앉을 수 있는지(사람이 없는지)
    int student=0; //자리에 앉은 학생 번호
    vector<int> friends; //주변에 앉은 친구들 번호
};



int main() {
    int n;
    DESK classroom[21][21];
    vector<vector<int>> like(401); // 좋아하는 학생 관리를 위한 벡터
    vector<int> line; //앉을 순서
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==1 || j==1 || i==n || j== n) { // 모서리부분 따로 계산해줍니다
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
                if(classroom[i][j].can == false) continue; //자리에 사람이 있으면
                int cnt = 0;
                for(int k=0; k<classroom[i][j].friends.size(); k++) { //친구 수 세기
                    for(int t=0; t<like[turn].size(); t++) {
                        if(classroom[i][j].friends[k] == like[turn][t]) cnt++;
                    }
                }
                bool change = false;
                if(best.friend_num < cnt) { //우선순위 비교 하는 과정입니다
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
                if(change) { //가장 적합한 자리 바뀜
                    best.friend_num = cnt;
                    best.y=i;
                    best.x=j;
                    best.empty = classroom[i][j].empty;
                }
            }
        }

        // 학생이 자리에 앉음
        classroom[best.y][best.x].can = false;
        classroom[best.y][best.x].student = turn;
        for(int i=0; i<4; i++) { //주변 자리들의 빈칸 개수를 1씩 줄여주고 친구에 자신을 넣어줍니다
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