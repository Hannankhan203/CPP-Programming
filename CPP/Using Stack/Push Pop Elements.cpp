#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // Push elements
    s.push(10);  // Stack: [10]
    s.push(20);  // Stack: [10, 20]
    s.push(30);  // Stack: [10, 20, 30]

    // Perform pop()
    int popped_element = s.top();  // Get top element before popping
    s.pop();  // Remove the top element

    // Output results
    cout << "Popped Element: " << popped_element << endl;  // Output: 30
    cout << "Stack after pop(): ";
    while (!s.empty()) {
        cout << s.top() << " ";  // Prints remaining elements
        s.pop();
    }
    // Output: 20 10
    return 0;
}