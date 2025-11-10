#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string line;

    getline(cin, line);

    stringstream ss(line);
    string word;
    while(ss >> word) {
        cout << word << endl;
    }

    return 0;
}