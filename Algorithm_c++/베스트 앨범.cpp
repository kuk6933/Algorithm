#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int>b) {
    if(a.first > b.first) {
        return true;
    }
    else if(a.first == b.first) {
        if(a.second < b.second) {
            return true;
        }
    }
    return false;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> um;
    for(int i=0; i<genres.size(); i++) {
        um[genres[i]]+=plays[i];
    }

    vector<pair<int, string>> v;
    for(auto elem: um) {
        v.push_back({elem.second, elem.first});
    }
    sort(v.rbegin(), v.rend());
    for(int i=0; i<v.size(); i++) {
        vector<pair<int,int>> tmp;
        for(int j=0; j<genres.size(); j++) {
            if(v[i].second == genres[j]) {
                tmp.push_back({plays[j], j});
            }
        }
        sort(tmp.begin(), tmp.end(), cmp);
        for(int j=0; j<tmp.size(); j++) {
            if(j==2) break;
            answer.push_back(tmp[j].second);
        }
    }
    return answer;
}