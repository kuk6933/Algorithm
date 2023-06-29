#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;

int v[101][101];
bool visited[101];
int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    for(int i=0; i<wires.size(); i++) {
        v[wires[i][0]][wires[i][1]] = 1;
        v[wires[i][1]][wires[i][0]] = 1;
    }

    for(int i=0; i<wires.size(); i++) {
        for(int j=1; j<=n; j++) {
            visited[j] = false;
        }
        vector<int> tmp;
        v[wires[i][0]][wires[i][1]] = 0;
        v[wires[i][1]][wires[i][0]] = 0;
        for(int j=1; j<=n; j++) {
            if(visited[j] == false) {
                int count = 0;
                queue<int> q;
                q.push(j);
                while(!q.empty()) {
                    int cur = q.front(); q.pop();
                    visited[cur] = true;
                    count++;
                    for(int k=1; k<=n; k++) {
                        if(v[cur][k] == 1 && visited[k] == false) {
                            q.push(k);
                        }
                    }
                }
                tmp.push_back(count);
            }
        }
        cout<<tmp[0] <<" "<<tmp[1]<<" ";
        if (abs(tmp[0] - tmp[1]) < answer) {
            answer = abs(tmp[0] - tmp[1]);
        }
        v[wires[i][0]][wires[i][1]] = 1;
        v[wires[i][1]][wires[i][0]] = 1;
    }
    return answer;
}