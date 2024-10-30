#ifndef AUTO
#define AUTO

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <windows.h>
#include "Gearbox.h"
#include "Tyres.h"
#include "Rims.h"
#include "Motor.h"

class Auto
{

private:
    // поля класса
    std::string m_brand;
    std::string m_model;
    Motor m_motor;
    Gearbox m_gearbox;
    Tyres m_tyres;
    Rims m_rims;
    double m_odometer;

    // оператор помещения в поток
    friend std::ostream &
    operator<<(std::ostream &output, const Auto &obj)
    {
        output << std::setw(15) << "\nAuto brand [" << obj.m_brand << "] model [" << obj.m_model << "] odometer: "
               << std::setprecision(2) << std::fixed << std::showpoint << obj.m_odometer << " km\n"
               << "\t\tSpecifications\n"
               << obj.m_motor
               << obj.m_gearbox
               << obj.m_rims
               << obj.m_tyres
               << '\n';

        return output;
    }

public:
    // конструкторы

    Auto();
    Auto(const std::string &brand,
         const std::string &model,
         const double odometer,
         const std::string &motorMarking,
         double motorVolume,
         const std::string &gearBoxMarking,
         unsigned short gearCount,
         const std::string &rimsMark,
         const std::string &tyreMark,
         unsigned short width,
         unsigned short height,
         unsigned short radius);

    // конструктор копирования
    Auto(const Auto &);

    // деструктор
    ~Auto();

    // оператор присваивания
    const Auto &operator=(const Auto &);

    // геттеры
    std::string getBrand() const;
    std::string getModel() const;
    Motor getMotor() const;
    Gearbox getGearbox() const;
    Tyres getTyres() const;
    Rims getRims() const;
    double getOdometer() const;

    // сеттеры
    void setBrand(const std::string &);
    void setModel(const std::string &);
    void setMotor(const Motor &);
    void setMotor(const std::string &, const double);
    void setGearbox(const Gearbox &);
    void setGearbox(const std::string &, const unsigned short);
    void setTyres(const Tyres &);
    void setTyres(const std::string &, const int, const int, const int);
    void setRims(const Rims &);
    void setRims(const std::string &, const int, const int, const int);
    void setOdometer(const double);

    // завожу машину
    void turnOn();

    // глушу машину
    void turnOff();

    // передача вверх
    void gearUp();

    // передача вниз
    void gearDown();

    // начать движение авто
    void startMoving();

    // замедлятся
    void stopMoving();
};

#endif