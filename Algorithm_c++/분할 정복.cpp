#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[65][65];
vector<string> str;
string s;
void input() {
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        str.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            map[i][j] = str[i][j]-'0';
        }
    }
}
void conquer(int r, int c, int sz) {

    int criteria = map[r][c];
    bool flag = true;
    for(int i= r; i < r+sz; i++) {
        for(int j=c; j< c+sz; j++) {
            if(criteria != map[i][j]) {
                flag = false;
                break;
            }
        }
        if(!flag) {
            break;
        }
    }
    if(flag) {
        s += to_string(criteria);
    } else {
        s += "(";
        conquer(r,c,sz/2);
        conquer(r,c+sz/2,sz/2);
        conquer(r+sz/2,c,sz/2);
        conquer(r+sz/2,c+sz/2,sz/2);
        s+=")";
    }
}
void solve() {
    input();

    conquer(0,0,n);
    cout<<s;
}
int main() {
    solve();
}