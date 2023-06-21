#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iostream>
using namespace std;


set<int> s;

bool isPrime(int a) {
    if(a == 0 || a == 1) return false;
    for(int i=2; i< sqrt(a); i++) {
        if(a % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    sort(numbers.begin(), numbers.end());
    int ans=0;
    do {
        string str = "";
        for(int i=0; i<numbers.size(); i++) {
            str += numbers[i];
            s.insert(stoi(str));
        }
    } while(next_permutation(numbers.begin(), numbers.end()));


    set<int>::iterator iter;
    for(iter = s.begin(); iter!=s.end(); iter++) {
        if(isPrime(*iter)) {
            cout<<*iter<<" ";
            ans++;
        }
    }
    return ans;
}