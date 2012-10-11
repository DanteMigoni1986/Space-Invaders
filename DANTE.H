#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <math.h>
#include <graphics.h>
#include <stdlib.h>


#ifdef EXT
 #define DECLARAR
#else
#define DECLARAR extern
#endif

DECLARAR
  int		Resolucion_x,Resolucion_y,N,Activo_Pasivo,Dandera;
DECLARAR
  int huge Original[256][256];
DECLARAR
  int huge Modificada[256][256];
DECLARAR
  int huge Modificada2[256][256];
DECLARAR
  int Hgram[2][256];
DECLARAR
  double factor_escalamiento;
DECLARAR
  int contador;
DECLARAR
  int level;
DECLARAR
  char continuar;