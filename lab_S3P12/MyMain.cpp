#include <iostream>
#include "MyClass.h"

using namespace std;

int main()
{
    MyClass locks[3] = 
    {
    MyClass(),
    MyClass(true, false, 0, false),
    MyClass(true, false, 0, false)
    };

    int work = 1;
    int command;
    int index;
    int codeResult;

    while (work)
    {
        cout << "\n----- ELECTRONIC DOOR LOCK -----" << endl;
        cout << "1. Show lock state" << endl;
        cout << "2. Enter access code" << endl;
        cout << "3. Close lock" << endl;
        cout << "4. Reset alarm" << endl;
        cout << "5. Show all locks" << endl;
        cout << "6. Process lock array" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter command: ";
        cin >> command;

        if (command >= 1 && command <= 4)
        {
            cout << "Enter lock index (0-2): ";
            cin >> index;

            if (index < 0 || index >= 3)
            {
                cout << "Incorrect index" << endl;
                continue;
            }
        }

        switch (command)
        {
            case 1:
                locks[index].showState();
                break;

            case 2:
                cout << "Enter code result "
                     << "(1 - correct, 0 - incorrect): ";
                cin >> codeResult;

                if (codeResult == 0 || codeResult == 1)
                {
                    locks[index].enterCode(codeResult == 1);
                }
                else
                {
                    cout << "Incorrect input" << endl;
                }
                break;

            case 3:
                locks[index].closeLock();
                break;

            case 4:
                locks[index].resetAlarm();
                break;

            case 5:
                for (int i = 0; i < 3; i++)
                {
                    cout << "\nLock number " << i << endl;
                    locks[i].showState();
                }
                break;

            case 6:
                for (int i = 0; i < 3; i++)
                {
                    cout << "\nLock number " << i << endl;
                    locks[i].processState();
                }
                break;

            case 0:
                work = 0;
                break;

            default:
                cout << "Unknown command" << endl;
                break;
        }
    }

    return 0;
}
