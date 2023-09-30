#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int k;
int n;
vector<int> v;
vector<int> tree[10];
void findCenter(int depth, int start, int end) {
    if(start >= end ){
        return;
    }
    int mid = (start + end) / 2;
    tree[depth].push_back(v[mid]);
    findCenter(depth + 1, start, mid);
    findCenter(depth + 1, mid+1, end);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>k;
    n = 1 << k;
    for(int i=1; i<n; i++) {
        int num;
        cin>>num;
        v.push_back(num);
    }
    findCenter(0, 0, n-1);
    for(int i=0; i<k; i++) {
        for(int j=0; j<tree[i].size(); j++) {
            cout<<tree[i][j]<<" ";
        }
        cout<<"\n";
    }
}