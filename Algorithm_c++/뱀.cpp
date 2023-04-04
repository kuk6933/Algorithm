#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n,k;
int board[101][101];
vector<pair<int,int>> s;
char dir = 'D';
int now = 1;
int cnt=0;
vector<pair<int,char>> v;
int main() {
    cin>>n>>k;
    int y,x;
    for(int i=0; i<k; i++) {
        cin >> y >> x;
        board[y][x] = 1;
    }
    int l;
    cin>>l;
    int t;
    char d;
    for(int i=0; i<l; i++) {
        cin>> t>> d;
        v.push_back(make_pair(t, d));
    }
    int time =0;
    s.push_back(make_pair(1,1));
    board[1][1] = 2;
    bool turn = false;
    while(1) {

        // 머리 움직임
        pair<int,int> head = s[s.size()-1];
        time++;
        if(turn) {
            if(dir == 'D') {
                now = (now + 1) % 4;
            }
            else if(dir == 'L') {
                now = now - 1;
                if(now == -1) {
                    now = 3;
                }
            }
            turn = false;
        }
        if(now == 0) {
            head.first -= 1;
        }
        else if(now == 1) {
            head.second += 1;
        }
        else if (now == 2) {
            head.first += 1;
        }
        else if (now == 3) {
            head.second -= 1;
        }

        // 끝나는 조건
        if(head.first > n || head.second > n|| head.first <=0 || head.second <= 0 || board[head.first][head.second] == 2) {
            break;
        }

        if(board[head.first][head.second] == 1) { // 있으면 push만
            s.push_back(make_pair(head.first, head.second));
            board[head.first][head.second] = 2;
        } else { // 사과 없는경우 움직임 따라감
            board[s[0].first][s[0].second] = 0; //꼬리칸 치워줌
            for(int i=0; i<s.size()-1; i++) {
                s[i] = s[i+1];
            }
            board[head.first][head.second] = 2;
            s[s.size()-1] = head;
        }
        if(v.size()-1 >= cnt) {
            if(v[cnt].first == time) {
                dir = v[cnt++].second;
                turn = true;
            }
        }
    }
    cout<<time;
}
