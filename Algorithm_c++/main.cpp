#include<iostream>
using namespace std;

#define MAX 101

struct Node {
    int key;
    char alpha;
    Node *left, *right;
};

int node_count = 0;
Node node_pool[MAX];

Node* new_node(int x, char alpha) {
    node_pool[node_count].key = x;
    node_pool[node_count].alpha = alpha;
    node_pool[node_count].left = nullptr;
    node_pool[node_count].right = nullptr;
    return &node_pool[node_count++];
}
void inorder(Node* cur) {
    if(cur->left != nullptr) {
        inorder(cur->left);
    }
    cout<<cur->alpha;
    if(cur->right != nullptr) {
        inorder(cur->right);
    }
}
int main(int argc, char** argv)
{
    int test_case;
    int T = 10;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        node_count = 0;
        int n;
        cin>>n;
        int num,left,right;
        char alpha;
        for(int i=1; i<=n; i++) {
            cin>>num;
            if(i<n / 2) { // 자식 둘
                cin>> alpha >> left >> right;
                Node* node = new_node(num, alpha);
                node->left = &node_pool[left-1];
                node->right = &node_pool[right-1];
            } else if (i == n / 2 && n % 2 == 1) { // 자식 둘
                cin >> alpha >> left >> right;
                Node* node = new_node(num, alpha);
                node->left = &node_pool[left-1];
                node->right = &node_pool[right-1];
            } else if (i == n / 2 && n % 2 == 0) { // 자식 하나
                cin>> alpha >> left;
                Node* node = new_node(num, alpha);
                node->left = &node_pool[left-1];
            } else { // 자식 X
                cin >> alpha;
                Node* node = new_node(num, alpha);
            }
        }
        cout<<"#"<< test_case<<" ";
        inorder(&node_pool[0]);
        cout<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}