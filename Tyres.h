#ifndef TYRES
#define TYRES
#include <string>
#include <iostream>
#include <iomanip>

class Tyres
{
private:
    std::string m_brand;
    unsigned short m_width;
    unsigned short m_height;
    unsigned short m_radius;

    friend std::ostream &operator<<(std::ostream &output, const Tyres &obj)
    {
        output << std::setw(15) << "Tyres brand [" << obj.m_brand << "] size [" << obj.m_width << 'x' << obj.m_height << "radius " << obj.m_radius << "]\n";

        return output;
    }

public:
    // конструкторы

    // конструктор по умолчанию
    Tyres();

    // конструктор с параметрами
    Tyres(const std::string &,
          unsigned short,
          unsigned short,
          unsigned short);

    // конструктор копирования
    Tyres(const Tyres &);

    ~Tyres();
    // операторы
    const Tyres &operator=(const Tyres &);
    // геттеры
    std::string getBrand() const;
    unsigned short getWidth() const;
    unsigned short getHeight() const;
    unsigned short getRadius() const;

    // сеттеры
    void setBrand(const std::string &);
    void setWidth(const unsigned short);
    void setHeight(const unsigned short);
    void setRadius(const unsigned short);
};

#endif