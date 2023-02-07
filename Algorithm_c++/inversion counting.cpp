#include<iostream>
using namespace std;
#define MAX 100001

int arr[MAX];
int arr2[MAX];
long long ans = 0;
void merge(int left,int right) {
    int mid = (left + right) / 2;
    int i = left;
    int j = mid+1;
    int k = left;
    while(i<=mid && j <= right) {
        if(arr[i] <= arr[j]) {
            arr2[k++] = arr[i++];
        } else {
            arr2[k++] = arr[j++];
            ans+= mid - i + 1;
        }
    }
    int tmp = i > mid ? j : i;
    while(k <= right) {
        arr2[k++] = arr[tmp++];
    }
    for(int i=left; i<=right; i++) {
        arr[i] = arr2[i];
    }
}

void partition(int left, int right) {

    if(left >= right) return;
    int mid = (left + right) / 2;
    partition(left, mid);
    partition(mid+1, right);
    merge(left, right);
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        ans = 0;
        int n;
        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        partition(0, n-1);
        cout<<"#"<<test_case<<" "<<ans<<"\n";
    }
    return 0;
}