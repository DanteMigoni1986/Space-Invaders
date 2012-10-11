#define EXT

#include <Dante.h>
Inicia();
Checkdie();
Level();
Menu();
Vidas();
Invaded();
Limpia(int y1,int y2, int y3);

class Nave
{
public:

      int xmax,xini,aleatorio,xini1,xini2,xfin,xfin1,xfin2,sent,nivel,color,y1,y2,destruye,xcrash1,ycrash1;

public:
      Nave();
      Dibujana();
      Dibuna2();
      Borra1();
      Borra2();
      Destroy();
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
   destruye=0;
   nivel=0;
}

Nave::Destroy()
{
   color=0;
   Dibujana();
   Borra1();
  // setfillstyle(1,0);
 //  bar(xini,y1,xfin,y2);
   destruye=1;
}

Nave::Dibujana()
{
   if(destruye==0)
   {
   setfillstyle(1,color);
   bar(xini,y1,xfin,y2);
   }
}
Nave::Dibuna2()
{

   setfillstyle(1,255);
   bar(xini1,430,xfin1,446);
   bar(xini2,422,xfin2,430);

}
Nave::Borra1()
{
   if (destruye==0)
   {
   setfillstyle(9,0);
   if(sent==1)
   bar(xini-1,y1,xini-1-nivel,y2);
   if(sent==2)
   bar(xfin+1,y1,xfin+1+nivel,y2);
   }
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

class Bala
{
public:
       int xstart,ledio,xgo,y3,shoot,shoot2,buscale,xcrash,ycrash;

public:

       Bala();
       Drawbull();
       Erabull();
       Drawbull2();
       Erabull2();
       Inc2();
       Coorde2();
       Inc();
       Coorde();
}
Bala::Bala()
{
   xstart=0;
   y3=130;
   shoot=0;
   buscale=0;
   ledio=0;
}

Bala::Drawbull()
{
   if(shoot==1)
   {
      setfillstyle(1,255);
      bar(xstart,y3,xstart+2,y3-6);
   }
}
Bala::Erabull()
{
   if(shoot==1)
   {
      setfillstyle(1,0);
      bar(xstart,y3,xstart+2,y3-6);
   }
}
Bala::Inc()
{
   if(shoot==1)
      y3=y3-18;
   if(y3<0 )
      {
      Erabull();
      shoot=0;
      y3=0;
      }
}
Bala::Coorde()
{
   if(getpixel(xstart+1,y3-7)!=0 || getpixel(xstart,y3-7)!=0 || getpixel(xstart+2,y3-7)!=0 || getpixel(xstart+1,y3-3)!=0 || getpixel(xstart,y3-3)!=0 || getpixel(xstart+2,y3-3)!=0|| getpixel(xstart+1,y3)!=0 || getpixel(xstart,y3)!=0 || getpixel(xstart+2,y3)!=0)
      {
	 moveto(xstart+1,y3-7);
	 xcrash=getx();
	 ycrash=gety();
	 buscale=1;
	// Erabull();
	 //shoot=0;
	// y3=0;
      }
}
Bala::Drawbull2()
{
   if(shoot2==1)
   {
      setfillstyle(1,15);
      bar(xgo,y3,xgo+2,y3+6);
   }
}
Bala::Erabull2()
{
   if(shoot2==1)
   {
      setfillstyle(1,0);
      bar(xgo,y3,xgo+2,y3+6);
   }
}
Bala::Inc2()
{
   if(shoot2==1)
      y3=y3+18;
   if(y3>440)
      {
      Erabull2();
      shoot2=0;
      y3=0;
      }
}
Bala::Coorde2()
{
   if(getpixel(xgo+1,y3+7)==15 && y3>400 || getpixel(xgo,y3+7)==15 && y3>400|| getpixel(xgo+2,y3+7)==15 && y3>400)
      {
	  contador++;
	  Erabull2();
	  shoot2=0;
	  y3=0;

      }
}
main()
{
int d=1,plus=0,xmax,xcompare,x2compare,ycompare,y2compare,y1,y2,y3,total,temp,gano=0,tempo,tempo2,tempo3,x1comp,inc=0,inc2=0,inc3=0,cuenta=0,x2comp,y1comp,y2comp,x3comp,x4comp,y3comp,y4comp,x5comp,x6comp,y5comp,y6comp,count=0;
char wise,bala;
int naves[20];
level=1;

Inicia();
xmax=getmaxx();
Menu();
Nave *Enemigos1=new Nave[7];
Nave *Enemigos2=new Nave[7];
Nave *Enemigos3=new Nave[6];
Bala *Bulloff=new Bala[15];
Bala *Bullen=new Bala[60];


for(int i=0;i<7;i++)
Enemigos1[i].y1=30;

for(i=0;i<7;i++)
Enemigos1[i].y2=50;

for(i=0;i<7;i++)
Enemigos1[i].nivel=Enemigos1[i].nivel+3;

Enemigos1[0].color=2;
Enemigos1[1].xini=Enemigos1[3].xini+60;
Enemigos1[1].xfin=Enemigos1[3].xfin+60;
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
Enemigos2[i].nivel=Enemigos2[i].nivel+3;

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

for(i=0;i<6;i++)
Enemigos3[i].y1=110;

for(i=0;i<6;i++)
Enemigos3[i].y2=130;

for(i=0;i<6;i++)
Enemigos3[i].nivel=Enemigos3[i].nivel+3;

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
Nave Nave2;
Nave2.nivel=3;
Nave2.Dibuna2();
Nave Nave3;
Nave3.nivel=4;
Nave3.color=8;
Nave3.destruye=0;
Nave3.xini=-40;
Nave3.xfin=0;
Nave3.y1=5;
Nave3.y2=25;


for(i=0;i<6;i++)
Enemigos3[i].Dibujana();




while(wise!='a')
{
   do
   {
       switch(d)
       {
	  case 1:
		if(Nave3.destruye==1 && plus<7 && contador>0)
		{contador=contador-9;plus++;}

		Vidas();
		if(gano==1)
		{
		   Level();
		   for(int i=0;i<7;i++)
		      Enemigos1[i].y1=30;
		   for(i=0;i<7;i++)
		   {
		      Enemigos1[i].xini=(xmax/2)-15;
		      Enemigos1[i].xfin=(xmax/2)+15;
		      Enemigos1[i].xini1=(xmax/2)-20;
		      Enemigos1[i].xfin1=(xmax/2)+20;
		      Enemigos1[i].xini2=(xmax/2)-4;
		      Enemigos1[i].xfin2=(xmax/2)+4;
		   }
		   for(i=0;i<7;i++)
		   {
		      Enemigos2[i].xini=(xmax/2)-15;
		      Enemigos2[i].xfin=(xmax/2)+15;
		      Enemigos2[i].xini1=(xmax/2)-20;
		      Enemigos2[i].xfin1=(xmax/2)+20;
		      Enemigos2[i].xini2=(xmax/2)-4;
		      Enemigos2[i].xfin2=(xmax/2)+4;
		   }
		   for(i=0;i<6;i++)
		   {
		      Enemigos3[i].xini=(xmax/2)-15;
		      Enemigos3[i].xfin=(xmax/2)+15;
		      Enemigos3[i].xini1=(xmax/2)-20;
		      Enemigos3[i].xfin1=(xmax/2)+20;
		      Enemigos3[i].xini2=(xmax/2)-4;
		      Enemigos3[i].xfin2=(xmax/2)+4;
		   }

		   for(i=0;i<7;i++)
		      Enemigos1[i].y2=50;

		   for(i=0;i<7;i++)
		      Enemigos1[i].nivel=Enemigos1[i].nivel+3;

		   for(i=0;i<7;i++)
		      Enemigos1[i].destruye=0;

		      Enemigos1[0].color=2;
		      Enemigos1[1].xini=Enemigos1[3].xini+60;
		      Enemigos1[1].xfin=Enemigos1[3].xfin+60;
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
		      Enemigos2[i].destruye=0;

		   for(i=0;i<7;i++)
		      Enemigos2[i].y2=90;

		   for(i=0;i<7;i++)
		      Enemigos2[i].nivel=Enemigos2[i].nivel+3;

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

		   for(i=0;i<6;i++)
		      Enemigos3[i].y1=110;

		   for(i=0;i<6;i++)
		      Enemigos3[i].y2=130;

		   for(i=0;i<6;i++)
		      Enemigos3[i].destruye=0;

		   for(i=0;i<6;i++)
		      Enemigos3[i].nivel=Enemigos3[i].nivel+3;

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

		   for(i=0;i<6;i++)
		      Enemigos3[i].Dibujana();

		      gano=0;
		      Nave3.nivel=4;
		      Nave3.color=8;
		      Nave3.destruye=0;
		     // Nave3.sent=1;
		      Nave3.xini=-40;
		      Nave3.xfin=0;
		      Nave3.y1=5;
		      Nave3.y2=25;
		      plus=0;
		      setfillstyle(1,0);
		      bar(0,0,650,30);

		}
		for(int y=0;y<7;y++)
		{
		    if(Enemigos3[y].destruye==1)
		      inc++;
		}tempo=inc;inc=0;
		for(y=0;y<8;y++)
		{
		    if(Enemigos2[y].destruye==1)
		      inc2++;
		}tempo2=inc2;inc2=0;
		for(y=0;y<8;y++)
		{
		    if(Enemigos1[y].destruye==1)
		      inc3++;
		}tempo3=inc3;inc3=0;

		total=tempo+tempo2+tempo3;
		if(total==20)
		{
		   gano=1;
		}
		Checkdie();
		if(continuar=='y')
		 {

		   for(int i=0;i<7;i++)
		      Enemigos1[i].y1=30;
		   for(i=0;i<7;i++)
		   {
		      Enemigos1[i].xini=(xmax/2)-15;
		      Enemigos1[i].xfin=(xmax/2)+15;
		      Enemigos1[i].xini1=(xmax/2)-20;
		      Enemigos1[i].xfin1=(xmax/2)+20;
		      Enemigos1[i].xini2=(xmax/2)-4;
		      Enemigos1[i].xfin2=(xmax/2)+4;
		   }
		   for(i=0;i<7;i++)
		   {
		      Enemigos2[i].xini=(xmax/2)-15;
		      Enemigos2[i].xfin=(xmax/2)+15;
		      Enemigos2[i].xini1=(xmax/2)-20;
		      Enemigos2[i].xfin1=(xmax/2)+20;
		      Enemigos2[i].xini2=(xmax/2)-4;
		      Enemigos2[i].xfin2=(xmax/2)+4;
		   }
		   for(i=0;i<6;i++)
		   {
		      Enemigos3[i].xini=(xmax/2)-15;
		      Enemigos3[i].xfin=(xmax/2)+15;
		      Enemigos3[i].xini1=(xmax/2)-20;
		      Enemigos3[i].xfin1=(xmax/2)+20;
		      Enemigos3[i].xini2=(xmax/2)-4;
		      Enemigos3[i].xfin2=(xmax/2)+4;
		   }

		   for(i=0;i<7;i++)
		      Enemigos1[i].y2=50;

		   for(i=0;i<7;i++)
		      Enemigos1[i].nivel=3;

		   for(i=0;i<7;i++)
		      Enemigos1[i].destruye=0;

		      Enemigos1[0].color=2;
		      Enemigos1[1].xini=Enemigos1[3].xini+60;
		      Enemigos1[1].xfin=Enemigos1[3].xfin+60;
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
		      Enemigos2[i].destruye=0;

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

		   for(i=0;i<6;i++)
		      Enemigos3[i].y1=110;

		   for(i=0;i<6;i++)
		      Enemigos3[i].y2=130;

		   for(i=0;i<6;i++)
		      Enemigos3[i].destruye=0;

		   for(i=0;i<6;i++)
		      Enemigos3[i].nivel=3;

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

		   for(i=0;i<6;i++)
		      Enemigos3[i].Dibujana();

		      gano=0;
		      y1=0;
		      y2=0;
		      y3=0;
		      Vidas();
		      contador=0;
		      continuar=0;
		      setfillstyle(1,0);
		      bar(0,0,650,400);
		      level=1;
		      Nave3.nivel=4;
		   //   Nave3.sent=1;
		      Nave3.color=8;
		      Nave3.destruye=0;
		      Nave3.xini=-40;
		      Nave3.xfin=0;
		      Nave3.y1=5;
		      Nave3.y2=25;
		      plus=0;
		 }
		for(int j=0;j<7;j++)
		   Enemigos1[j].sent=1;
		   j=0;
		for(j=0;j<7;j++)
		   Enemigos2[j].sent=1;
		   j=0;
		for(j=0;j<6;j++)
		   Enemigos3[j].sent=1;
		   j=0;
		Nave3.sent=1;
		if(Enemigos1[1].y1>100)
		{
		   Nave3.xini=Nave3.xini+Nave3.nivel;
		   Nave3.xfin=Nave3.xfin+Nave3.nivel;
		}
		if(Enemigos1[0].xfin<(xmax-250))
		{

		   for(j=0;j<7;j++)
		      {Enemigos1[j].xini=Enemigos1[j].xini+Enemigos1[j].nivel;Enemigos1[j].xfin=Enemigos1[j].xfin+Enemigos1[j].nivel;}
		      j=0;
		   for(j=0;j<7;j++)
		      {Enemigos2[j].xini=Enemigos2[j].xini+Enemigos2[j].nivel;Enemigos2[j].xfin=Enemigos2[j].xfin+Enemigos2[j].nivel;}
		      j=0;
		   for(j=0;j<6;j++)
		      {Enemigos3[j].xini=Enemigos3[j].xini+Enemigos3[j].nivel;Enemigos3[j].xfin=Enemigos3[j].xfin+Enemigos3[j].nivel;}
		      j=0;
		   for(j=0;j<16;j++)
		      Bulloff[j].Inc();
		      j=0;
		   for(j=0;j<61;j++)
		      Bullen[j].Inc2();
		      j=0;
		}
		else
		{
		   d=2;
		   for(int c=0;c<7;c++)
		   {
		      Enemigos1[c].y1=Enemigos1[c].y1+10;
		      Enemigos1[c].y2=Enemigos1[c].y2+10;
		   }
		   c=0;
		   for(c=0;c<7;c++)
		   {
		      Enemigos2[c].y1=Enemigos2[c].y1+10;
		      Enemigos2[c].y2=Enemigos2[c].y2+10;
		   }
		   c=0;
		   for(c=0;c<6;c++)
		   {
		      Enemigos3[c].y1=Enemigos3[c].y1+10;
		      Enemigos3[c].y2=Enemigos3[c].y2+10;
		   }
		   c=0;
		   y1=Enemigos3[2].y1;
		   y2=Enemigos2[2].y1;
		   y3=Enemigos1[2].y1;
		   Limpia(y1,y2,y3);
		}
		if(y1==380 || y2==380 || y3==380)
	  {
		      setfillstyle(1,0);
		      bar(0,200,650,400);
		      Invaded();
	  if(continuar=='n')
	     wise='a';
	  if(continuar=='y')
	  {

		   for(int i=0;i<7;i++)
		      Enemigos1[i].y1=30;
		   for(i=0;i<7;i++)
		   {
		      Enemigos1[i].xini=(xmax/2)-15;
		      Enemigos1[i].xfin=(xmax/2)+15;
		      Enemigos1[i].xini1=(xmax/2)-20;
		      Enemigos1[i].xfin1=(xmax/2)+20;
		      Enemigos1[i].xini2=(xmax/2)-4;
		      Enemigos1[i].xfin2=(xmax/2)+4;
		   }
		   for(i=0;i<7;i++)
		   {
		      Enemigos2[i].xini=(xmax/2)-15;
		      Enemigos2[i].xfin=(xmax/2)+15;
		      Enemigos2[i].xini1=(xmax/2)-20;
		      Enemigos2[i].xfin1=(xmax/2)+20;
		      Enemigos2[i].xini2=(xmax/2)-4;
		      Enemigos2[i].xfin2=(xmax/2)+4;
		   }
		   for(i=0;i<6;i++)
		   {
		      Enemigos3[i].xini=(xmax/2)-15;
		      Enemigos3[i].xfin=(xmax/2)+15;
		      Enemigos3[i].xini1=(xmax/2)-20;
		      Enemigos3[i].xfin1=(xmax/2)+20;
		      Enemigos3[i].xini2=(xmax/2)-4;
		      Enemigos3[i].xfin2=(xmax/2)+4;
		   }

		   for(i=0;i<7;i++)
		      Enemigos1[i].y2=50;

		   for(i=0;i<7;i++)
		      Enemigos1[i].nivel=3;

		   for(i=0;i<7;i++)
		      Enemigos1[i].destruye=0;

		      Enemigos1[0].color=2;
		      Enemigos1[1].xini=Enemigos1[3].xini+60;
		      Enemigos1[1].xfin=Enemigos1[3].xfin+60;
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
		      Enemigos2[i].destruye=0;

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

		   for(i=0;i<6;i++)
		      Enemigos3[i].y1=110;

		   for(i=0;i<6;i++)
		      Enemigos3[i].y2=130;

		   for(i=0;i<6;i++)
		      Enemigos3[i].destruye=0;

		   for(i=0;i<6;i++)
		      Enemigos3[i].nivel=3;

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

		   for(i=0;i<6;i++)
		      Enemigos3[i].Dibujana();

		      gano=0;
		      y1=0;
		      y2=0;
		      y3=0;
		      Vidas();
		      contador=0;
		      continuar=0;
		      level=1;
		      Nave3.nivel=4;
		     // Nave3.sent=1;
		      Nave3.color=8;
		      Nave3.destruye=0;
		      Nave3.xini=-40;
		      Nave3.xfin=0;
		      Nave3.y1=5;
		      Nave3.y2=25;
		      plus=0;
		      setfillstyle(1,0);
		      bar(0,0,650,30);

	  }
	}

		for(int b=0;b<7;b++)
		   Enemigos1[b].Dibujana();
		   b=0;
		for(b=0;b<7;b++)
		   Enemigos2[b].Dibujana();
		   b=0;
		for(b=0;b<6;b++)
		   Enemigos3[b].Dibujana();
		   b=0;
		if(Enemigos1[1].y1>100)
		Nave3.Dibujana();
		for(j=0;j<16;j++)
		{
		      Bulloff[j].Drawbull();
		      Bulloff[j].Coorde();
		      if(Bulloff[j].buscale==1)
		      {
		       xcompare=Nave3.xini;
		       x2compare=Nave3.xfin;
		       ycompare=Nave3.y1;
		       y2compare=Nave3.y2;
		       if(xcompare<=Bulloff[j].xcrash && x2compare>=Bulloff[j].xcrash && ycompare<=Bulloff[j].ycrash && y2compare>=Bulloff[j].ycrash)
		       {Nave3.Destroy();plus++;}
		       for(int v=0;v<8;v++)
		       {
		       x1comp=Enemigos3[v].xini;
		       x2comp=Enemigos3[v].xfin;
		       y1comp=Enemigos3[v].y1;
		       y2comp=Enemigos3[v].y2;
		       x3comp=Enemigos2[v].xini;
		       x4comp=Enemigos2[v].xfin;
		       y3comp=Enemigos2[v].y1;
		       y4comp=Enemigos2[v].y2;
		       x5comp=Enemigos1[v].xini;
		       x6comp=Enemigos1[v].xfin;
		       y5comp=Enemigos1[v].y1;
		       y6comp=Enemigos1[v].y2;
		       if(x1comp<=Bulloff[j].xcrash && x2comp>=Bulloff[j].xcrash && y1comp<=Bulloff[j].ycrash && y2comp>=Bulloff[j].ycrash)
		       Enemigos3[v].Destroy();
			if(x3comp<=Bulloff[j].xcrash && x4comp>=Bulloff[j].xcrash && y3comp<=Bulloff[j].ycrash && y4comp>=Bulloff[j].ycrash)
		       Enemigos2[v].Destroy();
			if(x5comp<=Bulloff[j].xcrash && x6comp>=Bulloff[j].xcrash && y5comp<=Bulloff[j].ycrash && y6comp>=Bulloff[j].ycrash)
		       Enemigos1[v].Destroy();

		       }
		       v=0;
		      }

		}j=0;
		for(j=0;j<7;j++)
		{
		      Enemigos3[j].aleatorio=random(50);
		      Enemigos2[j].aleatorio=random(50);
		}j=0;
		for(j=0;j<61;j++)
		{
		      if(Enemigos3[cuenta].aleatorio==3 && Enemigos3[cuenta].destruye==0)
		      {
		      Bullen[j].shoot2=1;
		      Bullen[j].xgo=Enemigos3[cuenta].xini+14;
		      Bullen[j].y3=Enemigos3[cuenta].y2;
		      Bullen[j].shoot2==0;
		      Bullen[j].Drawbull2();
		      Bullen[j].Erabull2();
		      }
		      cuenta++;
		      if(cuenta>6)
		      cuenta=0;
		}j=0;cuenta=0;
		for(j=0;j<61;j++)
		{
		      if(Enemigos2[cuenta].aleatorio==3 && Enemigos2[cuenta].destruye==0)
		      {
		      Bullen[j].shoot2=1;
		      Bullen[j].xgo=Enemigos2[cuenta].xini+14;
		      Bullen[j].y3=Enemigos2[cuenta].y2;
		      Bullen[j].shoot2==0;
		      Bullen[j].Drawbull2();
		      Bullen[j].Erabull2();
		      }
		      cuenta++;
		      if(cuenta>6)
		      cuenta=0;
		}j=0;cuenta=0;

		for(j=0;j<61;j++)
		{
		      Bullen[j].Drawbull2();
		      Bullen[j].Coorde2();
		}
		j=0;

		delay(100/Enemigos1[1].nivel);

		for(b=0;b<7;b++)
		   Enemigos1[b].Borra1();
		   b=0;
		for(b=0;b<7;b++)
		   Enemigos2[b].Borra1();
		   b=0;
		for(b=0;b<6;b++)
		   Enemigos3[b].Borra1();
		   b=0;
		if(Enemigos1[1].y1>100)
		{
		   Nave3.Borra1();
		}
		for(b=0;b<16;b++)
		      Bulloff[b].Erabull();
		      b=0;
		for(b=0;b<61;b++)
		      Bullen[b].Erabull2();
		      b=0;

		break;
	case 2:
		for(y=0;y<7;y++)
		{
		    if(Enemigos3[y].destruye==1)
		      inc++;
		}tempo=inc;inc=0;
		for(y=0;y<8;y++)
		{
		    if(Enemigos2[y].destruye==1)
		      inc2++;
		}tempo2=inc2;inc2=0;
		for(y=0;y<8;y++)
		{
		    if(Enemigos1[y].destruye==1)
		      inc3++;
		}tempo3=inc3;inc3=0;

		total=tempo+tempo2+tempo3;
		if(total==20)
		{
		   gano=1;
		}
		Checkdie();
			if(continuar=='y')
		 {

		   for(int i=0;i<7;i++)
		      Enemigos1[i].y1=30;
		   for(i=0;i<7;i++)
		   {
		      Enemigos1[i].xini=(xmax/2)-15;
		      Enemigos1[i].xfin=(xmax/2)+15;
		      Enemigos1[i].xini1=(xmax/2)-20;
		      Enemigos1[i].xfin1=(xmax/2)+20;
		      Enemigos1[i].xini2=(xmax/2)-4;
		      Enemigos1[i].xfin2=(xmax/2)+4;
		   }
		   for(i=0;i<7;i++)
		   {
		      Enemigos2[i].xini=(xmax/2)-15;
		      Enemigos2[i].xfin=(xmax/2)+15;
		      Enemigos2[i].xini1=(xmax/2)-20;
		      Enemigos2[i].xfin1=(xmax/2)+20;
		      Enemigos2[i].xini2=(xmax/2)-4;
		      Enemigos2[i].xfin2=(xmax/2)+4;
		   }
		   for(i=0;i<6;i++)
		   {
		      Enemigos3[i].xini=(xmax/2)-15;
		      Enemigos3[i].xfin=(xmax/2)+15;
		      Enemigos3[i].xini1=(xmax/2)-20;
		      Enemigos3[i].xfin1=(xmax/2)+20;
		      Enemigos3[i].xini2=(xmax/2)-4;
		      Enemigos3[i].xfin2=(xmax/2)+4;
		   }

		   for(i=0;i<7;i++)
		      Enemigos1[i].y2=50;

		   for(i=0;i<7;i++)
		      Enemigos1[i].nivel=3;

		   for(i=0;i<7;i++)
		      Enemigos1[i].destruye=0;

		      Enemigos1[0].color=2;
		      Enemigos1[1].xini=Enemigos1[3].xini+60;
		      Enemigos1[1].xfin=Enemigos1[3].xfin+60;
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
		      Enemigos2[i].destruye=0;

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

		   for(i=0;i<6;i++)
		      Enemigos3[i].y1=110;

		   for(i=0;i<6;i++)
		      Enemigos3[i].y2=130;

		   for(i=0;i<6;i++)
		      Enemigos3[i].destruye=0;

		   for(i=0;i<6;i++)
		      Enemigos3[i].nivel=3;

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

		   for(i=0;i<6;i++)
		      Enemigos3[i].Dibujana();

		      gano=0;
		      y1=0;
		      y2=0;
		      y3=0;
		      Vidas();
		      contador=0;
		      continuar=0;
		      setfillstyle(1,0);
		      bar(0,0,650,400);
		      level=1;
		      Nave3.nivel=4;
		      //Nave3.sent=1;
		      Nave3.color=8;
		      Nave3.destruye=0;
		      Nave3.xini=-40;
		      Nave3.xfin=0;
		      Nave3.y1=5;
		      Nave3.y2=25;
		      plus=0;
		      setfillstyle(1,0);
		      bar(0,0,650,30);
		 }
		for(int f=0;f<7;f++)
		   Enemigos1[f].sent=2;
		   f=0;
		for(f=0;f<7;f++)
		   Enemigos2[f].sent=2;
		   f=0;
		for(f=0;f<6;f++)
		   Enemigos3[f].sent=2;
		   f=0;
		   Nave3.sent=1;
		if(Enemigos1[1].y1>100)
		{
		   Nave3.xini=Nave3.xini+Nave3.nivel;
		   Nave3.xfin=Nave3.xfin+Nave3.nivel;
		}

		if (Enemigos1[0].xini>250)
		{
		for(j=0;j<7;j++)
		      {Enemigos1[j].xini=Enemigos1[j].xini-Enemigos1[j].nivel;Enemigos1[j].xfin=Enemigos1[j].xfin-Enemigos1[j].nivel;}
		      j=0;
		   for(j=0;j<7;j++)
		      {Enemigos2[j].xini=Enemigos2[j].xini-Enemigos2[j].nivel;Enemigos2[j].xfin=Enemigos2[j].xfin-Enemigos2[j].nivel;}
		      j=0;
		   for(j=0;j<6;j++)
		      {Enemigos3[j].xini=Enemigos3[j].xini-Enemigos3[j].nivel;Enemigos3[j].xfin=Enemigos3[j].xfin-Enemigos3[j].nivel;}
		      j=0;
		   for(j=0;j<16;j++)
		      Bulloff[j].Inc();
		      j=0;
		    for(j=0;j<61;j++)
		      Bullen[j].Inc2();
		      j=0;
		}
		else
		{
		   d=1;
		    for(int c=0;c<7;c++)
		   {
		      Enemigos1[c].y1=Enemigos1[c].y1+10;
		      Enemigos1[c].y2=Enemigos1[c].y2+10;
		   }
		   c=0;
		   for(c=0;c<7;c++)
		   {
		      Enemigos2[c].y1=Enemigos2[c].y1+10;
		      Enemigos2[c].y2=Enemigos2[c].y2+10;
		   }
		   c=0;
		   for(c=0;c<6;c++)
		   {
		      Enemigos3[c].y1=Enemigos3[c].y1+10;
		      Enemigos3[c].y2=Enemigos3[c].y2+10;
		   }
		   c=0;
		   y1=Enemigos3[2].y1;
		   y2=Enemigos2[2].y1;
		   y3=Enemigos1[2].y1;
		   Limpia(y1,y2,y3);

		}


		for(b=0;b<7;b++)
		   Enemigos1[b].Dibujana();
		   b=0;
		for(b=0;b<7;b++)
		   Enemigos2[b].Dibujana();
		   b=0;
		for(b=0;b<6;b++)
		   Enemigos3[b].Dibujana();
		   b=0;
		if(Enemigos1[1].y1>100)
		{   Nave3.Dibujana();
		}
		for(j=0;j<16;j++)
		{
		      Bulloff[j].Drawbull();
		      Bulloff[j].Coorde();
		      if(Bulloff[j].buscale==1)
		      {
		       xcompare=Nave3.xini;
		       x2compare=Nave3.xfin;
		       ycompare=Nave3.y1;
		       y2compare=Nave3.y2;
		       if(xcompare<=Bulloff[j].xcrash && x2compare>=Bulloff[j].xcrash && ycompare<=Bulloff[j].ycrash && y2compare>=Bulloff[j].ycrash)
		       {Nave3.Destroy();plus++;}
		       for(int v=0;v<8;v++)
		       {
		       x1comp=Enemigos3[v].xini;
		       x2comp=Enemigos3[v].xfin;
		       y1comp=Enemigos3[v].y1;
		       y2comp=Enemigos3[v].y2;
		       x3comp=Enemigos2[v].xini;
		       x4comp=Enemigos2[v].xfin;
		       y3comp=Enemigos2[v].y1;
		       y4comp=Enemigos2[v].y2;
		       x5comp=Enemigos1[v].xini;
		       x6comp=Enemigos1[v].xfin;
		       y5comp=Enemigos1[v].y1;
		       y6comp=Enemigos1[v].y2;
		       if(x1comp<=Bulloff[j].xcrash && x2comp>=Bulloff[j].xcrash && y1comp<=Bulloff[j].ycrash && y2comp>=Bulloff[j].ycrash)
		       Enemigos3[v].Destroy();
		       if(x3comp<=Bulloff[j].xcrash && x4comp>=Bulloff[j].xcrash && y3comp<=Bulloff[j].ycrash && y4comp>=Bulloff[j].ycrash)
		       Enemigos2[v].Destroy();
			if(x5comp<=Bulloff[j].xcrash && x6comp>=Bulloff[j].xcrash && y5comp<=Bulloff[j].ycrash && y6comp>=Bulloff[j].ycrash)
		       Enemigos1[v].Destroy();

		       }
		       v=0;
		      }

		}j=0;
		for(j=0;j<7;j++)
		{
		      Enemigos3[j].aleatorio=random(50);
		      Enemigos2[j].aleatorio=random(50);
		}j=0;
		for(j=0;j<61;j++)
		{
		      if(Enemigos3[cuenta].aleatorio==3 && Enemigos3[cuenta].destruye==0)
		      {
		      Bullen[j].shoot2=1;
		      Bullen[j].xgo=Enemigos3[cuenta].xini+14;
		      Bullen[j].y3=Enemigos3[cuenta].y2;
		     // Bullen[j].Drawbull2();
		      Bullen[j].Erabull2();
		      }
		      cuenta++;
		      if(cuenta>6)
		      cuenta=0;
		}j=0;cuenta=0;
		for(j=0;j<61;j++)
		{
		      if(Enemigos2[cuenta].aleatorio==3 && Enemigos2[cuenta].destruye==0)
		      {
		      Bullen[j].shoot2=1;
		      Bullen[j].xgo=Enemigos2[cuenta].xini+14;
		      Bullen[j].y3=Enemigos2[cuenta].y2;
		     // Bullen[j].Drawbull2();
		      Bullen[j].Erabull2();
		      }
		      cuenta++;
		      if(cuenta>6)
		      cuenta=0;
		}j=0;cuenta=0;

		for(j=0;j<61;j++)
		{
		      Bullen[j].Drawbull2();
		      Bullen[j].Coorde2();
		}
		j=0;

		delay(100/Enemigos1[1].nivel);

		for(b=0;b<7;b++)
		   Enemigos1[b].Borra1();
		   b=0;
		for(b=0;b<7;b++)
		   Enemigos2[b].Borra1();
		   b=0;
		for(b=0;b<6;b++)
		   Enemigos3[b].Borra1();
		   b=0;
		if(Enemigos1[1].y1>100)
		{  Nave3.Borra1();
		}
		for(b=0;b<16;b++)
		      Bulloff[b].Erabull();
		      b=0;
		for(b=0;b<61;b++)
		      Bullen[b].Erabull2();
		      b=0;
		break;
       }
   } while(!kbhit());
   wise=getch();


   if(wise=='j')
   {
   count++;
   Bulloff[count].shoot=1;
   Bulloff[count].xstart=Nave2.xini2+2;
   Bulloff[count].y3=421;
   Bulloff[count].Drawbull();
   delay(15);
   Bulloff[count].Erabull();
   if(count>14)
   count=0;
   }
   if(wise=='b')
   {
      wise=0;
      settextstyle(4,0,4);
      setcolor(15);
      outtextxy(280,250,"Pause");
      settextstyle(4,0,2);
      outtextxy(160,300,"Press 'x' to watch control settings");
      while(wise!='b')
      {
      switch(wise)
	 {
	    case 'x':
	    settextstyle(4,0,2);
	    setfillstyle(1,0);
	    bar(160,250,550,420);
	    outtextxy(200,250,"Press 'a' to exit game anytime");
	    outtextxy(200,270,"Press 'b' to pause game");
	    outtextxy(200,290,"Press 'm' to move to the rigth");
	    outtextxy(200,310,"Press 'n' to move to the left");
	    outtextxy(200,330,"Press 'j' to shoot`em!!");

	    break;
	 }
      wise=getch();
      }
      setfillstyle(1,0);
      bar(140,250,600,420);
   }
   switch (wise)
       {
	case 'm':
		Nave2.sent=1;
		if(Nave2.xfin1<Nave2.xmax)
		{
		Nave2.xini1=Nave2.xini1+Nave2.nivel+4;Nave2.xfin1=Nave2.xfin1+Nave2.nivel+4;Nave2.xini2=Nave2.xini2+Nave2.nivel+4,Nave2.xfin2=Nave2.xfin2+Nave2.nivel+4;
		}
		else
		{
		   wise='n';
		}
		Nave2.Dibuna2();
		Nave2.Borra2();
		for(int b=0;b<16;b++)
		      Bulloff[b].Drawbull();
		      b=0;

		for(b=0;b<16;b++)
		      Bulloff[b].Erabull();
		      b=0;



		break;
	case 'n':
		Nave2.sent=2;
		if (Nave2.xini1>0)
		{
		Nave2.xini1=Nave2.xini1-Nave2.nivel-4;Nave2.xfin1=Nave2.xfin1-Nave2.nivel-4;Nave2.xini2=Nave2.xini2-Nave2.nivel-4,Nave2.xfin2=Nave2.xfin2-Nave2.nivel-4;
		}
		else
		{
		   wise='m';
		}
		Nave2.Dibuna2();
		Nave2.Borra2();
		for(b=0;b<16;b++)
		      Bulloff[b].Drawbull();
		      b=0;

		for(b=0;b<16;b++)
		      Bulloff[b].Erabull();
		      b=0;
		break;
       }
}

//getch();
}
