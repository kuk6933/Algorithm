#include <iostream>
#include<vector>
using namespace std;

int count(string str) {
    int cnt = 0;
    for (int i=0; i<str.size(); i++) {
        if(str[i] == '1') {
            cnt++;
        }
    }
    return cnt;
}

int toBinary(int n) {
    string str;
    while(n != 0) {
        str += (n % 2 == 0 ? "0" : "1");
        n /=2;
    }
    int cnt = count(str);

    return cnt;
}
int solution(int n) {
    int answer = 0;
    int cnt = toBinary(n);

    for (int i=n+1; n <= 1000000; i++) {
        if (cnt == toBinary(i)) {
            answer = i;
            break;
        }
    }
    return answer;
}