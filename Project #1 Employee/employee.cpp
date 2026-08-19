#include<iostream>
#include<string>
using namespace std;

const int MAX = 100;
string names[MAX];
int ages[MAX];
double salaries[MAX];
char genders[MAX];

int added = 0;

void add_employee() {
    cout<<"Enter your name\n";
    cin>>names[added];

    cout<<"Enter age\n";
    cin>>ages[added];

    cout<<"Enter gender\n";
    cin>>genders[added];

    cout<<"Enter salary\n";
    cin>>salaries[added];

    added++;
}
void printall_employee() {
     if (added == 0) {
        cout << "****************************\n";
        cout<<"No such employee"<<"\n";
        return;
    }

    cout << "****************************\n";
    for(int i=0;i<added;i++) {

        if (ages[i] != -1) {
            cout<<names[i]<<" "<<ages[i]<<" "<<genders[i]<<" "<<salaries[i]<<"\n";
        }
    }
}
void delete_by_age() {
    int start_age,end_age;
    cout<<"Enter start and end age\n";
    cin>>start_age>>end_age;

    start_age = min(start_age,end_age);
    end_age = max(start_age,end_age);

    for(int i=0;i<added;i++) {

        if (ages[i]>=start_age && ages[i]<=end_age) {
          
            ages[i] = -1;
            added--;
            return;
        }
    }
}

void update_salary() {
    string employee_name;
    double emplyee_salary;
    
    cout<<"Enter the name and salary\n";
    cin>>employee_name>>emplyee_salary;

    for(int i=0;i<added;i++) {
        //age[i] != -1 to ensure employee record is active
        if (names[i] == employee_name && ages[i] != -1) {
            salaries[i] = emplyee_salary;

            cout<<"Update employee salary\n";
            return;
        }
    }
    

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
            cout<<"Again\n";

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
int main() {
    employee_program();

    return 0;
}