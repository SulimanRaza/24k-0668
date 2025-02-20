#include <iostream>
using namespace std;

class Menu
{
    string name, type;
    float price;

public:
    Menu(string n, string t, float p) : name(n), type(t)
    {
        if (p < 0.0)
        {
            price = 0.0;
        }
        else
        {
            price = p;
        }
    }
    string getType()
    {
        return type;
    };
    string getName()
    {
        return name;
    };
    float getTotal(float num)
    {
        return num * price;
    }
    float getPrice()
    {
        return price;
    }
    void Display()
    {
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Price: " << price << endl;
    }
};
class Coffeeshop
{
    Menu **menu;
    int menucap;
    int menucount;
    string *order;
    int ordercap;
    int ordercount;

public:
    Coffeeshop(int mc, int oc) : menucount(0), menucap(mc), ordercount(0), ordercap(oc)
    {
        menu = new Menu *[menucap];
        order = new string[ordercap];
    }

    void addmenu(Menu *m)
    {
        if (menucount < menucap)
        {
            menu[menucount] = m;
            menucount++;
            cout << "Menu has been added succefully!!!" << endl;
        }
        else
        {
            menucap *= 2;
            Menu **temp = new Menu *[menucap];
            for (int i = 0; i < menucount; i++)
            {
                temp[i] = menu[i];
            }
            delete[] menu;
            menu = temp;
            menu[menucount] = m;
            menucount++;
            cout << "Menu has been added succefully!!!" << endl;
        }
    }
    void DisplayMenu()
    {
        for (int i = 0; i < menucount; i++)
        {
            menu[i]->Display();
        }
    }

    void addorder(string n)
    {
        if (ordercount < ordercap)
        {
            order[ordercount] = n;
            ordercount++;
            cout << "Order has been added succefully!!!" << endl;
        }
        else
        {
            ordercap *= 2;
            string *temp = new string[ordercap];
            for (int i = 0; i < ordercount; i++)
            {
                temp[i] = order[i];
            }
            delete[] order;
            order = temp;
            order[ordercount] = n;
            ordercount++;
            cout << "Order has been added succefully!!!" << endl;
        }
    }

    void fullfillorder()
    {
        if (ordercount == 0)
        {
            cout << "All Orders Have Been Fulfilled" << endl;
        }
        else
        {
            for (int i = 0; i < ordercount; i++)
            {
                cout << "The Item : " << order[i] << " is ready " << endl;
            }
        }
    }

    void listorder()
    {
        if (ordercount == 0)
        {
            cout << "{}" << endl;
        }
        else
        {
            for (int i = 0; i < ordercount; i++)
            {
                cout << i + 1 << ". " << order[i] << endl;
            }
        }
    }

    float dueamount()
    {
        float total = 0;
        for (int i = 0; i < menucount; i++)
        {
            for (int j = 0; j < ordercount; j++)
            {
                if (menu[i]->getName() == order[j])
                {
                    total += menu[i]->getPrice();
                }
            }
        }
        return total;
    }

    void cheapestitem()
    {
        if (menucount == 0)
        {
            cout << "No items are available" << endl;
        }
        else
        {
            float min = menu[0]->getPrice();
            string mitem = menu[0]->getName();
            for (int i = 0; i < menucount; i++)
            {
                if (menu[i]->getPrice() < min)
                {
                    min = menu[i]->getPrice();
                    mitem = menu[i]->getName();
                }
            }
            cout << "Cheapest item: " << mitem << endl
                 << "Price: " << min << endl;
        }
    }

    void drinksOnly()
    {
        for (int i = 0; i < menucount; i++)
        {
            if (menu[i]->getType() == "drink")
                menu[i]->Display();
        }
    }

    void foodOnly()
    {
        for (int i = 0; i < menucount; i++)
        {
            if (menu[i]->getType() == "food")
                menu[i]->Display();
        }
    }
};

int main()
{
    Coffeeshop c(5, 5);

    while (1)
    {
        cout << endl;
        cout << "1. Add Menu Item" << endl;
        cout << "2. Display Menu" << endl;
        cout << "3. Add Order" << endl;
        cout << "4. Fulfill Order" << endl;
        cout << "5. List Orders" << endl;
        cout << "6. Show Due Amount" << endl;
        cout << "7. Show Cheapest Item" << endl;
        cout << "8. Show Drinks Only" << endl;
        cout << "9. Show Food Only" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string name, type;
            float price;
            cout << "Enter Item Name: ";
            getline(cin, name);
            cout << "Enter Type (drink/food): ";
            getline(cin, type);
            cout << "Enter Price: ";
            cin >> price;

            Menu *m = new Menu(name, type, price);
            c.addmenu(m);
            break;
        }
        case 2:
            c.DisplayMenu();
            break;
        case 3:
        {
            string order;
            cout << "Enter Item Name to Order: ";
            getline(cin, order);
            c.addorder(order);
            break;
        }
        case 4:
            c.fullfillorder();
            break;
        case 5:
            c.listorder();
            break;
        case 6:
            cout << "\nDue Amount: " << c.dueamount() << endl;
            break;
        case 7:
            c.cheapestitem();
            break;
        case 8:
            c.drinksOnly();
            break;
        case 9:
            c.foodOnly();
            break;
        case 10:
            cout << "Exiting Coffee Shop!!!" << endl;
            return 0;
        default:
            cout << "Invalid Input, Try Again!" << endl;
        }
    }
    return 0;
}