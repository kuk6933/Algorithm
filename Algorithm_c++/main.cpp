#include <iostream>
#include <string>
#include <stack>

#define MAX 201
using namespace std;
int main(int argc, char** argv)
{
    int test_case;
    int T = 10;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        int num, left, right;
        int ans = 1;
        char content;
        cin>> n;
        for(int i=1; i<=n; i++) {
            cin>>num;
            if(num < n /2) {
                cin>> content >> left>>right;
                if(content != '+' && content != '-' && content != '*' && content != '/') {
                    ans = 0;
                }
            } else if(num == n/2 && n%2 == 1) {
                cin>> content >> left>>right;
                if(content != '+' && content != '-' && content != '*' && content != '/') {
                    ans = 0;
                }
            } else if(num == n/2 && n%2 == 0){
                cin>> content >> left;
                if(content != '+' && content != '-' && content != '*' && content != '/') {
                    ans = 0;
                }
            } else {
                cin>> content;
                if(content <'0' || content > '9') {
                    ans = 0;
                }
            }
        }
        cout << "#"<< test_case<<" "<< ans <<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}