#include<iostream>
#include <vector>
#include <stack>
#define MAX 10005

using namespace std;
struct Node {
    int key;
    int idx;
    int parent;
    int child[2];
};

Node tree[MAX];
int v,e,l,r,ans;

void initialize() {
    ans = 0;
    for(int i=1; i<=v; i++) {
        tree[i].key = 0;
        tree[i].idx= 0 ;
        tree[i].parent = 1;
    }
}

void findParent(int n,stack<int> &stk) {
    while(n != 1) {
        stk.push(n);
        n = tree[n].parent;
    }
    stk.push(1);
}
void count(int n) {
    ans++;
    for(int i=0; i<tree[n].idx; i++) {
        count(tree[n].child[i]);
    }
}



int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        initialize();
        cin>>v>>e>>l>>r;
        for(int i=0;i<e; i++) {
            int p,c;
            cin>> p>>c;
            tree[p].child[tree[p].idx++] = c;
            tree[c].parent = p;
        }


        stack<int> stk1;
        stack<int> stk2;
        findParent(l,stk1);
        findParent(r, stk2);
        int root= 1;

        for(int i=0; i<min(stk1.size(), stk2.size()); i++) {
            int a, b;
            a= stk1.top(); stk1.pop();
            b = stk2.top(); stk2.pop();
            if(a ==b ) {
                root = a;
            } else {
                break;
            }
        }
        count(root);
        cout<<"#"<<test_case<<" "<< root <<" "<<ans<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}