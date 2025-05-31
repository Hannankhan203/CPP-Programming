#include <iostream>
#include <string>
using namespace std;

// Node structure for the BST
struct ContactNode {
    string name;
    string phone;
    ContactNode* left;
    ContactNode* right;

    ContactNode(string n, string p) {
        name = n;
        phone = p;
        left = right = nullptr;
    }
};

class PhoneBookBST {
private:
    ContactNode* root;

    ContactNode* insert(ContactNode* node, string name, string phone) {
        if (node == nullptr) {
            return new ContactNode(name, phone);
        }

        if (name < node->name)
            node->left = insert(node->left, name, phone);
        else if (name > node->name)
            node->right = insert(node->right, name, phone);
        else
            cout << "Contact with name " << name << " already exists.\n";

        return node;
    }

    void inOrder(ContactNode* node) {
        if (node) {
            inOrder(node->left);
            cout << node->name << " - " << node->phone << endl;
            inOrder(node->right);
        }
    }

    void preOrder(ContactNode* node) {
        if (node) {
            cout << node->name << " - " << node->phone << endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void postOrder(ContactNode* node) {
        if (node) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->name << " - " << node->phone << endl;
        }
    }

    ContactNode* search(ContactNode* node, string name) {
        if (!node || node->name == name)
            return node;

        if (name < node->name)
            return search(node->left, name);
        else
            return search(node->right, name);
    }

public:
    PhoneBookBST() {
        root = nullptr;
    }

    void addContact(string name, string phone) {
        root = insert(root, name, phone);
    }

    void displayContactsInOrder() {
        cout << "Contacts (In-order - Alphabetical Order):\n";
        inOrder(root);
    }

    void displayPreOrder() {
        cout << "Contacts (Pre-order):\n";
        preOrder(root);
    }

    void displayPostOrder() {
        cout << "Contacts (Post-order):\n";
        postOrder(root);
    }

    void findContact(string name) {
        ContactNode* result = search(root, name);
        if (result)
            cout << "Found: " << result->name << " - " << result->phone << endl;
        else
            cout << "Contact not found.\n";
    }
};

int main() {
    PhoneBookBST phoneBook;
    int choice;
    string name, phone;

    do {
        cout << "\nPhone Book Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts (In-order)\n";
        cout << "3. Display Contacts (Pre-order)\n";
        cout << "4. Display Contacts (Post-order)\n";
        cout << "5. Search Contact\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter phone number: ";
            getline(cin, phone);
            phoneBook.addContact(name, phone);
            break;
        case 2:
            phoneBook.displayContactsInOrder();
            break;
        case 3:
            phoneBook.displayPreOrder();
            break;
        case 4:
            phoneBook.displayPostOrder();
            break;
        case 5:
            cout << "Enter name to search: ";
            getline(cin, name);
            phoneBook.findContact(name);
            break;
        case 0:
            cout << "Exiting Phone Book.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
