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
        int num[11];
        int n;
        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>num[i];
        }
        int k;
        cin>>k;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push(make_pair(0, k));
        while(pq.top().second != 0) {
            auto cur = pq.top(); pq.pop();
            pq.push(make_pair(cur.first + cur.second, 0));
            for(int i=0; i<n; i++) {
                pq.push(make_pair(cur.first + cur.second % num[i], cur.second / num[i]));
            }
        }
        cout<<"#"<<test_case<<" "<<pq.top().first<<"\n";
    }
    return 0;
}