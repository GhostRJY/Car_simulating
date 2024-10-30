#include "Driver.h"
#define DEBUG
Driver::Driver()
    // инициализирую все указатели 0 из-за того что там лежат мусорные значения и соответственно сеттеры отрабатывают не правильно
    : m_fname{nullptr},
      m_lname{nullptr},
      m_ptrAuto{nullptr}
{
    setLastName("");
    setFirstName("");
    setExperience(0);
    setEnergy(100.00);

#ifdef DEBUG
    std::cout << "Empty Driver created\n";
#endif
}

Driver::Driver(const char *firstName, const char *lastName, Auto *automobile, const int experience, const double energy)
    : m_fname{nullptr},
      m_lname{nullptr},
      m_ptrAuto{nullptr} // инициализирую все указатели 0 из-за того что там лежат мусорные значения и соответственно сеттеры отрабатывают не правильно
{
    setLastName(lastName);
    setFirstName(firstName);
    setAuto(automobile);
    setExperience(experience);
    setEnergy(energy);

#ifdef DEBUG
    std::cout << "Driver " << this->m_fname << ' ' << this->m_lname << " created\n";
#endif
}

Driver::~Driver()
{
    if (this->m_fname != nullptr)
    {
        delete[] this->m_fname;
        this->m_fname = nullptr;
#ifdef DEBUG
        std::cout << "\nFirst name is deleted correctly\n";
#endif
    }

    if (this->m_lname != nullptr)
    {
        delete[] this->m_lname;
        this->m_lname = nullptr;
#ifdef DEBUG
        std::cout << "\nLast name is deleted correctly\n";
#endif
    }

    if (this->m_ptrAuto != nullptr)
    {
        delete this->m_ptrAuto;
        this->m_ptrAuto = nullptr;

#ifdef DEBUG
        std::cout << "\nAutoPtr is deleted correctly\n";
#endif
    }

#ifdef DEBUG
    std::cout << "Object is deleted correctly\n";
#endif
}

void Driver::setFirstName(const char *fName)
{
    if (this->m_fname != nullptr)
    {
        delete[] this->m_fname;
        this->m_fname = nullptr;
    }

    int length = std::strlen(fName) + 1;
    this->m_fname = new char[length];
    strcpy_s(this->m_fname, length, fName);
}

void Driver::setLastName(const char *lName)
{
    if (this->m_lname != nullptr)
    {
        delete[] this->m_lname;
        this->m_lname = nullptr;
    }

    int length = std::strlen(lName) + 1;
    this->m_lname = new char[length];
    strcpy_s(this->m_lname, length, lName);
}

void Driver::setAuto(Auto *autoPtr)
{
    if (this->m_ptrAuto != nullptr)
    {
        delete this->m_ptrAuto;
        this->m_ptrAuto = nullptr;
    }

    this->m_ptrAuto = autoPtr;
    autoPtr = nullptr;
}

void Driver::setExperience(const int experience)
{
    if (experience >= 0)
        this->m_experience = experience;
    else
    {
        std::cout << "invalid value!!!\n";
    }
}

void Driver::setEnergy(const double energy)
{
    if (energy >= 0.0 && energy <= 100.00)
        this->m_energy = energy;
    else
    {
        std::cout << "invalid value!!!\n";
    }
}

const char *Driver::getFirstName() const
{
    return this->m_fname;
}
const char *Driver::getLastName() const
{
    return this->m_lname;
}

const Auto Driver::getAuto() const
{
    return *this->m_ptrAuto;
}

int Driver::getExperience() const
{
    return this->m_experience;
}

double Driver::getEnergy() const
{
    return this->m_energy;
}