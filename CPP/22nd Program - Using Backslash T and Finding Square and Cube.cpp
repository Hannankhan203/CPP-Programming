#include<iostream>
using namespace std;

int main () {
	int a, sq, cb;
	cout<<"Input a value in a to find it's square and cube: \n";
	cin>>a;
	cout<<"Number\tsquare\tcube"<<endl;
	sq = a * a;
	cb = a * a * a;
	cout<<a<<"\t"<<sq<<"\t"<<cb;
	return 0;
}