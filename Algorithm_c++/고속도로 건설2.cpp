#include<iostream>
#include <queue>
#include <vector>
using namespace std;
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n,m;
        int ans = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<vector<pair<int,int>>> v;
        cin>>n>>m;
        bool visited[50002] = {false};
        v.resize(n+1);
        for(int i=0; i<m; i++) {
            int c1, c2, cost;
            cin>>c1>>c2>>cost;
            v[c1].push_back(make_pair(cost, c2));
            v[c2].push_back(make_pair(cost,c1));
        }

        for(int i=0; i<v[1].size(); i++) {
            pq.push(make_pair(v[1][i].first,v[1][i].second));
        }
        visited[1] = true;
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            if(visited[cur.second]) {
                continue;
            }
            visited[cur.second] = true;
            ans += cur.first;
            for(int i=0; i<v[cur.second].size(); i++) {
                if(!visited[v[cur.second][i].second]){
                    pq.push(make_pair(v[cur.second][i].first, v[cur.second][i].second));
                }
            }
        }
        cout<<"#"<<test_case<<" "<<ans<<"\n";
    }
    return 0;
}