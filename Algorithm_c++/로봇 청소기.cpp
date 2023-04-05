#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int board[50][50];

int n,m;
vector<int> vec;

int main() {
    cin>>n>>m;
    int y,x,d;
    cin>> y>> x>> d;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>board[i][j];
        }
    }
    int clean = 0;
    while(1) {
        //청소
        if(board[y][x] == 0) {
            clean++;
            board[y][x] = 2;
        }
        //4칸 탐색
        bool flag = false;
        for(int i=0; i<4; i++) {
            d--;
            if(d < 0) {
                d = 3;
            }
            if(board[y+ dy[d]][x+ dx[d]] == 0) {
                y = y + dy[d];
                x = x + dx[d];
                flag = true;
                break;
            }
        }
        if(!flag) {
            y = y + dy[(d+2)%4];
            x = x + dx[(d+2)%4];
            if(board[y][x] == 1) {
                break;
            }
        }
    }
    cout<<clean;
}