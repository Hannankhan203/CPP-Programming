#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

struct Student {
    int rollNo;
    string name;
    bool isOccupied;

    Student() : rollNo(-1), name(""), isOccupied(false) {}
};

class HashTable {
    Student table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    void insert(int rollNo, string name) {
        int index = hashFunction(rollNo);
        int i = 0;

        while (table[index].isOccupied && table[index].rollNo != -1) {
            i++;
            index = (index + i * i) % TABLE_SIZE;
            if (i == TABLE_SIZE) {
                cout << "Table full\n";
                return;
            }
        }

        table[index].rollNo = rollNo;
        table[index].name = name;
        table[index].isOccupied = true;
        cout << "Inserted at index " << index << endl;
    }

    void search(int rollNo) {
        int index = hashFunction(rollNo);
        int i = 0;

        while (table[index].isOccupied) {
            if (table[index].rollNo == rollNo) {
                cout << "Found: " << table[index].name << " at index " << index << endl;
                return;
            }
            i++;
            index = (index + i * i) % TABLE_SIZE;
            if (i == TABLE_SIZE) break;
        }
        cout << "Not found\n";
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i].isOccupied)
                cout << "[" << i << "] " << table[i].rollNo << ": " << table[i].name << endl;
            else
                cout << "[" << i << "] Empty\n";
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(10, "Alice");
    ht.insert(20, "Bob");
    ht.insert(30, "Charlie");
    ht.insert(40, "David");

    ht.search(30);
    ht.display();
    return 0;
}
