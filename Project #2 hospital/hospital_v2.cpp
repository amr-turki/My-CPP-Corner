#include<iostream>
#include<string>
using namespace std;

const int QUEUE = 5;
const int SPECLIAZTION = 20;

struct Queue {
    string names[QUEUE];
    int statistics[QUEUE];

    int added;
    int spec;

    Queue() {
        added = 0;
        spec = -1;
    }
    Queue(const int& spec) {
        this->spec = spec;
        added = 0;
    }

    void shiftPatients() {
        for (int i = added-1; i>=0; i--) {
            names[i+1] =names[i];
            statistics[i+1] = statistics[i];
        }
    }

    bool addNewPatient(const string& name,const int& statis) {
        if (added == QUEUE) {
            return false;
        }

        if (statis == 0) {
            names[added] = name;
            statistics[added] = statis;
        }
        else {
            shiftPatients();

            names[0] = name;
            statistics[0] = statis;
        }

        added++;

        return true;
    }

    void printSpecializationPatient() {
        if (added == 0)
            return;


        cout<<"There are "<<added<<" patients in specialization "<<spec<<"\n";
        for (int i = 0; i < added; i++) {
            cout<<names[i]<<" ";
            if (statistics[i] == 0) {
                cout<<"regular\n";
            }
            else {
                cout<<"urgent\n";
            }
        }
    }
    void removePatient() {
        for (int i = 1; i < added; i++) {
            names[i-1] =names[i];
            statistics[i-1] =statistics[i];
        }
    }
    void getNextPatient() {
        if (added == 0) {
            cout<<"No Patients at the moment. Have rest, Dr\n";
            return;
        }
        cout<<names[0]<<" please go with the Dr\n";

        removePatient();
        added--;
    }

};

struct HospitalSystem {
    Queue queues[SPECLIAZTION+1];

    HospitalSystem() {
        for (int i = 0; i < SPECLIAZTION+1; i++) {
            queues[i] = Queue(i);
        }
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


    void run() {
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
            else if (choice == 4) {
                break;
            }
        }
    }

    void addNewPatient() {
        int spec;
        string name;
        int statis;
        cout<<"Enter specialization, name, statis:\n";
        cin>>spec>>name>>statis;


        bool status = queues[spec].addNewPatient(name,statis);
        if (!status) {
            cout<<"Sorry we can not add more patients for this specialization \n";
        }
        else
        cout<<"Added patient in specialization: "<<spec<<"\n";
    }
    void printAllPatients() {
        cout<<"***********************************\n";
        for (int specialization = 1; specialization < SPECLIAZTION+1; specialization++) {
            queues[specialization].printSpecializationPatient();

        }
    }

    void getNextPatient() {
        int specialization;r
        cout<<"Enter specialization:\n";
        cin>>specialization;

        queues[specialization].getNextPatient();
    }
};
int main() {
    HospitalSystem hospitalSystem;
    hospitalSystem.run();

    return 0;
}