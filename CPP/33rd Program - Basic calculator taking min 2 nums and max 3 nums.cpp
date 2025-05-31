#include <iostream>
using namespace std;
// Function prototypes
float add(float, float, float = 0);
float subtract(float, float, float = 0);
float multiply(float, float, float = 0);
float divide(float, float, float = 0);
int main(){
    int choice;
    float num1, num2, num3;
    cout<<"Basic Calculator Program"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"1. Addition"<<endl;
    cout<<"2. Subtraction"<<endl;
    cout<<"3. Multiplication"<<endl;
    cout<<"4. Division"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    while(choice!= 5){
        switch(choice){
            case 1:
                cout<<"Enter two or three numbers: ";
                cin>>num1>>num2>>num3;
                cout<<"Result: "<<add(num1, num2, num3)<<endl;
                break;
            case 2:
                cout<<"Enter two or three numbers: ";
                cin>>num1>>num2>>num3;
                cout<<"Result: "<<subtract(num1, num2, num3)<<endl;
                break;
            case 3:
                cout<<"Enter two or three numbers: ";
                cin>>num1>>num2>>num3;
                cout<<"Result: "<<multiply(num1, num2, num3)<<endl;
                break;
            case 4:
                cout<<"Enter two numbers: ";
                cin>>num1>>num2;
                if(num2!= 0){
                    cout<<"Result: "<< divide(num1, num2)<<endl;
                }
				else{
                    cout<<"Error: Division by zero!"<<endl;
                }
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
        cout<<"Enter your choice: ";
        cin>>choice;
    }
    return 0;
}
// Function definitions
float add(float a, float b, float c){
    if(c == 0){
        return a + b;
    }
	else{
        return a + b + c;
    }
}
float subtract(float a, float b, float c){
    if(c == 0){
        return a - b;
    }
	else{
        return a - b - c;
    }
}
float multiply(float a, float b, float c){
    if(c == 0){
        return a * b;
    }
	else{
        return a * b * c;
    }
}
float divide(float a, float b, float c){
    if(c!= 0){
        return a / b / c;
    }
	else{
        return a / b;
    }
}