#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Book {
public:
    int id;
    string title;
    string author;
    bool issued;
    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        issued = false;
    }
};
vector<Book> books;
void addBook() {
    int id;
    string title, author;
    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Book Title: ";
    getline(cin, title);
    cout << "Enter Author Name: ";
    getline(cin, author);
    books.push_back(Book(id, title, author));
    cout << "Book added successfully!\n";
}
void displayBooks() {
    if (books.empty()) {
        cout << "No books available.\n";
        return;
    }
    for (auto &book : books) {
        cout << "\nBook ID: " << book.id;
        cout << "\nTitle: " << book.title;
        cout << "\nAuthor: " << book.author;
        cout << "\nStatus: " << (book.issued ? "Issued" : "Available");
        cout << "\n";
    }
}
void searchBook() {
    string title;
    cin.ignore();
    cout << "Enter title to search: ";
    getline(cin, title);
    bool found = false;
    for (auto &book : books) {
        if (book.title == title) {
            cout << "\nBook Found!";
            cout << "\nID: " << book.id;
            cout << "\nTitle: " << book.title;
            cout << "\nAuthor: " << book.author;
            cout << "\nStatus: " << (book.issued ? "Issued" : "Available");
            cout << "\n";
            found = true;
        }
    }
    if (!found)
        cout << "Book not found.\n";
}
void issueBook() {
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;
    for (auto &book : books) {
        if (book.id == id) {
            if (!book.issued) {
                book.issued = true;
                cout << "Book issued successfully!\n";
            } else {
                cout << "Book is already issued.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}
void returnBook() {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;
    for (auto &book : books) {
        if (book.id == id) {
            if (book.issued) {
                book.issued = false;
                cout << "Book returned successfully!\n";
            } else {
                cout << "Book was not issued.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}
int main() {
    int choice;
    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: cout << "Thank you!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);
    return 0;
}
