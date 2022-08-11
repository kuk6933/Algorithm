#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;
bool cmp(pair<double,int> a, pair<double,int> b) {
    if(a.first != b.first) {
        return a.first > b.first;
    }
    else {
        return a.second < b.second;
    }
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> numberOfArrivedPersons(501);
    vector<int> blockedState(501);
    vector<pair<double,int>> failRate;
    for(int i=0; i<stages.size(); i++) {
        for(int j=1; j<stages[i]; j++) {
            numberOfArrivedPersons[j]++;
        }
        blockedState[stages[i]]++;
    }
    failRate.resize(N);
    for(int i=1; i<=N; i++) {
        if(blockedState[i] != 0) {
            failRate[i-1] = make_pair(blockedState[i] / double(numberOfArrivedPersons[i]), i);
        }
        else {
            failRate[i-1] = make_pair(0, i);
        }
    }
    sort(failRate.begin(), failRate.end(), cmp);
    answer.resize(N);
    for(int i=0; i<N; i++) {
        answer[i] = failRate[i].second;
        cout<< failRate[i].first<<" ";
    }
    cout<<"\n";
    return answer;
}
