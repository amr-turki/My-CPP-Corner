#include<iostream>
#include<string>
using namespace std;

const int QUEUE = 5;
const int SPECILIZATION = 5;
string names[SPECILIZATION+1][QUEUE];
int statiss[SPECILIZATION+1][QUEUE];

int added[SPECILIZATION+1]{};

void right_shift(int spec,string names[],int statiss[])
{
    int size = added[spec];

    for(int i = size -1; i>=0 ; i--)
    {
        names[i+1] = names[i];
        statiss[i+1] = statiss[i];
    }
    added[spec]++;
}
void AddPatient()
{
    int spec;
    string name;
    int statis;
    cout<<"Enter specialization, name, statis:\n";
    cin>>spec>>name>>statis;

    
    if(added[spec] < QUEUE)
    {
        if(statis == 0)
        {
            names[spec][added[spec]] = name;
            statiss[spec][added[spec]] = statis;

            added[spec]++;
        }
        else
        {
            right_shift(spec,names[spec],statiss[spec]);  
            names[spec][0] = name;
            statiss[spec][0] = statis;
        }
    }
    else{
        cout<<"Sorry we can not add more patients for this specialization\n";
        return;
    }
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