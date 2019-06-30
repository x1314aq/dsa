/**
 * hihoCoder 1107 Shortest Proper Prefix
 * Trie
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

struct trie_node {
    char letter;
    unsigned int count;
    struct trie_node *childs[26];
} nodes[2000000];
int cur_node;

static struct trie_node *alloc_one() {
    return &nodes[cur_node++];
}

struct trie_root {
    struct trie_node *nodes[26];
} root;

static void tinsert(char *word) {
    char *c = word;
    struct trie_node *p;
    struct trie_node *n = root.nodes[*c - 'a'];
    if(!n) {
        n = alloc_one();
        n->letter = *c;
        root.nodes[*c - 'a'] = n;
    }
    n->count++;
    while(*++c) {
        p = n;
        n = n->childs[*c - 'a'];
        if(!n) {
            n = alloc_one();
            n->letter = *c;
            p->childs[*c - 'a'] = n;
        }
        n->count++;
    }
}

static void travel(struct trie_node *n, int &ans) {
    if(n->count <= 5) {
        ans++;
        return;
    }
    for(int i = 0; i < 26; i++) {
        struct trie_node *child = n->childs[i];
        if(child) travel(child, ans);
    }
}

static int traversal() {
    int ans = 0;
    for(int i = 0; i < 26; i++) {
        struct trie_node *n = root.nodes[i];
        if(n) travel(n, ans);
    }
    return ans;
}

char word[2000000];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", word);
        tinsert(word);
    }

    printf("%d\n", traversal());
    return 0;
}
