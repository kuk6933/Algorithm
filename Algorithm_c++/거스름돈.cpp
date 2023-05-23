#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

string str;
int main() {
    int n;
    cin>>n;

    if(n== 1 || n ==3 ) {
        cout<<-1;
        return 0;
    }
    int cnt=0;
    cnt += n/5;
    n %= 5;
    if(n%2!=0) {
        cnt--;
        n += 5;
        cnt += n/2;
    } else {
        cnt += n/2;
    }

    cout<<cnt;
}