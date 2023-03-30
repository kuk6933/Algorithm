#include <iostream>
#define MAX 200

using namespace std;

int arr[MAX] = {1, 2, 3, 4, 5, 6 ,7 ,8, 9};
int segmentTree[MAX*4];

int make_segmentTree(int node, int start, int end) {
    if(start == end) return segmentTree[node] = arr[start];

    int mid = (start + end) /2;
    int left_result = make_segmentTree(node*2, start, mid);
    int right_result = make_segmentTree(node * 2 + 1, mid+1, end);
    return segmentTree[node] = left_result + right_result;
}

int sum(int node, int start, int end, int left, int right) { //node: 현재 위치, start, end: 현재 노드의 범위, left, right: 찾고자 하는 범위
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) return segmentTree[node];

    int mid = (left + right) / 2;
    int left_result = sum(node*2, start, mid, left, right);
    int right_result = sum(node*2+1, mid+1, end, left, right);

    return left_result + right_result;
}

void update(int node, int start, int end, int idx, int diff) {
    if(idx > end || idx < start) return;
    segmentTree[node] += diff;

    if(start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, start, mid, idx, diff);
    }
}

int main() {
    int n;
    cin>>n;
    make_segmentTree(1, 0, n - 1);
    int Index = 1;
    int Value = 5;
    int Diff = Value - arr[Index];
    arr[Index] = Value;
    update(1, 0, n - 1, Index, Diff);
}