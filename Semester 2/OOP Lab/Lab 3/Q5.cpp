#include <iostream>
#include <string>
using namespace std;

class Book
{
    string Bookname;
    string ISBN;
    string Authorname;
    string Publisher;

public:
    void setBook(const string& Bookname, const string& ISBN, const string& Authorname, const string& Publisher)
    {
        this->Bookname = Bookname;
        this->ISBN = ISBN;
        this->Authorname = Authorname;
        this->Publisher = Publisher;
    }

    string getbookname()
    {
        return this->Bookname;
    }

    string getISBN()
    {
        return this->ISBN;
    }

    string getauthorname()
    {
        return this->Authorname;
    }

    string getpublisher()
    {
        return this->Publisher;
    }

    string getBookinfo()
    {
        return "Book Name: " + Bookname + "\nISBN: " + ISBN + "\nAuthor: " + Authorname + "\nPublisher: " + Publisher;
    }
};

int main(int argc, char *argv[])
{
    Book books[5];

    for (int i = 0; i < 5; i++)
    {
        books[i].setBook(argv[i * 4 + 1], argv[i * 4 + 2], argv[i * 4 + 3], argv[i * 4 + 4]);
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "Book " << i + 1 << " Info:" << endl;
        cout << books[i].getBookinfo() << endl;
        cout << "-----------------------------------\n";
    }
    return 0;
}