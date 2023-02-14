#include <vector>
#define MAX 200000
using namespace std;

vector<int> ints(MAX);
vector<int> maxSeg(MAX*4);
vector<int> minSeg(MAX*4);

void init(int start, int end, int node) {
    if(start == end){
        maxSeg[start] = ints[start];
        minSeg[start] = ints[start];
        return;
    }
    int mid = (start + end) / 2;
    init(start ,mid, node * 2) ;
    init(mid+1, end, node * 2 + 1);
    maxSeg[node] = max(maxSeg[node*2], maxSeg[node*2 + 1]);
    minSeg[node] = min(minSeg[node*2], minSeg[node*2 + 1]);
}

int getMax(int start, int end, int node, int left, int right) {
    if(left > end || right < start ){
        return 0;
    }
    if(left >= start && right <= end) {
        return maxSeg[node];
    }
    int mid = (start + end) / 2;
    return max(getMax(start, mid, node*2, left, right), getMax(mid + 1, end, node * 2 + 1, left, right));
}

int getMin(int start, int end, int node, int left, int right) {
    if(left > end || right < start ){
        return MAX;
    }
    if(left >= start && right <= end ) {
        return minSeg[node];
    }
    int mid = (start + end) / 2;
    return min(getMin(start, mid, node*2, left, right), getMin(mid + 1, end, node * 2 + 1, left, right));
}


void init(int n, int mValue[]) {

}

void add(int M, int mValue[]) {

}

void erase(int mFrom, int mTo) {

}

int find(int k) {

}

