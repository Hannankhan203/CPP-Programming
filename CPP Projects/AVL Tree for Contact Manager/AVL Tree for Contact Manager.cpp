#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string number;
    Contact* left;
    Contact* right;
    int height;
};

// Utility: Get height of a node
int getHeight(Contact* node) {
    return node ? node->height : 0;
}

// Utility: Get balance factor
int getBalance(Contact* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Utility: Update height
void updateHeight(Contact* node) {
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// Right rotate
Contact* rotateRight(Contact* y) {
    Contact* x = y->left;
    Contact* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotate
Contact* rotateLeft(Contact* x) {
    Contact* y = x->right;
    Contact* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Insert with AVL balancing
Contact* insert(Contact* node, string name, string number) {
    if (!node) {
        Contact* newNode = new Contact{name, number, nullptr, nullptr, 1};
        return newNode;
    }

    if (name < node->name)
        node->left = insert(node->left, name, number);
    else if (name > node->name)
        node->right = insert(node->right, name, number);
    else {
        cout << "Duplicate name not allowed.\n";
        return node;
    }

    updateHeight(node);
    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && name < node->left->name)
        return rotateRight(node);

    // Right Right
    if (balance < -1 && name > node->right->name)
        return rotateLeft(node);

    // Left Right
    if (balance > 1 && name > node->left->name) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left
    if (balance < -1 && name < node->right->name) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// In-order traversal
void inOrder(Contact* root) {
    if (root) {
        inOrder(root->left);
        cout << root->name << ": " << root->number << endl;
        inOrder(root->right);
    }
}

// Search contact
void search(Contact* root, string name) {
    if (!root) {
        cout << "Contact not found.\n";
        return;
    }

    if (name < root->name)
        search(root->left, name);
    else if (name > root->name)
        search(root->right, name);
    else
        cout << "Found: " << root->name << " -> " << root->number << endl;
}

// ==================
// Main Program
// ==================
int main() {
    Contact* root = nullptr;
    int choice;
    string name, number;

    do {
        cout << "\n--- Contact Manager (AVL Tree) ---\n";
        cout << "1. Add Contact\n";
        cout << "2. Search Contact\n";
        cout << "3. Display All Contacts (Sorted)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter number: ";
                getline(cin, number);
                root = insert(root, name, number);
                break;

            case 2:
                cout << "Enter name to search: ";
                getline(cin, name);
                search(root, name);
                break;

            case 3:
                cout << "Contact List:\n";
                inOrder(root);
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
