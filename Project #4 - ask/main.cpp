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
    static int inline id = 150;
    string user_id;
public:
    string signUp() {
        auto status =  ios::in | ios::out | ios::app;
        fstream file_handler("users.txt",status);
        if (file_handler.fail()) {
            return "We can not open file\n";
        }

        user_id = to_string(++id);
        file_handler<<user_id<<",";
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


        return user_id;
    }
    string login() {
       ifstream file_handler("users.txt");
        if (file_handler.fail()) {
            return "We can not open file\n";
        }

        cout<<"Enter user name & password\n";
        getline(cin,user_name);
        getline(cin,password);

        string line;
        while (getline(file_handler,line)) {
            vector<string> results;
            istringstream in(line);
            string text;
            while (getline(in,text,',')) {
                results.push_back(text);
            }
            if (results[1] == user_name && results[2] == password) {
                return user_id;
            }
        }
        file_handler.close();

        return "User is not found";
    }


    bool user_found(const string& user_id) {
        ifstream file_handler("users.txt");
        if (file_handler.fail()) {
            cout<<"We can not open file\n";
            return false;
        }

        string line;
        while (getline(file_handler,line)) {
            vector<string> results;
            istringstream in(line);

            string text;
            while (getline(in,text,',')) {
                results.push_back(text);
            }
            if (results[0] == user_id) {
                file_handler.close();
                return true;
            }
        }
        file_handler.close();
        return false;
    }


    bool AllowAnonymousQuestions(const string& id) {
        bool allow = true;
        ifstream file_handler("users.txt");
        if (file_handler.fail()) {
            cout<<"We can not open file\n";
            return false;
        }

        string line;
        while (getline(file_handler,line)) {
            vector<string> results;
            istringstream in(line);

            string text;
            while (getline(in,text,',')) {
                results.push_back(text);
            }
            if (results[0] == id) {

                file_handler.close();
                if (results[5] != "1") {
                    allow = false;
                    break;
                }
            }
        }
        file_handler.close();

        return allow;
    }
};

class Questions
{
    private:
    string from_user_id;
    string to_user_id;
    string question_id;
    string text;
    string allow_anonymous_questions;
    string question_or_reply;
    string parent_id;

    static int inline id = 100;

    USERS user;

    public:
    void AskQuestionNoThread() {
        auto status =  ios::in | ios::out | ios::app;
        fstream file_handler("questions.txt",status);
        if (file_handler.fail()) {
            cout<<"We can not open file\n";
            return ;
        }
        id++;
        question_id = to_string(id);
        parent_id = "0";
        file_handler<<parent_id<<","<<question_or_reply<<","<<allow_anonymous_questions<<","<<text<<","<<question_id<<","<<to_user_id<<","<<from_user_id<<"\n";

        file_handler.close();
    }
    void AskQuestionInThread(const string& q_id) {
        auto status =  ios::in | ios::out | ios::app;
        fstream file_handler("questions.txt",status);
        if (file_handler.fail()) {
            cout<<"We can not open file\n";
            return ;
        }
        id++;
        question_id = to_string(id);
        parent_id = q_id;

        file_handler<<parent_id<<","<<question_or_reply<<","<<allow_anonymous_questions<<","<<text<<","<<question_id<<","<<to_user_id<<","<<from_user_id<<"\n";
        file_handler.close();
    }
    void AskQuestion(const string& fr_user_id) {
        from_user_id = fr_user_id;

        cout<<"Enter User id or -1 to cancel: \n";
        cin>>to_user_id;

        if (!user.user_found(to_user_id)) {
            cout<<"User is not found";
            return;
        }

        question_or_reply = "Q";

        if (!user.AllowAnonymousQuestions(to_user_id)) {
            cout<<"Note: Anonymous question  are not allowed for this user\n";

            allow_anonymous_questions = "0";

            cout<<"For thread question: Enter Question id or -1 for new question: \n";
            string id;
            cin>>id;
            cin.ignore();

            if (id == "-1") {
                cout<<"Enter question text:\n";
                getline(cin,text);

                AskQuestionNoThread();
            }
            else {
                cout<<"Enter question text:\n";
                getline(cin,text);

                AskQuestionInThread(id);
            }
        }
        else {
            cout<<"Note: Anonymous question allowed for this user\n";
            string choice;
            cout<<"ِAsk Anonymous question (0 or 1)\n";
            cin>>choice;

            if (choice == "0" ) {
                allow_anonymous_questions = "0";
            }
            else {
                allow_anonymous_questions = "1";
            }

            cout<<"For thread question: Enter Question id or -1 for new question: \n";
            string id;
            cin>>id;
            cin.ignore();

            if (id == "-1") {
                cout<<"Enter question text:\n";
                getline(cin,text);

                AskQuestionNoThread();
            }
            else {
                cout<<"Enter question text:\n";
                getline(cin,text);

                AskQuestionInThread(id);
            }

        }
    }
};
class AskMe
{
    private:
    USERS user;
    Questions question;
  
public:
    
    void printQuestionsToMe() {
    }

    void printQuestionsFromMe() {
    }

    void answerQuestion() {
    }

    void deleteQuestion() {
    }

    void askQuestion(const string& user_id) {
        question.AskQuestion(user_id);
    }

    void listSystemUsers() {
    }

    void feed() {
    }

    void logout() {
    }

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

        string user_id;
        if (choice == 1) {
            if ( user.login() == "We can not open file\n")
            {
                cout<<"We can not open file\n";
                return;
            }

            else if (user.login() == "User is not found") {
                cout<<"User is not found\n";
                return;
            }
            else {
                user_id = user.login();
            }

        }else {
            if (user.signUp() == "We can not open file\n") {
                cout<<"We can not open file\n";
            }
            else
                user_id = user.signUp();
        }

        while (true) {
            int choice = menu();

            if (choice == 1) {
                printQuestionsToMe();
            }
            else if (choice == 2) {
                printQuestionsFromMe();
            }
            else if (choice == 3) {
                answerQuestion();
            }
            else if (choice == 4) {
                deleteQuestion();
            }
            else if (choice == 5) {
                askQuestion(user_id);
            }
            else if (choice == 6) {
                listSystemUsers();
            }
            else if (choice == 7) {
                feed();
            }
            else if (choice == 8) {
                break;
                //logout();
            }
        }

        
    }
};
int main()
{
    AskMe askMe;
    askMe.run();


    return 0;
}