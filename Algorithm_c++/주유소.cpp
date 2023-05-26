#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> road;
vector<long long> price;

int main() {
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++) {
        long long distance;
        cin>>distance;
        road.push_back(distance);
    }
    for(int i=0; i<n; i++) {
        long long p;
        cin>>p;
        price.push_back(p);
    }
    long long count = 0;
    long long cheap = price[0];
    for(int i=0; i<n; i++) {
        if(price[i] < cheap) {
            cheap = price[i];
        }
        count += cheap * road[i];
    }
    cout<<count;
}