#include <iostream>

using namespace std;

const size_t N = 10000;

class Stack {
    public:
    int a[N];
    int cnt = 0;

    void push(int n) {
        if (cnt < N) {
            a[cnt] = n;
            cnt++;
        } else {
            cout << "Stack is fulled!" << endl;
        }
    }

    int pop() {

        if (cnt > 0) {
            int result = a[cnt];
            a[cnt] = 0;
            cnt--;
            return result;
        }
        return -1;
    }
};

int main() {

    Stack s;

    int n;

    for (int i=0; i < n; ++i) {
        int x;
        cin >> x;
        s.push(x);
    }

    return 0; 
}