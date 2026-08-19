#include<iostream>
#include<string>
using namespace std;

int main() {
    const int MAX = 100;
    string names[MAX];
    int ages[MAX];
    double salaries[MAX];
    char genders[MAX];

    int added = 0;

    while (true) {
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

        if (choice == 1) {
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
        else if (choice == 2) {
            if (added == 0) {
                cout<<"No such employee"<<"\n";
                continue;
            }

            cout << "****************************\n";
            for(int i=0;i<added;i++) {

                if (ages[i] != -1) {
                    cout<<names[i]<<" "<<ages[i]<<" "<<genders[i]<<" "<<salaries[i]<<"\n";
                }
            }
        }
        else if (choice == 3) {
            int start_age,end_age;
            cout<<"Enter start and end age\n";
            cin>>start_age>>end_age;

            start_age = min(start_age,end_age);
            end_age = max(start_age,end_age);

            for(int i=0;i<added;i++) {

                if (ages[i]>=start_age && ages[i]<=end_age) {

                    ages[i] = -1;
                    added--;
                    continue;
                }
            }
        }
        else if (choice == 4) {
            string employee_name;
            double emplyee_salary;

            cout<<"Enter the name and salary\n";
            cin>>employee_name>>emplyee_salary;

            for(int i=0;i<added;i++) {
                //age[i] != -1 to ensure employee record is active
                if (names[i] == employee_name && ages[i] != -1) {
                    salaries[i] = emplyee_salary;

                    cout<<"Update employee salary\n";
                   continue;
                }
            }

            cout<<"No such employee"<<"\n";
        }
        else if(choice == 5){
            break;
        }

    }


    return 0;
}