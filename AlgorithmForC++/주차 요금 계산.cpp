#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> split(string sentense, char separator) {
    vector<string> ans;
    stringstream ss(sentense);
    string tmp;

    while(getline(ss,tmp, separator)) {
        ans.push_back(tmp);
    }
    return ans;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> dict;
    map<string,vector<string>>:: iterator iter;
    for(auto i: records) {
        vector<string> s = split(i, ' ');
        if(dict.find(s[1]) != dict.end()) {// 이미 있는 친구들
            if(dict[s[1]][0] != "0") {
                if(s[2] == "IN") {
                    dict[s[1]][0] = s[0];
                } else {
                    int h,m;
                    h = stoi(s[0].substr(0,2)) - stoi(dict[s[1]][0].substr(0,2)) ;
                    m = stoi(s[0].substr(3,2)) - stoi(dict[s[1]][0].substr(3,2));
                    if (m < 0) {
                        m += 60;
                        h-=1;
                    }
                    m += h* 60;
                    int curm = stoi(dict[s[1]][1]);
                    curm += m;
                    dict[s[1]][1] = to_string(curm);
                    dict[s[1]][0] = "0";
                }
            } else {
                dict[s[1]][0] = s[0];
            }
        } else {
            vector<string> v; // 처음 들어온 친구
            v.push_back(s[0]);
            v.push_back("0");
            dict[s[1]] = v;
        }
    }// 모두 처리함
    for(iter = dict.begin(); iter!=dict.end(); iter++) {
        if(iter->second[0] != "0") {
            int h = 23 - stoi(iter->second[0].substr(0,2));
            int m = 59 - stoi(iter->second[0].substr(3,2));
            m += h * 60;
            int curm = stoi(iter->second[1]);
            curm += m;
            iter->second[1] = to_string(curm);
        }
    }
    for(iter = dict.begin(); iter!=dict.end(); iter++) {
        if ( stoi(iter->second[1]) <= fees[0]) {
            answer.push_back(fees[1]);
        } else { //기본요금 + (시간 - 기본시간)/ 단위시간 * 단위요금
            int fee = fees[1] + ceil((stod(iter->second[1]) - fees[0]) / fees[2]) * fees[3];
            answer.push_back(fee);
        }
    }
    return answer;
}