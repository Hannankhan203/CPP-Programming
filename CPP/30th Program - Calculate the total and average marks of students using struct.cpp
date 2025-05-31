#include<iostream>
#include<string>
using namespace std;

struct Student {
	string name;
	int rollNumber;
	int marks[3];
};

void displayStudent(Student s) {
	cout<<"Name: "<<s.name<<endl;
	cout<<"Roll Number: "<<s.rollNumber<<endl;
	cout<<"Marks: ";
	for(int i = 0; i < 3; i++) {
		cout<<s.marks[i]<<" ";
	}
	cout<<endl;
}

void calculateTotalAndAverage(Student s){
	int total = 0;
	for(int i = 0; i < 3; i++){
		total += s.marks[i];
	}
	double average = total/3.0;
	cout<<"Total Marks: "<<total<<endl;
	cout<<"Average Marks: "<<average<<endl;
}

int compareStudents(Student s1, Student s2){
	int total1 = 0, total2 = 0;
	for(int i = 0; i < 3; i++){
		total1 += s1.marks[i];
		total2 += s2.marks[i];
	}
	if(total1 > total2){
		return 1;
	}
	else if(total1 < total2){
		return -1;
	}
	else{
		return 0;
	}
}

int main(){
	Student student1 = {"Alice", 1, {85, 90, 95}};
	Student student2 = {"Bob", 2, {70, 80, 75}};
	
	displayStudent(student1);
	calculateTotalAndAverage(student2);
	
	int comparision = compareStudents(student1, student2);
	if(comparision > 0){
		cout<<"Student 1 has higher total marks."<<endl;
	}
	else if(comparision < 0){
		cout<<"Student 2 has higher total marks."<<endl;
	}
	else{
		cout<<"Both students have the same total marks."<<endl;
	}
	
	return 0;
}