#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;


class USERS {
    string user_name;
    string password;
    string name;
    string email;
    string allow_anonymous_questions;
public:
    bool signUp() {
        auto status =  ios::out;
        fstream file_handler("users.txt",status);
        if (file_handler.fail()) {
            cout<<"We can not open file\n";
            return false;
        }


        std::cout << "Enter user name. (No spaces): ";
        getline(cin,user_name);
        file_handler<<user_name<<",";

        std::cout << "Enter password: ";
        getline(cin,password);
        file_handler<<password<<",";

        std::cout << "Enter name: ";
        getline(cin,name);
        file_handler<<name<<",";

        std::cout << "Enter email: ";
        getline(cin,email);
        file_handler<<email<<",";

        std::cout << "Allow anonymous questions?: (0 or 1) ";
        getline(cin,allow_anonymous_questions);
        file_handler<<allow_anonymous_questions<<"\n";
        file_handler.close();


        return true;
    }
    bool login() {
       ifstream file_handler("users.txt");
        if (file_handler.fail()) {
            cout<<"We can not open file\n";
            return false;
        }

        cout<<"Enter user name & password\n";
        getline(cin,user_name);
        getline(cin,password);

        string line;
        while (getline(file_handler,line)) {
            vector<string> results;
            istringstream in(line);
            while (getline(in,line,',')) {
                results.push_back(line);
            }
            if (results[0] == user_name && results[1] == password) {
                return true;
            }
        }
        file_handler.close();

        return false;
    }
};

class AskMe
{
    private:
    USERS user;
  
public:
    
    int menu() {
        int choice = -1;
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
        int choice;

        cout<<"Menu:\n";
        cout<<"\t1: Login\n";
        cout<<"\t2: Sign Up\n";
        cout<<"Enter number in range 1 - 2\n";
        cin >> choice;
        cin.ignore();

        bool status = true;
        if (choice == 1) {
           status = user.login();
        }else {
            status = user.signUp();
        }
        int choice = menu();
    }
};
int main()
{
    AskMe askMe;
    askMe.run();


    return 0;
}