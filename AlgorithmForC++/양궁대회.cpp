//
// Created by ohhyeongseok on 2022/09/22.
//
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> apeach;
vector<int> lion;
vector<int> maxRes; // 정답 배열
int maxDiff = 0; // 최대 점수차

// 깊이 / 어피치 점수/ 라이언 점수 /사용한 화살의 개수
void dfs(int dpt, int asc, int lsc, int n){
    if(dpt==11) {
        if(lsc <= asc) return;
        lion[10] += N-n; // 남은 화살 0점에 몰아주기
        if(lsc - asc > maxDiff) {
            maxRes = lion;
            maxDiff = lsc - asc;
        } else if(lsc - asc == maxDiff) { // 점수가 같은 경우, 낮은 점수에 많이 맞힌 경우가 정답
            for(int i=10; i>=0; i--){
                if(lion[i]==maxRes[i]) continue;
                else {
                    if(lion[i] > maxRes[i]) {
                        maxRes = lion; //통째로넣음
                    }
                    break;
                }
            }
        }
        return;
    }

    int next = apeach[dpt] + 1;
    if (next + n <= N) {
        int nasc = asc;
        int nlsc = lsc + 10 - dpt;
        if(next != 1 ) {
            nasc -= (10 - dpt);
        }
        lion.push_back(next);
        dfs(dpt+1, nasc, nlsc, next+n);
        lion.pop_back();
    }
    lion.push_back(0);
    dfs(dpt+1, asc, lsc, n);
    lion.pop_back();
}

vector<int> solution(int n, vector<int> info) {
    N = n;
    apeach = info;

    int total = 0; // 어피치의 초기 점수
    for(int i=0; i<info.size(); i++){
        if(info[i]) {
            total += (10-i);
        }
    }

    dfs(0, total, 0, 0);

    // maxDiff가 0인 경우 업데이트가 되지 않았으므로 어떠한 방법으로도 어피치의 점수를 넘길 수 없음
    if(maxDiff==0) maxRes.push_back(-1);
    return maxRes;
}

//참고 : https://barbera.tistory.com/58