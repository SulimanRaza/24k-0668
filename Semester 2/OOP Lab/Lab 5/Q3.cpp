#include <iostream>
#include <vector>
using namespace std;

class Menu
{
    string name, type;
    float price;

public:
    Menu(string n, string t, float p) : name(n), type(t), price(p < 0.0 ? 0.0 : p) {}

    string getType() const{ return type; }
    string getName() const{ return name; }
    float getPrice() const{ return price; }

    void Display()const
    {
        cout << "Name: " << name << "\nType: " << type << "\nPrice: $" << price << "\n"
             << endl;
    }
};

class Coffeeshop
{
    const string sname;
    vector<Menu> menu;
    vector<string> orders;

public:
    Coffeeshop(string s) : sname(s) {}

    void showShopName()
    {
        cout << "\n===============================" << endl;
        cout << "    Welcome to " << sname << "    " << endl;
        cout << "===============================\n"
             << endl;
    }

    void addMenu(Menu m)
    {
        menu.push_back(m);
        cout << "Menu item added successfully!\n";
    }

    void displayMenu()
    {
        if (menu.empty())
        {
            cout << "No menu items available.\n";
            return;
        }
        for (auto &m : menu)
            m.Display();
    }

    void addOrder(string n)
    {
        for (auto &m : menu)
        {
            if (m.getName() == n)
            {
                orders.push_back(n);
                cout << "Order added successfully!\n";
                return;
            }
        }
        cout << "This item is currently unavailable!\n";
    }

    void fulfillOrder()
    {
        if (orders.empty())
        {
            cout << "All orders have been fulfilled.\n";
        }
        else
        {
            cout << "The " << orders.front() << " is ready!\n";
            orders.erase(orders.begin());
        }
    }

    void listOrders()
    {
        if (orders.empty())
        {
            cout << "{}\n";
        }
        else
        {
            for (size_t i = 0; i < orders.size(); i++)
            {
                cout << i + 1 << ". " << orders[i] << endl;
            }
        }
    }

    float dueAmount()
    {
        float total = 0;
        for (const auto &order : orders)
        {
            for (const auto &m : menu)
            {
                if (m.getName() == order)
                {
                    total += m.getPrice();
                    break;
                }
            }
        }
        return total;
    }

    void cheapestItem()
    {
        if (menu.empty())
        {
            cout << "No items available\n";
            return;
        }

        auto cheapest = menu[0];
        for (const auto &m : menu)
        {
            if (m.getPrice() < cheapest.getPrice())
            {
                cheapest = m;
            }
        }
        cout << "Cheapest item: " << cheapest.getName() << " | Price: $" << cheapest.getPrice() << "\n";
    }

    void drinksOnly()
    {
        bool found = false;
        for (const auto &m : menu)
        {
            if (m.getType() == "drink")
            {
                m.Display();
                found = true;
            }
        }
        if (!found)
            cout << "No drinks available.\n";
    }

    void foodOnly()
    {
        bool found = false;
        for (const auto &m : menu)
        {
            if (m.getType() == "food")
            {
                m.Display();
                found = true;
            }
        }
        if (!found)
            cout << "No food items available.\n";
    }
};

int main()
{
    Coffeeshop shop("Aans Coffee");
    shop.showShopName();

    shop.addMenu(Menu("Espresso", "drink", 3.5));
    shop.addMenu(Menu("Latte", "drink", 4.0));
    shop.addMenu(Menu("Cappuccino", "drink", 4.5));
    shop.addMenu(Menu("Muffin", "food", 2.5));
    shop.addMenu(Menu("Croissant", "food", 3.0));

    cout << "\n--- Menu ---\n";
    shop.displayMenu();
  
    cout << "\nAdding orders...\n";
    shop.addOrder("Latte");
    shop.addOrder("Muffin");
    shop.addOrder("Espresso");
    shop.addOrder("Sandwich"); 

    cout << "\n--- Orders ---\n";
    shop.listOrders();

    cout << "\nTotal due amount: $" << shop.dueAmount() << endl;

    cout << "\nFulfilling Orders...\n";
    shop.fulfillOrder();
    shop.fulfillOrder();

    cout << "\n--- Remaining Orders ---\n";
    shop.listOrders();

    cout << "\nCheapest Item in the menu:\n";
    shop.cheapestItem();

    cout << "\n--- Drinks Only ---\n";
    shop.drinksOnly();

    cout << "\n--- Food Only ---\n";
    shop.foodOnly();

    return 0;
}

