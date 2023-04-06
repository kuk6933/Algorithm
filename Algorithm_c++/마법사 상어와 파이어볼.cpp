#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int dy[] = {-1,-1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1 ,0, -1, -1, -1};

struct FIREBALL {
    int y, x, m,d,s;
    FIREBALL(int ny, int nx, int nm, int ns, int nd) {
        y = ny;
        x = nx;
        m = nm;
        s = ns;
        d = nd;
    }
    FIREBALL();
};


int main() {
    int n,m,k;
    cin>>n>>m>>k;

    vector<FIREBALL> map[51][51];
    vector<FIREBALL> fireball;
    //입력
    for(int i=0; i<m; i++) {
        int y,x,m,d,s;
        cin>>y>>x>>m>>s>>d;
        fireball.push_back({y,x,m,s,d});
        map[y][x].push_back({y,x,m,s,d});
    }


    for(int K=0; K<k; K++) {

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                map[i][j].clear();
            }
        }
        //이동
        for(int i=0; i<fireball.size(); i++) {
            int cy = fireball[i].y;
            int cx = fireball[i].x;
            int mass = fireball[i].m;
            int speed = fireball[i].s;
            int direction = fireball[i].d;

            int move = speed % n;
            int ny = cy + dy[direction] *move;
            int nx = cx + dx[direction] *move;

            if(ny<=0) ny += n;
            if(nx<=0) nx += n;
            if(ny>n) ny -= n;
            if(nx>n) nx -= n;

            map[ny][nx].push_back({ny,nx,mass,speed,direction});
            fireball[i].y=  ny;
            fireball[i].x = nx;
        }

        //분할
        vector<FIREBALL> tmp;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(map[i][j].size()==0) continue;
                if(map[i][j].size()==1) {
                    tmp.push_back(map[i][j][0]);
                    continue;
                }
                int m_sum=0;
                int s_sum=0;
                bool odd = true;
                bool even = true;
                for(int t=0; t<map[i][j].size(); t++) {
                    if(map[i][j][t].d %2 == 1) even = false;
                    if(map[i][j][t].d %2 == 0) odd = false;
                    m_sum +=map[i][j][t].m;
                    s_sum +=map[i][j][t].s;
                }
                int children_m = m_sum/5;
                int children_s = s_sum/map[i][j].size();
                if(children_m ==0) continue;
                for(int t=0; t<4; t++) {
                    if(odd || even) {
                        tmp.push_back({i,j,children_m, children_s, t*2});
                    } else {
                        tmp.push_back({i,j,children_m, children_s, t*2 + 1});
                    }
                }
            }
        }
        fireball = tmp;
    }

    int ans = 0;
    for(int i=0; i<fireball.size(); i++) {
        ans+= fireball[i].m;
    }
    cout<<ans;

}