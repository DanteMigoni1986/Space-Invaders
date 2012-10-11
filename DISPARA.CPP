#include <Dante.h>


Dispara(int a)
{
   setfillstyle(1,255);
   for(int i=293;i>0;i=i-25)
   {
      bar(a+2,i,a+4,i-2);
      delay(30);
      putpixel(a+2,i,0);
      putpixel(a+3,i,0);
      putpixel(a+4,i,0);
      putpixel(a+2,i-1,0);
      putpixel(a+3,i-1,0);
      putpixel(a+4,i-1,0);
      putpixel(a+2,i-2,0);
      putpixel(a+3,i-2,0);
      putpixel(a+4,i-2,0);
   }


}

