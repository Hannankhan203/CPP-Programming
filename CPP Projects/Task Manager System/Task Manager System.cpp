#include <iostream>
#include <vector>
#include <string>
using namespace std;

// =========================
// BST Section for Task Info
// =========================

struct TaskNode {
    string taskName;
    TaskNode* left;
    TaskNode* right;

    TaskNode(string name) {
        taskName = name;
        left = right = nullptr;
    }
};

class TaskBST {
private:
    TaskNode* insert(TaskNode* root, string name) {
        if (!root) return new TaskNode(name);
        if (name < root->taskName)
            root->left = insert(root->left, name);
        else if (name > root->taskName)
            root->right = insert(root->right, name);
        return root;
    }

    TaskNode* search(TaskNode* root, string name) {
        if (!root || root->taskName == name) return root;
        if (name < root->taskName)
            return search(root->left, name);
        else
            return search(root->right, name);
    }

    TaskNode* minValueNode(TaskNode* node) {
        TaskNode* current = node;
        while (current && current->left)
            current = current->left;
        return current;
    }

    TaskNode* deleteNode(TaskNode* root, string name) {
        if (!root) return root;

        if (name < root->taskName)
            root->left = deleteNode(root->left, name);
        else if (name > root->taskName)
            root->right = deleteNode(root->right, name);
        else {
            if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;

            TaskNode* temp = minValueNode(root->right);
            root->taskName = temp->taskName;
            root->right = deleteNode(root->right, temp->taskName);
        }
        return root;
    }

    void inOrder(TaskNode* root) {
        if (root) {
            inOrder(root->left);
            cout << root->taskName << endl;
            inOrder(root->right);
        }
    }

public:
    TaskNode* root = nullptr;

    void addTask(string name) {
        root = insert(root, name);
    }

    void deleteTask(string name) {
        root = deleteNode(root, name);
    }

    void searchTask(string name) {
        TaskNode* result = search(root, name);
        if (result)
            cout << "Task '" << name << "' found.\n";
        else
            cout << "Task '" << name << "' not found.\n";
    }

    void showTasks() {
        cout << "Task List (Alphabetical):\n";
        inOrder(root);
    }
};

// ===================
// Heap for Priorities
// ===================

class MaxHeap {
private:
    vector<pair<string, int>> heap;

    void heapifyDown(int i) {
        int largest = i;
        int left = 2*i+1, right = 2*i+2;

        if (left < heap.size() && heap[left].second > heap[largest].second)
            largest = left;
        if (right < heap.size() && heap[right].second > heap[largest].second)
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i) {
        while (i != 0 && heap[(i-1)/2].second < heap[i].second) {
            swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }

public:
    void insertTask(string name, int priority) {
        heap.push_back({name, priority});
        heapifyUp(heap.size() - 1);
    }

    void deleteTopTask() {
        if (heap.empty()) {
            cout << "No tasks in heap.\n";
            return;
        }

        cout << "Executing high-priority task: " << heap[0].first << "\n";
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void showHeapTasks() {
        cout << "Priority Queue Tasks:\n";
        for (auto& task : heap) {
            cout << task.first << " (Priority: " << task.second << ")\n";
        }
    }
};

// =========================
// Main Program
// =========================

int main() {
    TaskBST taskTree;
    MaxHeap taskHeap;
    int choice;
    string task;
    int priority;

    do {
        cout << "\n--- Task Manager Menu ---\n";
        cout << "1. Add Task (BST)\n";
        cout << "2. Delete Task (BST)\n";
        cout << "3. Search Task (BST)\n";
        cout << "4. Show All Tasks (BST In-order)\n";
        cout << "5. Add Task to Priority Queue (Heap)\n";
        cout << "6. Execute Top Priority Task\n";
        cout << "7. Show Priority Queue Tasks\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter task name: ";
                getline(cin, task);
                taskTree.addTask(task);
                break;
            case 2:
                cout << "Enter task name to delete: ";
                getline(cin, task);
                taskTree.deleteTask(task);
                break;
            case 3:
                cout << "Enter task name to search: ";
                getline(cin, task);
                taskTree.searchTask(task);
                break;
            case 4:
                taskTree.showTasks();
                break;
            case 5:
                cout << "Enter task name: ";
                getline(cin, task);
                cout << "Enter task priority (higher = more urgent): ";
                cin >> priority;
                cin.ignore();
                taskHeap.insertTask(task, priority);
                break;
            case 6:
                taskHeap.deleteTopTask();
                break;
            case 7:
                taskHeap.showHeapTasks();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
