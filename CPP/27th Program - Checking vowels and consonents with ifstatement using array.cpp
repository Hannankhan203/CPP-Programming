#include<iostream>
using namespace std;
int main () {
	char vowels[] = {'a', 'e', 'i', 'o', 'u'};
	char ch;
	cout<<"Enter a character"<<endl;
	cin>>ch;
	bool isVowel = false;
	for (int i = 0; i < 5; ++i) {
		if (ch == vowels[i]) {
			isVowel = true;
			break;
		}
	}
	if (isVowel) {
		cout<<ch<<" is a vowel."<<endl;
	}
	else {
		cout<<ch<<" is a consonent."<<endl;
	}
	return 0;
}