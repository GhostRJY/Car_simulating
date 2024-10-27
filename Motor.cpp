#include "Motor.h"

Motor::Motor()
{
    this->setMarking("Motor");
    this->setVolume(0.5);
    this->setWork(false);

    std::cout << "Motor constructed\n";
}

Motor::Motor(const std::string &marking,
             double volume)
{
    this->setMarking(marking);
    this->setVolume(volume);
    this->setWork(false);

    std::cout << "Motor constructed\n";
}

Motor::Motor(const Motor &other)
{
    this->m_marking = other.m_marking;
    this->m_volume = other.m_volume;
    this->m_work = other.m_work;
}

Motor::~Motor()
{
    std::cout << "Motor destroyed\n";
}

const Motor &Motor::operator=(const Motor &right)
{
    if (this != &right)
    {
        m_marking = right.m_marking;
        m_volume = right.m_volume;
        m_work = right.m_work;
    }

    return *this;
}

void Motor::startEngine()
{
    this->m_work = true;
    std::cout << "(Motor is started)\n";
}

void Motor::offEngine()
{
    this->m_work = false;
    std::cout << "(Motor is off)\n";
}

bool Motor::getWork() const
{
    return this->m_work;
}

std::string Motor::getMarking() const
{
    return this->m_marking;
}

double Motor::getVolume() const
{
    return this->m_volume;
}

// сеттеры
void Motor::setMarking(const std::string &mark)
{
    this->m_marking = mark;
}

void Motor::setWork(const bool state)
{
    this->m_work = state;
}

void Motor::setVolume(const double volume)
{
    this->m_volume = volume;
}
