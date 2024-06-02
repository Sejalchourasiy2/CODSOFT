#include<iostream>
#include<cstdlib> //To generate random number
using namespace std;
int main()
{
    string name;
    char input;
    int inputuser;
    int score;
    cout<<"Enter Your name     ";
    getline(cin,name);  //getline ->to print the whole line if we use only cin so output will print just "name"
    cout<<endl;
    do
    {
        srand(0); // to always generate a random number
        int  variable=rand()%5 +1; // +1 is used to start game from 1 not 0.
        cout<<"Enter any number in between range 1 to 5";
        cin>>inputuser;
        cout<<endl;
        if(inputuser==variable)
        {
            cout<<"Congratulations ! You guess a correct number "<<endl;
            score++;
        }
        else{
            cout<<"sorry , You guessed wrong number please try again" <<endl;
        }
        cout<<"would you like to try again Y/N  ";
        cin>>input;
        cout<<endl;
    } while (input!='N');
    cout<<"Your score is     "<<score<<endl;
    cout<<"Game end"<<endl;
    
}