#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }
    void insert(int value) {
        root = insertRecursive(root, value);
    }
    void inorder() {
        inorderRecursive(root);
        cout << endl;
    }
    void preorder() {
        preorderRecursive(root);
        cout << endl;
    }
    void postorder() {
        postorderRecursive(root);
        cout << endl;
    }

private:
    Node* insertRecursive(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (node->value > value) {
            node->left = insertRecursive(node->left, value);
        } else if (node->value < value) {
            node->right = insertRecursive(node->right, value);
        }
        return node;
    }
    void inorderRecursive(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorderRecursive(node->left);
        cout << node->value << " ";
        inorderRecursive(node->right);
    }
    void preorderRecursive(Node* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->value << " ";
        inorderRecursive(node->left);
        inorderRecursive(node->right);
    }
    void postorderRecursive(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorderRecursive(node->left);
        inorderRecursive(node->right);
        cout << node->value << " ";
    }
    


};

int main() {
    BST tree;
    int n = 4;
    int x;
    for (int i=0; i<n; ++i) {
        cin >> x;
        tree.insert(x);
    }
    cout << "Inorder: ";
    tree.inorder();
    cout << "Preorder: ";
    tree.preorder();
    cout << "Postorder: "; 
    tree.postorder();

    return 0;
}