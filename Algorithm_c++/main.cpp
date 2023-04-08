#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int dice[7] = {0,1,2,3,4,5,6}; //위 앞 오른쪽 왼쪽 뒤 밑

void update(int d) {

    int d1= dice[1];
    int d2= dice[2];
    int d3= dice[3];
    int d4= dice[4];
    int d5= dice[5];
    int d6= dice[6];
    if(d==0) {
        dice[1]=d5;
        dice[5]=d6;
        dice[6]=d2;
        dice[2]=d1;
    } else if(d== 1) {
        dice[1]=d4;
        dice[4]=d6;
        dice[6]=d3;
        dice[3]=d1;
    } else if(d== 2) {
        dice[1]=d2;
        dice[2]=d6;
        dice[6]=d5;
        dice[5]=d1;
    } else if(d == 3) {
        dice[4]=d1;
        dice[1]=d3;
        dice[3]=d6;
        dice[6]=d4;
    }
}


int n,m,k;
int map[21][21];

int main() {
    int direction = 1;
    int sum = 0;
    cin>>n>>m>>k;
  for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
          cin>>map[i][j];
      }
  }

  pair<int,int> cur = {0,0};
  for(int K=0; K<k; K++) {
      int next_y = cur.first + dy[direction];
      int next_x = cur.second + dx[direction];

      if(next_y <0 || next_x <0 || next_y >=n || next_x >= m) {
          direction +=2;
          direction %= 4;
      }
      cur.first+= dy[direction];
      cur.second+= dx[direction];

      update(direction);

      int num = map[cur.first][cur.second];
      bool visited[21][21];
      for(int i=0; i<n; i++) {
          for(int j=0; j<m; j++) {
              visited[i][j] = false;
          }
      }
 //점수획득
      queue<pair<int,int>> q;
      int sz = 1;
      q.push({cur.first, cur.second});
      visited[cur.first][cur.second] = true;
      while(!q.empty()) {
          int curY = q.front().first;
          int curX = q.front().second;
          q.pop();
          for(int i=0; i<4; i++) {
              int ny = curY +dy[i];
              int nx = curX + dx[i];
              if(ny <0 || nx <0 || ny >=n || nx >= m) continue;
              if(visited[ny][nx]) continue;
              if(map[ny][nx]== num) {
                  q.push({ny,nx});
                  visited[ny][nx]= true;
                  sz++;
              }
          }
      }
      sum += num * sz;

      if(dice[6] > num) {
          direction++;
          direction %= 4;
      } else if(dice[6] < num) {
          direction--;
          if(direction<0) {
              direction+=4;
          }
      }
  }
  cout<<sum;
}
