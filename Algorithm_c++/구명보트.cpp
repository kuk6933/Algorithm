//
// Created by ohhyeongseok on 2022/09/29.
//
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int left = 0;
    int right = people.size() - 1;
    sort(people.begin(), people.end());
    int cnt = 0;
    while(left <= right) {
        if(people[left] + people[right] <= limit) {
            left++;
            right--;
            cnt++;
        } else {
            right--;
            cnt++;
        }
    }
    return cnt;
}