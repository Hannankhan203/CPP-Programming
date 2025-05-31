#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
    list<pair<string, int>> table[TABLE_SIZE];

    int hashFunction(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c; // sum of ASCII values
        }
        return hash % TABLE_SIZE;
    }

public:
    void insert(string name, int id) {
        int index = hashFunction(name);
        table[index].push_back({name, id});
        cout << "Inserted: " << name << " at index " << index << endl;
    }

    void search(string name) {
        int index = hashFunction(name);
        for (auto& entry : table[index]) {
            if (entry.first == name) {
                cout << "Found: " << name << " with ID " << entry.second << " at index " << index << endl;
                return;
            }
        }
        cout << "Name not found\n";
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "[" << i << "]: ";
            for (auto& entry : table[i]) {
                cout << "(" << entry.first << ", " << entry.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.insert("Alice", 1001);
    ht.insert("Bob", 1002);
    ht.insert("Charlie", 1003);
    ht.insert("Dave", 1004);

    ht.search("Charlie");
    ht.display();
    return 0;
}
