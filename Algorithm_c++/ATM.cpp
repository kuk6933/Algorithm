#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

int main() {
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        int a;
        cin>>a;
        vec.push_back(a);
    }

    sort(vec.begin(), vec.end());
    for(int i=1; i<vec.size(); i++) {
        vec[i] += vec[i-1];
    }

    long long cnt=0;
    for(int i=0; i<vec.size(); i++) {
        cnt+= vec[i];
    }
    cout<<cnt;

}