#include <iostream>
#include <string>
#include <stack>

#define MAX 201
using namespace std;
struct Node {
    string content;
    int key;
    Node* left, *right;
};
int node_count = 0;
Node node_pool[MAX];
stack<string> stk;
Node* new_node(int x, string content) {
    node_pool[node_count].key = x;
    node_pool[node_count].content = content;
    node_pool[node_count].left = nullptr;
    node_pool[node_count].right = nullptr;
    return &node_pool[node_count++];
}

void inorder(Node* cur) {
    if(cur->left != nullptr ){
        inorder(cur->left);
    }
    stk.push(cur->content);
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
        while(!stk.empty()) {
            stk.pop();
        }
        bool flag = false;
        int n;
        int num, left, right;
        string content;
        cin>> n;
        for(int i=1; i<=n; i++) {
            cin>>num;
            if(num < n /2) {
                cin>> content >> left >> right;
                Node* newNode = new_node(num, content);
                newNode->left = &node_pool[left-1];
                newNode->left = &node_pool[right-1];
            } else if(num == n/2 && n%2 == 1) {
                cin>> content >> left >> right;
                Node* newNode = new_node(num, content);
                newNode->left = &node_pool[left-1];
                newNode->left = &node_pool[right-1];
            } else if(num == n/2 && n%2 == 0){
                cin>> content >> left >> right;
                Node* newNode = new_node(num, content);
                newNode->left = &node_pool[left-1];
            } else {
                cin>> content >> left >> right;
                Node* newNode = new_node(num, content);
            }
        }
        inorder(&node_pool[0]);
        string pre = stk.top();
        stk.pop();
        while(!stk.empty()) {
            if(pre == "+" || pre == "-" || pre == "*" || pre == "/") {
                if(stk.top() == "+" || stk.top() == "-"|| stk.top() == "*" ||stk.top() == "/") {
                    cout << "#"<< test_case<<" "<< 0 <<"\n";
                    flag = false;
                    break;
                }
            }
            if(pre != "+" && pre != "-" && pre != "*" && pre != "/") {
                if(stk.top() != "+" && stk.top() != "-" && stk.top() != "*" && stk.top() != "/"){
                    flag = false;
                    cout << "#"<< test_case<<" "<<  0 <<"\n";
                    break;
                }
            }
            stk.pop();
        }
        if (flag) {
            cout << "#"<< test_case<<" "<< 1 <<"\n";
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}