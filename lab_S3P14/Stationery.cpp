#include "Stationery.h"

#include <iostream>
#include <cstring>

using namespace std;

Stationery::Stationery(const char* n, double p)
{
    strncpy(name, n, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
    price = p;
}

Stationery::~Stationery()
{
}

double Stationery::getPrice() const
{
    return price;
}

void Stationery::setName(const char* n)
{
    strncpy(name, n, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
}

void Stationery::setPrice(double p)
{
    price = p;
}

void Stationery::show() const
{
    cout << "Товар: " << name
         << ", цена: " << price << endl;
}

void Stationery::changeExtraProperty()
{
    cout << "У этого товара нет дополнительных свойств." << endl;
}

