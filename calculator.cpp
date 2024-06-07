#include <iostream>
using namespace std;

int main(){

    double num1, num2;
    char opr;

    cout<<"Enter the Operator ( +,-,*,/):";
    cin>>opr;

    cout<<"Enter the two numbers one by one :";
    cin>>num1>>num2;

    switch ( opr)
    {
        case  '+':
        cout << num1 <<opr <<num2 <<"="<< num1+num2 <<endl;
        break;
        case  '-':
        cout << num1 <<opr <<num2 <<"="<< num1-num2 <<endl;
        break;
        case  '*':
        cout << num1 <<opr <<num2 <<"="<< num1*num2 <<endl;
        break;
        case  '/':
        if(num2 == 0.0)
        {
            cout<< "Divide by Zero Situation" << endl;
        }
        else{
        cout << num1 <<opr <<num2 <<"="<< num1/num2 <<endl;
        }
        break;

        default:
        cout<<"Invalid operator";

    }
}

