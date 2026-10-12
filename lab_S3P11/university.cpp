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
    << setw(18) << "Name"       
    << setw(30) << "City"       
    << setw(15) << "Rector"       
    << setw(15) << "Students"       
    << setw(10) << "Faculties"       
    << setw(10) << "Rating" << '\n';    
    for (int i = 0; i < size; i++)  
    {      
        cout << left           
        << setw(6) << data[i].id           
        << setw(18) << data[i].name           
        << setw(30) << data[i].city           
        << setw(15) << data[i].rector           
        << setw(15) << data[i].students           
        << setw(10) << data[i].faculties           
        << setw(10) << data[i].rating << '\n';  
    }
}

void editUniversity(University* data, int size)
{  
    int id;
    cout << "Введите ID записи для изменения: ";
    cin >> id;
    for (int i = 0; i < size; i++)
    {
        if (data[i].id == id)
        {  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Новое название: ";
            getline(cin, data[i].name);
            cout << "Новый город: ";   
            getline(cin, data[i].city);
            cout << "Новое ФИО ректора: ";
            getline(cin, data[i].rector);
            cout << "Количество студентов: ";
            cin >> data[i].students;
            cout << "Количество факультетов: ";
            cin >> data[i].faculties;
            cout << "Рейтинг: ";
            cin >> data[i].rating;
            cout << "Запись изменена!\n";
            return;
         }
     }    
cout << "Запись не найдена!\n";
}

void calculate(const University* data, int size)
{
    if (size == 0)
    {
        cout << "Нет данных для вычислений!\n";
        return;
    }    
    long long totalStudents = 0;
    double totalRating = 0;
    for (int i = 0; i < size; i++)
    {
        totalStudents += data[i].students;
        totalRating += data[i].rating;
    }
    cout << "Общее количество студентов: "
    << totalStudents << '\n';
    cout << "Средний рейтинг университетов: "
    << fixed << setprecision(2)
    << totalRating / size << '\n';
}

void saveToFile(const University* data, int size)
{
    string filename;
    cout << "Введите имя нового файла: ";
    cin >> filename;
    ofstream fout(filename);
    if (!fout.is_open())
    {
        cout << "Ошибка открытия файла!\n";
        return;
    }
    for (int i = 0; i < size; i++)
    {
        fout << data[i].id << ';'
        << data[i].name << ';'
        << data[i].city << ';'
        << data[i].rector << ';'
        << data[i].students << ';'
        << data[i].faculties << ';'
        << data[i].rating << '\n';
    }
    fout.close();
    cout << "Данные сохранены в файл " << filename << '\n';
}

int main()
{
    University* data = NULL;
    int size = 0;
    int choice;
    loadFromFile(data, size);
    do
    {
        cout << "\n--- БАЗА УНИВЕРСИТЕТОВ ---\n";
        cout << "1. Просмотр данных\n";
        cout << "2. Корректировка записи\n";
        cout << "3. Вычисления\n";
        cout << "4. Сохранение в новый файл\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;
        
        if (choice == 1)
        showTable(data,size);
        
        else if (choice == 2)
        editUniversity(data,size);
        
        else if (choice == 3)
        calculate(data,size);
        
        else if (choice == 4)
        saveToFile(data,size);
        
        else if (choice == 0)
        cout << "Выход" << endl;
        else cout << "Неверный выбор" << endl;
     }
     while (choice != 0);
     
     delete[] data;
     return 0;
}
