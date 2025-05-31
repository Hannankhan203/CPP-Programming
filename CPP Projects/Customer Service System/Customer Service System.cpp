#include <iostream>
#include <string>
using namespace std;

// Node structure for each customer
struct Customer {
    int id;
    string name;
    Customer* next;
};

// Queue using linked list
class CustomerQueue {
private:
    Customer* front;
    Customer* rear;

public:
    CustomerQueue() {
        front = rear = nullptr;
    }

    // Add customer to the queue
    void Enqueue(int id, const string& name) {
        Customer* newCustomer = new Customer{id, name, nullptr};
        if (rear == nullptr) {
            front = rear = newCustomer;
        } else {
            rear->next = newCustomer;
            rear = newCustomer;
        }
        cout << "Customer " << name << " with ID " << id << " added to the queue.\n";
    }

    // Remove customer from the queue
    void Dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No customer to serve.\n";
            return;
        }

        Customer* temp = front;
        cout << "Serving customer " << temp->name << " with ID " << temp->id << ".\n";
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Always false for linked list unless system runs out of memory
    bool isFull() {
        return false;
    }

    // Check if a customer with specific ID is in the queue
    bool isInList(int id) {
        Customer* current = front;
        while (current != nullptr) {
            if (current->id == id) return true;
            current = current->next;
        }
        return false;
    }

    // Display queue
    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        Customer* current = front;
        cout << "Customers in queue:\n";
        while (current != nullptr) {
            cout << "- " << current->name << " (ID: " << current->id << ")\n";
            current = current->next;
        }
    }

    // Destructor to clean memory
    ~CustomerQueue() {
        while (!isEmpty()) {
            Dequeue();
        }
    }
};

// Main program
int main() {
    CustomerQueue queue;
    int choice, id;
    string name;

    while (true) {
        cout << "\n--- Bank Customer Queue Menu ---\n";
        cout << "1. Add Customer (Enqueue)\n";
        cout << "2. Serve Customer (Dequeue)\n";
        cout << "3. Check if Queue is Empty\n";
        cout << "4. Check if Customer is in Queue\n";
        cout << "5. Display All Customers\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Customer ID: ";
                cin >> id;
                cout << "Enter Customer Name: ";
                cin.ignore(); // to consume newline
                getline(cin, name);
                queue.Enqueue(id, name);
                break;
            case 2:
                queue.Dequeue();
                break;
            case 3:
                cout << (queue.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            case 4:
                cout << "Enter Customer ID to search: ";
                cin >> id;
                cout << (queue.isInList(id) ? "Customer is in queue." : "Customer not found in queue.") << endl;
                break;
            case 5:
                queue.displayQueue();
                break;
            case 6:
                cout << "Exiting system.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
