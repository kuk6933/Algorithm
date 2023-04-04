#include <iostream>
#include <algorithm>

using namespace std;
int n,m;
int board[501][501];
bool visited[501][501];
int ans=0;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int sum, int cnt) {
    if(cnt == 3) {
        ans = max(ans, sum);
        return;
    }
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(nx <0 || ny<0 || ny>=n || nx >=m) {
            continue;
        }
        if(!visited[ny][nx]) {
            visited[ny][nx] = true;
            dfs(ny,nx, sum+board[ny][nx], cnt+1);
            visited[ny][nx] = false;
        }
    }
}
int main() {
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            visited[i][j]= false;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>board[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            visited[i][j] = true;
            dfs(i,j,board[i][j], 0);
            visited[i][j] = false;
        }
    }
    for(int i=0; i<=n-2; i++) { //ㅗ
        for(int j=0; j<m-2; j++) {
            int sum = 0;
            sum = board[i+1][j] + board[i+1][j+1] + board[i][j+1]+ board[i+1][j+2];
            ans = max(ans, sum);
        }
    }
    for(int i=0; i<=n-2; i++) { //ㅜ
        for(int j=0; j<m-2; j++) {
            int sum = 0;
            sum = board[i][j] + board[i][j+1] + board[i][j+2]+ board[i+1][j+1];
            ans = max(ans, sum);
        }
    }


    for(int i=0; i<n-2; i++) { //ㅓ
        for(int j=0; j<=m-2; j++) {
            int sum = 0;
            sum = board[i+1][j] + board[i][j+1] + board[i+1][j+1]+ board[i+2][j+1];
            ans = max(ans, sum);
        }
    }

    for(int i=0; i<n-2; i++) { //ㅏ
        for(int j=0; j<=m-2; j++) {
            int sum = 0;
            sum = board[i][j] + board[i+1][j] + board[i+1][j+1]+ board[i+2][j];
            ans = max(ans, sum);
        }
    }
    cout<<ans;
}
