#include <iostream>
#include <fstream>
#include <cmath>
#include "gracz.h"
#include "interfejs.h"

void startGry(int rozmiar,bool pierwszy);
bool sprawdzWygrana(char **plansza, int rozmiar, char c);
bool sprawdzRemis(char **plansza, int rozmiar);
int CtScore(char **plansza, int rozmiar, char c);
int MiniMax(char **plansza, char PChar,int rozmiar, int depth, int a, int b);
void AI(char **plansza, gracz AIP,int rozmiar);