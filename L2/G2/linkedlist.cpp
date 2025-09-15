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

    LinkedList() {
        head = nullptr;
    }

    void append(int val) {
        Node* newNode = new Node(val);

        if(!head) { // initial case
            head = newNode;
        } else {
            Node* temp = head;
            while (temp -> next) {
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }

    Node* reverse(Node* head) {
        if (!head || !(head -> next)) {
            return head;
        }
        Node* newHead = reverse(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        return newHead;
    }

    void print() {
        Node* temp = head;
        while (temp) {
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
    for (int i=0; i<n; ++i) {
        cin >> x; 
        ll.append(x);
    }

    ll.print();

    Node* temp = ll.head;

    ll.head = ll.reverse(temp);

    ll.print();

    return 0;
}