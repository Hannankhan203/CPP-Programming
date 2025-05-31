#include<iostream>
using namespace std;
int main () {
	int myArray[5] = {10, 20, 30, 40, 50};
	cout<<"First element: "<<myArray[0]<<endl;
	cout<<"Second element: "<<myArray[1]<<endl;
	cout<<"Third element: "<<myArray[2]<<endl;
	myArray[1] = 25;
	for(int i = 0; i < 4; i++){
		cout<<"Updated: " <<myArray[1]<<endl;
	}
	return 0;
}