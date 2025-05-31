#include <iostream>
#include <list>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
    list<pair<int, string>> table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    void insert(int id, string name) {
        int index = hashFunction(id);
        table[index].push_back({id, name});
        cout << "Inserted: " << name << " at index " << index << endl;
    }

    void search(int id) {
        int index = hashFunction(id);
        for (auto& pair : table[index]) {
            if (pair.first == id) {
                cout << "Found: " << pair.second << " at index " << index << endl;
                return;
            }
        }
        cout << "Not found\n";
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "[" << i << "]: ";
            for (auto& pair : table[i])
                cout << "(" << pair.first << ", " << pair.second << ") ";
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(101, "Alice");
    ht.insert(111, "Bob");
    ht.insert(121, "Charlie");
    ht.insert(131, "David");

    ht.search(121);
    ht.display();
    return 0;
}
