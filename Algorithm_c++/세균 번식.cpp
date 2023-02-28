using namespace std;

struct Pos {
    int r; // y
    int c; // x
};

struct Cell {
    int target = -1;
    int energy = -1;
    int version = 0;
    Pos pos;
};

struct cmp {
    bool operator()(Cell a, Cell b) {
        if(a.energy == b.energy) {
            if(a.pos.r == b.pos.r) {
                return a.pos.c > b.pos.c;
            } else {
                return a.pos.r > b.pos.r;
            }
        } else {
            return a.energy < b.energy;
        }
    }
};

const int dr[] = { -1,0,0, 1 };
const int dc[] = { 0,-1,1,0 };
int n;
int version;

Cell dish[MAX_N+1][MAX_N+1];

priority_queue<Cell, vector<Cell>, cmp> pq;
int target_num[3];

void init(int N, int mDish[MAX_N][MAX_N])
{
    n = N;
    version = 0;
    target_num[1] = target_num[2] = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            dish[i+1][j+1].energy = mDish[i][j];
            dish[i+1][j+1].pos = {i+1, j+1};
            dish[i+1][j+1].version = 0;
            dish[i+1][j+1].target = 0;
        }
    }
}

int dropMedicine(int mTarget, int mRow, int mCol, int mEnergy)
{
    version++;
    if(dish[mRow][mCol].target == 0) { // empty
        target_num[mTarget]++;
        mEnergy -= dish[mRow][mCol].energy;
        dish[mRow][mCol].target = mTarget;
        dish[mRow][mCol].version = version;
    } else if(dish[mRow][mCol].target == mTarget) { // 같은 종류 세균
        dish[mRow][mCol].version = version;
    } else {
        return target_num[mTarget];
    }

    queue<Pos> q;
    pq = {};
    q.push(dish[mRow][mCol].pos);
    while(!q.empty()) {
        Pos cur = q.front(); q.pop();
        int cr = cur.r;
        int cc = cur.c;
        for(int i=0; i<4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if(nr <= 0 || nc <= 0 || nr > n || nc > n) continue;
            if(dish[nr][nc].version >= version) continue;
            if(dish[nr][nc].target!= 0 && dish[nr][nc].target != mTarget) continue;
            dish[nr][nc].version = version;
            if(dish[nr][nc].target == mTarget) {
                q.push(dish[nr][nc].pos);
            } else {
                pq.push(dish[nr][nc]);
            }
        }
    }
    //2단계 -- pq번식 가능한 위치 넣어놨음

    while(mEnergy > 0) {
        if(pq.empty()) break;
        Cell now = pq.top(); pq.pop();
        dish[now.pos.r][now.pos.c].version = version;
        dish[now.pos.r][now.pos.c].target = mTarget;
        target_num[mTarget]++;
        mEnergy -= now.energy;

        q.push(now.pos);
        while(!q.empty()) {
            Pos cur = q.front(); q.pop();
            int cr = cur.r;
            int cc = cur.c;
            for(int i=0; i<4; i++) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];

                if(nr <= 0 || nc <= 0 || nr > n || nc > n) continue;
                if(dish[nr][nc].version >= version) continue;
                if(dish[nr][nc].target!= 0 && dish[nr][nc].target != mTarget) continue;
                dish[nr][nc].version = version;
                if(dish[nr][nc].target == mTarget) {
                    q.push(dish[nr][nc].pos);
                } else {
                    pq.push(dish[nr][nc]);
                }
            }
        }
    }
    return target_num[mTarget];
}

int cleanBacteria(int mRow, int mCol)
{
    version++;
    if(dish[mRow][mCol].target == 0) {
        return -1;
    }
    dish[mRow][mCol].version = version;
    Cell start = dish[mRow][mCol];
    queue<Pos> q;
    q.push(start.pos);
    while(!q.empty()) {
        Pos cur = q.front(); q.pop();
        int cr = cur.r;
        int cc = cur.c;
        for(int i=0; i<4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if(nr <= 0 || nc <= 0 || nr > n || nc > n) continue;
            if(dish[nr][nc].version >= version) continue;
            if(dish[nr][nc].target != start.target) continue;
            dish[nr][nc].version = version;
            q.push(dish[nr][nc].pos);
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(dish[i][j].version >= version) {
                dish[i][j].version = 0;
                target_num[dish[i][j].target]--;
                dish[i][j].target = 0;
            }
        }
    }
    return target_num[start.target];
}