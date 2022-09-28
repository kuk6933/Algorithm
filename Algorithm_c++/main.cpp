#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;


vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<int> people(11) {1};
    char pre = words[0][words[0].size()-1];
    set<string> s;
    set<string>::iterator iter;
    s.insert(words[0]);
    people[1] = 1;
    int cnt = 2;
    for(int i=1; i<words.size(); i++) {
        if (cnt > n) {
            cnt = 1;
        }
        iter = s.find(words[i]);
        if(iter != s.end() ||
           words[i][0] != pre) {
            answer.push_back(cnt);
            answer.push_back(people[cnt]);
            return answer;
        }
        s.insert(words[i]);
        people[cnt]++;
        cnt++;
        pre = words[i][words[i].size()-1];
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}
int main() {
    vector<string> words = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};
    vector<int> a = solution(3,words);

    cout<< a[0] << " " <<a[1];
}