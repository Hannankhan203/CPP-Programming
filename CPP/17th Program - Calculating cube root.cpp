#include<iostream>
#include<cmath>
using namespace std;
int main(){
	float a, crt;
	cout<<"Input a value in a to calculate it's cube root : \n";
	cin>>a;
	crt = cbrt(a);
	cout<<"The cube root of "<<a<<" is "<<crt;
	return 0;
}