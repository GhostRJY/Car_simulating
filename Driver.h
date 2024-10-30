#ifndef DRIVER_H
#define DRIVER_H
#include "Auto.h"
#include <iostream>
#include <windows.h>

class Driver
{
private:
    char *m_fname;
    char *m_lname;
    Auto *m_ptrAuto;
    int m_experience;
    double m_energy;

public:
    Driver();
    Driver(const char *, const char *, Auto *, const int, const double);

    // убираю конструктор копирования т.к. по логике у меня не может быть одинаковых водителей
    Driver(const Driver &) = delete;

    ~Driver();
    // сеттеры
    void setFirstName(const char *);
    void setLastName(const char *);
    void setAuto(Auto *);
    void setExperience(const int);
    void setEnergy(const double);
    // геттеры
    const char *getFirstName() const;
    const char *getLastName() const;
    const Auto getAuto() const;
    int getExperience() const;
    double getEnergy() const;
};

#endif