#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;
vector<int> split(string sentense, char separator) {
    vector<int> ans;
    stringstream ss(sentense);
    string tmp;

    while(getline(ss,tmp,separator)) {
        ans.push_back(stoi(tmp));
    }
    return ans;
}

string solution(string s) {
    string answer = "";
    vector<int> vec = split(s, ' ');
    int mn= 2e6;
    int mx = -2e6;
    for(auto a: vec) {
        cout<<a<<" ";
        if(a<mn) {
            mn = a;
        }
        if(a>mx) {
            mx = a;
        }
    }
    answer += to_string(mn)+ " " + to_string(mx);
    return answer;
}
