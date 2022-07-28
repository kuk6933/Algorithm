#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    answer.resize(id_list.size(),0); //answer 초기화
    map<string,int> id_map; //id의 index를 매칭시키기 위한 map
    map<string,set<string>> reported; //first를 신고한사람을 second set에 넣음

    for(int i=0; i<id_list.size(); i++)
    {
        id_map[id_list[i]]=i; //매칭작업
    }
    string from, to; // from이 to를 report

    for(auto r: report )
    {
        stringstream ss(r); //공백을 두고 신고인과 피신고인이 구별됨
        ss >> from>> to;
        reported[to].insert(from); //신고인을 기준으로 신고한사람을 set에 삽입
    }

    for(auto r: reported)
    {
        if(r.second.size() >=k) //신고한 사람의 수가 k보다 많으면
        {
            for(auto reporter: r.second)
            {
                answer[id_map[reporter]]++; //신고한 사람이 메일 수를 1씩 증가시킴
            }
        }

    }
    return answer;
}
