#include <iostream>
#include <fstream>
#include <cmath>
#include "gra.h"
#include "interfejs.h"

int main()
{
    system("clear");
    gracz P1('x'), P2('o'); //inicjuje graczy oraz ich znak
    bool pierwszy, *wpierwszy = &pierwszy;
    int rozmiar, *wrozmiar = &rozmiar, wybor;
    rozmiar = 3;
    pierwszy = true;

    for (;;)
    {
        //początkowe menu, tutaj gracz podejmuje decyzje o zaczęciu gry
        std::cout << "1. Start" << std::endl;
        std::cout << "2. Zmien rozmiar planszy" << std::endl;
        std::cout << "3. Wyjscie" << std::endl;
        std::cin >> wybor;
        switch (wybor)
        {
        case 1:
        {
            startGry(rozmiar, pierwszy);
            break;
        }
        case 2:
        {
            system("clear");
            std::cout << "Podaj rozmiar planszy:" << std::endl;
            std::cin >> wybor;
            if (wybor >= 3)
            {
                rozmiar = wybor;
            }
            else
                std::cout << "Rozmiar musi byc conajmniej rowny 3" << std::endl;
            break;
        }
        case 3:
            break;
        default:
        {
            system("clear");
            std::cout << "Nie ma takiego polecenia" << std::endl;
            break;
        }
        }
        if (wybor == 3)
            break;
    }

    return 0;
}