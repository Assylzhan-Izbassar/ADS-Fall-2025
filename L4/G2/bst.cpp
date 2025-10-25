#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) {
        this->value=value;
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
    Node* search(int target) {
        return searchRecursive(root, target);
    }
    Node* maxNode() {
        return maxNodeRecursive(root);
    }
    Node* minNode() {
        return minNodeRecursive(root);
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
    Node* searchRecursive(Node* node, int target) {
        if (node == nullptr) {
            return node; // we not found!
        }
        if (node->value > target) {
            return searchRecursive(node->left, target);
        } else if (node->value < target) {
            return searchRecursive(node->right, target); 
        }
        return node; // we found!
    }
    Node* maxNodeRecursive(Node* node) {
        // while (node->right) {
        //     node = node->right;
        // }
        // return node;
        if (!node->right) {
            return node;
        }
        node = maxNodeRecursive(node->right);
        cout << "recursive back!" << endl;
        return node;
    }
    Node* minNodeRecursive(Node* node) {
        if (!node->left) {
            return node;
        }
        return minNodeRecursive(node->left);
    }
    void inorderRecursive(Node* node) {
        if (node == nullptr) { // checking for next to leaf node
            return;
        }
        inorderRecursive(node->left);
        cout << node -> value << " ";
        inorderRecursive(node->right);
        // nothing
    }
    void preorderRecursive(Node* node) {
        if (node == nullptr) { // checking for next to leaf node
            return;
        }
        cout << node -> value << " ";
        preorderRecursive(node->left);
        preorderRecursive(node->right);
    }
    void postorderRecursive(Node* node) {
        if (node == nullptr) { // checking for next to leaf node
            return;
        }
        postorderRecursive(node->left);
        postorderRecursive(node->right);
        cout << node -> value << " ";
    }
    Node* deleteNodeRecursive(Node* node, int target) {
        if (!node) { // no elements
            return node;
        }
        if (node->value > target) {
            return deleteNodeRecursive(node->left, target);
        } else if (node->value < target) {
            return deleteNodeRecursive(node->right, target); 
        } else {
            if (!node->left && !node->right) {
                Node* temp = node;
                delete node;
                return temp;
            }
            if (!node->left && node->right) {
                
            }
        }

    }
};

int main() {
    const int n = 6;
    int arr[n] = {8, 7, 12, 5, 16, 2};

    BST tree;
    for (int i=0; i<n; ++i) {
        tree.insert(arr[i]); 
    }
    cout << "Inorder: ";
    tree.inorder();
    cout << "Preorder: ";
    tree.preorder();
    cout << "Postorder: ";
    tree.postorder();

    // searching some element
    int target = 20;
    Node* targetNode = tree.search(target);

    if (targetNode) {
        cout << "Found! " << targetNode->value << endl;
    } else {
        cout << "Not Found!\n";
    }

    cout << "Max:\n" << tree.maxNode()->value << endl;
    cout << "Min: " << tree.minNode()->value << endl;

    return 0;
}