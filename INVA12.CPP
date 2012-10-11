#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
//las constantes y los colores
#define R 4
#define a 12
#define b 9
#define n 2
#define l 14
#define c 15
#define g 2
#define m 5
#define v 128

/*
BLACK           0
BLUE            1  ³ Yes ³ Yes
GREEN        ³  2  ³ Yes ³ Yes
CYAN         ³  3  ³ Yes ³ Yes
RED          ³  4  ³ Yes ³ Yes
MAGENTA      ³  5  ³ Yes ³ Yes
BROWN        ³  6  ³ Yes ³ Yes
LIGHTGRAY    ³  7  ³ Yes ³ Yes
DARKGRAY     ³  8  ³ No  ³ Yes
LIGHTBLUE    ³  9  ³ No  ³ Yes
LIGHTGREEN   ³ 10  ³ No  ³ Yes
LIGHTCYAN    ³ 11  ³ No  ³ Yes
LIGHTRED     ³ 12  ³ No  ³ Yes
LIGHTMAGENTA ³ 13  ³ No  ³ Yes
YELLOW       ³ 14  ³ No  ³ Yes
WHITE        ³ 15  ³ No  ³ Yes
BLINK        ³128  ³ No  ³
*/

//punteros far
void far
*nave1=NULL,*mala=NULL,*mala2=NULL,*mala3=NULL,*disparo=NULL,*disparomalo=NULL;
//declaracion de estructuras
//balas del bueno
struct balabueno
{
	int xbb;
	int ybb;
	int muerto;
};
struct listabb
{
	struct balabueno bb;
	struct listabb *antbb;
	struct listabb *sigbb;

}*auxbb=NULL,*inibb=NULL,*finbb=NULL;
///////////
struct balamalo
{
	int xm;
	int ym;

};
struct listamalo
{
	struct balamalo mm;
	struct listamalo *antm;
	struct listamalo *sigm;

}*auxm=NULL,*inim=NULL,*finm=NULL;
//los malisimos
struct regtan
{
	int x;
	int y;
}res;
struct lista
{
	struct regtan r;
	struct lista *sig;
	struct lista *ant;
}*aux=NULL,*fin=NULL,*ini=NULL;

struct estrellas
{
	int xe;
	int ye;
	int velocidade;

};
struct listae
{
	struct estrellas e;
	struct listae *sige;
	struct listae *ante;
}*auxe=NULL,*fine=NULL,*inie=NULL;
struct mejores
{
	char nombre[25];
	int puntos;
}mejor,mejoris[10];
// declaracion de variables
int mov=5,modo=VGAMED,tipo=VGA;
int y=60,x=20,pagina=0;
int tecla=1;
int radio=2,xbuena=300;
int xr=100,yr=300,i=1,llamonave=0;
int contbb=0,totalbb=5;
int velocidad=10;
int tocado=0;
int cuentanavebuena=3;
int contm=0,swmalo=0,punto=0;
int velocidadmalos=0;
char continuar='p';
int swpunto=0;
int swescudo=0,cuentaescudo=0,topeescudo=3;
int xsola=10,ysola=30,swsola=0,paraca=0;
//prototipos de las  funciones
void crear_estrellas();
void mover_estrellas();
void crear_imagenes(void);
void dibujar_rectangulos(void);
void crear_rectangulos(struct regtan);
void crear_imagenes(void);
void modo_grafico(void);
int vaciar_rectangulos(void);
int vaciar_balas_bueno(void);
int vaciar_balas_malo(void);
int vaciar_estrellas(void);
void mover_rectangulos(void);
void estrellas(void);
void NaveBuena(void);
void NaveSuelta(void);
void dibujarbb(void);
void moverbbeliminar();
void quitamala(void);
void dispamala(int,int);
void dibumala(void);
int tocadomalo(void);
void puntos(void);
void vidas(void);
void destruido(void);
void presentacion(void);
void menu(void);
void escudo(void);
void contadorescudos(void);
void navesola(void);
void recor(void);
////////////////////////MAIN/////////////////////////////
void main()
{
	//iniciar modo grafico
	modo_grafico();
	randomize();

	//pido memoria para los rectangulos
	//y les paso la coorenadas
	crear_imagenes();
	crear_estrellas();
	while(i<=21)
	{
			res.y=y;
			res.x=x;
			if(i%7==0)
			{
				y+=30;
				x=20;
			}
			else
			{
				x+=50;
			}
		 crear_rectangulos(res);
		 i++;
	}


	menu();
	presentacion();
	tecla=10;
	while(continuar!='n'&&continuar!='N')
	{
		if(cuentanavebuena<=0)
		{
			tecla=27;
			destruido();
		}
		//mientras la tecla pulsada no se escape
		while(tecla!=27&&cuentanavebuena>0)
		{
			//limpio el buffer
			fflush(stdin);
			//borro pantalla
			clearviewport();
			//pongo la nave buena
			//NaveBuena();
			//dibujo las estrelas
			estrellas();
			mover_estrellas();
			//dibujo los malisimos
			navesola();
			dibujar_rectangulos();
			swmalo=tocadomalo();
			if(swmalo==1)
			{  if(cuentanavebuena>0)cuentanavebuena--;

			}
			if(cuentanavebuena>0)
			{
			  NaveBuena();
			}
			if(cuentanavebuena<=0)
			{
				destruido();
				break;

			}
			dibumala();
			puntos();
			vidas();
			contadorescudos();

			//miro si han pulsado una tecla
			if(kbhit())
			{
				tecla=getch();
				if(tecla==13&&topeescudo>0)
				{
					//escudo();
					swescudo=1;
					topeescudo--;
				}
				if(tecla==27)continuar='n';
				if (tecla==0)
				{
					tecla=getch();
					switch (tecla)
					{
						case 75:xbuena-=10;
							  if (xbuena<10)xbuena=10;
						break;
						case 77:xbuena+=10;
							  if (xbuena>600)xbuena=600;
						break;
					}
				}

				//si la tecla es espacio
				else if(tecla==32 && contbb<totalbb)
				{
						//sonido dolby surround
						sound(8500);
						delay(100);
						sound(200);
						delay(50);
						nosound();
						dibujarbb();
				}
			}
			if(cuentaescudo>=100)
			{
				swescudo=0;
				cuentaescudo=0;
			}
			if(swescudo==1)
			{
				escudo();
			}
			//si el conbb es mayor de 0 es que hay disparos en el aire
			if(contbb>0)
			{
				//miro si he matado ha alguien
				quitamala();
				moverbbeliminar();
			}
			//muevo los malisimos

			mover_rectangulos();
			//cambio de pagina de video
			setactivepage(1-pagina);
			setvisualpage(pagina);
			pagina=1-pagina;

		}
	}
	recor();
	//vacio las listas
	while(vaciar_rectangulos())
	{
		//vacio la lista
	}
	while(vaciar_balas_malo())
	{
		//vacio la lista de las balas de los malos
	}
	while(vaciar_balas_bueno())
	{
		//vacio la lista de las balas del bueno
	}
	while(vaciar_estrellas())
	{
		//vacio la lista de las balas del bueno
	}
	closegraph();
}

