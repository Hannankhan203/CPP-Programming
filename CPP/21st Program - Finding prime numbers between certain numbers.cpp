#include<iostream>
using namespace std;
int main(){
	int a, b, num;
	cout<<"Input two values in a & b to find out the prime and non-prime numbers between them: \n";
	cin>>a>>b;
	for(num = a; num <= b; num++){
		int i;
		for(i = 2; i < num; i++){
			if(num % i == 0){
				cout<<num<<" is not a prime number\n";
				break;
			}
		}
		if(i == num){
			cout<<num<<" is a prime number\n";
		}
	}
	return 0;
}