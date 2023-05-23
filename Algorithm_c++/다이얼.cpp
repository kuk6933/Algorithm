#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

string str;
int main() {
    cin>>str;
    int cnt=0;

    for(int i=0; i<str.size(); i++) {
        int arr[26]= {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
        cnt += arr[str[i]-'A'];
    }
    cout<<cnt;
}