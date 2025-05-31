#include<iostream>
using namespace std;
int main(){
	int a = 10, b = 20;
	cout<<a<<"\t"<<b<<endl;
	int temp = a;
	a = b;
	b = temp;
	cout<<"\n"<<a<<"\t"<<b<<endl;
	return 0;
}