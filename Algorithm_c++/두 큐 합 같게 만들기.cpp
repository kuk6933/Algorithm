#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum= 0;
    long long sum2 = 0;

    queue<int> q, q2;

    for (int num: queue1) {
        sum += num;

        q.push(num);
    }

    for (int num: queue2) {
        sum2 += num;

        q2.push(num);
    }

    int maxIdx = queue1.size() + queue2.size();
    int ans = 0;

    while (ans < maxIdx*2) {
        if (sum == sum2) {
            return ans;
        }
        ans++;

        if (sum < sum2) {
            int cur = q2.front();
            q2.pop();

            q.push(cur);
            sum += cur;
            sum2 -= cur;
        }
        else {
            int cur = q.front();
            q.pop();

            q2.push(cur);
            sum2 += cur;
            sum -= cur;
        }
    }
    return -1;
}
