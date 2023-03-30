#include <algorithm>
#include <cassert>


using namespace std;
class MaxHeap {
#define parent (i >> 1)
#define left ( i << 1)
#define right (i << 1 | 1)

    static constexpr size_t MAX_N = 100000;
    size_t size;
    int data[MAX_N + 1];
    MaxHeap() = default;

    void push(int x) {
        data[++size] = x;
        for(int i = size; parent != 0 && data[parent] < data[i]; i >>= 1 ) {
            swap(data[parent], data[i]);
        }
    }

    size_t top() {
        assert(size != 0);
        return data[1];
    }

    void pop() {
        assert(size != 0);
        data[1] = data[size--];
        for(int i = 1; left <= size;) {
            if(left == size || data[left] > data[right]) {
                if(data[i] < data[left]) {
                    swap(data[i], data[left]);
                    i = left;
                } else {
                    break;
                }
            } else {
                if(data[i] < data[right]) {
                    swap(data[i], data[right]);
                    i = right;
                } else {
                     break;
                }
            }
        }
    }

};