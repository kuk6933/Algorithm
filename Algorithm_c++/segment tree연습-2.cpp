#include<iostream>
#include <vector>
#define MAX 100001
using namespace std;
vector<int>a (MAX);
vector<long long> even_tree(MAX << 2);
vector<long long> odd_tree(MAX << 2);


void init(int idx, int start, int end) {
    if(start == end) {
        if(start % 2 == 0) {
            even_tree[idx] = a[start];
            odd_tree[idx] = -a[start];
        } else {
            even_tree[idx] = -a[start];
            odd_tree[idx] = a[start];
        }
        return;
    }
    int mid = (start + end) / 2;
    int idx1 = idx << 1, idx2 = (idx<<1) + 1;

    init(idx1, start, mid);
    init(idx2, mid+1, end);
    odd_tree[idx] = odd_tree[idx1]+ odd_tree[idx2];
    even_tree[idx] = even_tree[idx1]+ even_tree[idx2];
}

long long getSum_even(int start, int end, int idx, int left, int right) {
    if(left > end  || right < start) {
        return 0;
    }
    if(left <= start && end <= right) {
        return even_tree[idx];
    }
    int mid = (start + end) / 2;
    return getSum_even(start, mid, idx<<1,left, right) + getSum_even(mid+1, end, (idx<<1)+1, left, right);
}

long long getSum_odd(int start, int end, int idx, int left, int right) {
    if(left > end  || right < start) {
        return 0;
    }
    if(left <= start && end <= right) {
        return odd_tree[idx];
    }
    int mid = (start + end) / 2;
    return getSum_odd(start, mid, idx<<1,left, right) + getSum_odd(mid+1, end, (idx<<1)+1, left, right);
}

void update(int start, int end, int idx, int where, int value) {
    if(where < start || where > end) {
        return;
    }
    if(start == end) {
        if(start % 2 == 0) {
            even_tree[idx] = value;
            odd_tree[idx] = -value;
        } else {
            even_tree[idx] = -value;
            odd_tree[idx] = value;
        }
        return;
    }
    int mid = (start + end)/ 2;
    int idx1 = idx<<1;
    int idx2 = (idx<<1) + 1;

    update(start, mid, idx1, where, value);
    update(mid+1, end, idx2, where, value);
    even_tree[idx] = even_tree[idx1] + even_tree[idx2];
    odd_tree[idx] = odd_tree[idx1] + odd_tree[idx2];
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
            if(cmd == 0) {
                int idx, val;
                cin>> idx>>val;
                update(0, n-1, 1, idx, val);
            } else {
                cout<<" ";
                int left, right;
                cin>>left>>right;
                long long ans = 0;
                if (left % 2 == 0) {
                    ans = getSum_even(0, n-1, 1, left, right-1);
                } else {
                    ans = getSum_odd(0, n-1, 1, left, right-1);
                }
                cout<<ans;
            }
        }
        cout<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}