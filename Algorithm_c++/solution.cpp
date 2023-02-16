#include <cstring>
#include <list>
#include <vector>
#include <string.h>
#define MAX 50002
#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999

using namespace std;

void mstrcpy(char *dest, const char *src) //복사
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
}

struct Node {
    char name[NAME_MAXLEN+1];
    Node* parent;
    vector<Node*> children;
    int count;
};

int node_count = 0;
Node node_pool[MAX];
Node* root = nullptr;

Node* new_node(char name[]) {
    node_pool[node_count].count = 0;
    node_pool[node_count].children.clear();
    mstrcpy(node_pool[node_count].name, name);
    return &node_pool[node_count++];
}

Node* find_node(char path[2000]) {
    Node* cur = root;
    char* res = strtok(path, "/");
    while(res != NULL) {
        for(int i= 0; i<cur->children.size(); i++) {
            if(cur->children[i] == nullptr) continue;
            if(strcmp(res, cur->children[i]->name) == 0) {
                cur = cur->children[i];
                break;
            }
        }
        res = strtok(NULL, "/");
    }
    return cur;
}

void init(int n) {
    char name[7];
    name[0] = '/';
    name[1] = '\0';
    node_count = 0;
    root = new_node(name);
    root->parent = nullptr;
}

void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {
    Node* p = find_node(path);
    Node* node = new_node(name);
    node->parent = p;
    p->children.push_back(node);
    while(p != nullptr) {
        p->count++;
        p = p->parent;
    }
}

void cmd_rm(char path[PATH_MAXLEN + 1]) {
    Node* cur = find_node(path);
    Node* p = cur->parent;
    int cnt = cur->count;

    for(int i=0; i<p->children.size(); i++) {
        if(p->children[i] == nullptr) continue;
        if(strcmp(p->children[i]->name, cur->name) == 0) {
            p->children[i] = nullptr;
            break;
        }
    }
    while(p != nullptr) {
        p->count -= (cnt+1);
        p = p->parent;
    }
}

void traversal(Node* source, Node* cp) {
    if(source == nullptr) {
        return;
    }
    for(int i=0; i<source->children.size(); i++) {
        if(source->children[i] == nullptr) continue;
        Node* node = new_node(source->children[i]->name);
        node->count = source->children[i]->count;
        node->parent = cp;
        cp->children.push_back(node);
        traversal(source->children[i], node);
    }
}

void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {

    Node* source = find_node(srcPath);
    Node* destination = find_node(dstPath);
    Node* cp = new_node(source->name);

    cp->count = source->count;
    traversal(source, cp);

    destination->children.push_back(cp);
    cp->parent = destination;

    while(destination != nullptr) {
        destination->count += cp->count+1;
        destination = destination->parent;
    }
}

void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
    Node* source = find_node(srcPath);
    Node* p = source->parent;
    Node* destination = find_node(dstPath);

    destination->children.push_back(source);
    source->parent = destination;
    for(int i=0; i<p->children.size(); i++) {
        if(p->children[i] == nullptr) continue;
        if(strcmp(p->children[i]->name, source->name) == 0) {
            p->children[i] = nullptr;
            break;
        }
    }
    while(p != nullptr) {
        p->count -= (source->count+1);
        p = p->parent;
    }
    while(destination != nullptr) {
        destination->count += (source->count+1);
        destination = destination->parent;
    }
}

int cmd_find(char path[PATH_MAXLEN + 1]) {
    return find_node(path)->count;
}

