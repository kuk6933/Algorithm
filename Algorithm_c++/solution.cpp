struct pair {
    int x;
    int y;
};

pair queue[101];
int board[11][11];
int road [11][11];
bool visited[11][11];
int sz;
int front,rear;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void enqueue(int y, int x) {
    pair p;
    p.y = y;
    p.x = x;
    queue[++front] = p;
}

pair dequeue() {
    return queue[++rear];
}

void bfs_init(int map_size, int map[10][10]) {

    sz = map_size;
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            road[j+1][i+1] = map[j][i];
        }
    }
}
int bfs(int x1, int y1, int x2, int y2) {
    front = -1;
    rear = -1;
    for(int i=1; i<11; i++) {
        for(int j=1; j<11; j++) {
            visited[j][i] = false;
            board[j][i] = 0;
        }
    }
    enqueue(y1, x1);
    visited[y1][x1] = true;

    while(rear != front) {
        pair cur = dequeue();
        if(cur.y == y2 && cur.x == x2) {
            return board[y2][x2];
        }
        for(int i=0; i<4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx <= 0 || ny <= 0 || nx>sz || ny > sz) {
                continue;
            }
            if(visited[ny][nx]) {
                continue;
            }
            if(road[ny][nx] == 1) {
                continue;
            }
            visited[ny][nx] = true;
            board[ny][nx] = board[cur.y][cur.x]+1;
            enqueue(ny ,nx);
        }
    }
    return -1;
}