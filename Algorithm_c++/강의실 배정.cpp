#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int,int>> v;
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        int s,e;
        cin>>s>>e;
        v.push_back({s,e});
    }
    sort(v.begin(), v.end());

    int cnt = 1;
    for(int i=0; i<v.size(); i++) {
        if(pq.empty()) {
            pq.push(v[i].second);
        } else {
            if(pq.top() <= v[i].first) {
                while(1) {
                    if(pq.top() > v[i].first) {
                        break;
                    }
                    pq.pop();
                }
                pq.push(v[i].second);
            } else {
                if(cnt <= pq.size()) {
                    cnt++;
                }
                pq.push(v[i].second);
            }
        }
    }
    cout<<cnt;
}
