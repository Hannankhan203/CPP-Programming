#include<iostream>
#include<string>
using namespace std;
const int maxCourses = 3;
const int maxAssignments = 3;
const int maxMarks = 10;
struct Course{
	string name;
	string teacher;
};
struct Assignment{
	int marks[maxAssignments];
};
Course courses[maxCourses];
Assignment assignments[maxCourses];
float calculateAverage(int marks[]){
	float sum = 0;
	for(int i = 0; i < maxAssignments; i++){
		sum += marks[i];
	}
	return sum / maxAssignments;
}
int main(){
	// Initialize courses and teachers
	courses[0] = {"Maths", "Mr. Faisal"};
	courses[1] = {"Science", "Ms. Sara"};
	courses[2] = {"English", "Ms. Hafsa"};
	// Input assignment marks for each course
	for(int i = 0; i < maxCourses; i++){
		cout<<"Enter marks for "<<courses[i].name<<" course:"<<endl;
		for(int j = 0; j < maxAssignments; j++){
			cout<<"Assignment "<<j + 1<<": ";
			cin>>assignments[i].marks[j];
		}
	}
	// Calculate and display average marks for each course
	for(int i = 0; i < maxCourses; i++){
		float average = calculateAverage(assignments[i].marks);
		cout<<"Average marks for "<<courses[i].name<<" course: "<<average<<endl;
	}
	return 0;
}