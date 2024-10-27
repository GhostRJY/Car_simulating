#include "Auto.h"

Auto::Auto()
{
    this->setBrand("Auto");

    this->setModel("Model");

    this->setMotor(Motor());

    this->setGearbox(Gearbox());

    this->setTyres(Tyres());

    this->setRims("rims", 200, 60, 17);

    std::cout << "Auto constructed\n";
}

Auto::Auto(const std::string &brand,
           const std::string &model,
           const std::string &motorMarking,
           double motorVolume,
           const std::string &gearBoxMarking,
           const unsigned short gearCount,
           const std::string &rimsMark,
           const std::string &tyreMark,
           unsigned short width,
           unsigned short height,
           unsigned short radius)
{
    // делегирую инициализацию полей класса
    this->setBrand(brand);

    this->setModel(model);

    this->setMotor(motorMarking, motorVolume);

    this->setGearbox(gearBoxMarking, gearCount);

    this->setTyres(tyreMark, width, height, radius);

    this->setRims(rimsMark, width, height, radius);

    std::cout << "Auto constructed\n";
}

Auto::Auto(const Auto &other)
{
    this->setBrand(other.m_brand);

    this->setModel(other.m_model);

    this->setMotor(other.m_motor);

    this->setGearbox(other.m_gearbox);

    this->setTyres(other.m_tyres);

    this->setRims(other.m_rims);
}

Auto::~Auto()
{
    std::cout << "Auto destroyed\n";
}

const Auto &Auto::operator=(const Auto &right)
{
    if (this != &right)
    {
        m_brand = right.m_brand;
        m_model = right.m_model;
        m_motor = right.m_motor;
        m_gearbox = right.m_gearbox;
        m_rims = right.m_rims;
        m_tyres = right.m_tyres;
    }
    return *this; // позволяет последовательное присваивание a=b=c
}

std::string Auto::getBrand() const
{
    return this->m_brand;
}

std::string Auto::getModel() const
{
    return this->m_model;
}

Motor Auto::getMotor() const
{
    return this->m_motor;
}

Gearbox Auto::getGearbox() const
{
    return this->m_gearbox;
}

Tyres Auto::getTyres() const
{
    return this->m_tyres;
}

Rims Auto::getRims() const
{
    return this->m_rims;
}

void Auto::setBrand(const std::string &brand)
{
    this->m_brand = brand;
}

void Auto::setModel(const std::string &model)
{
    this->m_model = model;
}

void Auto::setMotor(const Motor &motor)
{
    this->m_motor = motor;
}

void Auto::setMotor(const std::string &mark,
                    const double volume)
{
    this->m_motor = Motor(mark, volume);
}

void Auto::setGearbox(const Gearbox &gearbox)
{
    this->m_gearbox = gearbox;
}

void Auto::setGearbox(const std::string &mark,
                      unsigned short gearCount)
{
    this->m_gearbox = Gearbox(mark, gearCount);
}

void Auto::setTyres(const Tyres &tyres)
{
    this->m_tyres = tyres;
}

void Auto::setTyres(const std::string &mark,
                    const int width,
                    const int height,
                    const int radius)
{
    this->m_tyres = Tyres(mark, width, height, radius);
}

void Auto::setRims(const Rims &rims)
{
    this->m_rims = rims;
}

void Auto::setRims(const std::string &mark,
                   const int width,
                   const int height,
                   const int radius)
{
    this->m_rims = Rims(mark, width, height, radius);
}

void Auto::turnOn()
{
    m_motor.startEngine();
}

void Auto::turnOff()
{
    m_motor.offEngine();
}

void Auto::gearUp()
{
    m_gearbox.shiftUp();
}

void Auto::gearDown()
{
    m_gearbox.shiftDown();
}

void Auto::startMoving()
{
    if (m_motor.getWork())
    {
        while (m_gearbox.getGearPos() < m_gearbox.getGearCount())
        {

            gearUp();
            if (m_gearbox.getGearPos() == 2)
                std::cout << "Auto start moving\n";

            m_rims.spinWheels();
            Sleep(700);
        }
    }
    else
    {
        std::cout << "Your motor is off!!!\n";
    }
}

void Auto::stopMoving()
{
    m_gearbox.printGear();

    while (m_gearbox.getGearPos() > 1)
    {
        std::cout << "Auto slowing\n";
        gearDown();
        Sleep(1000);
    }

    std::cout << "Auto is stopped\n";
}