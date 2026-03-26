#include<iostream>
using namespace std;
bool AddPatient()
{
    
}
void PrintAllPatients()
{

}
bool GetNextPatient()
{

}
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
void hospital_program() {

    while (true) {
        int choice = menu();

        if (choice == 1) {
            AddPatient();
        }
        else if (choice == 2) {
            PrintAllPatients();
        }
        else if (choice == 3) {
            GetNextPatient();
        }
        else if(choice == 4){
            break;
        }
    }
}
int main()
{
    hospital_program();
    return 0;
}