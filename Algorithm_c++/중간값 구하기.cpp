#include<iostream>
#include <queue>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        long long ans=0;
        int n, first;
        cin>>n>>first;
        priority_queue<int> smaller;
        priority_queue<int, vector<int>,greater<int>> bigger;
        smaller.push(first);
        for(int i=0; i<n; i++) {
            int a,b;
            cin>>a>>b;
            if (a< smaller.top()) {
                smaller.push(a);
            } else {
                bigger.push(a);
            }

            if(smaller.size() < bigger.size()) {
                smaller.push(bigger.top());
                bigger.pop();
            } else if(smaller.size() > bigger.size() + 1) {
                bigger.push(smaller.top());
                smaller.pop();
            }

            if (b< smaller.top()) {
                smaller.push(b);
            } else {
                bigger.push(b);
            }
            if(smaller.size() < bigger.size()) {
                smaller.push(bigger.top());
                bigger.pop();
            } else if(smaller.size() > bigger.size() + 1) {
                bigger.push(smaller.top());
                smaller.pop();
            }
            ans = (ans+ smaller.top())%20171109;
        }
        cout<<"#"<<test_case<<" "<< ans%20171109<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}