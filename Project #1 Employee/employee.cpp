#include<iostream>
#include<string>
using namespace std;

const int MAX = 100;
string name[MAX];
int age[MAX];
double salary[MAX];
char gender[MAX];

int added = 0;

void add_employee() {
    cout<<"Enter your name\n";
    cin>>name[added];

    cout<<"Enter age\n";
    cin>>age[added];

    cout<<"Enter gender\n";
    cin>>gender[added];

    cout<<"Enter salary\n";
    cin>>salary[added];

    added++;
}
void printall_employee() {
    for(int i=0;i<added;i++) {

        if (age[i] != -1) {
            cout<<name[i]<<" "<<age<<" "<<gender<<" "<<salary[i]<<"\n";
        }
    }
}
void delete_by_age() {
    int start_age,end_age;
    cout<<"Enter start and end age\n";
    cin>>start_age>>end_age;

    for(int i=0;i<added;i++) {

        if (age[i]>=start_age && age[i]<=end_age) {
            age[i] = -1;
        }
    }
}

void update_salary() {
    string employee_name;
    double emplyee_salary;
    
    cout<<"Enter the name and salary\n";
    cin>>employee_name>>emplyee_salary;

    bool not_found = true;
    for(int i=0;i<added;i++) {
        //age[i] != -1 to ensure employee record is active
        if (name[i] == employee_name && age[i] != -1) {
            salary[i] = emplyee_salary;
            not_found = false;
            cout<<"Update employee salary\n";
            break;
        }
    }
    if (not_found ) 
        cout<<"No such employee"<<"\n";
   
}

int menu() {
    int choice = -1;
    while(choice == -1)
    {
        cout<<"Enter your choice:\n";
        cout<<"Enter 1 to Add new employee\n";
        cout<<"Enter 2 Print all employees\n";
        cout<<"Enter 3 Delete by age\n";
        cout<<"Enter 4 Update Salary by name\n";
        cout<<"Enter 5 to Exit\n";

        cin>>choice;

        if (!(choice>=1 && choice<=5)) 
        {
            cout<<"Invalid choice\n";
            cout<<'Again\n';

            choice = -1;
        }
    }
    return choice;
}
void employee_program() {

    while (true) {
        int choice = menu();

        if (choice == 1) {
            add_employee();
        }
        else if (choice == 2) {
            printall_employee();
        }
        else if (choice == 3) {
            delete_by_age();
        }
        else if (choice == 4) {
            update_salary();
        }
        else if(choice == 5){
            break;
        }
    }
}
void main() {
    employee_program();

}