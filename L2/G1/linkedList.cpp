#include <iostream>

using namespace std;

class Node {
    public:
    int val;
    Node* next;

    Node(int newVal) {
        val = newVal;
        next = nullptr;
    }
};

class LinkedList {
    public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void append(int newVal) {
        Node* newNode = new Node(newVal);

        if (!head) {
            tail = newNode;
            head = tail;
        } else {
            tail -> next = newNode;
            tail = tail -> next;
            // Node* temp = head;

            // while (temp -> next) {
            //     temp = temp -> next;
            // }
            // temp -> next = newNode;
        }
    }

    Node* reverse(Node* head) {
        if (!head || !head -> next) {
            return head;
        }

        Node* newNode = reverse(head -> next);
        // this line is recursive return
        head -> next -> next = head;
        head -> next = nullptr;

        return newNode;
    }

    void print() {
        Node* temp = head;

        while(temp) {
            cout << temp -> val;
            if (temp -> next) {
                cout << " -> ";
            }
            temp = temp -> next;
        }
        cout << endl;
    }

};

int main() {
    int n;
    cin >> n;
    int x;
    LinkedList ll; 
    for (size_t i=0; i<n; ++i) {
        cin >> x;
        ll.append(x);
    }

    ll.print();

    Node* reversed = ll.reverse(ll.head);
    Node* temp = reversed;
    while (temp) {
        cout << temp -> val;
        if (temp -> next) {
            cout << " -> ";
        } 
        temp = temp -> next;
    }
    cout << endl;

    return 0;
}