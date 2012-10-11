#include <Dante.h>


Borra1(int xini,int xfin,int nivel,int sent)
{

   setfillstyle(9,0);
   if(sent==1)
   bar(xini-1,30,xini-1-nivel,50);
   if(sent==2)
   bar(xfin+1,30,xfin+1+nivel,50);

}