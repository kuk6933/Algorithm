#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



vector<int> vec;



int main() {
    string str;
    string ans;
    cin>>str;

    int cnt = 0;
    for(int i=0; i<str.size(); i++) {
        if(str[i]=='X') {
            cnt++;
        } else {
            vec.push_back(cnt);
            if(cnt!=0) {
                vec.push_back(0);
            }
            cnt = 0;
        }
    }
    if(cnt !=0) {
        vec.push_back(cnt);
    }

    for(int i=0; i<vec.size(); i++) {
        if (vec[i] % 2 != 0) {
            cout << -1;
            return 0;
        }
        if (vec[i] == 0) {
            ans += ".";
        } else {
            int four = vec[i] / 4;
            vec[i] %= 4;
            for(int j=0; j<four; j++) {
                ans += "AAAA";
            }
            int two = vec[i] / 2;
            for(int j=0; j<two; j++) {
                ans += "BB";
            }
        }
    }
    cout<<ans;
}