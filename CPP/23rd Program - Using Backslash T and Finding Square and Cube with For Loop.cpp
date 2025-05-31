#include<iostream>
using namespace std;
int main () {
	int a, i, sq, cb;
	cout<<"Input the value in a to calculate square and cube: \n";
	cin>>a;
	cout<<"The square and cube of "<<a<<" is: \n";
	cout<<"Numbers\tsquare\tcube\n";
	for (i = 1; i <= a; i++) {
		sq = i * i;
		cb = i * i * i;
		cout<<i<<"\t"<<sq<<"\t"<<cb<<endl;
	}
	return 0;
}
