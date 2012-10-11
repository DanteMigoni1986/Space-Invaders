#include <Dante.h>
Dispara (int a);
Enemy();


Nave()
{
   int xmax,ymax,xini1,xini2,xfin1,xfin2,a;
   char d;

   xmax = getmaxx();
   ymax = getmaxy();
   xini1=(xmax/2)-20;
   xfin1=(xmax/2)+20;
   xini2=(xmax/2)-4;
   xfin2=(xmax/2)+4;
   setfillstyle(9,255);
   bar(xini1,300,xfin1,316);
   bar(xini2,292,xfin2,300);

   do{
   switch (d)
       {
	case 'm':
		if(xfin1<xmax)
		{
		xini1=xini1+5;xfin1=xfin1+5;xini2=xini2+5,xfin2=xfin2+5;
		}
		else
		{
		   xfin1=xmax;
		   xini1=xmax-39;
		   xfin2=xmax-15;
		   xini2=xmax-23;
		}
		setfillstyle(9,255);
		bar(xini1,300,xfin1,316);
		bar(xini2,292,xfin2,300);
		   for(int j=300;j<317;j++)
		   {
		      putpixel(xini1-1,j,0);
		      putpixel(xini1-2,j,0);
		      putpixel(xini1-3,j,0);
		      putpixel(xini1-4,j,0);
		      putpixel(xini1-5,j,0);
		   }
		   for(j=292;j<301;j++)
		   {
		      putpixel(xini2-1,j,0);
		      putpixel(xini2-2,j,0);
		      putpixel(xini2-3,j,0);
		      putpixel(xini2-4,j,0);
		      putpixel(xini2-5,j,0);
		      putpixel(xini2-6,j,0);
		   }
		   //Enemy();
		break;
	case 'n':
		if (xini1>0)
		{
		xini1=xini1-5;xfin1=xfin1-5;xini2=xini2-5,xfin2=xfin2-5;
		}
		else
		{
		   xfin1=39;
		   xini1=0;
		   xfin2=23;
		   xini2=15;
		}
		setfillstyle(9,255);
		bar(xini1,300,xfin1,316);
		bar(xini2,292,xfin2,300);
		for(j=300;j<317;j++)
		{
		   putpixel(xfin1+1,j,0);
		   putpixel(xfin1+2,j,0);
		   putpixel(xfin1+3,j,0);
		   putpixel(xfin1+4,j,0);
		   putpixel(xfin1+5,j,0);
		}
		for(j=292;j<301;j++)
		{
		   putpixel(xfin2,j,0);
		   putpixel(xfin2+1,j,0);
		   putpixel(xfin2+2,j,0);
		   putpixel(xfin2+3,j,0);
		   putpixel(xfin2+4,j,0);
		   putpixel(xfin2+5,j,0);
		   putpixel(xfin2+6,j,0);
		   putpixel(xfin2+7,j,0);
		}
		//Enemy();
		break;
       } d=getch();
	 if(d=='j')
		{
		   a=xini2;
		   Dispara(a);
		}
     }while(d!='o');
}