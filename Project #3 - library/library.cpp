#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Book {
    int id;
    int name;
    int total_borrowed;
    int total_quantity;

    vector<string> borrowed_names;
};

struct User {
    string name;
    int national_id;
    vector<int> borrowed_bookes_id;
};

struct Library
{
    void add_book() {}
    void search_books_by_prefix() {}
    void print_who_borrowed_book_by_name() {}
    void print_library_by_id() {}
    void print_library_by_name() {}
    void add_user() {}
    void user_borrow_book() {}
    void user_return_book() {}
    void print_users() {}


    int menu() {
        int choice = -1;
        while (choice == -1) {

            cout << "Library Menu;\n";
            cout << "1) add_book\n";
            cout << "2) search_books_by_prefix\n";
            cout << "3) print_who_borrowed_book_by_name\n";
            cout << "4) print_library_by_id\n";
            cout << "5) print_library_by_name\n";
            cout << "6) add_user\n";
            cout << "7) user_borrow_book\n";
            cout << "8) user_return_book\n";
            cout << "9) print_users\n";
            cout << "10) Exit\n\n";

            cout << "Enter your menu choice [1 - 10]: ";

            cin>>choice;
            if (!(choice>=1 && choice<=10)) {
                choice = -1;
            }

        }

        return choice;
    }

    void run() {
        while (true) {
            int choice = menu();

            if (choice == 10)
                break;
            if (choice == 1) {
                add_book();
            }
            else if (choice == 2) {
                search_books_by_prefix();
            }
            else if (choice == 3) {
                print_who_borrowed_book_by_name();
            }
            else if (choice == 4) {
                print_library_by_id();
            }
            else if (choice == 5) {
                print_library_by_name();
            }
            else if (choice == 6) {
                add_user();
            }
            else if (choice == 7) {
                user_borrow_book();
            }
            else if (choice == 8) {
                user_return_book();
            }
            else if (choice == 9) {
                print_users();
            }
        }
    }
};
int main()
{
    

    return 0;
}