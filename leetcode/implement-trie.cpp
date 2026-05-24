using namespace std;

class Trie {
public:
    struct Node {
        char c;
        Node *next[26];
        bool end;
        Node() : c('0'), end(false) {bzero(next, sizeof(next));}
        Node(char x) : c(x), end(false) {bzero(next, sizeof(next));}
    };

    Node root;

    Trie() {
    }

    void insert(string word) {
        Node *n = &root;
        auto it = word.cbegin();
        while (n) {
            if (it == word.cend()) {
                n->end = true;
                return;
            }
            int id = *it - 'a';
            if (!n->next[id]) {
                n->next[id] = new Node(*it);
            }
            n = n->next[id];
            ++it;
        }
    }

    bool search(string word) {
        Node *n = &root;
        auto it = word.cbegin();
        while (n) {
            if (it == word.cend()) {
                return n->end;
            }
            int id = *it - 'a';
            n = n->next[id];
            ++it;
        }
        return false;
    }

    bool startsWith(string prefix) {
        Node *n = &root;
        auto it = prefix.cbegin();
        while (n) {
            if (it == prefix.cend()) {
                return true;
            }
            int id = *it - 'a';
            n = n->next[id];
            ++it;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Trie trie = Trie();
    trie.insert("apple");
    trie.search("apple");   // return True
    trie.search("app");     // return False
    trie.startsWith("app"); // return True
    trie.insert("app");
    trie.search("app");     // return True
    return 0;
}
