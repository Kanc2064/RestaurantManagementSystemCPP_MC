#ifndef Menu_H
#define Menu_H
#include <iostream>
#include <map>
#include <utility>
#include <string>

using namespace std;

class Menu
{
private:
    map<string, pair<int, pair<string, string>>> menuList; // name,{price,{veg/nonveg,category}}

public:
    int getDishPrice(string dishName)
    {
        for (auto it : menuList)
        {
            if (it.first == dishName)
            {
                return it.second.first;
            }
        }
        return 0;
    }
    void addNewDish(string name, int price, string type, string category)
    {
        menuList[name] = {price, {type, category}};
        cout << "Dish added" << endl;
    }
    void removeDish(string name)
    {
        if (menuList.find(name) != menuList.end())
        {
            menuList.erase(name);
            cout << "Dish removed" << endl;
        }
        else
        {
            cout << "Dish not found... so, can't be removed" << endl;
        }
    }
    void updateDishPrice(string name, int updatedPrice)
    {
        if (menuList.find(name) == menuList.end())
        {

            cout << "Dish not found... so, price can't be updated" << endl;
        }
        for (auto it : menuList)
        {
            if (it.first == name)
            {
                it.second.first = updatedPrice;
                cout << "Price got updated" << endl;
            }
        }
    }
    vector<string> filterMenu(string type)
    {
        vector<string> typeFilteredList;
        for (auto it : menuList)
        {
            if (it.second.second.first == type)
            {
                typeFilteredList.push_back(it.first);
            }
        }
        return typeFilteredList;
    }
};
#endif