#include<iostream>

using namespace std;

class AskMe
{
    private:
  
public:
    
    int menu() {
        int choice;
        while (choice == -1) {
            cout << "Menu:\n";
            cout << "\t1: Print Questions To Me\n";
            cout << "\t2: Print Questions From Me\n";
            cout << "\t3: Answer Question\n";
            cout << "\t4: Delete Question\n";
            cout << "\t5: Ask Question\n";
            cout << "\t6: List System Users\n";
            cout << "\t7: Feed\n";
            cout << "\t8: Logout\n\n";

            cout << "Enter number in range 1 - 8: 1523\n";
            cin>>choice;

            if (!(choice>=1 && choice<=8)) {
                cout << "ERROR: invalid number...Try again\n";
                choice = -1;
            }
        }

        return choice;
    }

    void run()
    {
        int choice = menu();
    }
};
int main()
{
    AskMe askMe;
    askMe.run();


    return 0;
}