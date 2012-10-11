#include <Dante.h>



Level()
{
   setcolor(15);
   settextstyle(4, 0, 3);
   outtextxy(150,220,"Hell yeah!! You`ve killed those maggots!!");
   outtextxy(280,280,"Next Level");
   gotoxy(52,19);
   level++;
   printf("%d",level);
   delay(6000);
   setfillstyle(1,0);
   bar(70,150,600,500);
}