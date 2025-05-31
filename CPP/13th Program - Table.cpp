#include<iostream>
using namespace std;
int main(){
	int a;
	cout<<"Input a value in a to view it's table : \n";
	cin>>a;
	cout<<"The table of "<<a<<" is : \n";
	for(int i = 1; i <= 10; i++){
		cout<<a<<"*"<<i<<"="<<a * i<<"\n";
	}
	return 0;
}