#include <iostream>
#include <string>
#include "model/Menu.h"
#include "model/Table.h"
#include "model/Order.h"
#include "repository/Admin.h"
#include "customExceptions/customException.h"

using namespace std;

int main()
{

    Menu *menu = new Menu();
    Table *table = new Table();
    Order *order = new Order();
    Admin *admin = new Admin();
    customException *exc = new customException();

    admin->addAdminInitially();

    int numberOfTables;
    string adminName;
    string password;
    bool is_Admin = false;

    string choices;
    cout << "Are you an admin?Yes or No" << endl;
    cin >> choices;
    if (choices == "Yes")
    {
        cout << "Enter Admin name" << endl;
        cin >> adminName;
        cout << "Enter Password" << endl;
        cin >> password;
        try
        {
            if (admin->isAdmin(adminName, password) == true)
            {
                is_Admin = true;
            }
            else
            {
                throw exc;
            }
        }
        catch (customException *exc)
        {
            exc->adminNotFound();
            return 0;
        }
    }

    while (true)
    {
        cout << "Enter the activity that you want to perform" << endl;
        string mainActivity;
        cin >> mainActivity;
        if (mainActivity == "installTable")
        {
            try
            {
                if (is_Admin)
                {
                    cout << "How many tables you want to install?" << endl;
                    cin >> numberOfTables;
                    cout << numberOfTables << " tables installed." << endl;
                }
                else
                {
                    throw exc;
                }
            }
            catch (customException *exc)
            {
                exc->notAnAdmin();
            }
        }
        if (mainActivity == "addNewDishToMenu")
        {
            try
            {
                if (is_Admin)
                {
                    cout << "Enter the Dish name" << endl;
                    string name;
                    cin >> name;
                    cout << "Enter the Dish price" << endl;
                    int price;
                    cin >> price;
                    cout << "Enter the Dish type" << endl;
                    string type;
                    cin >> type;
                    cout << "Enter the Dish category" << endl;
                    string category;
                    cin >> category;
                    menu->addNewDish(name, price, type, category);
                }
                else
                {
                    throw exc;
                }
            }
            catch (customException *exc)
            {
                exc->notAnAdmin();
            }
        }
        else if (mainActivity == "RemoveDishFromMenu")
        {
            try
            {
                if (is_Admin)
                {
                    cout << "Enter the dish name to be removed" << endl;
                    string dishName;
                    cin >> dishName;
                    menu->removeDish(dishName);
                }
                else
                {
                    throw exc;
                }
            }
            catch (customException *exc)
            {
                exc->notAnAdmin();
            }
        }
        else if (mainActivity == "UpdateDishPrice")
        {
            try
            {
                if (is_Admin)
                {
                    cout << "Enter the dish name whose price needs to be updated" << endl;
                    string dishName;
                    cin >> dishName;
                    cout << "Enter the updated price" << endl;
                    int updatedPrice;
                    cin >> updatedPrice;
                    menu->updateDishPrice(dishName, updatedPrice);
                }
                else
                {
                    throw exc;
                }
            }
            catch (customException *exc)
            {
                exc->notAnAdmin();
            }
        }
        else if (mainActivity == "BookTable")
        {
            string choice;
            cout << "Do you want to book an specific table? Yes Or No" << endl;
            cin >> choice;
            if (choice == "Yes")
            {
                cout << "Enter the table number of your choice" << endl;
                int tableNumber;
                cin >> tableNumber;
                cout << "Enter Your name" << endl;
                string customerName;
                cin >> customerName;

                table->occupyOrReserveTableWithTableNumber(tableNumber, customerName, numberOfTables);
            }
            else if (choice == "No")
            {
                cout << "Enter Your name" << endl;
                string customerName;
                cin >> customerName;
                table->occupyOrReserveTableWithoutTableNumber(customerName, numberOfTables);
            }
        }
        else if (mainActivity == "MakeOrder")
        {
            string customerName;
            string dish;
            int quantity;
            cout << "Enter Your name" << endl;
            cin >> customerName;
            cout << "Enter the dish name" << endl;
            cin >> dish;
            cout << "Enter the quantity to be ordered" << endl;
            cin >> quantity;
            order->makeOrder(customerName, dish, quantity);
        }
        else if (mainActivity == "UpdateOrder")
        {
            string customerName;
            string dish;
            int quantity;
            cout << "Enter Your name" << endl;
            cin >> customerName;
            cout << "Enter the dish name to be updated" << endl;
            cin >> dish;
            cout << "Enter the quantity to be updated" << endl;
            cin >> quantity;
            order->updateOrder(customerName, dish, quantity);
        }
        else if (mainActivity == "removeOrder")
        {
            string customerName;
            string dish;
            cout << "Enter Your name" << endl;
            cin >> customerName;
            cout << "Enter the dish name to be removed" << endl;
            cin >> dish;
            order->removeOrder(customerName, dish);
        }
        else if (mainActivity == "processBilling")
        {
            string customerName;
            string paymentType;
            cout << "Enter customer name" << endl;
            cin >> customerName;
            cout << "Enter payment type" << endl;
            cin >> paymentType;
            order->getBilled(customerName, paymentType);
        }
        else if (mainActivity == "OrderDetails")
        {
            string customerName;
            cin >> customerName;
            order->orderdetails(customerName);
        }
    }
    return 0;
}

// g++ Main.cpp -o Main.exe