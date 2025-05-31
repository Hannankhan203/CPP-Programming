#include<iostream>
using namespace std;
int main(){
	float a, b, add, sub, mul, div;
	cout<<"Input two values in a & b \n";
	cin>>a>>b;
	add = a + b;
	sub = a - b;
	mul = a * b;
	div = a / b;
	cout<<"The Addition of a & b is : "<<add;
	cout<<"\nThe Subtraction of a & b is : "<<sub;
	cout<<"\nThe Multiplication of a & b is : "<<mul;
	cout<<"\nThe Division of a & b is : "<<div;
	return 0;
}