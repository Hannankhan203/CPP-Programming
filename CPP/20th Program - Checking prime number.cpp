#include<iostream>
using namespace std;
int main(){
	int a, i;
	cout<<"Input a value in a to check if it's a prime number or not: \n";
	cin>>a;
	for(i = 2; i < a; i++) {
		if(a % i == 0) {
			cout<<"'"<<a<<"'"<<" is not a prime number";
			break;
		}
	}
	if(i == a){
	cout<<"'"<<a<<"'"<<" is a prime number";
	}
	return 0;
}