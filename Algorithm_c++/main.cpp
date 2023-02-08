#include<iostream>
#include <vector>
using namespace std;
#define MAX 1000000000000000001
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    vector<unsigned long long> v;
    unsigned long long i= 1;
    while(1) {
        if( i*(i+1) / 2 >=MAX) {
            break;
        }
        v.push_back(i*(i+1) / 2);
        i++;
    }
    for(test_case = 1; test_case <= T; ++test_case)
    {
        unsigned long long n;
        cin>>n;
        cout<<"1";
    }
    return 0;
}