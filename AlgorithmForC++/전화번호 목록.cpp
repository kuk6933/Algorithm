#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i=0; i<phone_book.size()-1; i++) {
        int length = min(phone_book[i].size(), phone_book[i+1].size());
        for(int j = 0; j < length; j++) {
            if(j==phone_book[i].size()-1 && phone_book[i][j] == phone_book[i+1][j]) {
                return false;
            }
            if(phone_book[i][j] != phone_book[i+1][j]){
                break;
            }
        }
    }
    return answer;
}
