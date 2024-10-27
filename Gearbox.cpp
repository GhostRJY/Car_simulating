#include "Gearbox.h"

Gearbox::Gearbox()
{
    this->setMarking("Gearbox");
    this->setGearPos(1);
    this->setGearCount(3);

    std::cout << "Gearbox constructed\n";
}

Gearbox::Gearbox(const std::string &marking, const int gearCount)
{

    this->setMarking(marking);
    this->setGearPos(1);
    this->setGearCount(gearCount);

    std::cout << "Gearbox constructed\n";
}

// в конструкторе копирования исп-ю инициализацию т.к. передаваемый объект в качестве параметра не может быть создан не по правилам.
Gearbox::Gearbox(const Gearbox &other)
{
    this->m_marking = other.m_marking;
    this->m_gearPos = other.m_gearPos;
    this->m_gearCount = other.m_gearCount;
}

const Gearbox &Gearbox::operator=(const Gearbox &right)
{
    if (this != &right)
    {
        this->m_marking = right.m_marking;
        this->m_gearPos = right.m_gearPos;
        this->m_gearCount = right.m_gearCount;
    }

    return *this;
}

Gearbox::~Gearbox()
{
    std::cout << "Gearbox destroyed\n";
}

void Gearbox::setMarking(const std::string &marking)
{
    this->m_marking = marking;
}

std::string Gearbox::getMarking() const
{
    return this->m_marking;
}

std::vector<std::string> Gearbox::getGears() const
{
    return this->m_currentGear;
}

void Gearbox::setGearPos(const unsigned short position)
{
    if (position >= 0 && position <= m_gearCount)
        this->m_gearPos = position;
    else
        this->m_gearPos = 1;
}

void Gearbox::setGearCount(const int count)
{
    // устанавливаю количество ступеней передач
    if (count >= 2 && count < 11)
        this->m_gearCount = count + 1;
    else
    {
        std::cout << "unacceptable value! using standard gear count = 4";
        this->m_gearCount = 5;
    }
}

unsigned short Gearbox::getGearPos() const
{
    return this->m_gearPos;
}

unsigned short Gearbox::getGearCount() const
{
    return this->m_gearCount;
}

void Gearbox::shiftUp()
{
    if (m_gearPos <= m_gearCount)
    {
        ++m_gearPos;
        std::cout << "Gearbox is in [" << m_currentGear[m_gearPos] << "] position\n";
    }
    else
    {
        std::cout << "you can't shift up!!!" << '\n';
    }
}

void Gearbox::shiftDown()
{
    if (m_gearPos > 0)
    {
        --m_gearPos;
        std::cout << "Gearbox is in [" << m_currentGear[m_gearPos] << "] position\n";
    }
    else
    {
        std::cout << "you can't shift down!!!\n";
    }
}

void Gearbox::shiftNeutral()
{
    m_gearPos = 1;
    std::cout << "Gearbox is in neutral position\n";
}

void Gearbox::printGear()
{
    std::cout << "Gearbox is in [" << m_currentGear[m_gearPos] << "] position\n";
}
