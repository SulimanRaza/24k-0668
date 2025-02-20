#include <iostream>
using namespace std;
class shop;
class Book
{
    string author;
    string title;
    float price;
    string publisher;
    int stock;

public:
    Book(string a, string t, string pub, int s, float p ) : author(a), title(t), publisher(pub), stock(s), price(p)
    {
        if (stock < 0)
        {
            stock = 0;
        }
        else
        {
            stock = s;
        }
    }
    string getAuthor()
    {
        return author;
    };
    string getTitle()
    {
        return title;
    };
    int getStock()
    {
        return stock;
    };
    double getTotal(int quantity)
    {
        return quantity * price;
    }
    void updateStock(int n)
    {
        stock -= n;
    }
    void getBookDetails()
    {
        cout << " Author : " << author << endl;
        cout << " Title : " << title << endl;
        cout << " Publisher : " << publisher << endl;
        cout << " Stock : " << stock << endl;
    }
};

class store
{
    Book **book;
    int bookcap;
    int bookcount;

public:
    store(int c) : bookcount(0), bookcap(c)
    {
        book = new Book *[bookcap];
    }

    void addbook(Book *b)
    {
        if (bookcount < bookcap)
        {
            book[bookcount] = b;
            bookcount++;
            cout << "Book has been added succefully!!!" << endl;
        }
        else
        {
            bookcap *= 2;
            Book **temp = new Book *[bookcap];
            for (int i = 0; i < bookcount; i++)
            {
                temp[i] = book[i];
            }
            delete[] book;
            book = temp;
            book[bookcount] = b;
            bookcount++;
            cout << "Book has been added succefully!!!" << endl;
        }
    }

    void purchasebook(string t, string a)
    {
        for (int i = 0; i < bookcount; i++)
        {
            if (book[i]->getTitle() == t && book[i]->getAuthor() == a)
            {
                cout << "Book Found!!!" << endl;
                book[i]->getBookDetails();
                int num;
                cout << "Enter number of copies to purchase: ";
                cin >> num;
                if (num <= book[i]->getStock())
                {
                    cout << "Stock purchased \nYour total amount is: " << book[i]->getTotal(num) << endl;
                    book[i]->updateStock(num);
                }
                else
                {
                    cout << "Stock limit exceeded!!!" << endl;
                }
            }
            else
            {
                cout << "Book not Found!!!" << endl;
            }
        }
    }
    ~store()
    {
        for (int i = 0; i < bookcount; i++)
        {
            delete book[i];
        }
        delete[] book;
    }
};

int main()
{
    store s(2);
    while (1)
    {
        cout << "1. Add Book" << endl;
        cout << "2. Purchase Book" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cout << endl;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            string author, title, publisher;
            int stock;
            float price;

            cout << "Enter Book Author: ";
            getline(cin, author);
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Publisher: ";
            getline(cin, publisher);
            cout << "Enter Stock: ";
            cin >> stock;
            cout << "Enter Price: ";
            cin >> price;

            Book *b = new Book(author, title, publisher, stock, price);
            s.addbook(b);
            break;
        }

        case 2:
        {
            string author, title;
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Book Author: ";
            getline(cin, author);
            s.purchasebook(title, author);
            break;
        }

        case 3:
            cout << "Exiting store!!!" << endl;
            return 0;
        default:
            cout << "Invalid input, try again!!!" << endl;
        }
    }
    return 0;
}