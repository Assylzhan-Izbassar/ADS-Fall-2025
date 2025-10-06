#include <iostream>
#include <vector>
// #include <queue>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

class MaxHeap {
private:
    void heapifyUp(int i) { // child index
        while (i > 0) {
            int parentIdx = this->parent(i);
            if (heap[i] > heap[parentIdx]) {
                swap(heap[i], heap[parentIdx]);
                i = parentIdx;
            } else {
                break;
            }
        }
    }
    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < n && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < n && heap[right] > heap[largest]) {
                largest = right;
            }

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }
public:
    vector<int> heap;
    
    int parent(int i) { // child index
        return (i - 1) / 2;
    }
    int left(int i) { // parent index
        return 2 * i + 1;
    }
    int right(int i) { // parent index
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
    int pop() {
        if (heap.empty()) {
            return -1;
        }
        int top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return top;
    }
};

int main() {
    // priority_queue<int, vector<int>, greater<int>> pq;

    const int n = 6;
    // int arr[n] = {2, -1, 6, 10, 12, 20};
    int arr[n] = {12, 8, 6, 10, 2, 1};

    MaxHeap mh;
    for (int i=0; i<n; ++i) {
        mh.push(arr[i]);
        // pq.push(arr[i]);

        for (int j=0; j<mh.heap.size(); ++j) {
            cout << mh.heap[j] << " ";
        } 
        cout << endl;
    }

    cout << "Extracting...\n";

    for (int i=0; i < n; ++i) {
        cout << mh.pop() << " ";
    }
    cout << endl;

    // cout << "The top of the heap: " << mh.front() << endl;
    // cout << "Extract top: " << mh.pop() << endl;
    // cout << "The top of the heap: " << mh.front() << endl;
    // // cout << "The top of the heap: " << pq.top() << endl;

    // for (int j=0; j<mh.heap.size(); ++j) {
    //     cout << mh.heap[j] << " ";
    // } 
    // cout << endl;

    return 0;
}