#ifndef PEN_H
#define PEN_H

#include "Stationery.h"

class Pen : public Stationery
{
private:
    char inkColor[20];

public:
    Pen(const char* n, double p, const char* color);
    void setInkColor(const char* color);
    void show() const override;
    void changeExtraProperty() override;
};

#endif // PEN_H
