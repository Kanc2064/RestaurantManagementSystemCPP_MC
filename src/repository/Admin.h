#ifndef Admin_H
#define Admin_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Admin
{
private:
    map<string, string> namePasswordList;

public:
    void addAdminInitially()
    {
        namePasswordList["admin1"] = "123abc";
    }
    void addAdmin(string name, string password)
    {
        namePasswordList[name] = password;
    }
    bool isAdmin(string name, string password)
    {
        if (namePasswordList.find(name) != namePasswordList.end())
        {
            if (namePasswordList[name] == password)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return false;
    }
};

#endif