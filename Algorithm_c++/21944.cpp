#include <iostream>
#include <string>
#include <set>
using namespace std;

set<int> M[102]; // 난이도 L 1~100 에 문제번호 정렬 저장
int P1[100002];  // 문제 번호가 어떤 난이도인지 저장
int P2[100002]; // 문제 번호가 어떤 유형인지 저장

int n, p, l, g,x;
string s;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--) {
        cin >> p >> l >> g;
        M[l].insert(p);
        P1[p] = l;
        P2[p] = g;
    }
    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "recommend") {
            cin >> g >> x;
            int flag = 0;
            if (x == 1) {
                for (int i = 100; i > 0; i--) {
                    if (M[i].empty()) continue;
                    auto it = prev(M[i].end());
                    while (1) {
                        if (P2[*it] == g) { cout << *it<<'\n'; flag = 1; break; }
                        if (it == M[i].begin()) break;
                        it = prev(it);
                    }
                    if (flag == 1) break;
                }
            }
            else { // x = -1
                for (int i = 1; i <101; i++) {
                    if (M[i].empty()) continue;
                    auto it = M[i].begin();
                    while (1) {
                        if (P2[*it] == g) { cout << *it<<'\n'; flag = 1; break; }
                        if (next(it) == M[i].end()) break;
                        it = next(it);
                    }
                    if (flag == 1) break;
                }
            }
        }
        else if (s == "recommend2") {
            cin >> x;
            if (x == 1) {
                for (int i = 100; i > 0; i--) {
                    if (M[i].empty()) continue;
                    auto it = prev(M[i].end());
                    cout << *it << '\n';
                    break;
                }
            }
            else {
                for (int i = 1; i < 101; i++) {
                    if (M[i].empty()) continue;
                    auto it = M[i].begin();
                    cout << *it << '\n';
                    break;
                }
            }
        }
        else if (s == "recommend3") {
            cin >> x >> l;
            int flag = 0;
            if (x == -1) {
                for (int i = l-1; i > 0; i--) {
                    if (M[i].empty()) continue;
                    auto it = prev(M[i].end());
                    cout << *it << '\n';
                    flag = 1;
                    break;
                }
                if(flag==0) cout << -1 << '\n';
            }
            else {
                for (int i = l; i < 101; i++) {
                    if (M[i].empty()) continue;
                    auto it = M[i].begin();
                    cout << *it << '\n';
                    flag = 1;
                    break;
                }
                if (flag == 0) cout << -1 << '\n';
            }
        }
        else if (s == "add") {
            cin >> p >> l >> g;
            M[l].insert(p);
            P1[p] = l;
            P2[p] = g;
        }
        else if (s == "solved") {
            cin >> p;
            M[P1[p]].erase(p);
        }
    }
}