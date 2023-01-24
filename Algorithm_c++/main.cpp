#include <iostream>
#include <string>
#include <stack>
#include <queue>

#define MAX 1002
using namespace std;
struct Node {
    string content;
    int key;
    Node* left, *right;
};

int node_count = 0;
Node node_pool[MAX];
stack<int> stk;
queue<string> q;
Node* new_node(int x, string content) {
    node_pool[node_count].key = x;
    node_pool[node_count].content = content;
    node_pool[node_count].left = nullptr;
    node_pool[node_count].right = nullptr;
    return &node_pool[node_count++];
}

void postorder(Node* cur) {
    if(cur->left != nullptr ){
        postorder(cur->left);
    }
    if(cur->right != nullptr) {
        postorder(cur->right);
    }
    q.push(cur->content);
}
int main(int argc, char** argv)
{
    int test_case;
    int T = 10;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        node_count = 0;
        int n, num, left, right;
        string st;
        cin>>n;

        for(int i=1; i<=n; i++) {
            cin>>num;
            cin>>st;
            if(st == "+" || st == "-" ||st == "*" ||st == "/" ) {
                cin>>left >>right;
                Node* newNode = new_node(num, st);
                newNode->left = &node_pool[left-1];
                newNode->right = &node_pool[right-1];
            } else {
                Node* newnode = new_node(num,st);
            }
        }

        postorder(&node_pool[0]);
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            if(cur == "+" ||cur == "-" ||cur == "*" ||cur == "/") {
                int r= stk.top();
                stk.pop();
                int l = stk.top();
                stk.pop();
                int tmp;
                if(cur == "+") {
                    tmp = l + r;
                }
                if(cur == "-") {
                    tmp = l- r;
                }
                if(cur == "*") {
                    tmp = l * r;
                }
                if(cur == "/") {
                    tmp = l / r;
                }
                stk.push(tmp);
            } else {
                stk.push(stoi(cur));
            }
        }
        cout<<"#"<<test_case<<" "<< stk.top()<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}