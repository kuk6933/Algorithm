#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    int n,k;
    vector<pair<int,int>> belt(201);
    cin>>n>>k;

    int destroyed=0;
    int cnt = 0;
    for(int i=1; i<=2*n; i++) {
        int hp;
        cin>>hp;
        belt[i].first = hp;
    }

    while(1) {

        cnt++;
        pair<int,int> tmp = belt[2*n];
        for(int i= 2*n; i>0; i-- ) {
            belt[i] = belt[i-1];
        }
        belt[1] = tmp;
        belt[n].second =0;
        for(int i= n-1; i>0; i--) {
            if(belt[i].second==1) {
                if(belt[i+1].second ==0 && belt[i+1].first >0) {
                    belt[i].second = 0;
                    belt[i+1].second = 1;
                    belt[i+1].first -= 1;
                    if(belt[i+1].first == 0) destroyed++;
                }
            }
        }
        belt[n].second =0;
        if(belt[1].first > 0) {
            belt[1].second = 1;
            belt[1].first--;
            if(belt[1].first == 0) destroyed++;
        }
        if(destroyed >= k) break;
    }
    cout<<cnt;
}