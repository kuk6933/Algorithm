//
// Created by ohhyeongseok on 2022/10/12.
//

#include <string>
#include <vector>
#include <algorithm>

bool cmp(int a, int b) {
    return a > b;
}
using namespace std;

int solution(vector<int> scoville, int K) {
    int cnt = 0;
    while (1) {
        if(scoville.size() < 2) {
            if(scoville[scoville.size()-1] < K) {
                cnt = -1;
            }
            break;
        }
        sort(scoville.begin(), scoville.end(), cmp);
        if (scoville[scoville.size() - 1] < K) {
            cnt++;
            int a = scoville[scoville.size() - 1];
            int b = scoville[scoville.size() - 2];
            scoville.pop_back();
            scoville.pop_back();
            a = a + 2 * b;
            scoville.push_back(a);
        } else {
            break;
        }
    }
    return cnt;
}