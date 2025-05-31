#include<iostream>
using namespace std;
int main(){
	int a, i, cu;
	cout<<"Input a value in a to calculate it's cube : \n";
	cin>>a;
	for (i = 1; i <= a; i++){
		cu = i * i * i;
		cout<<i<<"="<<cu<<"\n";
	}
	return 0;
}