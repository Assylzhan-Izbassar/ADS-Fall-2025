#include <iostream>

using namespace std;


vector<size_t> primes(size_t n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i=2; i * i <= n; ++i) {
        if (is_prime[i] == true) {
            for (int j=i*i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<size_t> result;

    for(size_t i=0; i < is_prime.size(); ++i) {
        if (is_prime[i]) {
            result.push_back(i);
        }
    }

    return result;
}


int main() {

    size_t n;

    cin >> n;

    vector<size_t> p = primes(n);

    for (size_t i=0; i < p.size(); ++i) {
        cout << p[i] << " ";
    }
    cout << endl;

    return 0; 
}