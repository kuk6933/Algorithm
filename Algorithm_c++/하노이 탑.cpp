//
// Created by ohhyeongseok on 2022/11/22.
//
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> ans;

void hanoi(int n, int from, int by, int to) {
    if (n == 1 ) {
        ans.push_back({from, to});
    } else {
        hanoi(n-1,from,to,by);
        ans.push_back({from, to});
        hanoi(n-1,by,from,to);
    }
}
vector<vector<int>> solution(int n) {
    hanoi(n, 1, 2, 3);
    return ans;
}
