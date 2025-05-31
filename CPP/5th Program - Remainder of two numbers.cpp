#include<iostream>
using namespace std;
int main(){
	int a, b, rem;
	cout<<"Input two values in a & b \n";
	cin>>a>>b;
	rem = a % b;
	cout<<"The remainder of a & b is : "<<rem;
	return 0;
}