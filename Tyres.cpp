#include "Tyres.h"

Tyres::Tyres()
{
    this->setBrand("Tyres");
    this->setRadius(14);
    this->setWidth(160);
    this->setHeight(50);

    std::cout << "Tyres constructed\n";
}

Tyres::Tyres(const std::string &brand,
             unsigned short width,
             unsigned short height,
             unsigned short radius)
{
    this->setBrand(brand);
    this->setRadius(radius);
    this->setWidth(width);
    this->setHeight(height);

    std::cout << "Tyres constructed\n";
}

Tyres::Tyres(const Tyres &other)
{
    this->m_brand = other.m_brand;
    this->m_width = other.m_width;
    this->m_height = other.m_height;
    this->m_radius = other.m_radius;
}

const Tyres &Tyres::operator=(const Tyres &right)
{
    if (this != &right)
    {
        this->m_brand = right.m_brand;
        this->m_width = right.m_width;
        this->m_height = right.m_height;
        this->m_radius = right.m_radius;
    }
    return *this;
}

Tyres::~Tyres()
{
    std::cout << "Tyres destroyed\n";
}

std::string Tyres::getBrand() const
{
    return this->m_brand;
}

unsigned short Tyres::getWidth() const
{
    return this->m_width;
}

unsigned short Tyres::getHeight() const
{
    return this->m_height;
}

unsigned short Tyres::getRadius() const
{
    return this->m_radius;
}

void Tyres::setBrand(const std::string &brand)
{
    this->m_brand = brand;
}

void Tyres::setWidth(const unsigned short width)
{
    if (width >= 160 && width < 450)
        this->m_width = width;
    else
    {
        std::cout << "unacceptable value! using standard width = 160\n";
        this->m_width = 160;
    }
}

void Tyres::setHeight(const unsigned short height)
{
    if (height >= 20 && height <= 200)
        this->m_height = height;
    else
    {
        std::cout << "unacceptable value! using standard height = 60\n";
        this->m_height = 60;
    }
}

void Tyres::setRadius(const unsigned short radius)
{
    if (radius > 13 && radius < 30)
        this->m_radius = radius;
    else
    {
        std::cout << "unacceptable value! using standard width = 13\n";
        this->m_radius = 13;
    }
}