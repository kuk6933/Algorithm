#include<iostream>
using namespace std;

int heap[100002];
int cnt = 0;

void swap(int p, int c) {
    int tmp = heap[p];
    heap[p] = heap[c];
    heap[c] = tmp;
}

void insert(int x) {
    heap[++cnt] = x;
    int child = cnt;
    int parent = cnt / 2;
    while(child> 1 && heap[parent] < heap[child]) {
        swap(parent, child);
        child = parent;
        parent = child/2;
    }
}

int pop() {
    if(cnt== 0) {
        return -1;
    }
    int root = heap[1];
    heap[1] = heap[cnt];
    cnt--;
    int parent = 1;
    int child = parent * 2;
    if(child + 1 <= cnt) {
        child = (heap[child] > heap[child+1]) ? child : child+1;
    }
    while(child <= cnt && heap[parent] < heap[child]) {
        swap(parent, child);
        parent = child;
        child = parent * 2;
        if(child + 1 <= cnt) {
            child = (heap[child] > heap[child+1]) ? child : child+1;
        }
    }
    return root;
}
int main(int argc, char** argv) {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        cout<<"#" <<test_case<<" ";
        int n;
        cnt = 0;
        cin>>n;
        for(int i=0; i<n; i++) {
            int cmd;
            cin>>cmd;
            if(cmd == 1) {
                int input;
                cin>>input;
                insert(input);
            } else {
                cout<<pop()<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}