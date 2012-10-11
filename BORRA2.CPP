#include <Dante.h>


Borra2(int xini1,int xfin1,int xini2,int xfin2,int nivel,int sent)
{

   setfillstyle(9,0);
   if(sent==1)
   {
      setfillstyle(9,0);
      bar(xini1-1,300,xini1-5-nivel,316);
      setfillstyle(9,0);
      bar(xini2-1,292,xini2-5-nivel,300);
   }
   if(sent==2)
   {
      setfillstyle(9,0);
      bar(xfin1+1,300,xfin1+5+nivel,316);
      setfillstyle(9,0);
      bar(xfin2+1,292,xfin2+5+nivel,300);
   }

}