///////////////////////////funcion mejor///////////////////////////
void recor()  //mejoris es el vector,mejor es la variable y mejores es la estructura
{  
		char nombre[25],let;
		int i=0,encontrado=0,x=10;
		FILE *pf=NULL;
		pf=fopen("d:\\tc\\bin\\mejor.txt","r+b");
		if(pf==NULL)printf("ERROR");
		else
		{

			fread(mejoris,sizeof(struct mejores),10,pf);
			for(i=0;i<10;i++)
			{
				for(x=0;x<9;x++)
				{
					if(mejoris[x].puntos<mejoris[x+1].puntos)
					{
						mejor.puntos=mejoris[x].puntos;
						mejoris[x].puntos=mejoris[x+1].puntos;
						mejoris[x+1].puntos=mejor.puntos;

					}
				}
			}
			setactivepage(0);
			setvisualpage(0);
			clearviewport();
			setcolor(LIGHTBLUE);
			settextstyle(3,0,3);
			outtextxy(200,150,"INTRODUCE TU NOMBRE");
			gets(nombre);
			strcpy(mejor.nombre,nombre);
			mejor.puntos=punto;
			i=9;
			while(i>=0 && encontrado==0)
			{
				if(mejoris[i].puntos<mejor.puntos)
				{
					mejoris[i].puntos=mejor.puntos;
					strcpy(mejoris[i].nombre,mejor.nombre);
					encontrado=1;

				}
				i--;
			}
		}
		fclose(pf);
		pf=fopen("d:\\tc\\bin\\mejor.txt","wb");
		fwrite(mejoris,sizeof(struct mejores),10,pf);
		fclose(pf);
		pf=fopen("d:\\tc\\bin\\mejor.txt","rb");
		//fwrite(mejoris,sizeof(struct mejores),10,pf);
		if(pf==NULL)
		{
			setcolor(RED-BLINK);
			settextstyle(3,0,3);
			outtextxy(200,150,"HARCHIVO NO ENCONTRADO");
		}
		else
		{

				setcolor(BLUE);
				settextstyle(1,0,1);
				i=0;
				fread(&mejor,sizeof(struct mejores),1,pf);
				x=25;
				clearviewport();
				outtextxy(270,10,"LOS MEJORES SON...");
				while(!feof(pf)&i<10)
				{

					if(i==9&&encontrado==1)
					{
						setcolor(YELLOW);
						settextstyle(1,0,1);
						outtextxy(230,x,"<-TU PUNTUACION");
					}
					outtextxy(120,x,mejor.nombre);
					itoa(mejor.puntos,nombre,10);
					outtextxy(200,x,nombre);
					fread(&mejor,sizeof(struct mejores),1,pf);
					i++;
					x+=25;
				}

		}
	 //}
	 fclose(pf);
	 getch();
}
///////////////////////////funcion navesola///////////////////////
void navesola()
{
	int i=0;
	i=random(5000);
	if(i>4800&&swsola==0)
	{
		 putimage(xsola,ysola,mala3,COPY_PUT);
		 swsola=1;
	}
	if(swsola==1&&paraca==0)
	{
		xsola+=10;
		putimage(xsola,ysola,mala3,COPY_PUT);
		if(xsola>=640)
		{
			xsola=0;
			swsola=0;
		}
	}
	if(paraca==1)
	{
		swsola=1;
		putimage(xsola,ysola,mala2,COPY_PUT);
	}
	if(swsola==1&&paraca==1)
	{
		ysola+=5;
		putimage(xsola,ysola,mala2,COPY_PUT);
		if(ysola>=260&&xsola<=xbuena+10)
		{
			paraca=0;
			ysola=30;
			xsola=0;
			cuentanavebuena++;
		}
		if(ysola>=300)
		{
			paraca=0;
			ysola=30;
			xsola=0;
			swsola=0;
		}
	}
}
///////////////////////////FUNCION ESCUDO/////////////////////////
void escudo()
{
	setcolor(random(15)+1);
	circle(xbuena+10,310,40);
	cuentaescudo++;
}
////////////////////FUNCION PRESENTACION///////////////////////////
void presentacion()
{
	int xuno=10,yuno=0,i=0;
	fflush(stdin);
	putimage(xuno,120,mala,COPY_PUT);
	for(i=0;i<100;i++)
	{
		setcolor(random(16));

		line(xuno,yuno,xuno,yuno+i);
		delay(20);

	}
	for(i=0;i<100;i++)
	{
		setcolor(random(16));

		circle(xuno,120,i);
		delay(10);

	}
	while(!kbhit())
	{
		clearviewport();
		mover_estrellas();
		setcolor(random(16));
		settextstyle(3,0,5);
		outtextxy(10,40,"INVADERS 2002");
		setcolor(random(16));
		outtextxy(10,80,"PULSA UNA TECLA...");
		setcolor(random(16));
		settextstyle(3,0,2);
		outtextxy(100,160,"CONTROLES");
		setcolor(random(16));
		outtextxy(100,200,"(<-)=IZQUIERDA");
		outtextxy(100,240,"(->)=DERECHA");
		outtextxy(100,280,"(ESPACIO)=DISPARO");
		outtextxy(100,320,"(ENTER)=ESCUDO");
		if(kbhit())break;
		setactivepage(1-pagina);
		setvisualpage(pagina);
		pagina=1-pagina;
	}


}
///////////////////////////FUNCION MENU////////////////////////////
void menu()
{
 //	int i=0;//opc=0;
	//fflush(stdin);
	clearviewport();
	//pagina=1-pagina;
	setcolor(LIGHTBLUE);
	settextstyle(2,0,2);
	outtextxy(100,10,"ELIGE LAS OPCIONES:");
	//numero de vidas de 1 a 5
	do
	{
		clearviewport();
		setcolor(LIGHTBLUE);
		settextstyle(1,0,2);
		outtextxy(100,50,"NUMERO DE VIDAS(1a5)Y PULSA ENTER:");
		scanf("%d",&cuentanavebuena);
	}while(cuentanavebuena<0||cuentanavebuena>5);
	do
	{
		clearviewport();
		setcolor(LIGHTRED);
		settextstyle(1,0,2);
		outtextxy(100,50,"ELIGE NIVEL DE DIFICULTAD(1a5)Y PULSA ENTER:");
		scanf("%d",&mov);
	}while(mov<0||mov>5);
	mov*=mov;
	do
	{
		clearviewport();
		setcolor(LIGHTGREEN);
		settextstyle(1,0,2);
		outtextxy(100,50,"ELIGE EL NUMERO DEESCUDOS(1a5)Y PULSA ENTER:");
		scanf("%d",&topeescudo);
	}while(topeescudo<0||topeescudo>5);
  clearviewport();
}
///////////////////FUNCION CREAR_ESTRELLAS/////////////////////////
void crear_estrellas()
{
	int i=0;
	for(i=0;i<300;i++)
	{
		auxe=(struct listae *)malloc(sizeof(struct listae));
	  if(!inie)
	  {
		inie=auxe;
	  }
	  else
	  {
		 fine->sige=auxe;
	  }
	  auxe->e.xe=random(640);
	  auxe->e.ye=random(100);
	  auxe->e.velocidade=random(10)+1;
	  auxe->ante=fine;
	  auxe->sige=NULL;
	  fine=auxe;
	}
}
//////////////////////FUNCION  MOVER_ESTRELLAS///////////////////
void mover_estrellas()
{
	auxe=inie;
	while(auxe!=NULL)
	{
		putpixel(auxe->e.xe,auxe->e.ye,DARKGRAY);
		auxe->e.ye+=auxe->e.velocidade;
		if(auxe->e.ye>=350)auxe->e.ye=0;
		auxe=auxe->sige;
	}
}

