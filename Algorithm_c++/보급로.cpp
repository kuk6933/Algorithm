#include<iostream>
#include<string>
#include<queue>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0 ,-1};
struct Node {
    Node(int dx, int dy, int dcnt) {
        x = dx;
        y = dy;
        cnt = dcnt;
    }
    Node() {
    }
    int x;
    int y;
    int cnt;
};

struct cmp {
    bool operator()(Node a, Node b) {
        return a.cnt > b.cnt;
    }
};

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin>>n;
        string str[101];
        int map[101][101] = {0};
        int min[101][101];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                min[i][j] =210000000;
            }
        }
        for(int i=0; i<n; i++) {
            cin>>str[i];
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                map[i][j] = str[i][j] -'0';
            }
        }
        priority_queue<Node, vector<Node>, cmp> pq;

        pq.push(Node(0,0,0));
        while(!pq.empty()) {

            auto cur = pq.top(); pq.pop();
            if(cur.x == n-1 && cur.y == n-1) {
                cout<<"#"<<test_case<<" "<< cur.cnt<<"\n";
                break;
            }
            min[cur.x][cur.y] = cur.cnt;
            for(int i=0; i<4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if(nx >= n || ny >= n || nx<0 || ny <0) {
                    continue;
                }
                if(min[nx][ny] > cur.cnt + map[nx][ny]) {
                    pq.push(Node(nx,ny,cur.cnt + map[nx][ny]));
                }
            }
        }
    }
    return 0;
}