#include<iostream>
using namespace std;
int main(){
	int a, count, fact = 1;
	cout<<"Input a value in a to calculate it's factorial : \n";
	cin>>a;
	if (a >= 0){
		for(count = 1; count <= a; count++){
		fact = fact * count;
	}
		cout<<"The factorial of "<<a<<" is : "<<fact;
	}
	else{
		cout<<"Negative numbers don't have any factorial";
	}
	return 0;
}