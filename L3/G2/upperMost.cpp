#include <iostream>
#include <vector>

using namespace std;

int upperBoundBinarySearch(vector<int>& arr, int target) {
    int l = 0; // left pointer included
    int r = arr.size(); // right pointer not included

    while (l < r) {
        int mid = l + (r - l) / 2; // middle
        
        if (arr[mid] <= target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (l - 1 >= 0 && arr[l - 1] == target) {
        return l - 1;
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

    cout << upperBoundBinarySearch(arr, target) << endl;

    return 0;
}