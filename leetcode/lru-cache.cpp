using namespace std;

struct Node {
    Node *prev;
    Node *next;
    int key;
    int val;
    Node(): key(0), val(0), prev(nullptr), next(nullptr) {};
    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {};
};

class LRUCache {
public:
    Node *head;
    Node *tail;
    int size;
    int capacity;
    unordered_map<int, Node *> map_;

    LRUCache(int cap) {
        capacity = cap;
        size = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        map_.clear();
    }
    
    void remove(Node *n) {
        if (n->prev) {
            n->prev->next = n->next;
        }
        if (n->next) {
            n->next->prev = n->prev;
        }
    }

    void add(Node *n) {
        n->prev = head;
        n->next = head->next;
        head->next->prev = n;
        head->next = n;
    }

    void move_to_head(Node *n) {
        remove(n);
        add(n);
    }

    int get(int key) {
        if (map_.count(key)) {
            Node *n = map_[key];
            move_to_head(n);
            return n->val;
        }
        return -1;
    }
    
    Node *remove_tail() {
        Node *n = tail->prev;
        remove(n);
        return n;
    }

    void put(int key, int value) {
        if (map_.count(key)) {
            Node *n = map_[key];
            n->val = value;
            move_to_head(n);
            return;
        }
        Node *n = new Node(key, value);
        map_[key] = n;
        move_to_head(n);
        size++;
        if (size > capacity) {
            Node *m = remove_tail();
            map_.erase(m->key);
            delete m;
            size--;
        }
    }
};

int main(int argc, char *argv[]) {
    LRUCache obj(2);
    obj.put(1,1);
    obj.put(2,2);
    obj.get(1);
    obj.put(3,3);
    obj.get(2);
    obj.put(4,4);
    obj.get(1);
    obj.get(3);
    obj.get(4);

    return 0;
}
