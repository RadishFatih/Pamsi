#include <iostream>
#include <fstream>

class gracz
{
  protected:
  char PChar;
  public:
  char getChar() {return PChar;}
  bool InstertChar(char **plansza,int w,int k);
  gracz(char c) {PChar = c;}

};