#ifndef customException_H
#define customException_H

#include <iostream>

using namespace std;

class customException
{
public:
    void adminNotFound()
    {
        cout << "Admin not found" << endl;
    }
    void notAnAdmin()
    {
        cout << "not an admin" << endl;
    }
};
#endif