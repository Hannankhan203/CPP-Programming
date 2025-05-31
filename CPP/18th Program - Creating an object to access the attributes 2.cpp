#include<iostream>
#include<cstring>
using namespace std;
class person{
	public:
		void getdetails() {}
	char name[20];
	int id;
};
int main(){
	person p1;
	p1.id = 20;
	strcpy(p1.name, "Abdul Hannan Khan");
	cout<<p1.id<<"\n";
	cout<<p1.name;
	return 0;
}