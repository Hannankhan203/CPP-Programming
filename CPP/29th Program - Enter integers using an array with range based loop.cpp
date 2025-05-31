#include<iostream>
using namespace std;
int main(){
	int size = 5;
	int Array[size];
	cout<<"Enter "<<size<<" numbers"<<endl;
	for(int num : Array){
		cin>>num;
	}
	cout<<"You entered: "<<endl;
	for(int num : Array){
		cout<<num<<" "<<endl;
	}
	cout<<endl;
	return 0;
}