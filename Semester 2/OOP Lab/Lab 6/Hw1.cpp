#include <iostream>
#include <string>

using namespace std;

class Books {
protected:
    string genre;

public:
    Books(string g) : genre(g) {}
};

class Action : public Books {
private:
    string title;
    string author;

public:
    Action(string genre, string title, string author) 
        : Books(genre), title(title), author(author) {}

    void displayDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }
};

class Mystery : public Books {
private:
    string title;
    string author;

public:
    Mystery(string genre, string title, string author)
        : Books(genre), title(title), author(author) {}

    void displayDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }
};

int main() {
    Action actionBook("Action", "The Bourne Identity", "Robert Ludlum");
    Mystery mysteryBook("Mystery", "Gone Girl", "Gillian Flynn");

    cout << "Action Book Details:\n";
    actionBook.displayDetails();
    cout << "------------------------\n";

    cout << "Mystery Book Details:\n";
    mysteryBook.displayDetails();
    cout << "------------------------\n";

    return 0;
}