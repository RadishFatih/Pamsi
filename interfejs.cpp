#include "interfejs.h"
/*
Funkcja wys
*/
void wyswietlPlansze(int rozmiar, char **plansza)
{
    for (int j = 0; j < rozmiar; j++)
        std::cout << "+---";
    std::cout <<"+"<< std::endl;
    for (int i = 0; i < rozmiar; i++)
    {
        std::cout << "| ";
        for (int j = 0; j < rozmiar; j++)
        {
            std::cout << plansza[i][j] << " | ";
        }
        std::cout << std::endl;
        for (int j = 0; j < rozmiar; j++)
            std::cout << "+---";
        std::cout <<"+"<< std::endl;
    }
}

