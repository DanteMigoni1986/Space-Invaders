#include <Dante.h>

Menu()
{
   char a;
while(a!='y')
{
   while(!kbhit())
   {
      int y=150;
      settextstyle(4, 0, 8);
      for(int i=0;i<12;i++)
      {
	 setcolor(i);
	 settextstyle(4, 0, 8);
	 outtextxy(70,y,"Space Invaders");
	 settextstyle(4, 0, 2);
	 setcolor(15);
	 outtextxy(265,250,"Press any key");
	 delay(20);
	 y++;
      }i=0;y=150;
   }
   settextstyle(4, 0, 2);
   setcolor(15);
   outtextxy(425,250,"By Dante Migoni");
   settextstyle(4, 0, 4);
   outtextxy(160,300,"Wanna play? (Press 'y')");
   a=getch();
}
   setfillstyle(1,0);
   bar(70,150,600,450);
   setcolor(15);
   settextstyle(4, 0, 3);
   outtextxy(150,220,"Defend the universe from Invasion!!");
   outtextxy(280,280,"Level : 1");
   delay(6000);
   setfillstyle(1,0);
   bar(70,150,600,500);
}