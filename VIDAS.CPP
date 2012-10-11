#include <Dante.h>

Vidas()
{
   settextstyle(0, 0, 1);
   setcolor(15);
   outtextxy(544,462,"Health");
   setfillstyle(1,2);
   if(contador<1)
   bar(600,460,606,470);
   if(contador<2)
   bar(610,460,616,470);
   if(contador<3)
   bar(620,460,626,470);
   if(contador<4)
   bar(630,460,636,470);
}