#include <iostream>
#include <vector>

using namespace std;

// determining the prime number
bool is_prime(size_t n) { 
    for (size_t i=2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

vector<size_t> primes(size_t n) {
    vector<size_t> p;
    for (size_t i = 2; i <= n; ++i) {
        if (is_prime(i)) {
            p.push_back(i);
        }
    }

    return p;
}

int main() {

    size_t n;
    cin >> n;

    // algorithm for factorization
    vector<size_t> p = primes(n);

    // for (size_t i=0; i < p.size(); ++i) {
    //     cout << p[i] << " ";
    // }

    vector<size_t> factors;

    int temp = n;
    bool result = false;

    for(size_t i=0; i < p.size(); ++i) {
        while (temp % p[i] == 0) {
            temp /= p[i];
            factors.push_back(p[i]);
            if (temp == 0) {
                result = true;
                break;
            }
        }
        if (result) {
            break; 
        }
    }

    for (size_t i=0; i < factors.size(); ++i) {
        cout << factors[i] << " ";
    }

    cout << endl;

    return 0; 
}