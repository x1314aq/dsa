/**
 * hihoCoder 1014 Trie树
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct trie_node {
    char letter;
    unsigned char state;
    unsigned int count;
    struct trie_node *childs[26];
} nodes[1000000];
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
    n->state = 1;
}

static int tsearch(char *word) {
    char *c = word;
    struct trie_node *n = root.nodes[*c - 'a'];
    if(!n) return 0;
    while(*++c) {
        n = n->childs[*c - 'a'];
        if(!n) return 0;
    }
    return n->count;
}

int res[100005];
int main() {
    int n;
    scanf("%d", &n);
    char word[16];
    for(int i = 0; i < n; i++) {
        scanf("%s", word);
        tinsert(word);
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", word);
        res[i] = tsearch(word);
    }
    for(int i = 0; i < n; i++)
        printf("%d\n", res[i]);
    return 0;
}
