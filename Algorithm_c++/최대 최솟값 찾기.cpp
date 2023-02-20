#include <algorithm>

#define INF 2000000000
#define MX 230002
using namespace std;

struct Node {
    int mx;
    int mn;
    int alive;
    Node() {
        mx = -INF;
        mn = INF;
        alive = 0;
    }
    Node(int mx_value, int mn_value, int al) {
        mx = mx_value;
        mn = mn_value;
        alive = al;
    }
};
int totalAdd;
Node tree[MX<<2];
Node merge(Node u, Node v) {
    int mx = max(u.mx, v.mx);
    int mn = min(u.mn, v.mn);
    int alive = u.alive + v.alive;
    return Node(mx, mn, alive);
}

void update(int node, int begin, int end, int idx, int val) {
    if( idx< begin || end < idx) { //구간 벗어나면
        return;
    }
    if( begin == end ) { //리프노드까지 들어감
        if (val == INF) {
            tree[node] = Node();
        } else {
            tree[node] = Node(val, val, 1);
        }
        return;
    }
    //위로 올라가면서 값 갱신
    int mid = begin + end >> 1;
    update(node << 1, begin, mid, idx, val);
    update(node << 1 | 1 , mid + 1 , end, idx ,val);
    tree[node] = merge(tree[node<<1], tree[node<<1 | 1]);
}

Node query(int node, int begin, int end, int left, int right) {
    if(right<begin || end <left) {
        return Node();
    }
    if (left<=begin && end<= right) {
        return tree[node];
    }
    int mid = begin + end >> 1;
    Node u = query(node << 1 , begin, mid, left , right);
    Node v = query(node << 1 | 1, mid + 1 ,end, left ,right);
    return merge(u, v);
}

int Kth(int node, int begin, int end, int k) {
    if (begin == end) {
        return begin;
    }
    int mid = begin + end >> 1;
    if (tree[node << 1].alive < k) { //리프 노드가 아니면
        return Kth(node << 1 | 1 ,mid + 1, end, k-tree[node << 1].alive);
    }
    return Kth(node<<1, begin, mid, k);
}

void init(int N, int mValue[]) {
    for(int i=0; i<MX<<2; i++) {
        tree[i] = Node();
    }
    totalAdd= 0;
    for(int i=0; i<N; i++) {
        update(1, 1, MX, ++totalAdd, mValue[i]);
    }
}

void add(int M, int mValue[]) {
    for(int i=0; i<M; i++) {
        update(1,1,MX,++totalAdd, mValue[i]);
    }
}

void erase(int mFrom, int mTo) {
    for(int x= mTo; x>= mFrom; x--) {
        int del_index = Kth(1,1, MX, x);
        update(1, 1, MX, del_index, INF);
    }
}

int find (int K) {
    int totalAlive = tree[1].alive;
    int virtual_start = totalAlive -K +1;
    int real_start = Kth(1,1,MX, virtual_start);
    Node res = query(1, 1, MX, real_start, MX);
    return res.mx - res.mn;
}