#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int l = 0; // left pointer
    int r = arr.size(); // right pointer

    while (l <= r) { // wrong -> have to be l < r
        int mid = (l + r) / 2; // middle
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            r = mid;
        } else {
            l = mid; // wrong -> have to be l = mid + 1; 
        }
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

    cout << binarySearch(arr, target) << endl;

    return 0;
}