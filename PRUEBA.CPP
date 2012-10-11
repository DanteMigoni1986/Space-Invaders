#include <Dante.h>
//Inicia();
//Limpia(int y1,int y2, int y3);

class Nave
{
public:

      int xmax,xini,xini1,xini2,xfin,xfin1,xfin2,sent,nivel,color,y1,y2;

public:
      Nave();
   //   ~Nave();
      Dibujana();
      Dibuna2();
      Borra1();
      Borra2();
};

Nave::Nave()
{
   xmax=getmaxx();
   xini=(xmax/2)-15;
   xfin=(xmax/2)+15;
   xini1=(xmax/2)-20;
   xfin1=(xmax/2)+20;
   xini2=(xmax/2)-4;
   xfin2=(xmax/2)+4;
}

Nave::Dibujana()
{

   setfillstyle(9,color);
   bar(xini,y1,xfin,y2);

}
Nave::Dibuna2()
{

   setfillstyle(9,255);
   bar(xini1,430,xfin1,446);
   bar(xini2,422,xfin2,430);

}
Nave::Borra1()
{

   setfillstyle(9,0);
   if(sent==1)
   bar(xini-1,y1,xini-1-nivel,y2);
   if(sent==2)
   bar(xfin+1,y1,xfin+1+nivel,y2);

}
Nave::Borra2()
{

    setfillstyle(9,0);
   if(sent==1)
   {
      setfillstyle(9,0);
      bar(xini1-1,430,xini1-5-nivel,446);
      setfillstyle(9,0);
      bar(xini2-1,422,xini2-5-nivel,430);
   }
   if(sent==2)
   {
      setfillstyle(9,0);
      bar(xfin1+1,430,xfin1+5+nivel,446);
      setfillstyle(9,0);
      bar(xfin2+1,422,xfin2+5+nivel,430);
   }

}

main()
{
int d=1,xmax,y1,y2,y3;
char wise;
clrscr();
int graphdriver=DETECT, graphmode, factor_ajuste;

   initgraph(&graphdriver, &graphmode, "c:\\TC\\bgi");
xmax=getmaxx();
Nave *Enemigos1=new Nave[7];
Nave *Enemigos2=new Nave[7];
Nave *Enemigos3=new Nave[6];

for(int i=0;i<7;i++)
Enemigos1[i].y1=30;

for(i=0;i<7;i++)
Enemigos1[i].y2=50;

for(i=0;i<7;i++)
Enemigos1[i].nivel=3;

Enemigos1[0].color=2;
Enemigos1[1].xini=Enemigos1[1].xini+60;
Enemigos1[1].xfin=Enemigos1[1].xfin+60;
Enemigos1[1].color=1;
Enemigos1[2].xini=Enemigos1[2].xini-60;
Enemigos1[2].xfin=Enemigos1[2].xfin-60;
Enemigos1[2].color=1;
Enemigos1[3].xini=Enemigos1[3].xini+120;
Enemigos1[3].xfin=Enemigos1[3].xfin+120;
Enemigos1[3].color=12;
Enemigos1[4].xini=Enemigos1[4].xini-120;
Enemigos1[4].xfin=Enemigos1[4].xfin-120;
Enemigos1[4].color=12;
Enemigos1[5].xini=Enemigos1[5].xini-180;
Enemigos1[5].xfin=Enemigos1[5].xfin-180;
Enemigos1[5].color=14;
Enemigos1[6].xini=Enemigos1[6].xini+180;
Enemigos1[6].xfin=Enemigos1[6].xfin+180;
Enemigos1[6].color=14;
for(i=0;i<7;i++)
Enemigos1[i].Dibujana();

for(i=0;i<7;i++)
Enemigos2[i].y1=70;

for(i=0;i<7;i++)
Enemigos2[i].y2=90;

for(i=0;i<7;i++)
Enemigos2[i].nivel=3;

Enemigos2[0].color=2;
Enemigos2[1].xini=Enemigos2[1].xini+80;
Enemigos2[1].xfin=Enemigos2[1].xfin+80;
Enemigos2[1].color=1;
Enemigos2[2].xini=Enemigos2[2].xini-80;
Enemigos2[2].xfin=Enemigos2[2].xfin-80;
Enemigos2[2].color=1;
Enemigos2[3].xini=Enemigos2[3].xini+160;
Enemigos2[3].xfin=Enemigos2[3].xfin+160;
Enemigos2[3].color=12;
Enemigos2[4].xini=Enemigos2[4].xini-160;
Enemigos2[4].xfin=Enemigos2[4].xfin-160;
Enemigos2[4].color=12;
Enemigos2[5].xini=Enemigos2[5].xini-240;
Enemigos2[5].xfin=Enemigos2[5].xfin-240;
Enemigos2[5].color=14;
Enemigos2[6].xini=Enemigos2[6].xini+240;
Enemigos2[6].xfin=Enemigos2[6].xfin+240;
Enemigos2[6].color=14;
for(i=0;i<7;i++)
Enemigos2[i].Dibujana();

for(int a=0;a<6;a++)
Enemigos3[a].y1=110;

for(a=0;a<6;a++)
Enemigos3[a].y2=130;

for(a=0;a<6;a++)
Enemigos3[a].nivel=3;

Enemigos3[0].xini=Enemigos3[0].xini+40;
Enemigos3[0].xfin=Enemigos3[0].xfin+40;
Enemigos3[0].color=2;
Enemigos3[1].xini=Enemigos3[1].xini-40;
Enemigos3[1].xfin=Enemigos3[1].xfin-40;
Enemigos3[1].color=2;
Enemigos3[2].xini=Enemigos3[2].xini+120;
Enemigos3[2].xfin=Enemigos3[2].xfin+120;
Enemigos3[2].color=12;
Enemigos3[3].xini=Enemigos3[3].xini-120;
Enemigos3[3].xfin=Enemigos3[3].xfin-120;
Enemigos3[3].color=12;
Enemigos3[4].xini=Enemigos3[4].xini+200;
Enemigos3[4].xfin=Enemigos3[4].xfin+200;
Enemigos3[4].color=14;
Enemigos3[5].xini=Enemigos3[5].xini-200;
Enemigos3[5].xfin=Enemigos3[5].xfin-200;
Enemigos3[5].color=14;
for(a=0;a<6;a++)
Enemigos3[a].Dibujana();

Nave Nave2;
Nave2.nivel=3;
Nave2.Dibuna2();



getch();
}