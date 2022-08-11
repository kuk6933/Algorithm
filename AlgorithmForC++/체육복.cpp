#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    vector<int>Class(31);
    for(int i=1; i<=30; i++)
    {
        Class[i]=1;
    }
    int lostIndex=0;
    int reserveIndex=0;
    for(int i=1; i<=n; i++)
    {
        if(lostIndex<lost.size()) {
            if (lost[lostIndex] == i) {
                Class[i]--;
                lostIndex++;
            }
        }
        if(reserveIndex<reserve.size()) {
            if (reserve[reserveIndex] == i) {
                Class[i]++;
                reserveIndex++;
            }
        }

    }
    for(int i=1; i<=n; i++)
    {
        if(Class[i]==0)
        {
            if(i>1 && Class[i-1]==2) //앞번호
            {
                Class[i-1]--;
                Class[i]++;
            }
            else if(i<n && Class[i+1]==2) // 뒷번호만
            {
                Class[i+1]--;
                Class[i]++;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(Class[i]>0)
        {
            answer++;
        }
    }
    return answer;
}

int main()
{
    vector<int>lost;
    vector<int>reserve;
    lost.push_back(1);
    reserve.push_back(2);
    int a= solution(2,lost,reserve);
    cout<<a;
}
