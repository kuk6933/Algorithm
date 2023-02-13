#include <map>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

map<int,int> m ;
vector<vector<pair<int,int>>> vec(602, vector<pair<int,int>>());
vector<vector<pair<int,int>>> rvec(602, vector<pair<int,int>>());
int cnt = 1;

int init(int N, int sCity[], int eCity[], int mCost[]) {
    cnt = 1;
    m.clear();
    for(int i=0; i<602; i++) {
        vec[i].clear();
        rvec[i].clear();
    }
    for(int i=0; i<N; i++) {
        if(m[sCity[i]] == 0) {
            m[sCity[i]] = cnt++;
        }
        if(m[eCity[i]] == 0) {
            m[eCity[i]] = cnt++;
        }
        vec[m[sCity[i]]].emplace_back(make_pair(mCost[i], m[eCity[i]]));
        rvec[m[eCity[i]]].emplace_back(make_pair(mCost[i], m[sCity[i]]));
    }
    cnt--;
    return cnt;
}

void add(int sCity, int eCity, int mCost) {
    vec[m[sCity]].emplace_back(make_pair(mCost, m[eCity]));
    rvec[m[eCity]].emplace_back(make_pair(mCost, m[sCity]));
}

int dijkstra(int v) {
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0, v));
    vector<int> result(602);
    for(int i =1; i<=cnt; i++) {
        result[i] = INF;
    }
    result[v] = 0;
    while(!pq.empty()) {
        pair<int,int> cur = pq.top();
        pq.pop();
        int sz = vec[cur.second].size();
        for (int i = 0; i < sz; i++) {
            int next = vec[cur.second][i].second;
            int nCost = vec[cur.second][i].first;
            if(next == v) {
                continue;
            }
            if (result[next] > nCost + cur.first) {
                result[next] = nCost + cur.first;
                pq.push(make_pair(result[next], next));
            }
        }
    }
    int res = 0;
    for(int i = 0; i<=cnt; i++) {
        res += result[i];
    }
    return res;
}
int rdijkstra(int v) {
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0, v));
    vector<int> result(601);
    for(int i =1; i<=cnt; i++) {
        result[i] = INF;
    }
    result[v] = 0;
    while(!pq.empty()) {
        pair<int,int> cur = pq.top();
        pq.pop();
        int sz = rvec[cur.second].size();
        for (int i = 0; i < sz; i++) {
            int next = rvec[cur.second][i].second;
            int nCost = rvec[cur.second][i].first;
            if(next == v) {
                continue;
            }
            if (result[next] > nCost + cur.first) {
                result[next] = nCost + cur.first;
                pq.push(make_pair(result[next], next));
            }
        }
    }
    int res = 0;
    for(int i = 1; i<=cnt; i++) {
        res += result[i];
    }
    return res;
}
int cost(int mHub) {
    int ans =0;
    ans += dijkstra(m[mHub]);
    ans += rdijkstra(m[mHub]);
    return ans;
}