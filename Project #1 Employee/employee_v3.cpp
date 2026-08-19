#include<iostream>
#include<string>
using namespace std;

const int MAX = 100;
struct Employee
{
    private:
    string name;
    int age;
    double salary;
    char gender;
    int added;

    public:
    Employee(){
        added = 0;
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
    void run() {

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



    void add_employee() {
         if (added == MAX) {
            cout<<"No such employee"<<"\n";
            return;
        }


        cout<<"Enter your name\n";
        cin>>name;

        cout<<"Enter age\n";
        cin>>age;

        cout<<"Enter gender\n";
        cin>>gender;

        cout<<"Enter salary\n";
        cin>>salary;

        added++;

    }

    void printall_employee() const {
         if (added == 0) {
            cout << "****************************\n";
            cout<<"No such employee"<<"\n";
            return;
        }

        cout << "****************************\n";
    
        if (age != -1) {
                cout<<name<<" "<<age<<" "<<gender<<" "<<salary<<"\n";
        }
        
     }


    void delete_by_age() {
        int start_age,end_age;
        cout<<"Enter start and end age\n";
        cin>>start_age>>end_age;

        start_age = min(start_age,end_age);
        end_age = max(start_age,end_age);

        for(int i=0;i<added;i++) {

            if (age=start_age && age<=end_age) {

                age = -1;
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
            if (name == employee_name && age != -1) {
                salary = emplyee_salary;

                cout<<"Update employee salary\n";
                return;
            }
        }

        cout<<"No such employee"<<"\n";
    
    }

};

int main() {
    Employee emp;
    emp.run();

    return 0;
}