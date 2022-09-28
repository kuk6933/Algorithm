//
// Created by ohhyeongseok on 2022/09/28.
//
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<pair<int, int>> v;
    vector<int> ans;
    for (int i = 1; i <= yellow; i++) {
        if (yellow % i == 0) {
            v.push_back({i + 2, yellow / i + 2});
        }
    }
    for (int i = 0; i < v.size(); i++) {
        int a = 2 * v[i].first;
        int b = 2 * v[i].second;
        int result = a + b - 4;
        if (result == brown) {
            if (v[i].first >= v[i].second) {
                ans.push_back(v[i].first);
                ans.push_back(v[i].second);
            } else {
                ans.push_back(v[i].second);
                ans.push_back(v[i].first);
            }
            break;
        }
    }
    return ans;
}
