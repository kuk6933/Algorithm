#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long w, h, k, n, m;
long long cnt= 0;
long long accX,accY;
int y[200001];
int x[200001];

vector<int> yCuts;
vector<long long> xCuts;

void cut() {
    for(int i=0; i< n; i++) {
        int length = y[i] - accY;
        if (length <= k) {
            yCuts.push_back(length);
        }
        h = h - (length);
        accY += length;
    }
    for(int i=0; i< m; i++) {
        int length = x[i]- accX;
        if(length <= k) {
            xCuts.push_back(length);
        }
        w= w - length;
        accX+= length;
    }

    if (h <= k) {
        yCuts.push_back(h);
    }
    if(w <= k) {
        xCuts.push_back(w);
    }
}

void input() {
    cin>>w>>h>>k;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>y[i];
    }
    cin>>m;
    for(int i=0; i<m; i++) {
        cin>>x[i];
    }
}

void parametricSearch() {
    sort(yCuts.begin(), yCuts.end());
    sort(xCuts.begin(), xCuts.end());
    int l,r,mid;
    for(int i=0; i<yCuts.size(); i++) {
        l=0;
        r = xCuts.size()-1;
        while(l <= r) {
            mid = (l + r )/2;
            if(xCuts[mid] * yCuts[i] > k) {
                r = mid - 1;
            } else if( xCuts[mid] * yCuts[i] <= k) {
                l = mid + 1;
            }
        }
        if(xCuts[mid] * yCuts[i] <= k) {
            cnt += mid + 1;
        } else {
            cnt += mid;
        }
    }
}

void solve() {
    input();
    cut();
    parametricSearch();
    cout<<cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
