#include "Pen.h"

#include <iostream>
#include <cstring>

using namespace std;

Pen::Pen(const char* n, double p, const char* color)
    : Stationery(n, p)
{
    strncpy(inkColor, color, sizeof(inkColor) - 1);
    inkColor[sizeof(inkColor) - 1] = '\0';
}

void Pen::setInkColor(const char* color)
{
    strncpy(inkColor, color, sizeof(inkColor) - 1);
    inkColor[sizeof(inkColor) - 1] = '\0';
}

void Pen::show() const
{
    cout << "Авторучка: " << name
         << ", цена: " << price
         << ", цвет чернил: " << inkColor << endl;
}

void Pen::changeExtraProperty()
{
    char color[20];
    cout << "Введите новый цвет чернил (одно слово): ";
    cin >> color;
    setInkColor(color);
}

