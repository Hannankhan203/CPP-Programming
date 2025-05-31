#include <iostream>
using namespace std;

const int SIZE = 5;

class PrinterQueue {
	private:
		string tasks[SIZE];
		int front, rear;
		
	public:
		PrinterQueue() {
			front = rear = -1;
		}
		
		bool isEmpty() {
			return front == -1;
		}
		
		bool isFull() {
			return (rear + 1) % SIZE == front;
		}
		
		void Enqueue(string task) {
			if(isFull()) {
				cout << "Queue if full. Cannot add new print task.\n";
				return;
			}
			
			if(isEmpty()) {
				front = rear = 0;
			} else {
				rear = (rear + 1) % SIZE;
			}
			
			tasks[rear] = task;
			cout << "Added print task: " << task << endl;
		}
		
		void Dequeue() {
			if(isEmpty()) {
				cout << "No tasks to print.\n";
				return;
			}
			
			cout << "Printing: " << tasks[front] << endl;
			if(front == rear) {
				front = rear = -1;
			} else {
				front = (front + 1) % SIZE;
			}
		}
		
		bool isInList(string task) {
			if(isEmpty()) {
				return false;
			}
			
			int i = front;
			while(true) {
				if(tasks[i] == task) {
					return true;
				}
				if(i == rear) {
					break;
				}
				i = (i + 1) % SIZE;
			}
			return false;
		}
		
		void displayQueue() {
			if(isEmpty()) {
				cout << "Queue is empty.\n";
				return;
			}
			
			cout << "Current print queue: ";
			int i = front;
			while(true) {
				cout << tasks[i] << " ";
				if(i == rear) {
					break;
				}
				i = ( i + 1) % SIZE;
			}
			cout << endl;
		}
};

int main() {
	PrinterQueue pq;
	pq.Enqueue("Doc1");
	pq.Enqueue("Doc2");
	pq.Enqueue("Doc3");
	pq.displayQueue();
	
	pq.Dequeue();
	pq.Enqueue("Doc4");
	pq.Enqueue("Doc5");
	pq.Enqueue("Doc6");
	pq.displayQueue();
	
	cout << "Is Doc3 in queue? " << (pq.isInList("Doc3") ? "Yes" : "No") << endl;
	
	return 0;
}