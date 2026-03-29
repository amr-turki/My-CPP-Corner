#include<iostream>
#include<vector>
#include<string>
#include <algorithm>

using namespace std;

const int MAX_BOOKS = 10;
const int MAX_USERS = 5;

struct Book {
    int id;
    string name;
    int total_borrowed;
    int total_quantity;

    vector<string> borrowed_names;

    Book()
    {
        total_borrowed = 0;
    }

    bool borrrow(string user_name) {
        if (total_borrowed == total_quantity) {
            cout<<"Sorry, no available copies for this book at the moment.\n";
            return false;
        }
        borrowed_names.push_back(user_name);

        total_borrowed++;
      

        return true;
    }

    void who_borrowed_book() {
        if (borrowed_names.size() == 0) {
            cout << "No users borrowed this book yet.\n";
            return;
        }

        for (int i = 0;i<borrowed_names.size();i++) {
            cout<<borrowed_names[i]<<"\n";
        }
    }

    void return_book(string user_name) {

        for (int i = 0;i<borrowed_names.size();i++) {
            if (borrowed_names[i] == user_name) {
                borrowed_names.erase(borrowed_names.begin()+i);
                break;
            }
        }
        total_borrowed--;


    }

     bool search_by_prefix(string book_name) {
        if (name.size() < book_name.size()) return false;

        int counter = 0;
        for (int i = 0;i<(int)book_name.size();i++) {
            if (name[i] != book_name[i]) {
                return false;
            }
            else {
                counter++;
            }

            if (counter == book_name.size()) {

                return true;
            }

        }

        return false;
    }

    void print() {
        cout << "id = " << id<< " name = " << name << " total_quantity " << total_quantity<< " total_borrowed " << total_borrowed << "\n";   
    }

};

bool comp_by_id(const Book &b1, const Book &b2) {
    return b1.id < b2.id;
}

bool comp_by_name(const Book &b1, const Book &b2) {
    return b1.name < b2.name;
}



struct User {
    string name;
    int national_id;
    vector<int> borrowed_bookes_id;

    void borrow(int book_id) {
        borrowed_bookes_id.push_back(book_id);
    }

    void return_book(int book_id) {
        for (int i=0;i<borrowed_bookes_id.size();i++) {
            if (borrowed_bookes_id[i] == book_id) {
                borrowed_bookes_id.erase(borrowed_bookes_id.begin()+i);
                break;
            }
        }
    }

    void print() {
        cout<<"user "<<name<<" id "<<national_id<<" borrowed books ids: ";
        for (const auto &id : borrowed_bookes_id) {
            cout<<id<<" ";
        }
        cout<<"\n";
    }
};

struct Library
{
    Book books[MAX_BOOKS];
    User users[MAX_USERS];
    int added_books ;
    int added_users ;

    Library() {
        added_books = 0;
        added_users = 0;
    }

    bool user_exists(string user_name) {
        for (int i = 0;i<added_users;i++) {
            if (users[i].name == user_name) {
                return true;
            }
        }
        return false;
    }
    bool book_exists(string book_name) {
        for (int i = 0;i<added_books;i++) {
            if (books[i].name == book_name) {
                return true;
            }
        }
        return false;
    }


    void add_book() {
        if (added_books >= MAX_BOOKS) {
            cout << "Added book exceeds maximum number of books";
            return;
        }

        string name;
        int id;
        int total_quantity;
        cout<<"Enter book info: id & name & total quantity:\n";
        cin>>books[added_books].id>>books[added_books].name>>books[added_books].total_quantity;
        added_books++;
    }
    void search_books_by_prefix() {
        cout<<"Enter book name prefix:\n";
        string book_name_prefix;
        cin>>book_name_prefix;

        bool status = false;
        for (int i=0;i<added_books;i++) {
            if (books[i].search_by_prefix(book_name_prefix)) {
                status  = true;
                cout<<books[i].name<<"\n";

            }
        }
        if (status == false)
        cout<<"No Books with such prefix\n";
    }


    void print_who_borrowed_book_by_name() {
        cout<<"Enter book name:\n";
        string book_name;
        cin>>book_name;
        if (book_exists(book_name)) {
            for (int i = 0;i<added_books;i++) {
                if (books[i].name == book_name) {
                    books[i].who_borrowed_book();

                    break;
                }
            }
        }
        else
        cout<<"Invalid book name.\n";
    }


    void print_library_by_id() {
        sort(books,books+added_books,comp_by_id);
        for (int i = 0;i<added_books;i++) {
            books[i].print();
        }
    }


    void print_library_by_name() {
        sort(books,books+added_books,comp_by_name);
        for (int i = 0;i<added_books;i++) {
            books[i].print();
        }
    }


    void add_user() {
        if (added_users >= MAX_USERS) {
            cout << "Added user exceeds maximum number of users";
            return;
        }

        cout<<"Enter user name & national id:";
        cin>>users[added_users].name>>users[added_users].national_id;
        added_users++;
    }

    

    void user_borrow_book() {
        cout<<"Enter user name and book name:\n";
        string user_name,book_name;
        cin>>user_name>>book_name;

        if (book_exists(book_name) && user_exists(user_name)) {

            bool status = false;
            int book_id;
            for (int i = 0;i<added_books;i++) {
                if (books[i].name == book_name) {
                    status = books[i].borrrow(user_name);
                    book_id = books[i].id;
                    break;
                }
            }
            if (status) {
                for (int i = 0;i<added_users;i++) {
                    if (users[i].name == user_name) {
                        users[i].borrow(book_id);
                        break;
                    }
                }
            }


        }
        else if (user_exists(user_name) == false) {
            cout<<"Sorry User is not exists\n";
        }
        else if (book_exists(book_name) == false) {
            cout<<"Sorry Book is not exists\n";
        }


    }
    void user_return_book() {
         cout<<"Enter user name and book name:\n";
        string user_name,book_name;
        cin>>user_name>>book_name;

        if (book_exists(book_name) && user_exists(user_name)) {


            int book_id;
            for (int i = 0;i<added_books;i++) {
                if (books[i].name == book_name) {
                    books[i].return_book(user_name);
                    book_id = books[i].id;
                    break;
                }
            }
                for (int i = 0;i<added_users;i++) {
                    if (users[i].name == user_name) {
                        users[i].return_book(book_id);
                        break;
                    }
                }
        }
        else if (user_exists(user_name) == false) {
            cout<<"Sorry User is not exists\n";
        }
        else if (book_exists(book_name) == false) {
            cout<<"Sorry Book is not exists\n";
        }
    }


    void print_users() {
        for (int i=0;i<added_users;i++) {
            users[i].print();
        }
    }


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