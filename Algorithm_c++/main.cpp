//
// Created by ohhyeongseok on 2022/10/28.
//
#include <string>
#include <set>
#include <vector>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<vector<int>> sorted;
    vector<int> ans;
    set<int> t;
    string str = "";
    vector<int> v;
    for(int i= 1; i<s.size()-1; i++) {
        if(s[i] == '{') {
            v.clear();
        } else if (s[i] == '}') {
            sorted.push_back(v);
        } else if (s[i] == ',') {
            continue;
        } else { // 숫자
            str += s[i];
            if(s[i+1] == ',' || s[i+1] == '}') {
                v.push_back(stoi(str));
                str = "";
            }
        }
    }
    sort(sorted.begin(), sorted.end(), cmp);

    return ans;
}
