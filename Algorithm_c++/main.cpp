#include <iostream>

using namespace std;
#define MAX_NODE 10000

struct Node {
    int data;
    Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
    node[nodeCnt].data = data;
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
    head->next = newNode;
}

void addNode2Tail(int data)
{
    Node* prev = head;
    while(prev->next != nullptr) {
        prev = prev->next;
    }
    Node* newNode = getNode(data);
    newNode->next = nullptr;
    prev->next = newNode;
}

void addNode2Num(int data, int num)
{
    Node* prev = head;
    while(prev->next != nullptr && prev->next->data != num) {
        prev = prev->next;
    }
    if(prev->next != nullptr) {
        Node* newNode = getNode(data);
        newNode->next = prev->next;
        prev->next = newNode;
    }
}

void removeNode(int data)
{
    Node* prev = head;
    while(prev->next != nullptr && prev->next->data != data) {
        prev = prev->next;
    }
    if(prev->next != nullptr) {
       prev->next = prev->next->next;
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




#1
5
4 5
3 4 5
2 3 4 5
2 3 4 5 7
1 2 3 4 5 7
1 2 3 4 5 6 7
1 2 3 4 5 6 7 8
2 3 4 5 6 7 8
1 2 3 4 5 6 7 8 9 10

#2
2 3 5 7

#3
11 77 85 99 111 123 125 204 333
20:17:49 실행을 시작합니다.
20:17:49 성공적으로 컴파일 되었습니다.
20:17:49 Input data가 없으므로 Sample input으로 테스트됩니다.