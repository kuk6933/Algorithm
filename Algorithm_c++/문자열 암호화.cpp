#include <cstring>
#include <string>
#define MAX 50000
#define HASH_SIZE  26 * 26 * 26
using namespace std;

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int n, char init_string[]);
extern int change(char string_A[], char string_B[]);
extern void result(char ret[]);

static int seed = 5;  // seed can be changed
static int pseudo_rand(void)
{
    seed = seed * 214013 + 2531011;
    return (seed >> 16) & 0x7FFF;
}

#define MAXL (50005)
#define DUMMY_LEN (5959)

static int init_string_len = 0, char_type = 0, query_cnt = 0;
static char dummy1[DUMMY_LEN];
static char init_string[MAXL];
static char dummy2[DUMMY_LEN];
static char result_string[MAXL];
static char dummy3[DUMMY_LEN];
static char user_ans_string[MAXL];
static char dummy4[DUMMY_LEN];
static char string_A[4], string_B[4];


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main() {
    setbuf(stdout, NULL);
//	freopen("sample_input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    int total_score = 0;
    for (int TC = 1; TC <= T; TC++) {
        int score = 100;
        scanf("%d%d%d%d", &seed, &init_string_len, &char_type, &query_cnt);

        for (int i = 0; i < init_string_len; i++)
        {
            init_string[i] = pseudo_rand() % char_type + 'a';
        }
        init_string[init_string_len] = '\0';

        init(init_string_len, init_string);

        string_A[3] = string_B[3] = '\0';
        for (int i = 0; i < query_cnt; i++)
        {
            for (int k = 0; k < 3; k++)
            {
                string_A[k] = pseudo_rand() % char_type + 'a';
                string_B[k] = pseudo_rand() % char_type + 'a';
            }
            int user_ans = change(string_A, string_B);
            int ans;
            scanf("%d", &ans);

            if (ans != user_ans)
            {
                score = 0;
            }
        }

        result(user_ans_string);
        scanf("%s", result_string);

        for (int i = 0; i < init_string_len; i++)
        {
            if (result_string[i] != user_ans_string[i])
            {
                score = 0;
                break;
            }
        }

        total_score += score;
        printf("#%d %d\n", TC, score);
    }
    printf("Total score : %d\n", total_score/T);

    return 0;
}
struct Node {
    int idx;
    int hash;
    Node* next;
    Node* prev;
};
string str;

Node nodes[MAX];
Node Hash[HASH_SIZE];


int getHash(string &a, int i) {
    return (a[i] - 'a') * 26 * 26 + (a[i + 1] - 'a') * 26 + (a[i + 2] - 'a');
}

void init(int n, char init_string[]) {
    str = init_string;
    for (int i = 0; i < HASH_SIZE; ++i) {
        Hash[i] = { -1, i, nullptr, nullptr };
    }
    for(int i= n-3; i>=0; i--) {
        int hash = getHash(str, i);
        nodes[i] = {i, hash, nullptr, nullptr};
        nodes[i].prev = &Hash[hash];
        nodes[i].next = Hash[hash].next;
        if(Hash[hash].next != nullptr) {
            Hash[hash].next->prev = &nodes[i];
        }
        Hash[hash].next = &nodes[i];
    }
}

int change(char string_A[], char string_B[]) {
    string tmp = string_A;
    int aHash = getHash(tmp,0);

    int cnt = 0;
    int idx = -1;
    Node* node = Hash[aHash].next;
    while(node != nullptr) {
        cnt++;
        idx = node->idx;
        for(int i=0; i<3; i++) {
            str[idx+i] = string_B[i];
        }

        while(node != nullptr && node->idx - idx <= 2) {
            node = node->next;
        }
        for(int i=idx -2; i<= idx+2; i++) {
            if(i < 0 || i>= str.size()-2) {
                continue;
            }

            int hash = getHash(str, i);
            if(nodes[i].hash == hash) {
                continue;
            }
            nodes[i].hash = hash;
            if (nodes[i].prev) {
                nodes[i].prev->next = nodes[i].next;
            }
            if (nodes[i].next) {
                nodes[i].next->prev = nodes[i].prev;
            }

            Node* tmpNode = &Hash[hash];
            while(tmpNode->next != nullptr && tmpNode->next->idx < i) {
                tmpNode = tmpNode->next;
            }
            nodes[i].next = tmpNode->next;
            tmpNode->next = &nodes[i];
            nodes[i].prev = tmpNode;
            if (nodes[i].next) nodes[i].next->prev = &nodes[i];
        }
    }
    return cnt;
}

void result(char ret[]) {
    for(int i=0; i<str.size(); i++) {
        ret[i] = str[i];
    }
}