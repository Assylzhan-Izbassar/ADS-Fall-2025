#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class MinHeap {
private:
    
    void heapifyUp(int i) { // i in the step is some child
        while (i > 0) {
            int parent = this->parent(i);
            if (heap[i] < heap[parent]) {
                swap(heap[i], heap[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();

        while (true) {
            int l = this->left(i);
            int r = this->right(i);
            int largestIdx = i;

            if (l < n && heap[l] < heap[largestIdx]) {
                largestIdx = l;
            }
            if (r < n && heap[r] < heap[largestIdx]) {
                largestIdx = r;
            }
            if (i != largestIdx) {
                swap(heap[i], heap[largestIdx]);
                i = largestIdx;
            } else {
                break;
            }
        }
    }

public:
    vector<int> heap;
    int parent(int i) {
        return (i - 1) / 2;
    }
    int left(int i) {
        return 2 * i + 1;
    } 
    int right(int i) {
        return 2 * i + 2;
    }
    void push(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1); 
    }
    int front() {
        if (!heap.empty()) {
            return heap[0];
        }
        return -1;
    }
    int pop_front() {
        if (heap.empty()) {
            return -1;
        }
        int extremum = heap[0];
        int n = heap.size() - 1;
        swap(heap[0], heap[n]);
        heap.pop_back();
        
        heapifyDown(0);
        
        return extremum;
    }

    vector<int> sort() {
        vector<int> copy = heap;
        vector<int> sorted;
        int n = heap.size();
        for (int i=0; i<n; ++i) {
            int top = this->pop_front();
            sorted.push_back(top);
        }
        heap = copy;
        return sorted;
    }

    void print() {
        for (int i=0; i<heap.size(); ++i) {
            cout << heap[i] << " "; 
        }
        cout << endl;
    }
};

int main() {

    const int n = 7;
    int arr[n] = {10, 8, 7, 12, -1, 6, 2};

    MinHeap h;

    for (int i=0; i<n; ++i) {
        h.push(arr[i]);
    }

    vector<int> sorted = h.sort();

    for (int i=0; i<h.heap.size(); ++i) {
        cout << h.heap[i] << " ";
    }
    cout << endl; 

    for (int i=0; i<sorted.size(); ++i) {
        cout << sorted[i] << " ";
    }
    cout << endl; 

    return 0;
}