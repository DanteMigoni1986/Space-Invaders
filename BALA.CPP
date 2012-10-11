#include <Dante.h>


Bala(int x,int alt)
{
   setfillstyle(1,255);
   bar(x+2,alt,x+4,alt-9);
   if(getpixel(x,alt)!=0)
      printf("Le diste\n");
}

