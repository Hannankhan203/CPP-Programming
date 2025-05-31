#include<iostream>
using namespace std;
int main(){
	int size = 5;
	int Array[size];
	cout<<"Enter "<<size<<" integers:"<<endl;
	for(int i = 0; i < size; ++i){
		cout<<"Enter integer "<<i + 1<<": "<<endl;
		cin>>Array[i]; 
	}
	cout<<"You entered: "<<endl;
	for(int i = 0; i < size; ++i){
		cout<<Array[i]<<" "<<endl;
	}
		cout<<endl;
		return 0;
}