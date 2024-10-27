#ifndef MOTOR
#define MOTOR

#include <string>
#include <iostream>
#include <iomanip>

class Motor
{
private:
    // поля
    std::string m_marking;
    bool m_work;
    double m_volume;

    friend std::ostream &operator<<(std::ostream &output, const Motor &obj)
    {
        output << std::setw(15) << "Motor mark [" << obj.m_marking << "] volume [" << obj.m_volume << "]\n";

        return output;
    }

public:
    // конструкторы
    // конструктор по умолчанию
    Motor();

    // конструктор с параметрами
    Motor(const std::string &, double);

    // конструктор копирования
    Motor(const Motor &);
    ~Motor();

    // оператор присваивания копирования
    const Motor &operator=(const Motor &);

    // работа с двигателем
    void startEngine();

    void offEngine();

    // геттеры
    bool getWork() const;
    std::string getMarking() const;
    double getVolume() const;

    // сеттеры
    void setMarking(const std::string &);
    void setWork(const bool);
    void setVolume(const double);
};

#endif