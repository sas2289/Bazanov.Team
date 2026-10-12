#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

struct University
{
	int id;
	string name;
	string city;
	string rector;
	int students;
	int faculties;
	double rating;
};

void loadFromFile(University*& data, int& size)

{
	ifstream fin("university.txt");
	if (!fin.is_open())
	{      
		cout << "Файл university.txt не найден. База пуста.\n";
		return;
	}    
	University item;
	while (fin >> item.id)
	
	{     
	fin.ignore(1, ';');
	getline(fin, item.name, ';');
	getline(fin, item.city, ';');
	getline(fin, item.rector, ';');
	if (!(fin >> item.students)) break;
	fin.ignore(1, ';');
	if (!(fin >> item.faculties)) break;
	fin.ignore(1, ';');
	if (!(fin >> item.rating)) break;
	fin.ignore(numeric_limits<streamsize>::max(), '\n');
	University* temp = new University[size + 1];
	for (int i = 0; i < size; i++)
	temp[i] = data[i];
	temp[size] = item;
	delete[] data;
	data = temp;
	size++;
	}
	
	fin.close();
}

void showTable(const University* data, int size)
{
    if (size == 0)
    {      
        cout << "База данных пуста!\n";      
        return;  
    }
       
    cout << left       
    << setw(6) << "ID"       
    << setw(25) << "Название"       
    << setw(18) << "Город"       
    << setw(25) << "Ректор"       
    << setw(12) << "Студенты"       
    << setw(12) << "Факульт."       
    << setw(10) << "Рейтинг" << '\n';    
    for (int i = 0; i < size; i++)  
    {      
        cout << left           
        << setw(6) << data[i].id           
        << setw(25) << data[i].name           
        << setw(18) << data[i].city           
        << setw(25) << data[i].rector           
        << setw(12) << data[i].students           
        << setw(12) << data[i].faculties           
        << setw(10) << data[i].rating << '\n';  
    }
}  
