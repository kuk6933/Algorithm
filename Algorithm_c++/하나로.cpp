//
// Created by ohhyeongseok on 2023/01/29.
//
#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct bridge {
    double cost;
    int a;
    int b;
};

int parent[1001];

bool cmp (bridge a, bridge b) {
    return a.cost < b.cost;
}

double square(double a) {
    return a*a;
}

int findParent(int x) {
    if (parent[x] != x) {
        parent[x] = findParent(parent[x]);
    }
    return parent[x];
}

void uni (int q, int w ) {
    int a = findParent(q);
    int b = findParent(w);
    if(a < b) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        double ans;
        double c;
        ans = 0;
        vector<pair<int,int>> v;
        cin >> n;
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
        int loc[n][2];
        for(int i=0; i<n; i++) {
            cin>>loc[i][0];
        }
        for(int i=0; i<n; i++) {
            cin>>loc[i][1];
        }
        for(int i=0; i<n; i++) {
            v.push_back(make_pair(loc[i][0], loc[i][1]));
        }
        cin>>c;
        vector<bridge> vec;
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                bridge tmp;
                tmp.a = i;
                tmp.b = j;
                tmp.cost = sqrt(square(v[i].first-v[j].first) + square(v[i].second-v[j].second));
                vec.push_back(tmp);
            }
        }
        sort(vec.begin(), vec.end(), cmp);

        for(int i=0; i<vec.size(); i++) {
            if(findParent(vec[i].a) != findParent(vec[i].b)) {
                uni(vec[i].a, vec[i].b);
                ans += c*square(vec[i].cost);
            }
        }
        long long answer = (long long)floor(ans+0.5);
        cout<<"#"<<test_case<<" "<< answer<<"\n";
    }
    return 0;
}