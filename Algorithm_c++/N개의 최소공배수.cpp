//
// Created by ohhyeongseok on 2022/09/29.
//
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int n = 0;
    for(int i=0; i<arr.size(); i++)
    {
        if(n<arr[i]) {
            n = arr[i];
        }
    }
    bool can = true;
    while(1) {
        can = true;
        for(int i=0; i<arr.size(); i++) {
            if(n%arr[i] !=0) {
                can = false;
                n++;
                break;
            }
        }
        if(can) {
            return n;
        }
    }
}