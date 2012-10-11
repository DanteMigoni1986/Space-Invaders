#include <Dante.h>
Inicia();
Limpia(int y1,int y2, int y3);

class Nave
{
public:

      int xmax,*xini,xini1,xini2,*xfin,xfin1,xfin2,sent,nivel,color,*y1,*y2;

public:
      Nave();
      ~Nave();
      Navemala();
      Dibujana();
      Dibuna2();
      Borra1();
      Borra2();
};

Nave::Nave()
{
   xmax=getmaxx();
   xini=new int;
   xfin=new int;
   y1=new int;
   y2=new int;
   *xini=(xmax/2)-15;
   *xfin=(xmax/2)+15;
   xini1=(xmax/2)-20;
   xfin1=(xmax/2)+20;
   xini2=(xmax/2)-4;
   xfin2=(xmax/2)+4;
}
Nave::~Nave()
{
   setfillstyle(1,0);
   bar(*xini,*y1,*xfin,*y2);

   delete xini;
   delete xfin;
   delete y1;
   delete y2;
}

Nave::Dibujana()
{

   setfillstyle(9,color);
   bar(*xini,*y1,*xfin,*y2);

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
   bar(*xini-1,*y1,*xini-1-nivel,*y2);
   if(sent==2)
   bar(*xfin+1,*y1,*xfin+1+nivel,*y2);

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

Inicia();
xmax=getmaxx();
Nave *Enemigos=new Nave[20];
Enemigos[3].color=2;
//*Enemigos[3]->y1=20;
Enemigos[3].Dibujana();


Nave *Nave1=new Nave();
Nave1->nivel=3;
Nave1->color=2;
*Nave1->y1=30;
*Nave1->y2=50;
Nave1->Dibujana();
Nave *Nave3=new Nave();
Nave3->nivel=3;
*Nave3->xini=*Nave3->xini+60;
*Nave3->xfin=*Nave3->xfin+60;
Nave3->color=1;
*Nave3->y1=30;
*Nave3->y2=50;
Nave3->Dibujana();
Nave *Nave4=new Nave();
Nave4->nivel=3;
*Nave4->xini=*Nave4->xini-60;
*Nave4->xfin=*Nave4->xfin-60;
Nave4->color=1;
*Nave4->y1=30;
*Nave4->y2=50;
Nave4->Dibujana();
Nave *Nave5=new Nave();
Nave5->nivel=3;
*Nave5->xini=*Nave5->xini+120;
*Nave5->xfin=*Nave5->xfin+120;
Nave5->color=12;
*Nave5->y1=30;
*Nave5->y2=50;
Nave5->Dibujana();
Nave *Nave6=new Nave();
Nave6->nivel=3;
*Nave6->xini=*Nave6->xini-120;
*Nave6->xfin=*Nave6->xfin-120;
Nave6->color=12;
*Nave6->y1=30;
*Nave6->y2=50;
Nave6->Dibujana();
Nave *Nave7=new Nave();
Nave7->nivel=3;
*Nave7->xini=*Nave7->xini-180;
*Nave7->xfin=*Nave7->xfin-180;
Nave7->color=14;
*Nave7->y1=30;
*Nave7->y2=50;
Nave7->Dibujana();
Nave *Nave8=new Nave();
Nave8->nivel=3;
*Nave8->xini=*Nave8->xini+180;
*Nave8->xfin=*Nave8->xfin+180;
Nave8->color=14;
*Nave8->y1=30;
*Nave8->y2=50;
Nave8->Dibujana();
Nave *Nave9=new Nave();
Nave9->nivel=3;
Nave9->color=2;
*Nave9->y1=70;
*Nave9->y2=90;
Nave9->Dibujana();
Nave *Nave10=new Nave();
Nave10->nivel=3;
*Nave10->xini=*Nave10->xini+80;
*Nave10->xfin=*Nave10->xfin+80;
Nave10->color=1;
*Nave10->y1=70;
*Nave10->y2=90;
Nave10->Dibujana();
Nave *Nave11=new Nave();
Nave11->nivel=3;
*Nave11->xini=*Nave11->xini-80;
*Nave11->xfin=*Nave11->xfin-80;
Nave11->color=1;
*Nave11->y1=70;
*Nave11->y2=90;
Nave11->Dibujana();
Nave *Nave12=new Nave();
Nave12->nivel=3;
*Nave12->xini=*Nave12->xini+160;
*Nave12->xfin=*Nave12->xfin+160;
Nave12->color=12;
*Nave12->y1=70;
*Nave12->y2=90;
Nave12->Dibujana();
Nave *Nave13=new Nave();
Nave13->nivel=3;
*Nave13->xini=*Nave13->xini-160;
*Nave13->xfin=*Nave13->xfin-160;
Nave13->color=12;
*Nave13->y1=70;
*Nave13->y2=90;
Nave13->Dibujana();
Nave *Nave14=new Nave();
Nave14->nivel=3;
*Nave14->xini=*Nave14->xini-240;
*Nave14->xfin=*Nave14->xfin-240;
Nave14->color=14;
*Nave14->y1=70;
*Nave14->y2=90;
Nave14->Dibujana();
Nave *Nave15=new Nave();
Nave15->nivel=3;
*Nave15->xini=*Nave15->xini+240;
*Nave15->xfin=*Nave15->xfin+240;
Nave15->color=14;
*Nave15->y1=70;
*Nave15->y2=90;
Nave15->Dibujana();
Nave *Nave16=new Nave();
Nave16->nivel=3;
*Nave16->xini=*Nave16->xini+40;
*Nave16->xfin=*Nave16->xfin+40;
Nave16->color=2;
*Nave16->y1=110;
*Nave16->y2=130;
Nave16->Dibujana();
Nave *Nave17=new Nave();
Nave17->nivel=3;
*Nave17->xini=*Nave17->xini-40;
*Nave17->xfin=*Nave17->xfin-40;
Nave17->color=2;
*Nave17->y1=110;
*Nave17->y2=130;
Nave17->Dibujana();
Nave *Nave18=new Nave();
Nave18->nivel=3;
*Nave18->xini=*Nave18->xini+120;
*Nave18->xfin=*Nave18->xfin+120;
Nave18->color=12;
*Nave18->y1=110;
*Nave18->y2=130;
Nave18->Dibujana();
Nave *Nave19=new Nave();
Nave19->nivel=3;
*Nave19->xini=*Nave19->xini-120;
*Nave19->xfin=*Nave19->xfin-120;
Nave19->color=12;
*Nave19->y1=110;
*Nave19->y2=130;
Nave19->Dibujana();
Nave *Nave20=new Nave();
Nave20->nivel=3;
*Nave20->xini=*Nave20->xini+200;
*Nave20->xfin=*Nave20->xfin+200;
Nave20->color=14;
*Nave20->y1=110;
*Nave20->y2=130;
Nave20->Dibujana();
Nave *Nave21=new Nave();
Nave21->nivel=3;
*Nave21->xini=*Nave21->xini-200;
*Nave21->xfin=*Nave21->xfin-200;
Nave21->color=14;
*Nave21->y1=110;
*Nave21->y2=130;
Nave21->Dibujana();
Nave Nave2;
Nave2.nivel=3;
Nave2.Dibuna2();

while(wise!='a')
{
   do
   {
       switch(d)
       {
	  case 1:
		Nave1->sent=1;
		Nave3->sent=1;
		Nave4->sent=1;
		Nave5->sent=1;
		Nave6->sent=1;
		Nave7->sent=1;
		Nave8->sent=1;
		Nave9->sent=1;
		Nave10->sent=1;
		Nave11->sent=1;
		Nave12->sent=1;
		Nave13->sent=1;
		Nave14->sent=1;
		Nave15->sent=1;
		Nave16->sent=1;
		Nave17->sent=1;
		Nave18->sent=1;
		Nave19->sent=1;
		Nave20->sent=1;
		Nave21->sent=1;
		if(*Nave1->xfin<(xmax-250))
		{
		*Nave1->xini=*Nave1->xini+Nave1->nivel;*Nave1->xfin=*Nave1->xfin+Nave1->nivel;
		*Nave3->xini=*Nave3->xini+Nave3->nivel;*Nave3->xfin=*Nave3->xfin+Nave3->nivel;
		*Nave4->xini=*Nave4->xini+Nave4->nivel;*Nave4->xfin=*Nave4->xfin+Nave4->nivel;
		*Nave5->xini=*Nave5->xini+Nave5->nivel;*Nave5->xfin=*Nave5->xfin+Nave5->nivel;
		*Nave6->xini=*Nave6->xini+Nave6->nivel;*Nave6->xfin=*Nave6->xfin+Nave6->nivel;
		*Nave7->xini=*Nave7->xini+Nave7->nivel;*Nave7->xfin=*Nave7->xfin+Nave7->nivel;
		*Nave8->xini=*Nave8->xini+Nave8->nivel;*Nave8->xfin=*Nave8->xfin+Nave8->nivel;
		*Nave9->xini=*Nave9->xini+Nave9->nivel;*Nave9->xfin=*Nave9->xfin+Nave9->nivel;
		*Nave10->xini=*Nave10->xini+Nave10->nivel;*Nave10->xfin=*Nave10->xfin+Nave10->nivel;
		*Nave11->xini=*Nave11->xini+Nave11->nivel;*Nave11->xfin=*Nave11->xfin+Nave11->nivel;
		*Nave12->xini=*Nave12->xini+Nave12->nivel;*Nave12->xfin=*Nave12->xfin+Nave12->nivel;
		*Nave13->xini=*Nave13->xini+Nave13->nivel;*Nave13->xfin=*Nave13->xfin+Nave13->nivel;
		*Nave14->xini=*Nave14->xini+Nave14->nivel;*Nave14->xfin=*Nave14->xfin+Nave14->nivel;
		*Nave15->xini=*Nave15->xini+Nave15->nivel;*Nave15->xfin=*Nave15->xfin+Nave15->nivel;
		*Nave16->xini=*Nave16->xini+Nave16->nivel;*Nave16->xfin=*Nave16->xfin+Nave16->nivel;
		*Nave17->xini=*Nave17->xini+Nave17->nivel;*Nave17->xfin=*Nave17->xfin+Nave17->nivel;
		*Nave18->xini=*Nave18->xini+Nave18->nivel;*Nave18->xfin=*Nave18->xfin+Nave18->nivel;
		*Nave19->xini=*Nave19->xini+Nave19->nivel;*Nave19->xfin=*Nave19->xfin+Nave19->nivel;
		*Nave20->xini=*Nave20->xini+Nave20->nivel;*Nave20->xfin=*Nave20->xfin+Nave20->nivel;
		*Nave21->xini=*Nave21->xini+Nave21->nivel;*Nave21->xfin=*Nave21->xfin+Nave21->nivel;
		}
		else
		{
		   d=2;
		   *Nave1->y1=*Nave1->y1+10;
		   *Nave1->y2=*Nave1->y2+10;
		   *Nave3->y1=*Nave3->y1+10;
		   *Nave3->y2=*Nave3->y2+10;
		   *Nave4->y1=*Nave4->y1+10;
		   *Nave4->y2=*Nave4->y2+10;
		   *Nave5->y1=*Nave5->y1+10;
		   *Nave5->y2=*Nave5->y2+10;
		   *Nave6->y1=*Nave6->y1+10;
		   *Nave6->y2=*Nave6->y2+10;
		   *Nave7->y1=*Nave7->y1+10;
		   *Nave7->y2=*Nave7->y2+10;
		   *Nave8->y1=*Nave8->y1+10;
		   *Nave8->y2=*Nave8->y2+10;
		   *Nave9->y1=*Nave9->y1+10;
		   *Nave9->y2=*Nave9->y2+10;
		   *Nave10->y1=*Nave10->y1+10;
		   *Nave10->y2=*Nave10->y2+10;
		   *Nave11->y1=*Nave11->y1+10;
		   *Nave11->y2=*Nave11->y2+10;
		   *Nave12->y1=*Nave12->y1+10;
		   *Nave12->y2=*Nave12->y2+10;
		   *Nave13->y1=*Nave13->y1+10;
		   *Nave13->y2=*Nave13->y2+10;
		   *Nave14->y1=*Nave14->y1+10;
		   *Nave14->y2=*Nave14->y2+10;
		   *Nave15->y1=*Nave15->y1+10;
		   *Nave15->y2=*Nave15->y2+10;
		   *Nave16->y1=*Nave16->y1+10;
		   *Nave16->y2=*Nave16->y2+10;
		   *Nave17->y1=*Nave17->y1+10;
		   *Nave17->y2=*Nave17->y2+10;
		   *Nave18->y1=*Nave18->y1+10;
		   *Nave18->y2=*Nave18->y2+10;
		   *Nave19->y1=*Nave19->y1+10;
		   *Nave19->y2=*Nave19->y2+10;
		   *Nave20->y1=*Nave20->y1+10;
		   *Nave20->y2=*Nave20->y2+10;
		   *Nave21->y1=*Nave21->y1+10;
		   *Nave21->y2=*Nave21->y2+10;
		   //delete Nave20;
		   Nave20->color=0;
		   y1=*Nave21->y1;
		   y2=*Nave13->y1;
		   y3=*Nave1->y1;
		   Limpia(y1,y2,y3);
		}
		Nave1->Dibujana();
		Nave3->Dibujana();
		Nave4->Dibujana();
		Nave5->Dibujana();
		Nave6->Dibujana();
		Nave7->Dibujana();
		Nave8->Dibujana();
		Nave9->Dibujana();
		Nave10->Dibujana();
		Nave11->Dibujana();
		Nave12->Dibujana();
		Nave13->Dibujana();
		Nave14->Dibujana();
		Nave15->Dibujana();
		Nave16->Dibujana();
		Nave17->Dibujana();
		Nave18->Dibujana();
		Nave19->Dibujana();
		Nave20->Dibujana();
		Nave21->Dibujana();
		delay(100/Nave1->nivel);
		Nave1->Borra1();
		Nave3->Borra1();
		Nave4->Borra1();
		Nave5->Borra1();
		Nave6->Borra1();
		Nave7->Borra1();
		Nave8->Borra1();
		Nave9->Borra1();
		Nave10->Borra1();
		Nave11->Borra1();
		Nave12->Borra1();
		Nave13->Borra1();
		Nave14->Borra1();
		Nave15->Borra1();
		Nave16->Borra1();
		Nave17->Borra1();
		Nave18->Borra1();
		Nave19->Borra1();
		Nave20->Borra1();
		Nave21->Borra1();

		break;
	case 2:
		Nave1->sent=2;
		Nave3->sent=2;
		Nave4->sent=2;
		Nave5->sent=2;
		Nave6->sent=2;
		Nave7->sent=2;
		Nave8->sent=2;
		Nave9->sent=2;
		Nave10->sent=2;
		Nave11->sent=2;
		Nave12->sent=2;
		Nave13->sent=2;
		Nave14->sent=2;
		Nave15->sent=2;
		Nave16->sent=2;
		Nave17->sent=2;
		Nave18->sent=2;
		Nave19->sent=2;
		Nave20->sent=2;
		Nave21->sent=2;

		if ((*Nave1->xini)>250)
		{
		*Nave1->xini=*Nave1->xini-Nave1->nivel;*Nave1->xfin=*Nave1->xfin-Nave1->nivel;
		*Nave3->xini=*Nave3->xini-Nave3->nivel;*Nave3->xfin=*Nave3->xfin-Nave3->nivel;
		*Nave4->xini=*Nave4->xini-Nave4->nivel;*Nave4->xfin=*Nave4->xfin-Nave4->nivel;
		*Nave5->xini=*Nave5->xini-Nave5->nivel;*Nave5->xfin=*Nave5->xfin-Nave5->nivel;
		*Nave6->xini=*Nave6->xini-Nave6->nivel;*Nave6->xfin=*Nave6->xfin-Nave6->nivel;
		*Nave7->xini=*Nave7->xini-Nave7->nivel;*Nave7->xfin=*Nave7->xfin-Nave7->nivel;
		*Nave8->xini=*Nave8->xini-Nave8->nivel;*Nave8->xfin=*Nave8->xfin-Nave8->nivel;
		*Nave9->xini=*Nave9->xini-Nave9->nivel;*Nave9->xfin=*Nave9->xfin-Nave9->nivel;
		*Nave10->xini=*Nave10->xini-Nave10->nivel;*Nave10->xfin=*Nave10->xfin-Nave10->nivel;
		*Nave11->xini=*Nave11->xini-Nave11->nivel;*Nave11->xfin=*Nave11->xfin-Nave11->nivel;
		*Nave12->xini=*Nave12->xini-Nave12->nivel;*Nave12->xfin=*Nave12->xfin-Nave12->nivel;
		*Nave13->xini=*Nave13->xini-Nave13->nivel;*Nave13->xfin=*Nave13->xfin-Nave13->nivel;
		*Nave14->xini=*Nave14->xini-Nave14->nivel;*Nave14->xfin=*Nave14->xfin-Nave14->nivel;
		*Nave15->xini=*Nave15->xini-Nave15->nivel;*Nave15->xfin=*Nave15->xfin-Nave15->nivel;
		*Nave16->xini=*Nave16->xini-Nave16->nivel;*Nave16->xfin=*Nave16->xfin-Nave16->nivel;
		*Nave17->xini=*Nave17->xini-Nave17->nivel;*Nave17->xfin=*Nave17->xfin-Nave17->nivel;
		*Nave18->xini=*Nave18->xini-Nave18->nivel;*Nave18->xfin=*Nave18->xfin-Nave18->nivel;
		*Nave19->xini=*Nave19->xini-Nave19->nivel;*Nave19->xfin=*Nave19->xfin-Nave19->nivel;
		*Nave20->xini=*Nave20->xini-Nave20->nivel;*Nave20->xfin=*Nave20->xfin-Nave20->nivel;
		*Nave21->xini=*Nave21->xini-Nave21->nivel;*Nave21->xfin=*Nave21->xfin-Nave21->nivel;
		}
		else
		{
		   d=1;
		   *Nave1->y1=*Nave1->y1+10;
		   *Nave1->y2=*Nave1->y2+10;
		   *Nave3->y1=*Nave3->y1+10;
		   *Nave3->y2=*Nave3->y2+10;
		   *Nave4->y1=*Nave4->y1+10;
		   *Nave4->y2=*Nave4->y2+10;
		   *Nave5->y1=*Nave5->y1+10;
		   *Nave5->y2=*Nave5->y2+10;
		   *Nave6->y1=*Nave6->y1+10;
		   *Nave6->y2=*Nave6->y2+10;
		   *Nave7->y1=*Nave7->y1+10;
		   *Nave7->y2=*Nave7->y2+10;
		   *Nave8->y1=*Nave8->y1+10;
		   *Nave8->y2=*Nave8->y2+10;
		   *Nave9->y1=*Nave9->y1+10;
		   *Nave9->y2=*Nave9->y2+10;
		   *Nave10->y1=*Nave10->y1+10;
		   *Nave10->y2=*Nave10->y2+10;
		   *Nave11->y1=*Nave11->y1+10;
		   *Nave11->y2=*Nave11->y2+10;
		   *Nave12->y1=*Nave12->y1+10;
		   *Nave12->y2=*Nave12->y2+10;
		   *Nave13->y1=*Nave13->y1+10;
		   *Nave13->y2=*Nave13->y2+10;
		   *Nave14->y1=*Nave14->y1+10;
		   *Nave14->y2=*Nave14->y2+10;
		   *Nave15->y1=*Nave15->y1+10;
		   *Nave15->y2=*Nave15->y2+10;
		   *Nave16->y1=*Nave16->y1+10;
		   *Nave16->y2=*Nave16->y2+10;
		   *Nave17->y1=*Nave17->y1+10;
		   *Nave17->y2=*Nave17->y2+10;
		   *Nave18->y1=*Nave18->y1+10;
		   *Nave18->y2=*Nave18->y2+10;
		   *Nave19->y1=*Nave19->y1+10;
		   *Nave19->y2=*Nave19->y2+10;
		   *Nave20->y1=*Nave20->y1+10;
		   *Nave20->y2=*Nave20->y2+10;
		   *Nave21->y1=*Nave21->y1+10;
		   *Nave21->y2=*Nave21->y2+10;
		   y1=*Nave21->y1;
		   y2=*Nave13->y1;
		   y3=*Nave1->y1;
		   Limpia(y1,y2,y3);
		}
		Nave1->Dibujana();
		Nave3->Dibujana();
		Nave4->Dibujana();
		Nave5->Dibujana();
		Nave6->Dibujana();
		Nave7->Dibujana();
		Nave8->Dibujana();
		Nave9->Dibujana();
		Nave10->Dibujana();
		Nave11->Dibujana();
		Nave12->Dibujana();
		Nave13->Dibujana();
		Nave14->Dibujana();
		Nave15->Dibujana();
		Nave16->Dibujana();
		Nave17->Dibujana();
		Nave18->Dibujana();
		Nave19->Dibujana();
		Nave20->Dibujana();
		Nave21->Dibujana();
		delay(100/Nave1->nivel);
		Nave1->Borra1();
		Nave3->Borra1();
		Nave4->Borra1();
		Nave5->Borra1();
		Nave6->Borra1();
		Nave7->Borra1();
		Nave8->Borra1();
		Nave9->Borra1();
		Nave10->Borra1();
		Nave11->Borra1();
		Nave12->Borra1();
		Nave13->Borra1();
		Nave14->Borra1();
		Nave15->Borra1();
		Nave16->Borra1();
		Nave17->Borra1();
		Nave18->Borra1();
		Nave19->Borra1();
		Nave20->Borra1();
		Nave21->Borra1();
		break;
       }
   } while(!kbhit());
   wise=getch();

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
		break;
       }
}

getch();
}


