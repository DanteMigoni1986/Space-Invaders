#include <Dante.h>
Inicia();
Nave();



Enemy ()


{
   int xmax,xini,xfin,d=1,cont=0;
   char condi;
   xmax= getmaxx();

   setfillstyle(9,255);
   xini=(xmax/2)-15;
   xfin=xini+30;
   bar(xini,30,xfin,45);


   do
   {
       switch(d)
       {
	  case 1:
		if(xfin<(xmax-100))
		{
		xini=xini+3;xfin=xfin+3;
		}
		else
		{
		   xfin=xmax-99;
		   xini=xmax-129;
		   d=2;
		}
		setfillstyle(9,255);
		bar(xini,30,xfin,45);
		delay(30);
		   for(int j=30;j<46;j++)
		   {
		      putpixel(xini-1,j,0);
		      putpixel(xini-2,j,0);
		      putpixel(xini-3,j,0);
		      putpixel(xini-4,j,0);
		   }
		Nave();
		break;
	case 2:
		if (xini>100)
		{
		xini=xini-3;xfin=xfin-3;
		}
		else
		{
		   xfin=129;
		   xini=99;
		   cont++;
		   d=1;
		   if (cont==3)
		   condi='o';
		}
		setfillstyle(9,255);
		bar(xini,30,xfin,45);
		delay(30);
		for(j=30;j<46;j++)
		{
		   putpixel(xfin+1,j,0);
		   putpixel(xfin+2,j,0);
		   putpixel(xfin+3,j,0);
		   putpixel(xfin+4,j,0);
		}
		Nave();
		break;
       }
   } while(condi!='o');
   d=getch();
}