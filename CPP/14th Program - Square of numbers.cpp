#include<iostream>
using namespace std;
int main(){
	int a, i, sq;
	cout<<"Input a value in a to calculate it's square : \n";
	cin>>a;
	for(i = 1; i <= a; i++){
		sq = i * i;
		cout<<i<<"="<<sq<<"\n";
	}
	return 0;
}