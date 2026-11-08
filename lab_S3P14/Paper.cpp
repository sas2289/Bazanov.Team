#include "Paper.h"

#include <iostream>

using namespace std;

Paper::Paper(const char* n, double p, int s)
    : Stationery(n, p)
{
    sheets = s;
}

void Paper::setSheets(int s)
{
    sheets = s;
}

void Paper::show() const
{
    cout << "Бумага: " << name
         << ", цена: " << price
         << ", количество листов: " << sheets << endl;
}

void Paper::changeExtraProperty()
{
    int value;
    cout << "Введите новое количество листов: ";
    cin >> value;
    setSheets(value);
}

