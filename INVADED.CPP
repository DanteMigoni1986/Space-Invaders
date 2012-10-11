#include <Dante.h>





Invaded()
{
   settextstyle(4, 0, 2);
   setcolor(15);
   while(continuar!='y')
   {
   outtextxy(220,250,"You`ve been invaded!!");
   outtextxy(240,280,"Try again?  (y)");
   continuar=getch();
   }
   setfillstyle(1,0);
   bar(220,220,500,350);

}