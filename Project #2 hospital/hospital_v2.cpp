#include<iostream>
#include<string>
using namespace std;

const int QUEUE = 5;
const int SPECILIZATION = 5;
struct Queue
{
    
    string names[QUEUE];
    int statiss[QUEUE];
    int size;
    int spec;
    Queue(int spec)
    {
        size = 0;
        this->spec = spec;
    }
    Queue()
    {
        size = 0;
        this->spec = -1;
    }


    
    void right_shift()
    {
       
        for(int i = size -1; i>=0 ; i--)
        {
            names[i+1] = names[i];
            statiss[i+1] = statiss[i];
        }
    }
    bool AddPatient(int spec,string name,int statis)
    {

        if(size < QUEUE)
        {
            if(size == 0)
            {
                names[0] = name;
                statiss[0] = statis;
            }
            else if(statis == 0)
            {
                names[size] = name;
                statiss[size] = statis;
            }
            else
            {
                right_shift();  
                names[0] = name;
                statiss[0] = statis;
            }

            size++;

            return true;
        }
        else{
            cout<<"Sorry we can not add more patients for this specialization\n";
            return false;
        }
    }

     void PrintAllPatients()
     {
            if(size >= 1)
            {
                cout<<"There are "<<size<<" patients in specilization "<<spec<<"\n";
                for(int queue = 0;queue<size;queue++)
                    {
                        cout<<names[queue]<<" ";
                        if(statiss[queue] == 0)
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

    void left_shift()
    {
          
        for(int i = 1; i<size ; i++)
        {
            names[i-1] = names[i];
            statiss[i-1] = statiss[i];
        }
        size--;
    }

    bool GetNextPatient()
    {

        if(size<1)
            return false;
        

        cout<<names[0]<<" please go with the Dr\n";
        left_shift();


        return true;
    }

};

struct Hospital
{    
    Queue queues[SPECILIZATION+1];
    Hospital()
    {
        for(int i=1;i<=SPECILIZATION;i++)
        {
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
        
        bool status  = queues[spec].AddPatient(spec,name,statis);
        
        if(status == true)
        {
            cout<<"Patient added to this specialization\n";
        }
        else
        {
            cout<<"Sorry we can not add more patients for this specialization\n";
        }
   
    }

    void PrintAllPatients()
    {
   
        for(int spec = 1;spec<=SPECILIZATION;spec++)
        {
            queues[spec].PrintAllPatients();
            
        }
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
        bool status  = queues[spec].GetNextPatient();


        if(status == false)
        {
            cout<<"No patients at the moment. Have rest, Dr\n";
            return;
        }

    }

};

int main()
{
    Hospital Hospital;
    Hospital.run();

    return 0;
}