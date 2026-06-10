#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
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
                return results[0];
            }
        }
        file_handler.close();

        return "User is not found";
    }

    void ListSystemUsers()
    {
        ifstream file_handler("users.txt");
        if (file_handler.fail()) {
            cout<<"Can not open file\n";
            return ;
        }

        string line;
        while (getline(file_handler,line)) {
            vector<string> results;
            istringstream in(line);

            string text;
            while (getline(in,text,',')) {
                results.push_back(text);
            }

            if (results.empty()) {
                cout<<"No users found\n";
                return;
            }
            cout<<"ID: "<<results[0]<<"\t"<<"Name: "<<results[1]<<"\n";
        }


        file_handler.close();
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
    string answer;
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
        file_handler << parent_id << "," << allow_anonymous_questions << "," << text << "," << question_id << "," << to_user_id << "," << from_user_id << "," << answer << "\n";

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

        file_handler << parent_id << "," << allow_anonymous_questions << "," << text << "," << question_id << "," << to_user_id << "," << from_user_id << "," << answer << "\n";
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
    void PrintQuestionsToMe(const string& user_id) {
        vector<Questions> parent_questions;
        map<string, vector<Questions>> threads;

        ifstream file_handler("questions.txt");
        if (file_handler.fail()) {
            cout << "Can not open file\n";
            return;
        }

        string line;
        while (getline(file_handler, line)) {
            if (line.empty()) continue;
            istringstream in(line);
            Questions q;

            if (getline(in, q.parent_id, ',') &&
                getline(in, q.allow_anonymous_questions, ',') &&
                getline(in, q.text, ',') &&
                getline(in, q.question_id, ',') &&
                getline(in, q.to_user_id, ',') &&
                getline(in, q.from_user_id, ',') &&
                getline(in, q.answer, '\n')) {

                if (q.parent_id == "0") {
                    parent_questions.push_back(q);
                } else {
                    threads[q.parent_id].push_back(q);
                }
            }
        }
        file_handler.close();

        for (int i = 0; i < parent_questions.size(); i++) {
            if (parent_questions[i].to_user_id == user_id) {
                cout << "Question ID: (" << parent_questions[i].question_id << ") ";

                if (parent_questions[i].allow_anonymous_questions == "1") {
                    cout << "from user id (-1)";
                } else {
                    cout << "from user id (" << parent_questions[i].from_user_id << ")";
                }

                cout << "\t Question: " << parent_questions[i].text << "\n";

                if (!parent_questions[i].answer.empty()) {
                    cout << "\t Answer: " << parent_questions[i].answer << "\n";
                }

                string curr_id = parent_questions[i].question_id;
                for (int j = 0; j < threads[curr_id].size(); j++) {
                    cout << "\tThread: Question Id (" << threads[curr_id][j].question_id << ") ";

                    if (threads[curr_id][j].allow_anonymous_questions == "1") {
                        cout << "from user id (-1)";
                    } else {
                        cout << "from user id (" << threads[curr_id][j].from_user_id << ")";
                    }

                    cout << "\t Question: " << threads[curr_id][j].text << "\n";

                    if (!threads[curr_id][j].answer.empty()) {
                        cout << "\t\t Thread Answer: " << threads[curr_id][j].answer << "\n";
                    }
                }
                cout << "\n";
            }
        }
    }

    void PrintQuestionsFromMe(const string& user_id) {
        ifstream file_handler("questions.txt");
        if (file_handler.fail()) {
            cout << "Can not open file\n";
            return;
        }

        string line;
        while (getline(file_handler, line)) {
            if (line.empty()) continue;
            istringstream in(line);
            Questions q;

            if (getline(in, q.parent_id, ',') &&
                getline(in, q.allow_anonymous_questions, ',') &&
                getline(in, q.text, ',') &&
                getline(in, q.question_id, ',') &&
                getline(in, q.to_user_id, ',') &&
                getline(in, q.from_user_id, ',') &&
                getline(in, q.answer, '\n')) {

                if (q.from_user_id == user_id) {
                    if (q.parent_id != "0") {
                        cout << "\tThread Parent ID (" << q.parent_id << ") ";
                    }

                    cout << "Question ID: (" << q.question_id << ") ";

                    if (q.allow_anonymous_questions == "0") {
                        cout << "!AQ ";
                    }

                    cout << "to user id (" << q.to_user_id << ")\t Question: " << q.text << "\n";

                    if (!q.answer.empty()) {
                        cout << "\t Answer: " << q.answer << "\n";
                    } else {
                        cout << "\t NOT Answered YET\n";
                    }
                    cout << "\n";
                }
            }
        }
        file_handler.close();
    }
};
class AskMe
{
    private:
    USERS user;
    Questions question;
  
public:
    
    void printQuestionsToMe(const string& user_id) {
        question.PrintQuestionsToMe(user_id);
    }

    void printQuestionsFromMe(const string& user_id) {
        question.PrintQuestionsFromMe(user_id);
    }

    void answerQuestion() {
    }

    void deleteQuestion() {
    }

    void askQuestion(const string& user_id) {
        question.AskQuestion(user_id);
    }

    void listSystemUsers() {
        user.ListSystemUsers();
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
            string result = user.login();
            if ( result == "We can not open file\n")
            {
                cout<<result;
                return;
            }

            else if (result == "User is not found") {
                cout<<result;
                return;
            }
            else {
                user_id = result;
            }

        }else {
            string result = user.signUp();
            if (result == "We can not open file\n") {
                cout<<result;
            }
            else
                user_id = result;
        }

        while (true) {
            int choice = menu();

            if (choice == 1) {
                printQuestionsToMe(user_id);
            }
            else if (choice == 2) {
                printQuestionsFromMe(user_id);
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