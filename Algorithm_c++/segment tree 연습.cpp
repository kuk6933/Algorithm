#include<iostream>
#include <vector>
#define MAX 100001
#define INF 1000000000
using namespace std;
vector<int>a (MAX);
vector<int> mx(MAX << 2);
vector<int> mn(MAX << 2);

int minVal(int x, int y) { return (x < y) ? x : y; }
int maxVal(int x, int y) { return (x > y) ? x : y; }

void init(int idx, int start, int end) {
    if(start == end) {
        mx[idx] = a[start];
        mn[idx] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    int idx1 = idx << 1, idx2 = (idx<<1) + 1;

    init(idx1, start, mid);
    init(idx2, mid+1, end);

    mx[idx] = maxVal(mx[idx1], mx[idx2]);
    mn[idx] = minVal(mn[idx1], mn[idx2]);
}

int getMax(int start, int end, int idx, int left, int right) {
    if(left > end  || right < start) {
        return 0;
    }
    if(left <= start && end <= right) {
        return mx[idx];
    }
    int mid = (start + end) / 2;
    return maxVal(getMax(start, mid, idx<<1,left, right), getMax(mid+1, end, (idx<<1)+1, left, right));
}

int getMin(int start, int end, int idx, int left, int right) {
    if(left > end  || right < start) {
        return INF;
    }
    if(left <= start && end <= right) {
        return mn[idx];
    }
    int mid = (start + end) / 2;
    return minVal(getMin(start, mid, idx<<1,left, right), getMin(mid+1, end, (idx<<1)+1, left, right));
}

void update(int start, int end, int idx, int where, int value) {
    if(where < start || where > end) {
        return;
    }
    if(start == end) {
        mx[idx] = value;
        mn[idx] = value;
        return;
    }
    int mid = (start + end)/ 2;
    int idx1 = idx<<1;
    int idx2 = (idx<<1) + 1;

    update(start, mid, idx1, where, value);
    update(mid+1, end, idx2, where, value);

    mx[idx] = maxVal(mx[idx1], mx[idx2]);
    mn[idx] = minVal(mn[idx1], mn[idx2]);
}
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cout<<"#"<<test_case;
        int n,q;
        cin>>n>>q;
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        init(1, 0, n-1);
        for(int i=0; i<q; i++) {
            int cmd;
            cin>>cmd;
            switch (cmd) {
                case 0:
                    int idx, val;
                    cin>> idx>>val;
                    update(0, n-1, 1, idx, val);
                    break;
                case 1:
                    cout<<" ";
                    int left, right;
                    cin>>left>>right;
                    int mx = getMax(0, n-1, 1, left, right-1);
                    int mn = getMin(0, n-1, 1, left, right-1);
                    cout<<mx - mn;
            }
        }
        cout<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}