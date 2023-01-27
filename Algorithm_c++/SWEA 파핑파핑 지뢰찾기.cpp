#include <iostream>
#include <queue>
using namespace std;

int n;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int map[301][301];
bool check(int x, int y) {
    bool zero = true;
    for(int i=0; i<8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx< 0 || ny< 0 || nx>= n || ny>= n) {
            continue;
        }
        if(map[nx][ny] == -1 ) {
            zero = false;
            break;
        }
    }
    return zero;
}
int main(int argc, char** argv) {// -1 -> 지뢰 0 -> 탐색x 1 -> 탐완
    int test_case;
    int T;
    cin>> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> n;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            for (int j = 0; j < n; j++) {
                if (str[j] == '*') {
                    map[i][j] = -1;
                } else {
                    map[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 0) {
                    if (check(i, j)) {
                        cnt++;
                        queue<pair<int, int>> q;
                        q.push(make_pair(i, j));
                        map[i][j] = 1;
                        while (!q.empty()) {
                            auto cur = q.front();
                            q.pop();
                            for (int i = 0; i < 8; i++) {
                                int nx = cur.first + dx[i];
                                int ny = cur.second + dy[i];
                                if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
                                    continue;
                                }
                                if(map[nx][ny] == 0) {
                                    if (check(nx, ny)) {
                                        q.push(make_pair(nx, ny));
                                    }
                                }
                                map[nx][ny] = 1;
                            }
                        }
                    }
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(map[i][j] == 0) {
                    cnt++;
                    map[i][j]= 1;
                }
            }
        }
        cout<<"#"<<test_case<<" "<<cnt<<"\n";
    }
    return 0;
}