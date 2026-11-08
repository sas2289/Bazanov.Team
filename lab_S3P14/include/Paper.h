#ifndef PAPER_H
#define PAPER_H

#include "Stationery.h"

class Paper : public Stationery
{
private:
    int sheets;

public:
    Paper(const char* n, double p, int s);
    void setSheets(int s);
    void show() const override;
    void changeExtraProperty() override;
};

#endif // PAPER_H
