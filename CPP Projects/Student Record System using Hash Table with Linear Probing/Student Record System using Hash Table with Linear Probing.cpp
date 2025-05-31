#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

struct Student {
    int rollNo;
    string name;
    bool isOccupied;

    Student() {
        rollNo = -1;
        name = "";
        isOccupied = false;
    }
};

class HashTable {
private:
    Student table[TABLE_SIZE];

    // Hash function using Division Method
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    // Insert student record
    void insert(int rollNo, string name) {
        int index = hashFunction(rollNo);
        int originalIndex = index;
        int i = 0;

        while (table[index].isOccupied && table[index].rollNo != -1) {
            i++;
            index = (originalIndex + i) % TABLE_SIZE;

            if (i == TABLE_SIZE) {
                cout << "Hash Table is full. Cannot insert.\n";
                return;
            }
        }

        table[index].rollNo = rollNo;
        table[index].name = name;
        table[index].isOccupied = true;

        cout << "Inserted successfully at index " << index << ".\n";
    }

    // Search student by roll number
    void search(int rollNo) {
        int index = hashFunction(rollNo);
        int originalIndex = index;
        int i = 0;

        while (table[index].isOccupied) {
            if (table[index].rollNo == rollNo) {
                cout << "Student Found at index " << index << ": " << table[index].name << endl;
                return;
            }
            i++;
            index = (originalIndex + i) % TABLE_SIZE;

            if (i == TABLE_SIZE) break;
        }

        cout << "Student not found.\n";
    }

    // Display hash table
    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i].isOccupied)
                cout << "[" << i << "] " << table[i].rollNo << " : " << table[i].name << endl;
            else
                cout << "[" << i << "] Empty\n";
        }
    }
};

// ===========================
// Main Function
// ===========================
int main() {
    HashTable ht;
    int choice, rollNo;
    string name;

    do {
        cout << "\n--- Student Record Hash Table ---\n";
        cout << "1. Insert Student\n";
        cout << "2. Search Student\n";
        cout << "3. Display Table\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Roll No: ";
                cin >> rollNo;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                ht.insert(rollNo, name);
                break;

            case 2:
                cout << "Enter Roll No to search: ";
                cin >> rollNo;
                ht.search(rollNo);
                break;

            case 3:
                ht.display();
                break;

            case 0:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
