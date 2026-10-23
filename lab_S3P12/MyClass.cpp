#include "MyClass.h"
#include <iostream>

using namespace std;

MyClass::MyClass()
{
    locked = true;
    alarm = false;
    attempts = 0;
    codeAccepted = false;
}

MyClass::MyClass(bool locked, bool alarm,
                 int attempts, bool codeAccepted)
{
    this->locked = locked;
    this->alarm = alarm;
    this->attempts = attempts;
    this->codeAccepted = codeAccepted;
}

void MyClass::showState()
{
    cout << "Lock: "
         << (locked ? "Closed" : "Open") << endl;

    cout << "Alarm: "
         << (alarm ? "On" : "Off") << endl;

    cout << "Wrong attempts: " << attempts << endl;

    cout << "Code accepted: "
         << (codeAccepted ? "Yes" : "No") << endl;
}

void MyClass::enterCode(bool correct)
{
    if (alarm)
    {
        cout << "Alarm is active. Reset it first."
             << endl;
        return;
    }

    if (!locked)
    {
        cout << "The lock is already open." << endl;
        return;
    }

    if (correct)
    {
        codeAccepted = true;
        locked = false;
        attempts = 0;

        cout << "Correct code. The lock is open."
             << endl;
    }
    else
    {
        codeAccepted = false;
        attempts++;

        cout << "Incorrect code. Attempts: "
             << attempts << endl;

        if (attempts >= 3)
        {
            alarm = true;
            cout << "Alarm activated" << endl;
        }
    }
}

void MyClass::closeLock()
{
    locked = true;
    codeAccepted = false;

    cout << "The lock is closed." << endl;
}

void MyClass::resetAlarm()
{
    alarm = false;
    attempts = 0;
    codeAccepted = false;
    locked = true;

    cout << "Alarm reset. The lock is closed."
         << endl;
}

void MyClass::processState()
{
    if (alarm)
    {
        cout << "Status: Active" << endl;
    }
    else if (locked)
    {
        cout << "Status: Locked" << endl;
    }
    else
    {
        cout << "Status: Unlocked" << endl;
    }
}
