#include "gra.h"
static int INF = 900000000;
void startGry(int rozmiar,bool pierwszy)
{
    gracz P1('x'),P2('o');
    int k,w;
    char **plansza;
    plansza = new char *[rozmiar];
    for(int i=0; i<rozmiar; i++)   plansza[i] = new char [rozmiar];
    for(int i=0; i<rozmiar; i++)
    {
        for(int j=0; j<rozmiar; j++) plansza[i][j]='-';
    }
    system("clear");
    wyswietlPlansze(rozmiar,plansza);
   if(pierwszy)
   {
   for(;;)
   {
    std::cout<<"Tura gracza:";
    std::cin>>w>>k;
   while( P2.InstertChar(plansza,w,k) )
   {
       system("clear");
       wyswietlPlansze(rozmiar,plansza);
       std::cout<<"Pole jest zajete, wybierz ponownie!"<<std::endl;
       std::cin>>w>>k;
   }
    system("clear");
    wyswietlPlansze(rozmiar,plansza);
    std::cout<<"Tura kompuetra prosze czekac..."<<std::endl;
    if(sprawdzWygrana(plansza,rozmiar,P2.getChar()))
    {
        std::cout<<"O wygrywa"<<std::endl;
        break;
    }
    if(sprawdzRemis(plansza,rozmiar))
    {
       std::cout<<"Remis!"<<std::endl;
       break; 
    }

    AI(plansza,P1,rozmiar);
    system("clear");
    wyswietlPlansze(rozmiar,plansza);
    if(sprawdzWygrana(plansza,rozmiar,P1.getChar()))
    {
        std::cout<<"X wygrywa"<<std::endl;
        break;
    }
    if(sprawdzRemis(plansza,rozmiar))
    {
       std::cout<<"Remis!"<<std::endl;
       break; 
    }
   }
   }
   else
   {
        for(;;)
   {
    std::cout<<"Tura kompuetra prosze czekac..."<<std::endl;
    AI(plansza,P1,rozmiar);
    system("clear");
    wyswietlPlansze(rozmiar,plansza);
    if(sprawdzWygrana(plansza,rozmiar,P1.getChar()))
    {
        std::cout<<"X wygrywa"<<std::endl;
        break;
    }
    if(sprawdzRemis(plansza,rozmiar))
    {
       std::cout<<"Remis!"<<std::endl;
       break; 
    }
    std::cout<<"Tura gracza, podaj wspozende znaku: ";
    std::cin>>w>>k;
    while( P2.InstertChar(plansza,w,k) )
   {
       system("clear");
       wyswietlPlansze(rozmiar,plansza);
       std::cout<<"Pole jest zajete wybierz ponownie!"<<std::endl;
       std::cin>>w>>k;
   }
    system("clear");
    wyswietlPlansze(rozmiar,plansza);
    if(sprawdzWygrana(plansza,rozmiar,P2.getChar()))
    {
        std::cout<<"O wygrywa"<<std::endl;
        break;
    }
    if(sprawdzRemis(plansza,rozmiar))
    {
       std::cout<<"Remis!"<<std::endl;
       break; 
    }

   }
   }
}

bool sprawdzWygrana(char **plansza, int rozmiar, char c){
    int temp;
    for (int i = 0; i < rozmiar; i++){
        temp = 0;
        for (int j = 0; j < rozmiar; j++){
            if (plansza[i][j] == c)
                temp++;
            if (temp == rozmiar)
                return true;
        }
    }

    for (int i = 0; i < rozmiar; i++){
        temp = 0;
        for (int j = 0; j < rozmiar; j++){
            if (plansza[j][i] == c)
                temp++;
            if (temp == rozmiar)
                return true;
        }
    }
    temp = 0;
    for (int i = 0; i < rozmiar; i++){
        if (plansza[i][i] == c)
            temp++;
        if (temp == rozmiar)
            return true;
    }
    temp = 0;
    for (int i = 1; i <= rozmiar; i++){
        if (plansza[rozmiar - i][i - 1] == c)
            temp++;
        if (temp == rozmiar)
            return true;
    }
    return false;
}
bool sprawdzRemis(char **plansza, int rozmiar){
    for (int i = 0; i < rozmiar; i++){
        for (int j = 0; j < rozmiar; j++){
            if (plansza[i][j] != 'x' && plansza[i][j] != 'o')
                return false;
        }
    }
    return true;
}

