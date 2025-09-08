#include <iostream>

using namespace std;

const size_t N = 100000;

class Stack {
    public:
    int arr[N];
    int size = 0;

    size_t push(int x) {
        if (size < N) {
            arr[size] = x;
            size++;
            return size;
        } else {
            return -1;
        }
    }

    int pop() {
        if (size > 0) {
            int x = arr[size - 1];
            arr[size - 1] = 0;
            size--;
            return x;
        }
        return -1;
    }
};

int main() {
    size_t n;
    cin >> n;

    Stack s;
    int x;

    for (size_t i=0; i < n; ++i) {
        cin >> x;
        s.push(x);
    }

    cout << s.pop() << endl;

    cout << "Success!" << endl;

    return 0;
}