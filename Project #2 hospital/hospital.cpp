#include<iostream>
using namespace std;


int menu() {
    int choice = -1;
    while(choice == -1)
    {
        cout << "Enter your choice:\n";
        cout << "1) Add new patient\n";
        cout << "2) Print all patients\n";
        cout << "3) Get next patient\n";
        cout << "4) Exit\n";

        cin>>choice;

        if (!(choice>=1 && choice<=4)) 
        {
            cout<<"Invalid choice\n";
            cout<<'Again\n';

            choice = -1;
        }
    }
    return choice;
}
int main()
{

    return 0;
}