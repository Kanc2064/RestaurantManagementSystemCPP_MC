#ifndef Table_H
#define Table_H
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Table
{
private:
    map<int, string> tables; // tableNumber,{customerName,table status}

public:
    void occupyOrReserveTableWithTableNumber(int tableNumber, string customerName, int totalTableCount)
    {
        if (tableNumber > totalTableCount - 1)
        {
            cout << "Enter a table number within 0 and " << totalTableCount - 1 << endl;
            return;
        }

        if (tables.find(tableNumber) != tables.end())
        {
            cout << "already occupied";
        }
        else
        {
            tables[tableNumber] = customerName;
            cout << "Table booked" << endl;
        }
    }
    void occupyOrReserveTableWithoutTableNumber(string customerName, int totalTableCount)
    {
        for (int i = 0; i < totalTableCount; i++)
        {
            if (tables.find(i) == tables.end())
            {
                tables[i] = customerName;
                cout << "Table booked" << endl;
                break;
            }
        }
    }
};

#endif