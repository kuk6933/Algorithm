#define MAX_NODE 10000

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
    node[nodeCnt].data = data;
    node[nodeCnt].prev = nullptr;
    node[nodeCnt].next = nullptr;
    return &node[nodeCnt++];
}

void init()
{
    nodeCnt = 0;
    head = getNode(-1);
}

void addNode2Head(int data)
{
    Node* newNode = getNode(data);
    newNode->next = head->next;
    newNode->prev = head;
    head->next = newNode;
    if (newNode->next != nullptr) {
        newNode->next->prev = newNode;
    }
}

void addNode2Tail(int data)
{
    Node* newNode = getNode(data);
    Node* prev = head;
    while(prev->next != nullptr) {
        prev = prev->next;
    }
    prev->next = newNode;
    newNode->prev = prev;
}

void addNode2Num(int data, int num)
{
    int cnt = 1;
    Node* newNode = getNode(data);
    Node* prev = head;
    while(prev->next != nullptr && cnt != num) {
        prev = prev->next;
        cnt++;
    }
    newNode->next = prev->next;
    newNode->prev = prev;
    if(prev->next != nullptr) {
        prev->next->prev = newNode;
    }
    prev->next = newNode;
}

int findNode(int data)
{
    int cnt = 1;
    Node* prev = head;
    while(prev->next != nullptr && prev->next->data != data) {
        prev = prev->next;
        cnt++;
    }
    return cnt;
}

void removeNode(int data)
{
    Node* prev = head;
    while(prev->next != nullptr && prev->next->data != data) {
        prev = prev->next;
    }
    if(prev->next != nullptr) {
        if(prev->next->next != nullptr) {
            prev->next = prev->next->next;
            prev->next->prev = prev;
        } else {
            prev->next =nullptr;
        }

    }
}

int getList(int output[MAX_NODE])
{
    Node* prev = head;
    int i = 0;
    while(prev->next != nullptr) {
        prev = prev->next;
        output[i] = prev->data;
        i++;
    }
    return i;
}

int getReversedList(int output[MAX_NODE])
{
    Node* prev = head;
    int i = 0;
    while(prev->next != nullptr) {
        prev = prev->next;
    }
    while(prev->prev != nullptr) {
        output[i]=prev->data;
        prev = prev->prev;
        i++;
    }
    return i;
}