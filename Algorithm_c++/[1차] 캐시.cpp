//
// Created by ohhyeongseok on 2022/09/30.
//
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    for(int i=0; i<cities.size(); i++) {
        for(int j = 0; j<cities[i].size(); j++) {
            if(cities[i][j]<97) {
                cities[i][j]+=32;
            }
        }
    }
    vector<string> cache;
    int ans = 0;
    for(int i=0; i<cities.size(); i++) {
        bool hit = false;
        if(cache.size() != 0) {
            for(int j=0; j<cache.size(); j++) {
                if(cache[j] == cities[i]) {
                    hit = true;
                    cache.erase(cache.begin() + j);
                    cache.insert(cache.begin(), cities[i]);
                    ans += 1;
                    break;
                }
            }
            if(hit==false) {
                if(cache.size() >= cacheSize){
                    cache.pop_back();
                }
                cache.insert(cache.begin(), cities[i]);
                ans+=5;
            }
        } else {
            if(cacheSize > 0) {
                cache.push_back(cities[i]);
            }
            ans+=5;
        }
    }
    return ans;
}