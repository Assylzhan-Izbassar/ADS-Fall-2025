#include <iostream>

using namespace std;

size_t gcd(size_t a, size_t b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}


int main() {
    size_t a, b;
    cin >> a >> b;

    cout << gcd(a, b) << endl;

    return 0; 
}