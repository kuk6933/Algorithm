#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int N, K, input, ans;
priority_queue<int, vector<int>, greater<>> pq;
vector<int> v;
unordered_set<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    cin>>K;
    for(int n=0; n<N; n++) {
        cin>>input;
        s.insert(input);
    }
    for(auto cur: s) {
        v.push_back(cur);
    }
    sort(v.begin(), v.end());
    for(int i=1; i<v.size(); i++) {
        pq.push(v[i]-v[i-1]);
    }

    for(int i=0; i<v.size()-K; i++) {
        if(pq.empty()) {
            break;
        }
        ans += pq.top();
        pq.pop();
    }
    cout<<ans;
}