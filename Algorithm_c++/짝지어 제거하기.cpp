//
// Created by ohhyeongseok on 2022/09/29.
//
#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> stk;
    stk.push(s[0]);
    for(int i=1; i<s.size(); i++ ) {
        if(!stk.empty() && s[i] == stk.top()) {
            stk.pop();
        } else {
            stk.push(s[i]);
        }
    }
    if(stk.empty()) {
        return 1;
    } else {
        return 0;
    }
}