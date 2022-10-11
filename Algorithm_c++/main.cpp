#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<int> q;
    q.push(numbers[0]);
    q.push(-numbers[0]);
    int cnt = 0;

    for(int i=1; i<numbers.size(); i++) {
        int qsz = q.size();
        for(int j=0; j<qsz; j++) {
            int cur = q.front();
            q.pop();
            q.push(cur + numbers[i]);
            q.push(cur - numbers[i]);
        }
    }

    int qz = q.size();
    for (int i=0; i<qz; i++)
    {
        if (q.front() == target) {
            cnt++;
        }
        q.pop();
    }
    return cnt;
}
int main() {
    int a = solution({1, 1, 1, 1, 1}, 3);
    cout<< a;
}