///////////////////FUNCION DESTRUIDO///////////////////////////////
void destruido()
{
	int i=0;
	clearviewport();
	for(i=0;i<100;i++)
	{

		setcolor(random(16)+1);
		settextstyle(1,0,10);
		outtextxy(50,0,"HAS SIDO INVADIDO");
		outtextxy(50,100,"INVADIDO");
		circle(xbuena,350-i,i);
		setactivepage(1-pagina);
		setvisualpage(pagina);
		pagina=1-pagina;
		delay(10);
		if(kbhit())break;
	}
	clearviewport();
	setcolor(random(16)+1);
	settextstyle(1,0,3);
	outtextxy(50,0,"¨DESEAS CONTINUAR(S/N)?");
	setactivepage(1-pagina);
	setvisualpage(pagina);
	pagina=1-pagina;
	continuar=getch();
	if(continuar=='s'||continuar=='S')
	{
		tecla='p';
		cuentanavebuena=3;
	}

}
///////////////////FUNCION PUNTOS//////////////////////////////////
void puntos()
{
	char let[5];

	itoa(punto,let,10);
	setcolor(BLUE);
	settextstyle(1,0,1);
	outtextxy(50,0,"Puntos:");
	outtextxy(150,0,let);
	sprintf(let,"%d",punto);
	if(punto!=0&&punto%1000==0&&swpunto==0)
	{
		cuentanavebuena++;
		swpunto=1;
	}

}
///////////////////FUNCION CONTADORESCUDOS///////////////
void contadorescudos()
{
	char let[2];
	itoa(topeescudo,let,10);
	setcolor(LIGHTGREEN);
	settextstyle(1,0,1);
	outtextxy(250,0,"Escudos:");
	outtextxy(350,0,let);
	sprintf(let,"%d",topeescudo);
}

