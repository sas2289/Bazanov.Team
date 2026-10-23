#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass
{
private:
    bool locked;
    bool alarm;
    int attempts;
    bool codeAccepted;

public:
    MyClass();
    MyClass(bool locked, bool alarm,
            int attempts, bool codeAccepted);

    void showState();
    void enterCode(bool correct);
    void closeLock();
    void resetAlarm();
    void processState();
};

#endif // MYCLASS_H
