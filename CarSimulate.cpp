#include <iostream>
#include "Auto.h"
#include "Driver.h"

int main()
{

    Auto *autoPtr = new Auto("Audi", "A6", 1503.0, "3.0 TDI", 3.0, "ZF", 7, "BBS", "Pirelli", 245, 50, 18);

    std::cout << *autoPtr;

    Driver driver("Yevhenii", "Rode", autoPtr, 300, 100.00);

    std::cout << driver.getAuto();
    std::cout << driver.getEnergy() << " " << driver.getExperience() << "\n\n";

    // симуляция поездки

    driver.sitInCar();
    driver.startEngine();
    if (driver.startTrip(100))
    {
        std::cout << driver.getEnergy() << " " << driver.getExperience() << "\n\n";
    }
    else
    {
        driver.goOut();
        driver.goSleep();
    }

    // проверка указателя у которого забрал автомобиль
    // delete autoPtr;
    return 0;
}
