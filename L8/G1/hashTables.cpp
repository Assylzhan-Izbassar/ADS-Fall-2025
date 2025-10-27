#include <iostream>
#include <vector>
#include <list>
// #include <utility>
#include <map>

using namespace std;

class HashTable {
private:
    vector<list<pair<int, string>>> table;
    list<pair<int, string>>::iterator bucketIt;
    int capacity;
    int elements;
    double threshold;

    int hash(int key) { // input some key, and output some index to store the element
        // rand += 7;
        int x = key;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = (x >> 16) ^ x;
        // return ((((key*key) / 31) % this->capacity) + 29 * rand) % this->capacity;
        return x % this->capacity;
    }

    void resize() {
        int oldSize = this->table.size();
        int newSize = 2 * oldSize;
        this->capacity = newSize;

        vector<list<pair<int, string>>> newTable(newSize);

        for (int i=0; i < table.size(); ++i) {
            for (bucketIt=table[i].begin(); bucketIt!=table[i].end(); ++bucketIt) {
                int newIndex = this->hash((*bucketIt).first);
                newTable[newIndex].push_back(make_pair((*bucketIt).first, (*bucketIt).second));
            }
        }
        // table = std::move(newTable);
        table = newTable;
    }

public:
    HashTable(int capacity, double threshold=0.75) { // bucket
        this->capacity = capacity;
        table.resize(capacity);
        this->threshold = threshold;
        this->elements = 0;
    }

    void insert(int key, string value) {
        if ((double) elements / (double) table.size() > threshold) {
            resize();
        }

        int index = this->hash(key);

        // checking the existance
        for (bucketIt=table[index].begin(); bucketIt!=table[index].end(); ++bucketIt) {
            if ((*bucketIt).first == key) {
                (*bucketIt).second = value;
                return;
            } 
        }

        // int startIdx = index;
        // while(!table[index].empty()) {
        //     index = (index + 1) % this->capacity;

        //     if(startIdx == index) {
        //         cout << "Hash Table is full\n";
        //         return; 
        //     }
        // }

        // otherwise
        table[index].push_back(make_pair(key, value));
        elements++;
    }

    string search(int key) {
        int index = hash(key);

        for (bucketIt=table[index].begin(); bucketIt!=table[index].end(); ++bucketIt) {
            if ((*bucketIt).first == key) {
                return (*bucketIt).second;
            }
        }


        // int startIdx = index;
        // while (!table[index].empty()) {
        //     bucketIt = table[index].begin();
        //     if ((*bucketIt).first == key) {
        //         return (*bucketIt).second;
        //     }

        //     index = (index + 1) % capacity;

        //     if (startIdx == index) {
        //         break;
        //     }
        // }
        return "Not Found!";
    }

    void display() {
        for (int idx=0; idx<table.size(); ++idx) {
            cout << idx << ": [";
            for (bucketIt=table[idx].begin(); bucketIt!=table[idx].end(); ++bucketIt) {
                cout << "("<< (*bucketIt).first << ", " << (*bucketIt).second << ")";
            }
            cout << "]\n";
        }
    }
};

int main() {
    // int n;
    // cin >> n;

    // vector<int> v(n);

    // for (int i=0; i<n; ++i) {
    //     cin >> v[i];
    // }

    unordered_map<int, string> hashTable;

    const int N = 3;
    HashTable ht(N);

    ht.insert(2, "apple");
    ht.insert(9, "pineapple");
    ht.insert(16, "cherry");
    ht.insert(23, "orange");
    ht.insert(31, "mango");

    ht.display();

    cout << ht.search(9) << endl;

    cout << "Unordered map:\n";

    hashTable.insert({1, "apple"});
    hashTable.insert({5, "pineapple"});
    hashTable.insert({10, "orange"});

    unordered_map<int, string>::iterator it;

    for(it=hashTable.begin(); it!=hashTable.end(); ++it) {
        cout << (*it).first << " " << (*it).second << endl; 
    }

    return 0;
}