///////////////////FUNCION VIDAS/////////////////////////
void vidas()
{
	char let[2];
	int i=0;
	itoa(cuentanavebuena,let,10);
	setcolor(RED);
	outtextxy(450,0,"Vidas: ");
	//outtextxy(510,0,let);
	//sprintf(let,"%d",cuentanavebuena);

	for(i=0;i<cuentanavebuena;i++)
	{
		 putimage(510+(i*20),0,nave1,COPY_PUT);
	}
}
///////////////////FUNCION DISPARO MALO/////////////////////////////
void dispamalo(int x,int y)
{
		auxm=(struct listamalo *)malloc(sizeof(struct listamalo))
		;
	  if(!inim)
	  {
		inim=auxm;
	  }
	  else
	  {
		 finm->sigm=auxm;
	  }
	  auxm->mm.xm=x;
	  auxm->mm.ym=y;
	  auxm->antm=finm;
	  auxm->sigm=NULL;
	  finm=auxm;

}
/////////////////////FUNCION DIBUMALA///////////////////////////
void dibumala()
{

		auxm=inim;
		//muevo los disparos
		while(auxm)
		{
			if(auxm->mm.ym<=300)
			{
				auxm->mm.ym+=velocidad;
			}
			//primero miro que este abajo
			putimage(auxm->mm.xm,auxm->mm.ym,disparomalo,COPY_PUT);
			auxm=auxm->sigm;

		}

}
///////////////////////////FUNCION TOCADOMALO////////////////////
int tocadomalo()
{
	struct listamalo *auxm2=NULL,*auxm3=NULL;
	int matao=0,i=0;
	auxm3=inim;
	//miro si he tocado al buenazo o he llegado a 'TIERRA'
	while(auxm3!=NULL)
	{

		 if(auxm3->mm.ym>=300)
		 {
			//ahora miro si esta en las coordenadas de la nave buena
			if((auxm3->mm.xm>=xbuena&&auxm3->mm.xm<=xbuena+25)&&swescudo==0)
			{
					matao=1;
					setcolor(random(15)+1);
					for(i=0;i<20;i++)circle(xbuena+10,300,i);

			}
			if(auxm3->antm==NULL && auxm3->sigm==NULL)//el ultimo elemento
			{
				free(auxm3);
				finm=inim=auxm3=NULL;
				auxm3=NULL;

			}
					else if(auxm3->antm==NULL&&auxm3->sigm!=NULL)//este seria el primero
					{

						inim=inim->sigm;
						inim->antm=NULL;
						free(auxm3);
						auxm3=inim;
					}
					else if(auxm3->antm!=NULL&&auxm3->sigm!=NULL)//este seria uno del medio
					{
						auxm2=auxm3->sigm;
						auxm3->antm->sigm=auxm3->sigm;
						auxm3->sigm->antm=auxm3->antm;
						free(auxm3);
						auxm3=auxm2;
					}
					else if(auxm3->antm!=NULL&&auxm3->sigm==NULL)//este seria fin
					{
						finm=finm->antm;
						finm->sigm=NULL;
						free(auxm3);
						auxm3=NULL;
					}

		  }
		  contm--;
		  if(contm<=0)break;
		auxm3=auxm3->sigm;
	}
	return matao;
}
//////////////////////////////FUNCION QUITAMALA////////////////////////////
void quitamala()
{
	struct lista *aux2=NULL;
		int y=40,x=20;
		int i=0,z=1;
		aux=ini;
		//muevo las dos listas y miro si el disparo esta dentro
		//de las coordenadas de los malos
		while(aux!=NULL)
		{
			auxbb=inibb;
			while(auxbb!=NULL&&auxbb->bb.muerto!=0)
			{
				if(auxbb->bb.ybb==ysola&&paraca==0)
				{
					if(auxbb->bb.xbb>=xsola&&auxbb->bb.xbb<=xsola+30)
					{
					  for(i=0;i<10;i++)
						circle(xsola+15,ysola,i);
						paraca=1;
						punto+=25;
					}
				 }
				if ((auxbb->bb.xbb>=aux->r.x&&auxbb->bb.xbb<=aux->r.x+25
&&auxbb->bb.ybb<=aux->r.y&&auxbb->bb.ybb<=aux->r.y-5))
				{
					for(i=0;i<10;i++)circle(aux->r.x+2,aux->r.y+2,i);
					auxbb->bb.muerto=0;

					//aumento los puntos
					punto+=10;
					if(swpunto==1)
					{
						swpunto=0;
					}
					if(aux->ant==NULL && aux->sig==NULL)//el ultimo elemento
					{
						free(aux);
						fin=ini=aux=NULL;
						aux=NULL;
						punto+=100;

						if(mov*(-1)<10)
						{
							//aumento en 1 la dificultad
							mov++;
						}
						while(vaciar_rectangulos())
						{
							//vacio la lista de las balas de los malos
						}
						//pido memoria para los rectangulos
						//y les paso la coorenadas
						while(z<=21)
						{
							res.y=y;
							res.x=x;
							if(z%7==0)
							{
								y+=30;
								x=20;
							}
							else
							{
								x+=50;
							}
							crear_rectangulos(res);

							z++;
						}
					  ///////////////////////////////////////////
					}
					else if(aux->ant==NULL&&aux->sig!=NULL)//este seria el primero
					{

						ini=ini->sig;
						ini->ant=NULL;
						free(aux);
						aux=ini;
					}
					else if(aux->ant!=NULL&&aux->sig!=NULL)//este seria uno del medio
					{
						aux2=aux->sig;
						aux->ant->sig=aux->sig;
						aux->sig->ant=aux->ant;
						free(aux);
						aux=aux2;
					}
					else if(aux->ant!=NULL&&aux->sig==NULL)//este seria fin
					{
						fin=fin->ant;
						fin->sig=NULL;
						free(aux);
						aux=NULL;
					}
				aux=ini;
				}
			  auxbb=auxbb->sigbb;

			 }
			 aux=aux->sig;
		}

}
/////////////////FUNCION DIBUJARBB///////////////////////////////////
void dibujarbb()
{   //pido memoria
	auxbb=(struct listabb *)malloc(sizeof(struct listabb));
	  if(!inibb)
	  {
		inibb=auxbb;
	  }
	  else
	  {
		 finbb->sigbb=auxbb;
	  }
	  auxbb->bb.xbb=xbuena;
	  auxbb->bb.ybb=300;
	  auxbb->bb.muerto=1;
	  auxbb->antbb=finbb;
	  auxbb->sigbb=NULL;
	  finbb=auxbb;
	  //aumento el contador de balas
	  contbb++;

}
//////////////////funcion moverbb///////////////////
void moverbbeliminar()
{
	struct listabb *auxbb2=NULL;
		auxbb=inibb;
		//muevo los disparos
		while(auxbb)
		{
			if(auxbb->bb.ybb>=0)
			{
				auxbb->bb.ybb-=velocidad;
			}
			else if(auxbb->bb.ybb<=0)
			{
				auxbb->bb.ybb=300;
			}
			putimage(auxbb->bb.xbb,auxbb->bb.ybb,disparo,COPY_PUT);
			auxbb=auxbb->sigbb;

		}
	auxbb=inibb;
	//miro si he tocado alguna nave de los malos o he llegado al 'CIELO'
	while(auxbb)
	{
		//si se cuple lo elimino
		if (auxbb->bb.ybb<=0||auxbb->bb.muerto==0)
		{
			if(auxbb->antbb==NULL && auxbb->sigbb==NULL)//el ultimo elemento
			{
				free(aux);
				finbb=inibb=auxbb=NULL;
				auxbb=NULL;


			}
			else if(auxbb->antbb==NULL&&auxbb->sigbb!=NULL)//este seria el primero
			{

				inibb=inibb->sigbb;
				inibb->antbb=NULL;
				free(auxbb);
				auxbb=inibb;
			}
			else if(auxbb->antbb!=NULL&&auxbb->sigbb!=NULL)//este seria uno del medio
			{
				auxbb2=auxbb->sigbb;
				auxbb->antbb->sigbb=auxbb->sigbb;
				auxbb->sigbb->antbb=auxbb->antbb;
				free(auxbb);
				auxbb=auxbb2;
			}
			else if(auxbb->antbb!=NULL&&auxbb->sigbb==NULL)//este seria fin
			{
				finbb=finbb->antbb;
				finbb->sigbb=NULL;
				free(auxbb);
				auxbb=NULL;
			}
			//disminuo el contador de balas para poder disparar otra vez
			contbb--;
		}
		else
		{
			auxbb=auxbb->sigbb;
		}
	}
}
///////////////////////////FUNCION MOVER_RECTANGULOS/////////////////
void mover_rectangulos()
{
	int sw=0,sw2=0,i=1;
	int y=40,x=20;
	aux=ini;
	//recorro la lista y muevo la x de todos los rectangulos
	while(aux!=NULL)
	{
		aux->r.x+=mov;
		if(aux->r.x>=600||aux->r.x<=2)
		{
			sw=1;
		}
		if(random(1000)<4&&contm<5)
		{
					sound(50);
					delay(100);
					sound(3000);
					delay(20);
					nosound();
					//dibujarbb();
			dispamalo((aux->r.x),aux->r.y);
			contm++;
		}
		if(aux->r.y>=270)sw2=1;
		aux=aux->sig;

	}

	if(sw)mov=mov*(-1);

	aux=ini;
	//si llega a un extremo los bajo
	if(sw==1)
	{  while(aux!=NULL)
		{
			aux->r.y+=5;
			aux=aux->sig;
		}
	}
	if(sw2==1)
	{
		sw2=0;
		cuentanavebuena--;
		while(vaciar_rectangulos())
		{
		//vacio la lista  de los malos
		}
		//pido memoria para los rectangulos
		//y les paso la coorenadas
		while(i<=21)
		{
			res.y=y;
			res.x=x;
			if(i%7==0)
			{
				y+=30;
				x=20;
			}
			else
			{
				x+=50;
			}
		 crear_rectangulos(res);
		 i++;
		}
	 pagina=1-pagina;
	}


}
/////////////////////////////FUNCION CREAR_RECTANGULOS////////////////////////////
void crear_rectangulos(struct regtan p)
{   //pido memoria
	aux=(struct lista *)malloc(sizeof(struct lista));

	//miro que aux no sea NULL
	if(aux)
	{
	  if(!ini)
	  {
		ini=aux;
	  }
	  else
	  {
		 fin->sig=aux;
	  }
	  aux->r=p;
	  aux->ant=fin;
	  aux->sig=NULL;
	  fin=aux;

	}
}
////////////////////////FUNCION MODO GRAFICO////////////////////////
void modo_grafico()
{
	//inicio el modo grafico
	initgraph(&tipo,&modo,"d:\\tc\\bgi");

}
///////////////////////FUNCION DIBUJAR///////////////////////////////
void dibujar_rectangulos()
{
	aux=ini;
	while(aux!=NULL)
	{
		putimage(aux->r.x,aux->r.y,mala,COPY_PUT);

		aux=aux->sig;
	}
}
/////////////////////////FUNCION VACIAR_RECTANGULOS/////////////////////////////////////////
int vaciar_rectangulos()
{  if (ini)
	{
		aux=ini;
		ini=ini->sig;
		free(aux);
		aux=NULL;
		return 1;
	}
	ini=NULL;
	fin=NULL;
	return 0;
}
/////////////////////////FUNCION VACIAR_BALAS_MALO/////////////////////
int vaciar_balas_malo()
{  if (inim)
	{
		auxm=inim;
		inim=inim->sigm;
		free(auxm);
		auxm=NULL;
		return 1;
	}
	inim=NULL;
	finm=NULL;
	return 0;
}
/////////////////////////FUNCION VACIAR_BALAS_BUENO/////////////////////
int vaciar_balas_bueno()
{  if (inibb)
	{
		auxbb=inibb;
		inibb=inibb->sigbb;
		free(auxbb);
		auxbb=NULL;
		return 1;
	}
	inibb=NULL;
	finbb=NULL;
	return 0;
}
/////////////////////////FUNCIONVACIAR_ESTRELLAS//////////////////
int vaciar_estrellas()
{
	if (inie)
	{
		auxe=inie;
		inie=inie->sige;
		free(auxe);
		auxe=NULL;
		return 1;
	}
	inie=NULL;
	fine=NULL;
	return 0;
}
///////////////////////FUNCION ESTRELLAS///////////////////////////
void estrellas()
{
	int i=0,x,y;
	for(i=0;i<50;i++)
	{

		x=random(640);
		y=random(350);
		putpixel(x,y,BROWN);
	}
}
///////////////////FUNCION NAVE BUENA//////////////////////////////////
void NaveBuena()
{

	putimage(xbuena,300,nave1,COPY_PUT);

}
///////////////////FUNCION CREAR_IMAGENES///////////////////////////////
void crear_imagenes(void)
{
	int fila,col;
	int d[10][3]=        {b,R,b,
					  l,l,l,
					  l,l,l,
					  l,l,l,
					  0,l,0,
					  0,l,0,
					  0,l,0,
					  0,l,0,
					  0,l,0,
					  l,b,l};

	int bm[10][3]=   {l,l,l,
				  l,l,l,
				  0,l,0,
				  0,l,0,
				  0,l,0,
				  0,l,0,
				  R,l,R,
				  R,R,R,
				  R,R,R,
				  0,R,0};

	int n1[27][23]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,0,0,R,R,R,0,0,0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,0,R,R,R,R,R,0,0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,b,b,b,b,b,b,b,0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,b,b,b,b,b,b,b,b,b,0,0,0,0,0,0,0,
					0,0,0,0,0,0,b,b,b,b,b,b,b,b,b,b,b,0,0,0,0,0,0,
					0,0,0,0,0,0,b,b,b,b,b,b,b,b,b,b,b,0,0,0,0,0,0,
					0,0,0,0,0,0,b,b,b,b,b,b,b,b,b,b,b,0,0,0,0,0,0,
					0,0,0,0,0,b,b,b,b,b,b,b,b,b,b,b,b,b,0,0,0,0,0,
					0,0,0,0,0,b,b,b,b,b,b,b,b,b,b,b,b,b,0,0,0,0,0,
					0,0,0,0,0,b,b,b,b,b,b,b,b,b,b,b,b,b,0,0,0,0,0,
					0,0,0,0,0,b,b,b,b,b,b,b,b,b,b,b,b,b,0,0,0,0,0,
					0,0,0,0,0,b,b,b,b,b,b,b,b,b,b,b,b,b,0,0,0,0,0,
					0,0,0,0,0,b,b,b,b,b,b,b,b,b,b,b,b,b,0,0,0,0,0,
					0,0,0,0,0,b,b,b,b,b,b,b,b,b,b,b,b,l,0,0,0,0,0,
					0,0,0,b,l,0,b,b,b,b,b,b,b,b,b,b,b,0,l,b,0,0,0,
					0,0,0,l,l,l,0,b,b,b,0,0,0,b,b,b,0,l,l,l,0,0,0,
					0,0,0,l,l,l,0,b,b,0,b,l,b,0,b,b,0,l,l,l,0,0,0,
					0,0,l,l,l,l,0,b,b,0,l,l,l,0,b,b,0,l,l,l,l,0,0,
					0,0,l,l,l,l,l,0,0,b,l,l,l,0,0,0,l,l,l,l,l,0,0,
					0,l,l,l,l,l,l,l,b,l,l,l,l,l,b,l,l,l,l,l,l,l,0,
					0,l,l,l,l,l,l,0,b,l,l,l,l,l,b,0,l,l,l,l,l,l,0,
					0,l,l,l,l,l,l,0,0,b,l,l,l,b,0,0,l,l,l,l,l,l,0,
					0,R,R,l,l,R,R,0,0,R,R,l,R,R,0,0,R,R,l,l,R,R,0,
					0,0,R,R,R,R,0,0,0,0,R,R,R,0,0,0,0,R,R,R,R,0,0,
					0,0,0,0,0,0,0,0,0,0,0,R,0,0,0,0,0,0,0,R,0,0,0,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};

		int m1[25][25]={0,0,b,0,0,0,0,0,0,0,a,0,0,0,0,0,0,0,b,0,0,0,0,0,0,
						0,b,g,b,0,0,0,0,0,a,b,a,0,0,0,0,0,b,g,b,0,0,0,0,0,
						0,0,g,0,0,0,0,0,a,0,b,0,a,0,0,0,0,0,g,0,0,0,0,0,0,
						0,0,g,g,g,g,g,a,0,0,b,0,0,a,g,g,g,g,g,0,0,0,0,0,0,
						0,0,0,0,g,g,a,0,0,0,b,0,0,0,a,g,g,g,b,0,0,0,0,0,0,
						0,b,0,g,g,a,0,b,b,0,b,0,b,b,0,a,g,b,m,b,0,0,0,0,0,
						b,m,b,g,a,0,0,b,b,0,b,0,b,b,0,0,a,m,m,m,0,0,0,0,0,
						m,m,m,a,0,0,0,0,0,b,a,b,0,0,0,0,0,a,m,m,0,0,0,0,0,
						m,m,a,0,0,0,0,0,b,a,a,a,b,0,0,0,0,0,a,m,0,0,0,0,0,
						m,a,0,0,0,0,0,b,a,a,a,a,a,b,0,0,0,0,0,a,0,0,0,0,0,
						v,v,v,v,v,v,v,v,v,v,v,v,v,v,v,v,v,v,v,v,0,0,0,0,0,
						0,b,b,b,0,0,0,0,0,b,b,b,0,0,0,0,0,b,b,b,0,0,0,0,0,
						0,0,b,0,0,0,0,0,0,0,b,0,0,0,0,0,0,0,b,0,0,0,0,0,0,
						0,0,b,0,0,0,0,0,0,0,b,0,0,0,0,0,0,0,b,0,0,0,0,0,0,
						0,b,b,b,0,0,0,0,0,b,b,b,0,0,0,0,0,b,b,b,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};


		////////////////////////////////////////////////////////////////
