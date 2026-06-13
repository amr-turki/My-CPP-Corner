#include<iostream>
#include<string>
using namespace std;

const int MAX = 100;

class Employee
{
    private:
    string name;
    int age;
    double salary;
    char gender;

    public:
    Employee() = default;

    void add_employee() {
        cout<<"Enter your name\n";
        cin>>name;

        cout<<"Enter age\n";
        cin>>age;

        cout<<"Enter gender\n";
        cin>>gender;

        cout<<"Enter salary\n";
        cin>>salary;

    }

    void printall_employee() const {
      
        if (age != -1) {
                cout<<name<<" "<<age<<" "<<gender<<" "<<salary<<"\n";
        }
        
     }


    void delete_by_age(const int& start_age,const int& end_age) {

      
        if (age>=start_age && age<=end_age) {
                age = -1;
        }
        
    }


    bool update_salary(const string& employee_name,const double& emplyee_salary) {

            //age[i] != -1 to ensure employee record is active
        if (name == employee_name && age != -1) {
            salary = emplyee_salary;

            return true;
        }

        return false;


 }

};

class EmployeeProgram
{
    private:
    Employee* emp;
    static int inline added = 0;

    public:
    EmployeeProgram()
    {
        emp = new Employee[MAX];
    }

    void add_employee() {
        if(added == MAX)
        {
            cout<<"Can not add more employees\n";
            return;

        }
     
        emp[added].add_employee();
        added++;
    }

    void printall_employee() {
        for(int i=0;i<added;i++)
       {
         emp[i].printall_employee();
       }
    } 


    void delete_by_age() {
        int start_age,end_age;
        cout<<"Enter start and end age\n";
        cin>>start_age>>end_age;

        for(int i = 0;i<added;i++)
        emp[i].delete_by_age(start_age,end_age);
    }



    void update_salary() {
        string employee_name;
        double emplyee_salary;
        
        cout<<"Enter the name and salary\n";
        cin>>employee_name>>emplyee_salary;

        bool found = false;
        for(int i=0;i<added;i++){
            found  = emp[i].update_salary(employee_name,emplyee_salary);

            if(found == true)
            {
                break;
            }
        }

        if(found)
            cout<<"Update employee salary\n";
        else
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
    ~EmployeeProgram()
    {
        delete[] emp;
        emp = nullptr;
    }

};
int  main() {
    EmployeeProgram* object = new EmployeeProgram();
    object->run();

    delete object;
    object = nullptr;


    return 0;
}