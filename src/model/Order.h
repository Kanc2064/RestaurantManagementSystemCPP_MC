#ifndef Order_H
#define Order_H
#include <iostream>
#include <map>
#include <utility>
#include <string>
#include "Menu.h"

using namespace std;

class Order
{
    Menu *menu = new Menu();

private:
    map<pair<string, string>, int> orders; //{custName,Dishname},quantity

public:
    void orderdetails(string customerName)
    {
        for (auto it : orders)
        {
            if (it.first.first == customerName)
            {
                cout << it.first.second << " " << it.second << endl;
            }
        }
    }
    void makeOrder(string customerName, string dish, int quantity)
    {
        if (orders.find({customerName, dish}) != orders.end())
        {
            orders[{customerName, dish}] += quantity;
        }
        else
        {
            orders[{customerName, dish}] = quantity;
        }
        cout << "Order placed" << endl;
    }
    void updateOrder(string customerName, string dish, int quantity)
    {
        if (orders.find({customerName, dish}) != orders.end())
        {
            orders[{customerName, dish}] = quantity;
        }
        cout << "Order updated" << endl;
    }
    void removeOrder(string customerName, string dish)
    {
        orders.erase({customerName, dish});
        cout << "Order removed" << endl;
    }
    void getBilled(string customerName, string paymentType)
    {
        float totalBill = 0;
        int dishPrice;
        for (auto it : orders)
        {
            if (it.first.first == customerName)
            {
                string dishName = it.first.second;
                int quantity = it.second;
                dishPrice = menu->getDishPrice(dishName);
                totalBill = totalBill + (dishPrice * quantity);
            }
        }
        if (paymentType == "card")
        {
            totalBill = totalBill + (totalBill / 100);
        }
        else
        {
            totalBill = totalBill + (totalBill * 28 / 100);
        }

        cout << "Total Bill is " << totalBill << endl;
    }
};
#endif