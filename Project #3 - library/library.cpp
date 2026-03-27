#include<iostream>
using namespace std;

struct Library
{
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
};
int main()
{
    

    return 0;
}