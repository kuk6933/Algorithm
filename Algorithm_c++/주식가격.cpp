//
// Created by ohhyeongseok on 2022/10/16.
//
//
// Created by ohhyeongseok on 2022/10/16.
//
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> vec(100000,0);
    vec.resize(prices.size());
    stack<pair<int,int>> stk;
    for(int i=0; i<prices.size(); i++) {
        while(!stk.empty()) { // 떨어진 경우
            if(stk.top().first > prices[i]) {
                vec[stk.top().second] = i - stk.top().second;
                stk.pop();
            } else {
                break;
            }
        }
        stk.push({prices[i], i});
    }
    while(!stk.empty()) {
        vec[stk.top().second] = prices.size() -1  - stk.top().second;
        stk.pop();
    }
    return vec;
}