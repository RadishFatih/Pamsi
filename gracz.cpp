#include "gracz.h"


bool gracz::InstertChar(char **plansza,int w, int k)
{
  if(plansza[w][k]!='x'&&plansza[w][k]!='o')
  {
    plansza[w][k]=gracz::getChar();
    return false;
  }
  else 
  return true;
}