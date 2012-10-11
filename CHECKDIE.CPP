#include <Dante.h>


Checkdie()
{
   int temp;

   temp=contador;
   contador=contador/9;
   setfillstyle(1,0);
   if (contador==1)
   bar(600,460,606,470);
   if (contador==2)
   bar(610,460,616,470);
   if (contador==3)
   bar(620,460,626,470);
   if (contador==4)
   bar(630,460,636,470);
   if(contador==4)
   {  while(continuar!='y')
      {
      settextstyle(4,0,4);
      outtextxy(160,300,"You loose. Try again?? (y)");
      continuar=getch();
      }
   }
   //printf("perdiste");
   contador=temp;

}