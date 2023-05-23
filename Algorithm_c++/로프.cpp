#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

int main() {
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        int w;
        cin>>w;
        vec.push_back(w);
    }
    sort(vec.begin(), vec.end());
    int ans = 0;
    for(int i=0; i<vec.size(); i++) {
        if(ans < vec[i]* (vec.size()-i)) {
            ans = vec[i] * (vec.size() - i);
        }
    }
    cout<<ans;

}