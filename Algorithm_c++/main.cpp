#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    long long ans=0;
    cin>>n;
    vector<int> v;
    int num;
    for(int i=0; i <n; i++) {
        cin>>num;
        v.push_back(num);
    }
    int b,c;
    cin>>b>>c;
    for(int i=0; i<v.size(); i++) {
        v[i]-= b;
        ans++;
        if(v[i]> 0) {
            if(v[i] <= c) {
                ans++;
            } else {
                ans += v[i]/ c;
                if(v[i]%c >0) {
                    ans++;
                }
            }
        }
    }
    cout<<ans;
}
