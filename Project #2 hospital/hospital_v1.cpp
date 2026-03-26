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
}
void AddPatient()
{
    int spec;
    string name;
    int statis;
    cout<<"Enter specialization, name, statis:\n";
    cin>>spec>>name>>statis;

     if (!(spec>=1 && spec<=5)) 
    {
        cout<<"Invalid input. Specialization must be in the range [1-5].\n";
        cout<<"Again\n";

        spec = -1;
         while(spec == -1)
         {
            cout<<"Enter specilization: ";

            cin>>spec;

            if (!(spec>=1 && spec<=5)) 
            {
                cout<<"Invalid input. Specialization must be in the range [1-5].\n";
                cout<<"Again\n";

                spec = -1;
            }
         }
        
    }
   
    
    if(added[spec] < QUEUE)
    {
        if(added[spec] == 0)
        {
            names[spec][0] = name;
            statiss[spec][0] = statis;
        }
        else if(statis == 0)
        {
            names[spec][added[spec]] = name;
            statiss[spec][added[spec]] = statis;
        }
        else
        {
            right_shift(spec,names[spec],statiss[spec]);  
            names[spec][0] = name;
            statiss[spec][0] = statis;
        }

        added[spec]++;
    }
    else{
        cout<<"Sorry we can not add more patients for this specialization\n";
        return;
    }
}
void PrintAllPatients()
{
   
    for(int spec = 1;spec<=SPECILIZATION;spec++)
    {
        if(added[spec] >= 1)
        {
            cout<<"There are "<<added[spec]<<" patients in specilization "<<spec<<"\n";
            for(int queue = 0;queue<added[spec];queue++)
                {
                    cout<<names[spec][queue]<<" ";
                    if(statiss[spec][queue] == 0)
                    {
                        cout<<"Regular\n";
                    }
                    else
                    {
                        cout<<"Urgent\n";
                    }

                }
        }
        
    }
}

void left_shift(int spec,string names[],int statiss[])
{
    int size = added[spec];

    for(int i = 1; i<size ; i++)
    {
        names[i-1] = names[i];
        statiss[i-1] = statiss[i];
    }
    added[spec]--;
}
void GetNextPatient()
{
    int spec = -1;
    while(spec == -1)
    {
        cout<<"Enter specilization: ";

        cin>>spec;

        if (!(spec>=1 && spec<=5)) 
        {
            cout<<"Invalid input. Specialization must be in the range [1-5].\n";
            cout<<"Again\n";

            spec = -1;
        }
    }

    if(added[spec]<1)
    {
        cout<<"No patients at the moment. Have rest, Dr\n";
        return;
    }

    cout<<names[spec][0]<<" please go with the Dr\n";
    left_shift(spec,names[spec],statiss[spec]);

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
            cout<<"Again\n";

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