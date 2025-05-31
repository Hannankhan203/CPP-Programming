#include <iostream>
using namespace std;

struct Patient {
	string name;
	int priority;
	Patient* next;
};

class PriorityQueue {
	private:
		Patient* head;
		
	public:
		PriorityQueue() {
			head = nullptr;
		}
		
		void Enqueue(string name, int priority) {
			Patient* newPatient = new Patient{name, priority, nullptr};
			
			if(head == nullptr || priority < head->priority) {
				newPatient->next = head;
				head = newPatient;
			} else {
				Patient* temp = head;
				while(temp->next && temp->next->priority <= priority) {
					temp = temp->next;
				}
				newPatient->next = temp->next;
				temp->next = newPatient;
			}
			
			cout << "Patient " << name << " (Priority " << priority << ") added to the queue.\n";
		}
		
		void Dequeue() {
			if(head == nullptr) {
				cout << "No patients to treat.\n";
				return;
			}
			
			Patient* temp = head;
			cout << "Treating patient: " << temp->name << " (Priority " << temp->priority << ")\n";
			head = head->next;
			delete temp;
		}
		
		void displayQueue() {
			if(!head) {
				cout << "No patients in queue.\n";
				return;
			}
			
			Patient* temp = head;
			cout << "Patients in queue:\n";
			while(temp) {
				cout << "- " << temp->name << " (Priority " << temp->priority << ")\n";
				temp = temp->next;
			}
		}
};

int main() {
	PriorityQueue er;
	er.Enqueue("Alice", 2);
	er.Enqueue("Bob", 1);
	er.Enqueue("Charlie", 3);
	er.Enqueue("Dana", 0);
	er.displayQueue();
	er.Dequeue();
	er.Dequeue();
	er.displayQueue();
	
	return 0;
}