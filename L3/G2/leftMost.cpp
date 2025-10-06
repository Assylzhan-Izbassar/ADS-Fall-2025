#include <iostream>
#include <vector>

using namespace std;

int lowerBoundBinarySearch(vector<int>& arr, int target) {
    int l = 0; // left pointer
    int r = arr.size() - 1; // right pointer

    while (l < r) {
        int mid = l + (r - l) / 2; // middle
        
        if (arr[mid] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (arr[r] == target) {
        return r;
    }
    return -1; 
}

int main() {

    vector<int> arr;
    int n, x, target;

    cin >> n;

    for (int i=0; i<n; ++i) cin >> x, arr.push_back(x);

    cin >> target;

    sort(arr.begin(), arr.end()); 

    cout << lowerBoundBinarySearch(arr, target) << endl;

    return 0;
}