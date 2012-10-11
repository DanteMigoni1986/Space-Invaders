#include <Dante.h>
Dibujana(int xini,int xfin);
Dibuna2(int xini1,int xfin1,int xini2,int xfin2);
Borra1(int xini,int xfin,int nivel,int sent);
Borra2(int xini1,int xfin1,int xini2,int xfin2,int nivel,int sent);
Bala(int x,int alt);
Borraba(int x,int alt);
Inicia();


main()
{
   char condi,wise,bala;
   int xini,xini1,xini2,xfin,xfin1,xfin2,xmax,sent,m,nivel=3,cont=0,d=1,a,x,alt;
   clrscr();
   Inicia();
   xmax=getmaxx();
   xini=(xmax/2)-15;
   xfin=(xmax/2)+15;
   xini1=(xmax/2)-20;
   xfin1=(xmax/2)+20;
   xini2=(xmax/2)-4;
   xfin2=(xmax/2)+4;

   Dibujana(xini,xfin);
   Dibuna2(xini1,xfin1,xini2,xfin2);
while(wise!='a')
{
   do
   {
       switch(d)
       {
	  case 1:
		sent=1;
		if(xfin<(xmax-100))
		{
		xini=xini+nivel;xfin=xfin+nivel;
		}
		else
		{
		   d=2;
		}
		Dibujana(xini,xfin);
		Borra1(xini,xfin,nivel,sent);
		delay(100/nivel);
		if(bala=='j' && alt>0)
		{
		   if(alt==290)
		      x=xini2;

		      alt=alt-20;
		      Bala(x,alt);
		      delay(15);
		      Borraba(x,alt);
		}
		break;
	case 2:
		sent=2;
		if (xini>100)
		{
		xini=xini-nivel;xfin=xfin-nivel;
		}
		else
		{
		   d=1;
		}
		Dibujana(xini,xfin);
		delay(100/nivel);
		Borra1(xini,xfin,nivel,sent);
		if(bala=='j' && alt>0)
		{
		   if(alt==290)
		      x=xini2;

		      alt=alt-20;
		      Bala(x,alt);
		      delay(15);
		      Borraba(x,alt);
		}
		break;
       }
   } while(!kbhit());
   wise=getch();
   if(wise=='j')
      {
	 alt=290;
	 bala='j';
      }
   switch (wise)
       {
	case 'm':
		sent=1;
		if(xfin1<xmax)
		{
		xini1=xini1+nivel+4;xfin1=xfin1+nivel+4;xini2=xini2+nivel+4,xfin2=xfin2+nivel+4;
		}
		else
		{
		   wise='n';
		}
		Dibuna2(xini1,xfin1,xini2,xfin2);
		Borra2(xini1,xfin1,xini2,xfin2,nivel,sent);
		if(bala=='j' && alt>0)
		{
		   if(alt==290)
		      x=xini2;

		      alt=alt-20;
		      Bala(x,alt);
		      delay(15);
		      Borraba(x,alt);
		}
		break;
	case 'n':
		sent=2;
		if (xini1>0)
		{
		xini1=xini1-nivel-4;xfin1=xfin1-nivel-4;xini2=xini2-nivel-4,xfin2=xfin2-nivel-4;
		}
		else
		{
		  wise='m';
		}
		Dibuna2(xini1,xfin1,xini2,xfin2);
		Borra2(xini1,xfin1,xini2,xfin2,nivel,sent);
		if(bala=='j' && alt>0)
		{
		   if(alt==290)
		      x=xini2;

		      alt=alt-20;
		      Bala(x,alt);
		      delay(15);
		      Borraba(x,alt);
		}
		break;
       }
}

  getch();


}