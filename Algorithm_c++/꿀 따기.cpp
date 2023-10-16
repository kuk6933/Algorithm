// 백준 21758 : 꿀 따기
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> map(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> map[i];
        total += map[i];
    }

    int ans = 0;
    int dup; // 두 벌이 중복해서 가져가는 꿀의 양

    // 벌 - 꿀 - 벌
    for (int i = 1; i < n; i++) {
        dup = map[i];
        ans = max(ans, total - map[0] - map[n - 1] + dup);
    }

    // 벌 - 벌 - 꿀
    dup = map[n - 1];
    for (int i = n - 2; i > 0; i--) {
        ans = max(ans, total - map[0] - map[i] + dup);
        dup += map[i];
    }

    // 꿀 - 벌 - 벌
    dup = map[0];
    for (int i = 1; i < n - 1; i++) {
        ans = max(ans, total - map[n - 1] - map[i] + dup);
        dup += map[i];
    }

    cout << ans << '\n';
}