int CtScore(char **plansza, int rozmiar, char c){
    int score = 0;
    int temp;
    for (int i = 0; i < rozmiar; i++){
        temp = 0;
        for (int j = 0; j < rozmiar; j++){
            if (plansza[i][j] == c)
                temp++;
            else if (plansza[i][j] != '-'){

                temp = 0;
                break;
            }
        }
        if (temp != 0)
            score += pow(10, temp);
    }

    for (int i = 0; i < rozmiar; i++){
        temp = 0;
        for (int j = 0; j < rozmiar; j++){
            if (plansza[j][i] == c)
                temp++;
            else if (plansza[j][i] != '-'){
                temp = 0;
                break;
            }
        }
        if (temp != 0)
            score += pow(10, temp);
    }

    temp = 0;

    for (int i = 0; i < rozmiar; i++){
        if (plansza[i][i] == c)
            temp++;
        else if (plansza[i][i] != '-'){
            temp = 0;
            break;
        }
    }
    if (temp != 0)
        score += pow(10, temp);
    temp = 0;

    for (int i = 1; i <= rozmiar; i++){
        if (plansza[rozmiar - i][i - 1] == c)
            temp++;
        if (plansza[rozmiar - i][i - 1] != c && plansza[rozmiar - 1][i - 1] != '-')
        {
            temp = 0;
            break;
        }
    }
    if (temp != 0)
        score += pow(10, temp);
    return score;
}
int MiniMax(char **plansza, char PChar, int rozmiar, int depth, int a, int b){
    int m, minmax;
    if (sprawdzWygrana(plansza, rozmiar, PChar))
    {
        if (PChar == 'x')
            return 100000000;
        else
            return -100000000;
    }
    if (sprawdzRemis(plansza, rozmiar) || depth == 0)
    {
        if (PChar == 'x')
            return CtScore(plansza, rozmiar, PChar);
        else
            return (-1) * CtScore(plansza, rozmiar, PChar);
    }
    if (PChar == 'o')
    {
        PChar = 'x';
        minmax = -INF;
    }
    else
    {
        PChar = 'o';
        minmax = INF;
    }
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            if (plansza[i][j] == '-')
            {
                if (PChar == 'x')
                {
                    plansza[i][j] = PChar;
                    m = MiniMax(plansza, PChar, rozmiar, depth - 1, a, b);
                    if (minmax < m)
                        minmax = m;
                    if (a < minmax)
                        a = minmax;
                    plansza[i][j] = '-';
                    if (a >= b)
                        return minmax;
                }

                else
                {
                    plansza[i][j] = PChar;
                    m = MiniMax(plansza, PChar, rozmiar, depth - 1, a, b);
                    if (minmax > m)
                        minmax = m;
                    if (b > minmax)
                        b = minmax;
                    plansza[i][j] = '-';
                    if (a >= b)
                        return minmax;
                }
            }
        }
    }
    return minmax;
}

void AI(char **plansza, gracz AIP,int rozmiar){
  int m, minmax=-INF, movej,movei;
  for(int i=0; i<rozmiar; i++)
  {
      for(int j=0; j<rozmiar; j++)
      {
          if(plansza[i][j]=='-')
          {
             plansza[i][j]= AIP.getChar();
             m=MiniMax(plansza,AIP.getChar(),rozmiar,6,-INF,INF);
             plansza[i][j]= '-';
             if(m>minmax)
             {
                 minmax=m; 
                 movei=i; 
                 movej=j;
             }
          }
          
      }
  }
 AIP.InstertChar(plansza,movei,movej);
}