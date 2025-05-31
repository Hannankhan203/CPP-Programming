#include<iostream>
using namespace std;
int main () {
	char alphabet;
	cout<<"Enter any alphabet to check if it's a vowel or consonent."<<endl;
	cin>>alphabet;
	alphabet = tolower(alphabet);
	if (alphabet == 'a' || alphabet == 'e' || alphabet == 'i' || alphabet == 'o' || alphabet == 'u') {
		cout<<"It's a vowel";
	}
	else {
		cout<<"It's a consonent";
	}
	return 0;
}