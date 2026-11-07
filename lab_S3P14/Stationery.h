#ifndef STATIONERY_H
#define STATIONERY_H

class Stationery
{
protected:
    char name[50];
    double price;

public:
    Stationery(const char* n, double p);
    virtual ~Stationery();

    double getPrice() const;
    void setName(const char* n);
    void setPrice(double p);

    virtual void show() const;
    virtual void changeExtraProperty();
};

#endif // STATIONERY_H