int dibujo[100][50]={
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,0,0,0,
0,0,0,0,0,15,15,15,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,0,0,
0,0,0,0,15,15,15,15,0,6,6,6,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,0,
0,0,15,15,15,15,15,15,6,6,6,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,
0,15,15,15,15,15,15,0,0,6,6,6,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,
15,15,15,15,15,15,15,15,6,6,0,6,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,
15,15,15,15,15,15,15,15,15,15,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
15,15,0,0,15,15,15,0,0,15,15,15,0,0,15,15,15,0,0,15,15,15,0,0,15,15,15,0,0,15,15,15,0,0,15,15,15,0,0,15,15,15,0,0,15,15,15,0,0,15,
15,0,0,0,0,15,0,0,0,0,15,0,0,0,0,15,0,0,0,0,15,0,0,0,0,15,0,0,0,0,15,0,0,0,0,15,0,0,0,0,15,0,0,0,0,15,0,0,0,15,
0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,
0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,
0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,
0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,
0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,
0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,
0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,15,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,15,15,15,15,15,15,15,15,15,15,15,15,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,15,15,15,15,4,4,4,15,15,15,15,15,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,15,15,15,15,4,4,4,15,15,15,15,15,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,15,4,4,4,4,4,4,4,4,4,15,15,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,15,4,4,4,4,4,4,4,4,4,15,15,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,15,4,4,4,4,4,4,4,4,4,15,15,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,15,15,15,15,4,4,4,15,15,15,15,15,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,15,15,15,15,4,4,4,15,15,15,15,15,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,15,15,15,15,15,15,15,15,15,15,15,15,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		////////////////////////////////////////////////////////////////
int ovni[30][50]={
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,15,15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,15,4,4,15,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,14,14,14,14,14,14,4,15,15,15,15,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,14,14,14,12,12,12,12,12,4,3,3,5,3,3,3,5,3,5,5,5,5,3,5,3,3,5,3,3,5,3,3,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,
0,14,14,14,12,12,12,12,12,4,3,3,5,5,3,5,5,3,5,3,3,5,3,5,3,5,3,3,3,3,3,3,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,
0,0,0,14,14,12,12,12,12,4,3,3,5,3,5,3,5,3,5,5,5,5,3,5,5,3,3,3,3,5,3,3,3,3,1,1,1,1,1,1,3,3,0,0,0,0,0,0,0,0,
0,0,0,0,0,14,14,14,14,4,3,3,5,3,3,3,5,3,5,3,3,5,3,5,3,5,3,3,3,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		///////////////////////////////////////////////////////////////
for(fila=0;fila<30;fila++)
  {
	for(col=0;col<50;col++)
	{
		putpixel(col,fila,ovni[fila][col]);
	}
  }
  mala3=malloc(imagesize(0,0,49,29));
  //recoge la imagen y vuelca en la memoria
  getimage(0,0,49,29,mala3);

  for(fila=0;fila<27;fila++)
  {
	for(col=0;col<23;col++)
	{
		putpixel(col,fila,n1[fila][col]);
	}
  }
  nave1=malloc(imagesize(0,0,22,26));
  //recoge la imagen y vuelca en la memoria
  getimage(0,0,22,26,nave1);



  for(fila=0;fila<25;fila++)
  {
	for(col=0;col<25;col++)
	{
		putpixel(col,fila,m1[fila][col]);
	}
  }
  mala=malloc(imagesize(0,0,24,24));
  //recoge la imagen y vuelca en la memoria
  getimage(0,0,24,24,mala);

  for(fila=0;fila<100;fila++)
  {
	for(col=0;col<50;col++)
	{
		putpixel(col,fila,dibujo[fila][col]);
	}
  }
  mala2=malloc(imagesize(0,0,49,99));
  //recoge la imagen y vuelca en la memoria
  getimage(0,0,49,99,mala2);


	for(fila=0;fila<10;fila++)
	{
		for(col=0;col<3;col++)
		{
			putpixel(col,fila,bm[fila][col]);
		}
	}
	disparomalo=malloc(imagesize(0,0,2,9));
	//recoge la imagen y vuelca en la memoria
	getimage(0,0,2,9,disparomalo);

	for(fila=0;fila<10;fila++)
	{
		for(col=0;col<3;col++)
		{
			putpixel(col,fila,d[fila][col]);
		}
	}
	disparo=malloc(imagesize(0,0,2,9));
	//recoge la imagen y vuelca en la memoria
	getimage(0,0,2,9,disparo);


}
