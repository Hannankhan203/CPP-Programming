#include<iostream>
using namespace std;
int main () {
	int a, i = 1, sq, cb;
	cout<<"Input the value in a to calculate square and cube: \n";
	cin>>a;
	cout<<"The square and cube of "<<a<<" is: \n";
	cout<<"Numbers\tsquare\tcube\n";
	if (a > 0) {
		do {
			sq = i * i;
			cb = i * i * i;
			cout<<i<<"\t"<<sq<<"\t"<<cb<<endl;
			i++;	
		}
		while (i <= a);
		}
	else {
		cout<<"Input a number";
	}
