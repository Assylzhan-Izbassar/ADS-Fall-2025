#include <iostream>
#include <vector>

using namespace std;

vector<size_t> seive(size_t n) {
    vector<size_t> primes(n+1, true);
    primes[0] = primes[1] = false;

    for (size_t x = 2; x <= n; ++x) {
        if (primes[x]) {
            for (size_t j = x + x; j <= n; j += x) {
                primes[j] = false;
            }
        }
    }
    vector<size_t> result; 

    for (size_t i = 0; i < primes.size(); ++i) {
        if (primes[i]) {
            result.push_back(i);
        }
    }

    return result;
}

bool is_prime(size_t x) {
    if (x == 2) {
        return true;
    }
    if (x < 2) {
        return false;
    }
    for (size_t i = 2; i * i <= x; ++i) {
        if (!(x % i)) {
            return false;
        }
    } 
    return true;
}

vector<size_t> primes(size_t n) {
    vector<size_t> res;

    for (size_t x = 2; x <= n; ++x) {
        if (is_prime(x)) {
            res.push_back(x);
        }
    }
    return res;
}

vector<size_t> factors(size_t n, vector<size_t> primes) {
    size_t temp = n;
    vector<size_t> res;

    for (size_t i = 0; i < primes.size(); ++i) {
        if (temp == 0) {
            break;
        }
        while (temp % primes[i] == 0) {
            res.push_back(primes[i]);
            temp /= primes[i];
        }
    }
    return res;
}

int main() {

    size_t n;
    cin >> n;

    vector<size_t> p = seive(n);

    // // all primes
    // vector<size_t> p = primes(n);

    for(size_t i = 0; i < p.size(); ++i) {
        cout << p[i] << " ";
    }
    cout << endl;

    // // algorithm for finding prime factors
    // vector<size_t> result = factors(n, p);
    
    // // output
    // for(size_t i = 0; i < result.size(); ++i) {
    //     cout << result[i] << " ";
    // }

    // cout << endl;

    return 0;
}