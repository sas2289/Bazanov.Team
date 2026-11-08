#include "include/Stationery.h"
#include "include/Paper.h"
#include "include/Pen.h"

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    Paper paper1("Бумага A4", 250.0, 500);
    Paper paper2("Бумага цветная", 180.0, 100);
    Pen pen1("Авторучка синяя", 45.0, "синий");
    Pen pen2("Авторучка черная", 50.0, "черный");

    Stationery* items[4];
    items[0] = &paper1;
    items[1] = &paper2;
    items[2] = &pen1;
    items[3] = &pen2;

    int choice;

    do
    {
        cout << "\nМЕНЮ" << endl;
        cout << "1. Просмотр товаров" << endl;
        cout << "2. Изменение свойств товара" << endl;
        cout << "3. Расчет средней цены" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < 4; i++)
            {
                cout << i + 1 << ". ";
                items[i]->show();
            }
            break;

        case 2:
        {
            int number;
            int property;

            cout << "Введите номер товара (1-4): ";
            cin >> number;

            if (number < 1 || number > 4)
            {
                cout << "Неверный номер товара." << endl;
                break;
            }

            cout << "1. Изменить название" << endl;
            cout << "2. Изменить цену" << endl;
            cout << "3. Изменить дополнительное свойство" << endl;
            cout << "Выберите свойство: ";
            cin >> property;

            if (property == 1)
            {
                char newName[50];
                cout << "Введите новое название: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.getline(newName, 50);
                items[number - 1]->setName(newName);
            }
            else if (property == 2)
            {
                double newPrice;
                cout << "Введите новую цену: ";
                cin >> newPrice;
                items[number - 1]->setPrice(newPrice);
            }
            else if (property == 3)
            {
                items[number - 1]->changeExtraProperty();
            }
            else
            {
                cout << "Неверный пункт меню." << endl;
            }
            break;
        }

        case 3:
        {
            double sum = 0.0;

            for (int i = 0; i < 4; i++)
            {
                sum += items[i]->getPrice();
            }

            cout << fixed << setprecision(2);
            cout << "Средняя цена товара: " << sum / 4 << endl;
            break;
        }

        case 0:
            cout << "Выход из программы." << endl;
            break;

        default:
            cout << "Неверный пункт меню." << endl;
        }
    }
    while (choice != 0);

    return 0;
}

