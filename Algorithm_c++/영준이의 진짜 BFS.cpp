#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#define MAX 100002

using namespace std;

int dp[MAX][20];
int depth[MAX];
long long ans;
int maxLevel;
vector<vector<int>> graph;

int LCA(int a, int b) {
    if(depth[a] != depth[b]) {
        if(depth[a] > depth[b]) { //b가 더 깊게
            swap(a, b);
        }

        for(int i= maxLevel; i>=0; i--) {
            if(depth[a] <= depth[dp[b][i]]) {
                b = dp[b][i];
            }
        }
    }

    int lca = a;
    if (a != b) {
        for(int i = maxLevel; i>=0; i--) {
            if(dp[a][i] != dp[b][i]) {
                a = dp[a][i];
                b = dp[b][i];
            }
            lca = dp[a][i];
        }
    }
    return lca;
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case) {
        int n;
        cin >> n;
        graph.clear();
        graph.resize(n+2);
        depth[1] = 0;
        ans = 0;
        maxLevel = (int)floor(log2(MAX));
        for (int i = 2; i <= n; i++) {
            int parent;
            cin >> parent;
            graph[parent].push_back(i);
            graph[i].push_back(parent);
            depth[i] = depth[parent] + 1;
            dp[i][0] = parent;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= maxLevel; j++) {
                int tmp = dp[i][j - 1];
                dp[i][j] = dp[tmp][j - 1];
            }
        }
        for (int i = 1; i <= n; i++) {
            sort(graph[i].begin(), graph[i].end());
        }

        queue<int> q;
        int pre = 1;
        q.push(1);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            int lca = LCA(cur, pre);
            int tm1 = depth[cur] - depth[lca];
            int tm2 = depth[pre] - depth[lca];
            ans += depth[cur] - depth[lca];
            ans += depth[pre] - depth[lca];
            pre = cur;
            for (int i = 0; i < graph[cur].size(); i++) {
                if (depth[graph[cur][i]] > depth[cur]) {
                    q.push(graph[cur][i]);
                }
            }
        }
        cout<<"#"<<test_case<<" "<<ans <<"\n";
    }
    return 0;
}