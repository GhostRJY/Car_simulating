#ifndef GEARBOX
#define GEARBOX
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class Gearbox
{
private:
    std::string m_marking;
    const std::vector<std::string> m_currentGear{"Rear", "Neutral", "First", "Second", "Third", "Fourth", "Fifth", "Six", "Seven", "Eight", "Ninth", "Tenth"};
    unsigned short m_gearCount;
    unsigned short m_gearPos;

    friend std::ostream &operator<<(std::ostream &output, const Gearbox &obj)
    {
        output << std::setw(15) << "Gearbox type [" << obj.getMarking() << ", " << obj.getGearCount() - 1 << "]\n";
        return output;
    }

    // прячу фун-ию от пользователя чтоб он не мог изменить кол-во передач после создания
    void setGearCount(const int);

public:
    // конструкторы
    // конструктор по умолчанию
    Gearbox();
    // конструктор с параметрами
    Gearbox(const std::string &, const int);

    // конструктор копирования
    Gearbox(const Gearbox &);

    ~Gearbox();

    // операторы
    const Gearbox &operator=(const Gearbox &);

    // сеттеры
    void setMarking(const std::string &);

    void setGearPos(const unsigned short);

    // геттеры
    unsigned short getGearPos() const;
    unsigned short getGearCount() const;
    std::string getMarking() const;
    std::vector<std::string> getGears() const;

    // работа с коробкой передач
    void shiftUp();

    void shiftDown();

    void shiftNeutral();

    // отображение состояний
    void printGear();
};

#endif