//#include <cstring>
//#include <list>
//#include <vector>
//using namespace std;
//#define MAX 50002
//#define NAME_MAXLEN 6
//#define PATH_MAXLEN 1999
//
//bool mstrcmp(const char *a, const char *b) //비교
//{
//    int i;
//    for (i = 0; a[i] != '\0'; i++)
//    {
//        if (a[i] != b[i])
//            return false;
//    }
//    return true;
//}
//
//void mstrcpy(char *dest, const char *src) //복사
//{
//    int i = 0;
//    while (src[i] != '\0')
//    {
//        dest[i] = src[i];
//        i++;
//    }
//    dest[i] = src[i];
//}
//
//struct Node {
//    char name[NAME_MAXLEN+1];
//    Node* parent;
//    vector<Node*> children;
//    int count;
//};
//
//int node_count = 0;
//Node node_pool[MAX];
//Node* root = nullptr;
//
//Node* new_node(char name[]) {
//    node_pool[node_count].count = 0;
//    mstrcpy(node_pool[node_count].name, name);
//    return &node_pool[node_count++];
//}
//
//Node* find_node(char path[2000]) {
//    Node* cur = root;
//    char* res = strtok(path, "/");
//    while(res != NULL) {
//        for(int i= 0; i<cur->children.size(); i++) {
//            if(cur->children[i] == nullptr) continue;
//            if(mstrcmp(res, cur->children[i]->name)) {
//                cur = cur->children[i];
//                break;
//            }
//        }
//        res = strtok(NULL, "/");
//    }
//    return cur;
//}
//
//void init(int n) {
//    char name[NAME_MAXLEN + 1];
//    name[0] = '/';
//    name[1] = '\0';
//    node_count = 0;
//    root = new_node(name);
//    root->parent = nullptr;
//}
//
//void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {
//
//    Node* p = find_node(path);
//    Node* node = new_node(name);
//    node->parent = p;
//    p->children.push_back(node);
//    while(p != nullptr) {
//        p->count++;
//        p = p->parent;
//    }
//}
//
//void cmd_rm(char path[PATH_MAXLEN + 1]) {
//
//    Node* p = find_node(path);
//    char* name;
//    mstrcpy(name, p->name);
//    int cnt = p->count;
//    p= p->parent;
//    for(int i=0; i<p->children.size(); i++) {
//        if(p->children[i] == nullptr) continue;
//        if(mstrcmp(p->children[i]->name, name)) {
//            p->children[i] = nullptr;
//            break;
//        }
//    }
//    while(p != nullptr) {
//        p->count -= (cnt+1);
//        p = p->parent;
//    }
//}
//
//void traversal(Node* source, Node* cp) {
//    if(source == nullptr) {
//        return;
//    }
//    for(int i=0; i<source->children.size(); i++) {
//        if(source->children[i] == nullptr) continue;
//        Node* node = new_node(source->children[i]->name);
//        node->count = source->children[i]->count;
//        node->parent = cp;
//        cp->children.push_back(node);
//        traversal(source->children[i], node);
//    }
//}
//
//void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
//
//    Node* source = find_node(srcPath);
//    Node* destination = find_node(dstPath);
//
//    Node* cp = new_node(source->name);
//    cp->count = source->count;
//    traversal(source, cp);
//
//    destination->children.push_back(cp);
//    cp->parent = destination;
//
//    while(destination != nullptr) {
//        destination->count += cp->count+1;
//        destination = destination->parent;
//    }
//}
//
//void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
//    Node* source = find_node(srcPath);
//    Node* parent = source->parent;
//    Node* destination = find_node(dstPath);
//
//    destination->children.push_back(source);
//    source->parent = destination;
//    for(int i=0; i<parent->children.size(); i++) {
//        if(parent->children[i] == nullptr) continue;
//        if(mstrcmp(parent->children[i]->name, source->name)) {
//            parent->children[i] = nullptr;
//            break;
//        }
//    }
//    while(parent != nullptr) {
//        parent->count -= (source->count+1);
//        parent = parent->parent;
//    }
//    while(destination != nullptr) {
//        destination->count += (source->count+1);
//        destination = destination->parent;
//    }
//}
//
//int cmd_find(char path[PATH_MAXLEN + 1]) {
//    return find_node(path)->count;
//}