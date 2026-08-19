#include<iostream>
#include<string>
using namespace std;

const int QUEUE = 5;
const int SPECILIZATION = 20;
string names[SPECILIZATION+1][QUEUE];
int statistics[SPECILIZATION+1][QUEUE];
int added[SPECILIZATION+1]{};

void shiftPatients(string names[],int statistics[],int size) {
    for (int i = size-1; i>=0; i--) {
        names[i+1] =names[i];
        statistics[i+1] =statistics[i];
    }
}

void addNewPatient() {
    int spec;
    string name;
    int statis;
    cout<<"Enter specialization, name, statis:\n";
    cin>>spec>>name>>statis;

     if (added[spec] == QUEUE) {
        cout<<"Sorry we can not add more patients for this specialization \n";
         return;
    }

    if (statis == 0) {
        names[spec][added[spec]] = name;
        statistics[spec][added[spec]] = statis;
    }
    else {
        shiftPatients(names[spec],statistics[spec],added[spec]);

        names[spec][0] = name;
        statistics[spec][0] = statis;
    }

    added[spec]++;
    cout<<"Added patient in specialization: "<<spec<<"\n";
}

void printSpecializationPatient(string names[],int statistics[], int size) {
    for (int i = 0; i < size; i++) {
        cout<<names[i]<<" ";
        if (statistics[i] == 0) {
            cout<<"regular\n";
        }
        else {
            cout<<"urgent\n";
        }
    }
}
void printAllPatients() {

    cout<<"***********************************\n";

    for (int specialization = 1; specialization < SPECILIZATION+1; specialization++) {

        if (added[specialization] == 0)
            continue;

        cout<<"There are "<<added[specialization]<<" patients in specialization "<<specialization<<"\n";
        printSpecializationPatient(names[specialization],statistics[specialization],added[specialization]);

    }
}

void removePatient(string names[],int statistics[],int size) {
    for (int i = 1; i < size; i++) {
        names[i-1] =names[i];
        statistics[i-1] =statistics[i];
    }
}
void getNextPatient() {
    int specialization;
    cout<<"Enter specialization:\n";
    cin>>specialization;

    if (added[specialization] == 0) {
        cout<<"No Patients at the moment. Have rest, Dr";
        return;
    }
    cout<<names[specialization][0]<<" please go with the Dr\n";

    removePatient(names[specialization],statistics[specialization],added[specialization]);
    added[specialization]--;
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
void hospitalProgram() {

    while (true) {
        int choice = menu();

        if (choice == 1) {
            addNewPatient();
        }
        else if (choice == 2) {
           printAllPatients();
        }
        else if (choice == 3) {
           getNextPatient();
        }
        else if(choice == 4){
            break;
        }
    }
}
int main()
{
    hospitalProgram();
    return 0;
}