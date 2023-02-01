
using namespace std;
struct Node {
    Node() {
    }
    int uID;
    int income;
    Node(int uuID, int uincome) {
        uID = uuID;
        income = uincome;
    }
};
Node heap[100001];
int cnt = 0;

void swap(int p, int c) {
    Node tmp = heap[p];
    heap[p] = heap[c];
    heap[c]= tmp;
}

void init() {
    cnt = 0;
}
void addUser(int uID, int income)
{
    heap[++cnt] = Node(uID, income);
    int child = cnt;
    int parent = child / 2;
    while(child > 1 && heap[parent].income <= heap[child].income) {
        if(heap[parent].income == heap[child].income && heap[parent].uID < heap[child].uID) {
            break;
        }
        swap(parent ,child);
        child = parent;
        parent = child / 2;
    }
}

Node pop() {

    Node ans = heap[1];
    swap(1, cnt);
    cnt--;

    int parent = 1;
    int child = parent * 2;
    if(child +1 <= cnt) {
        if(heap[child].income == heap[child+1].income) {
            child = (heap[child].uID < heap[child+1].uID) ? child : child+1;
        } else {
            child = (heap[child].income > heap[child+1].income) ? child : child+1;
        }
    }
    while(child <= cnt && heap[parent].income <= heap[child].income) {
        if(heap[parent].income == heap[child].income && heap[parent].uID < heap[child].uID) {
            break;
        }
        swap(parent, child);
        parent = child;
        child = child * 2;
        if(child + 1 <= cnt) {
            if(heap[child].income == heap[child+1].income) {
                child = (heap[child].uID < heap[child+1].uID) ? child : child+1;
            } else {
                child = (heap[child].income > heap[child+1].income) ? child : child+1;
            }
        }
    }
    return ans;
}

int getTop10(int result[10])
{

    Node arr[10];
    int sz = (cnt > 10) ? 10 : cnt;
    for(int i=0; i<sz; i++) {
        Node tmp = pop();
        result[i] = tmp.uID;
        arr[i]= tmp;
        if(cnt==0) {
            break;
        }
    }
    for(int i=0; i<sz; i++) {
        addUser(arr[i].uID, arr[i].income);
    }
    return sz;
}