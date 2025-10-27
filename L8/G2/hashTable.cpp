#include <iostream>
#include <vector>
#include <list> // linked list

using namespace std;

class HashTable {
private:
    vector<list<pair<int, string>>> table;
    int capacity;
    list<pair<int, string>>::iterator it;
    
    int elementCounter;
    double threshold;

    int hash(int key) {
        return key % this->capacity;
    }
    double load_factor () {
        return this->elementCounter / this->capacity;
    }

    void resizeTable () {
        int oldSize = this->capacity;
        int newSize = 2 * this->capacity;
        this->capacity = newSize;

        vector<list<pair<int, string>>> newTable(newSize);

        for(int i=0; i < table.size(); ++i) {
            for (it=table[i].begin(); it != table[i].end(); ++it) {
                int newIndex = hash((*it).first);
                newTable[newIndex].push_back(make_pair((*it).first, (*it).second));
            }
        }
        table = newTable;
    }

public:
    HashTable(int capacity, double threshold=0.75) {
        this->capacity = capacity;
        table.resize(this->capacity);
        elementCounter = 0;
        this->threshold = threshold;
    }

    void insert(int key, string value) {
        if (load_factor() > this->threshold) {
            resizeTable();
        }
        int index = hash(key);

        int startIdx = index;
        while (!table[index].empty()) {
            index = (index + 1) % capacity;

            // update the value;
            for (it=table[index].begin(); it!=table[index].end(); ++it) {
                if ((*it).first == key) {
                    (*it).second = value;
                    return;
                }
            }

            if (startIdx == index) {
                cout << "Hash Table is fulled!\n";
                break;
            }
        }

        table[index].push_back(make_pair(key, value));
        elementCounter++;
    }

    string search(int key) {
        int index = hash(key);
        int start = index;

        while(!table[index].empty()) {
            // for (it=table[index].begin(); it!=table[index].end(); ++it) {
            //     if ((*it).first == key) {
            //         return (*it).second;
            //     }
            // }
            it=table[index].begin();
            if ((*it).first == key) {
                return (*it).second;
            }
            index = (index + 1) % capacity;
            if (index == start) {
                break; 
            }
        }
        return "Not Found!";
    }

    void display() {
        for (int i=0; i < table.size(); ++i) {
            cout << i << ": [";
            for (it=table[i].begin(); it != table[i].end(); ++it) {
                cout << "(" << (*it).first << ", " << (*it).second << ")";
            }
            cout << "]\n";
        }
    }

};

int main() {

    // "apple" -> 5,
    // "orange" -> 10,
    // "pineapple" -> 7,

    // insert - [O(1), O(n)] - calculating hash function
    // search - [O(1), O(n)], n = #elements inside the bucket
    // delete - [O(1), O(n)], n = #elements inside the bucket

    HashTable ht(5);
    
    ht.insert(5, "apple");
    ht.insert(10, "orange");
    ht.insert(7, "pineapple");
    ht.insert(12, "mango");
    ht.insert(23, "cherry");
    ht.insert(41, "graps");

    ht.display();
    
    cout << ht.search(10) << endl;

    return 0;
}