using namespace std;

class MinStack {
public:
    vector<int> arr;
    vector<int> brr;

    MinStack() {
    }

    void push(int val) {
        arr.push_back(val);
        if (brr.empty()) {
            brr.push_back(val);
        } else {
            brr.push_back(min(val, brr.back()));
        }
    }

    void pop() {
        arr.pop_back();
        brr.pop_back();
    }

    int top() {
        return arr.back();
    }

    int getMin() {
        return brr.back();
    }
};

int main(int argc, char *argv[]) {
    MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    int a = obj.getMin();
    obj.pop();
    int b = obj.top();
    int c = obj.getMin();
    return 0;
}
