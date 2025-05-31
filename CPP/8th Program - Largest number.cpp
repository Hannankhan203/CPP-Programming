#include<iostream>
using namespace std;
int main(){
	int a, b, c;
	cout<<"Input three values in a, b & c \n";
	cin>>a>>b>>c;
	if(a >= b && a >= c){
		cout<<"The largest number is : "<<a;
	}
	else if(b >= a && b >= c){
		cout<<"The largest number is : "<<b;
	}
	else if(c >= a && c >= b){
		cout<<"The largest number is : "<<c;
	}
	return 0;
}