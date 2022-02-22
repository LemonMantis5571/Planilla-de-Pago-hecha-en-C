#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <time.h>
#include <ctype.h>
#include<GRAPHICS.H>
#include <STDBOOL.h>
int u[]={77,100,148,100,148,262,244,262,244,165,305,165,305,315,77,315,77,101};
int ni[]={163,100,385,100,385,263,410,263,410,165,481,165,481,316,321,316,321,148,233,148,233,245,163,245,163,100};
int punto[]={410,102,482,102,482,150,410,150,410,102};
int driver = DETECT,modo,codigo;
int poligono [] = {502, 311,120, 311,120, 151,502, 151,502, 311};
int raya [] = {122,279.1, 500,279.1};
int rayaroja [] = {122, 287, 500, 287};
int rayaroja2[] = {120,190,120,190};
int raya2 [] = {120,176, 500, 176};
int tc20 [] = {0,0,1,479,639,479,639,1};
int triangulo [] = {120,233, 184,279, 120,279,120,233};
int cuadrado [] = {119,396,119,448,500,448, 500,396,119,396};
int tri[] = {0,100, 100,100, 50,0};
#define BLINK 128 /* blink */
#define User "masaya"
#define Pass "monito"
#define Longitud 10
#define ENTER 13
#define ESPACIO 32
#define Limite1  100000L
#define Limite2  200000L
#define Limite3  330000L
#define Limite4  500000L
#define MAXSTRLN 20
#define MAXPERSON 10

int Cantidad = 3, ContadorCarnet = 3;
char nombre[MAXPERSON][MAXSTRLN]={"Chaeryeong","Ryujin","ROSE"};
char temp [MAXPERSON][MAXSTRLN], *namewanted;
int find = 0, pos = 0, i, j, findpos[MAXPERSON];
int CarnetAux[MAXPERSON];
char *newname;
int cantidad = 0;
bool Buscarr;

typedef struct{
	int Salario;
    float Pago_Horas_extra;
	int Horas_extra;
	int Comisiones;
	int Carnet;
    float Total_Ingresos;
    float INNS_Laboral;
    int meses;
    float IR;
    float Deducciones;
    float Neto;
    float INSSPatrol;
    float INATEC;
} agregar;
agregar Empleado[10];
int errores = 3;
int intento = 3;
int maxcolor = 14;
void agregaar(void);
void carga(void);
void logografico(void);
void credenciales(void);
void mostrar(void);
void Inicializador(void);
void actualizar(void);
void eliminar(void);
void buscar(void);
void acsii(void);
void Lavadodedinero(int);
void planilla(void);
void planilla1();
void Planilla2(void);
void Planilla3(void);
void planilla1(void);
void Inicializador(){
	int i;

	for(i=0; i<3; i++){
		Empleado[i].Salario = 30000;
		Empleado[i].Horas_extra = 5;
		Empleado[i].Comisiones = 10;
		Empleado[i].Carnet = i+1;
        Empleado[i].meses =50;
        Lavadodedinero(i);
       
	}
		Empleado[1].Salario = 10;
        Empleado[1].Horas_extra = 120;
        Empleado[1].Comisiones = 30;
        Empleado[1].meses =550;
        Lavadodedinero(1);

		Empleado[2].Salario = 350;
        Empleado[2].Comisiones = 1;
        Empleado[2].Horas_extra =9999;
        Empleado[2].meses =460;
       Lavadodedinero(2);
}
void carga(void)
{

  int a=20,b=0,porcentaje=2;
  system("cls");
  textbackground(BLACK);
  while(b<=49)
    {
    gotoxy(30,15);
    textcolor(CYAN + BLINK);
    cprintf("Cargando, por favor espere");
	gotoxy(a,20);printf("%c",219);delay(200);
	b++;
	a++;
    porcentaje+=2;
    gotoxy(40,23);
    printf("%d %s",porcentaje,"%");
    }
}
void presentacion(void)
{
    FILE *p;
    char ch;
    system("cls");
    p=fopen("BBB.txt","r");

    if(p==NULL)
    {
        printf("Archivo no encontrado");
    }
	else ch=fgetc(p);

    while(ch!=EOF)
    {
		delay(50);
		printf("%c",ch);
		ch=fgetc(p);

    }

    fclose(p);
}
void prefijos(void)
{
    

    initgraph(&driver,&modo, "c:\\tc20\\BIN");
    cleardevice();

    /* Dibujo */



    setbkcolor(4);
    setcolor(1);

        /* Texto Uni */
    setcolor(8);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(80,77,"Universidad Nacional de Ingenieria");
    delay(120);

    setcolor(WHITE);
	settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(70,70,"Universidad Nacional de Ingenieria");
    delay(120);

  

    /* Bandera Maxi Pali */
    setcolor(14);

    setlinestyle(SOLID_LINE,14,THICK_WIDTH);
    setfillstyle(SOLID_FILL,2);

    drawpoly(5,poligono);
    fillpoly(5,poligono);

    drawpoly(2,raya);
    fillpoly(2,raya);

    drawpoly(2,raya2);
    fillpoly(2,raya2);

    setcolor(14);
    
    setfillstyle(SOLID_FILL,2);
    drawpoly(4,triangulo);
    fillpoly(4,triangulo);

    setcolor(4);

    setlinestyle(SOLID_LINE,4,THICK_WIDTH);
    fillpoly(2,rayaroja);
   

    /* Texto dentro de la bandera */
    setcolor(WHITE);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 3);
    outtextxy(225,225,"MAXIPALI");

    /* Texto Debajo de la bandera */
    setcolor(WHITE);
    settextstyle (TRIPLEX_FONT  , HORIZ_DIR, 2);
	outtextxy(160,319,"PRECIO BAJO SIEMPRE");

    /* Recuadro TC20 */
    setcolor(WHITE);
    setlinestyle(SOLID_LINE,WHITE,THICK_WIDTH);
    drawpoly(4,tc20);
  
    /* Rectangulo */
  /*  setcolor(WHITE);
    fillpoly(5,cuadrado); */

    /* Texto Enter */
    /* Verde */
    setcolor(4);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(100,389,"Presione Enter para Continuar");

    /*AZUL */
    setcolor(WHITE);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(90,384,"Presione Enter para Continuar");

    sleep(1.5);

    setcolor(4);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(90,384,"Presione Enter para Continuar");
    setcolor(WHITE);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(100,389,"Presione Enter para Continuar");

    sleep(1.5);

    setcolor(4);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(100,389,"Presione Enter para Continuar");
    setcolor(WHITE);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(90,384,"Presione Enter para Continuar");

    sleep(1.5);

    setcolor(4);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(90,384,"Presione Enter para Continuar");
    setcolor(WHITE);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(100,389,"Presione Enter para Continuar");

    sleep(1.5);

    setcolor(4);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(100,389,"Presione Enter para Continuar");
    setcolor(WHITE);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(90,384,"Presione Enter para Continuar");

    
    sleep(1.5);

    setcolor(4);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(90,384,"Presione Enter para Continuar");
    setcolor(WHITE);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(100,389,"Presione Enter para Continuar");

    sleep(1.5);

    setcolor(4);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(100,389,"Presione Enter para Continuar");
    setcolor(WHITE);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(90,384,"Presione Enter para Continuar");

    
    sleep(1.5);

    setcolor(4);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(90,384,"Presione Enter para Continuar");
    setcolor(WHITE);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(100,389,"Presione Enter para Continuar");

    sleep(1.5);

    setcolor(4);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(100,389,"Presione Enter para Continuar");
    setcolor(WHITE);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(90,384,"Presione Enter para Continuar");

    
    sleep(1.5);

    setcolor(4);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(90,384,"Presione Enter para Continuar");
    setcolor(WHITE);
    settextstyle (DEFAULT_FONT  , HORIZ_DIR, 2);
	outtextxy(100,389,"Presione Enter para Continuar");

    getch();
    closegraph(); 
    logografico();
    sleep(2);
    closegraph();
    carga();
}
void credenciales()
{
    char Username[Longitud+1];
    char Password[Longitud+1];
    char caracter;
    int i = 0, p;
    int long1;
    int ingreso = 0;

    do{
        i = 0;
        system("cls");
        fflush(stdin);

        gotoxy(34,4);textcolor(BLUE);
        cprintf("CREDENCIALES");
		gotoxy(28,5);textcolor(WHITE);
        cprintf("Ingrese sus credenciales");
		gotoxy(29,6);
		cprintf("Intentos permitidos: %i", intento);
		gotoxy(19,8);
        cprintf("Usuario: ");

        switch (getch()){
            case ENTER:
                goto intento;
            case ESPACIO:
                goto intento;
            default:

                gets(Username);
            break;
        }

        long1 = strlen(Username);
        if (long1 > 10){
            textcolor(YELLOW);gotoxy(28,10);
            cprintf("(?) El usuario es incorrecto.\n");
			gotoxy(31,11);
			cprintf("(?) Exceso de estupidez.");
            getch();
            goto intento;
        }

        gotoxy(19,10);
        cprintf("Ingrese la clave: ");

        switch (getch()){
             case ENTER:
                 goto intento;
             case ESPACIO:
                 goto intento;
			 default:

				while(caracter = getch())
                 if(caracter == 13){
                     Password[i] = '\0';
                     break;
                 }else if(caracter == 8){
                    if(i > 0){
                         i--;
                         printf("\b \b");
                    }
                 }else{
                    if(i < Longitud){
                     printf("*");
                     Password[i] = caracter;
                     i++;
                    }
                }
             break;
            }

		for (p = 0; p < 3 ; p++){
			textcolor(GREEN);
			gotoxy(33,13);
			cprintf("Viendo si es cierto chatel");
			gotoxy(59+p,13);
			cprintf(".");
			delay(800);
		}

        if (strcmp(Username,User) == 0 && strcmp(Password,Pass) == 0){
            ingreso = 1;
        }else{

            if(strcmp(Username,User) != 0){
                textcolor(YELLOW);
				gotoxy(25,15);
                cprintf("(?) El usuario es incorrecto.\n");
                getch();
            }
            if(strcmp(Password,Pass) != 0){
                textcolor(YELLOW);
				gotoxy(26,16);
				cprintf("(?) La clave es incorrecta.\n");
				getch();
            }

            intento:
            intento--;

            if (intento == 0){
				textcolor(YELLOW+BLINK);gotoxy(21,18);
                cprintf("(?) Fallaste: sos bien paja, todo incorrecto.");
				gotoxy(28,19);
                cprintf("(?) Nos vimos chatel.");
				getch();
                exit(EXIT_SUCCESS);
            }
        }

    } while (intento > 0 && ingreso != 1);

	textcolor(GREEN+BLINK);
	gotoxy(32,15);
	cprintf("ACCESO PERMITIDO");
	delay(1000);
}
void agregaar(void)
{
   char opc;
	int CantidadFull = 0;

	system("cls");
	fflush(stdin);
	do{
		system("cls");
		fflush(stdin);
		if(Cantidad < MAXPERSON){
			gotoxy(33,5); textcolor(YELLOW);
			cprintf("A G R E G A R");
			gotoxy(36,7);
            printf("Ingrese el nombre: ");
			gets(nombre[Cantidad]);

			gotoxy(33,8);
			printf("Salario:");scanf("%i", &Empleado[Cantidad].Salario);

			gotoxy(33,10);
			printf("Horas extras:");scanf("%i", &Empleado[Cantidad].Horas_extra);

			gotoxy(33,12);
			printf("Comisiones:");scanf("%i", &Empleado[Cantidad].Comisiones);
            Lavadodedinero(Cantidad);
			gotoxy(30,14);
			printf("Registrado correctamente");

			ContadorCarnet++;
			Empleado[Cantidad].Carnet = ContadorCarnet;
			Cantidad++;
			
		}else
        {
			gotoxy(30,12);
			printf("El campo de concentracion esta lleno :O");
			CantidadFull = 1;
			getch();
		}

		if(CantidadFull == 0){
            system("cls");
			gotoxy(30,11);
			printf("Desea ingresar otro esclavo?");
			gotoxy(30,12);
			printf("S o N");
			do{
				opc = getch();
			} while (tolower(opc) != 'n' && tolower(opc) != 's');
		}else{
			opc = 'n';
		}
	} while (tolower(opc) != 'n');

}
void actualizar(){
    int opc, realopc;
    buscar();
    system("cls");
    textcolor(YELLOW);
    cprintf("\n \t \t ACTUALIZAR");
    if(Buscarr == true){
        textcolor(GREEN);
        cprintf("\n ESCLAVO ENCONTRADO >:I");
        for(j = 0; j < pos; j++){
            printf("\n %d. %s", j+1, temp[j]);
        }

        printf("\nIngrese el numero del Trabajo a actualizar: ");
        scanf("%d", &opc);

        opc = opc - 1;
        realopc = findpos[opc];
        system("cls");
		fflush(stdin);

		gotoxy(31,5); textcolor(YELLOW);
		cprintf("A C T U A L I Z A R");
		gotoxy(31,7);
		printf("Ingrese el nuevo nombre: ");
		gets(newname);

		gotoxy(31,8);
		printf("Salario:");scanf("%i", &Empleado[realopc].Salario);
		printf("\n\t\t\t\tHoras extra:");scanf("%i", &Empleado[realopc].Horas_extra);
		printf("\n\t\t\t\tComision:");scanf("%i", &Empleado[realopc].Comisiones);
        Lavadodedinero(realopc);
		strcpy(nombre[realopc], newname);
    }else{
        gotoxy(35,8);
        textcolor(RED);
        cprintf("\n NO SE ENCONTRO JAULA");
        getch();
    }
    Buscarr = false;
    pos = 0;
    namewanted = '\0';
}
void buscar(){
    int c =0;

    system("cls");
    fflush(stdin);
    textcolor(YELLOW);
    cprintf("\n\t\t\t BUSCAR ESCLAVO: ");
    gets(namewanted);
    c = atoi(namewanted);


    for(i = 0; i < Cantidad; i++){
        if(strcmp(nombre[i], namewanted) == 0 || c==Empleado[i].Carnet)
        {
            Buscarr = true;
            findpos[pos] = i;
            strcpy(temp[pos], nombre[i]);
            CarnetAux[pos] = Empleado[i].Carnet;
            pos++;
        }
    }
}
void eliminar(){
    int opc, realopc, i;
    buscar();
    system("cls");
    textcolor(YELLOW);
    cprintf("\n\t\t ELIMINAR ESCLAVO");
    if(Buscarr == true){
        textcolor(GREEN);
        cprintf("\n \n \n ESCLAVO ENCONTRADO >:I");

        for(j = 0; j < pos ; j++){
            gotoxy(36,8);
            printf("\n %d. %s", j+1, temp[j]);
        }

        printf("\n Ingrese el numero del Esclavo a Despedir: \t");
        scanf("%d", &opc);

        opc -=1;
        realopc = findpos[opc];

        for(i = realopc; i < Cantidad ; i++){
            strcpy(nombre[i],nombre[i+1]);
            Empleado[i].Salario = Empleado[i+1].Salario;
			Empleado[i].Comisiones = Empleado[i+1].Comisiones;
			Empleado[i].Horas_extra = Empleado[i+1].Horas_extra;
			Empleado[i].Carnet = Empleado[i+1].Carnet;
            Empleado[i].Total_Ingresos = Empleado[i+1].Total_Ingresos;
            Empleado[i].meses = Empleado[i+1].meses;
            Empleado[i].Pago_Horas_extra = Empleado[i+1].Pago_Horas_extra;
            Empleado[i].Deducciones = Empleado[i+1].Deducciones;
            Empleado[i].Neto = Empleado[i+1].Neto;
            Empleado[i].IR = Empleado[i+1].IR;
            Empleado[i].INNS_Laboral = Empleado[i+1].INNS_Laboral;
            Empleado[i].INSSPatrol = Empleado[i+1].INSSPatrol;
            Empleado[i].INATEC = Empleado[i+1].INATEC;
        }
        Cantidad --;
    }else{
        gotoxy(35,8);
        textcolor(RED);
        cprintf("\n NO SE ENCONTRO JAULA");
        getch();
    }
    Buscarr = false;
    pos = 0;
    namewanted = '\0';
}
void resulbusqueda(){
    system("cls");
    textcolor(YELLOW);
    cprintf("\n\t\tBUSCAR: ");
    if (Buscarr == true){
        textcolor(GREEN);
        cprintf("\n \n \nESCLAVO ENCONTRADO >:I");

        for(j = 0; j < pos; j++){
            gotoxy(36,8);
            printf("\n%d. %s %i", j+1, temp[j], CarnetAux[j]);
        }
    }else{
        textcolor(RED);
        cprintf("\n NO SE ENCONTRO JAULA");
        getch(); 
    }
    Buscarr = false;
    pos = 0;
    namewanted = '\0';
}
void logografico(void)
{
  int i,a,b,c;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"..\\bgi");

    while(!kbhit())
    {
	cleardevice();
	setcolor(BLUE);
	for(i=0;i<=294;i++){
		putpixel(233,i,BLUE);
		a=480-i;
		putpixel(407,a,BLUE);
		delay(1);
	}
	for(i=0;i<=407;i++){
		putpixel(i,294,BLUE);
		a=640-i;
		putpixel(a,186,BLUE);
		delay(1);
	}
	delay(60);
	setfillstyle(WIDE_DOT_FILL,LIGHTBLUE);
	floodfill(250,210,BLUE);
	delay(60);
	setfillstyle(CLOSE_DOT_FILL,LIGHTBLUE);
	floodfill(234,293,BLUE);
	delay(60);
	setfillstyle(SOLID_FILL,BLUE);
	floodfill(406,293,BLUE);

	setcolor(WHITE);
	for(i=0;i<=267;i++){
		line(263,i,270,i);
		a=480-i;
		line(369,a,376,a);
		delay(2);
	}
	b=376;
	c=a;
	for(i=270;i<=305;i++){
		line(i,258,i,267);
		line(369,a,376,a);
		a--;
		line(b,c,b,c+11);
		b++;
		delay(2);
	}
	for(i=258;i>=214;i--){
		line(298,i,305,i);
		line(369,a,376,a);
		a--;
		line(b,c,b,c+11);
		b++;
		delay(2);
	}
	for(i=305;i<=341;i++){
		line(i,214,i,223);
		line(369,a,376,a);
		a--;
		line(b,c,b,c+11);
		b++;
		delay(2);
	}
	for(i=223;i<=480;i++){
		line(334,i,341,i);
		line(369,a,376,a);
		a--;
		line(b,c,b,c+11);
		b++;
		delay(2);
	}
	setcolor(BLACK);
	for(i=0;i<=267;i++){
		line(263,i,270,i);
		a=480-i;
		line(369,a,376,a);
		delay(2);
	}
	b=376;
	c=a;
	for(i=270;i<=305;i++){
		line(i,258,i,267);
		line(369,a,376,a);
		a--;
		line(b,c,b,c+11);
		b++;
		delay(2);
	}
	for(i=258;i>=214;i--){
		line(298,i,305,i);
		line(369,a,376,a);
		a--;
		line(b,c,b,c+11);
		b++;
		delay(2);
	}
	for(i=305;i<=341;i++){
		line(i,214,i,223);
		line(369,a,376,a);
		a--;
		line(b,c,b,c+11);
		b++;
		delay(2);
	}
	for(i=223;i<=480;i++){
		line(334,i,341,i);
		line(369,a,376,a);
		a--;
		line(b,c,b,c+11);
		b++;
		delay(2);
	}
	delay(60);
	setfillstyle(WIDE_DOT_FILL,BLACK);
	floodfill(250,210,RED);
	delay(60);
    }

    getch();
    closegraph();



 
}
void acsii(void)
{
    FILE *p;
    char ch;
    system("cls");
    textcolor(WHITE);
    p=fopen("Policia.txt","r");

    if(p==NULL)
    {
        printf("Archivo no encontrado");
    }
	else ch=fgetc(p);

    while(ch!=EOF)
    {
		delay(50);
		printf("%c",ch);
		ch=fgetc(p);

    }

    fclose(p);
}
void Lavadodedinero (int i) 
{
    float APLI=0;
    float temporizador = 0, Exceso=0,ImpuestoB = 0;

    Empleado[i].Pago_Horas_extra = (Empleado[i].Salario)/120 * (Empleado[i].Horas_extra);
    Empleado[i].Total_Ingresos = (Empleado[i].Salario+Empleado[i].Pago_Horas_extra+Empleado[i].Comisiones);
    Empleado[i].INNS_Laboral = (Empleado[i].Total_Ingresos*7/100);
    
    temporizador = (Empleado[i].Total_Ingresos - Empleado[i].INNS_Laboral);
    temporizador = temporizador * 12;

    if(temporizador <= Limite1){
        ImpuestoB = 0;
        APLI = 0;
        Exceso = 0;
    }else{
        if(temporizador <= Limite2){
            ImpuestoB = 0;
            APLI = 0.15;
            Exceso = 100000L;
        }else{
            if(temporizador <= Limite3){
                ImpuestoB = 15000L;
                APLI = 0.20;
                Exceso = 200000L;
            }else{
                if(temporizador <= Limite4){
                    ImpuestoB = 45000L;
                    APLI = 0.25;
                    Exceso = 350000L;
                }else{
                    if(temporizador > Limite4){
                        ImpuestoB = 82500L;
                        APLI = 0.30;
                        Exceso = 500000L;
                    }
                }
            }
        }
    }
    Empleado[i].IR = (((temporizador - Exceso) * APLI) + ImpuestoB) / 12;
    Empleado[i].Deducciones = (Empleado[i].IR + Empleado[i].INNS_Laboral);
    Empleado[i].Neto = (Empleado[i].Total_Ingresos - Empleado[i].Deducciones);
    Empleado[i].INSSPatrol = (Empleado[i].Total_Ingresos * 0.225);
    Empleado[i].INATEC = (Empleado[i].Salario * 0.2);
    
}
 /*void planilla()
{
    int i, x;
    system("cls");

    for (i = 0; i < 79; i++)
    {
        textcolor(YELLOW);
        gotoxy(i, 25);
        cprintf("%c", 220);
        gotoxy(i, 3);
        cprintf("%c", 220);
        gotoxy(i, 1);
        cprintf("%c", 223);
    }
    for (i = 21; i < 79; i++)
    {
        textcolor(YELLOW);
        gotoxy(i, 6);
        cprintf("%c", 220);
        textcolor(GREEN);
        gotoxy(22, 5);
        cprintf("Pago H. Extra");
    }

    for (x = 0; x < 26; x++)
    {
        textcolor(YELLOW);
        gotoxy(79, x);
        cprintf("%c", 219);
        gotoxy(1, x);
        cprintf("%c", 219);

        gotoxy(21, x);
        cprintf("%c", 219);
        gotoxy(4, 2);
        textcolor(RED);
        cprintf("Nombre y Carnet");
        gotoxy(40, 2);
        cprintf("Renumeracion Bruta y Deducciones");
    }

    for (i = 4; i < 26; i++)
    {
        textcolor(YELLOW);
        gotoxy(37, i);
        cprintf("%c", 219);

        gotoxy(46, i);
        cprintf("%c", 219);

        textcolor(GREEN);
        gotoxy(38, 5);
        cprintf("INNS LA");

        textcolor(YELLOW);
        gotoxy(53, i);
        cprintf("%c", 219);
        textcolor(GREEN);
        gotoxy(48, 5);
        cprintf("IR");

        textcolor(YELLOW);
        gotoxy(64, i);
        cprintf("%c", 219);
        textcolor(GREEN);
        gotoxy(55, 5);
        cprintf("INNS PA");

        textcolor(GREEN);
        gotoxy(67, 5);
        cprintf("NETO");
    }
    for(i = 0; i < Cantidad; i++){
            Lavadodedinero(i);
			gotoxy(4, 8+i);
            textcolor(BROWN);
        	cprintf("%s", nombre[i]);

		

			/*gotoxy(40,7+i);
			printf("%i", Empleado[i].Horas_extra);

			gotoxy(55,7+i);
			printf("%.2f", Empleado[i].Comisiones);
            */
		 /*	gotoxy(2,8+i); 
		
        	printf("%i", Empleado[i].Carnet); 

            gotoxy(26, 8+i);
            printf("%.2f%c", Empleado[i].Pago_Horas_extra,'$');

            gotoxy(38, 8+i);
            printf("%.2f%c", Empleado[i].INNS_Laboral,'$');

            gotoxy(48, 8+i);
            printf("%.1f%c", Empleado[i].IR,'$');

            gotoxy(55, 8+i);
            printf(" %.2f%c",Empleado[i].INSSPatrol,'$');

            gotoxy(67, 8+i);
            printf("%.2f%c", Empleado[i].Neto,'$');

        }
    getch();
    system("cls");
} */
 /*void planilla1()
{
       int i, x;
    system("cls");

    for (i = 0; i < 79; i++)
    {
        textcolor(YELLOW);
        gotoxy(i, 25);
        cprintf("%c", 220);
        gotoxy(i, 3);
        cprintf("%c", 220);
        gotoxy(i, 1);
        cprintf("%c", 223);
    }
    for (i = 21; i < 79; i++)
    {
        textcolor(YELLOW);
        gotoxy(i, 6);
        cprintf("%c", 220);
        textcolor(GREEN);
        gotoxy(22, 5);
        cprintf("Salario");
    }

    for (x = 0; x < 26; x++)
    {
        textcolor(YELLOW);
        gotoxy(79, x);
        cprintf("%c", 219);
        gotoxy(1, x);
        cprintf("%c", 219);

        gotoxy(21, x);
        cprintf("%c", 219);
        gotoxy(4, 2);
        textcolor(RED);
        cprintf("Nombre y Carnet");
        gotoxy(40, 2);
        cprintf("Renumeracion Bruta y Deducciones");
    }

    for (i = 4; i < 26; i++)
    {
        textcolor(YELLOW);
        gotoxy(37, i);
        cprintf("%c", 219);

        gotoxy(46, i);
        cprintf("%c", 219);

        textcolor(GREEN);
        gotoxy(38, 5);
        cprintf("H.Extra");

        textcolor(YELLOW);
        gotoxy(53, i);
        cprintf("%c", 219);
        textcolor(GREEN);
        gotoxy(48, 5);
        cprintf("COMS");

        textcolor(YELLOW);
        gotoxy(64, i);
        cprintf("%c", 219);
        textcolor(GREEN);
        gotoxy(55, 5);
        cprintf("TOTAL");

        textcolor(GREEN);
        gotoxy(67, 5);
        cprintf("EXPLOTADO");
    }
    for(i = 0; i < Cantidad; i++){
            Lavadodedinero(i);
			gotoxy(4, 8+i);
            textcolor(BROWN);
        	cprintf("%s", nombre[i]);

			gotoxy(23, 8+i);
			printf("%d%c", Empleado[i].Salario,'$');

			gotoxy(39, 8+i);
			printf("%i", Empleado[i].Horas_extra);

			gotoxy(48, 8+i);
			printf("%d%c", Empleado[i].Comisiones,'$');

            gotoxy(2,8+i);
        	printf("%i", Empleado[i].Carnet);

            gotoxy(55, 8+i);
            printf("%.2f%c", Empleado[i].Total_Ingresos,'$');
        

            gotoxy(67, 8+i);
            printf("%d %s", Empleado[i].meses,"Meses");
    

        }
    getch();
    system("cls");



 
} */
void planilla1(){
    int x,i;

    system("cls");
    /*Fondo Pantalla*/
    for(x = 0; x < 78; x++){
        textcolor(BLUE);
        gotoxy(2+x,2);
        cprintf("%c",219);
        gotoxy(2+x,3);
        cprintf("%c",219);
        gotoxy(2+x,4);
        cprintf("%c",219);
        gotoxy(2+x,5);
        cprintf("%c",219);
        gotoxy(2+x,6);
        cprintf("%c",219);
        gotoxy(2+x,7);
        cprintf("%c",219);
        gotoxy(2+x,8);
        cprintf("%c",219);
        gotoxy(2+x,9);
        cprintf("%c",219);
        gotoxy(2+x,10);
        cprintf("%c",219);
        gotoxy(2+x,11);
        cprintf("%c",219);
        gotoxy(2+x,12);
        cprintf("%c",219);
        gotoxy(2+x,13);
        cprintf("%c",219);
        gotoxy(2+x,14);
        cprintf("%c",219);
        gotoxy(2+x,15);
        cprintf("%c",219);
        gotoxy(2+x,16);
        cprintf("%c",219);
        gotoxy(2+x,17);
        cprintf("%c",219);
        gotoxy(2+x,18);
        cprintf("%c",219);
        gotoxy(2+x,19);
        cprintf("%c",219);
        gotoxy(2+x,20);
        cprintf("%c",219);
        gotoxy(2+x,21);
        cprintf("%c",219);
        gotoxy(2+x,22);
        cprintf("%c",219);
        gotoxy(2+x,23);
        cprintf("%c",219);
        gotoxy(2+x,24);
        cprintf("%c",219);
    }
    for(x = 0; x < 74; x++){
        textcolor(CYAN);
        textbackground(BLUE);
        gotoxy(3,2);
        cprintf("%c", 201);
        gotoxy(4+x,2);
        cprintf("%c", 205);
        gotoxy(78,2);
		cprintf("%c", 187);

        gotoxy(3,24);
        cprintf("%c", 200);
        gotoxy(4+x,24);
        cprintf("%c", 205);
        gotoxy(78,24);
		cprintf("%c", 188);
    }
    for(x = 0; x < 21; x++){ /*Marco cyan*/
        textcolor(CYAN);
        textbackground(BLUE);
        gotoxy(3,3+x);
        cprintf("%c",186);
        gotoxy(78,3+x);
        cprintf("%c", 186);
    }
    for(x = 0; x < 21; x++){ /*Lineas intermedias*/
        gotoxy(12,3+x);
        cprintf("%c", 179);
        gotoxy(28,3+x);
		cprintf("%c", 179);
        gotoxy(40,3+x);
		cprintf("%c", 179);
        gotoxy(48,3+x);
		cprintf("%c", 179);
        gotoxy(61,3+x);
        cprintf("%c", 179);
    }
    for(x = 0; x <73; x++){
        gotoxy(4+x,5);
        cprintf("%c", 196);
    }
    textcolor(YELLOW);
    gotoxy(5,4);
    cprintf("Carnet");
    gotoxy(17,4);
    cprintf("Nombre");
    gotoxy(31,4);
    cprintf("Salario");
    gotoxy(43,3);
    cprintf("HRS");gotoxy(42,4);cprintf("Extra");
    gotoxy(52,3);
    cprintf("Pago D.");gotoxy(53,4);cprintf("HRS");
    gotoxy(65,4);
    cprintf("Comisiones");
/*Coordenadas para pintar */
    for(i = 0; i < Cantidad; i++){
        Lavadodedinero(i);
        textcolor(WHITE);
        gotoxy(7,6+i);
	    cprintf("%i", Empleado[i].Carnet);
        gotoxy(14,6+i); /*Nombre */
        cprintf("%s", nombre[i]);
        gotoxy(30,6+i); /*Salario */
        cprintf("%d%c", Empleado[i].Salario,'$');
        gotoxy(43,6+i);
        cprintf("%i", Empleado[i].Horas_extra);
        gotoxy(50,6+i); /*Pago Horas */
        cprintf("%.2f%c", Empleado[i].Pago_Horas_extra,'$');
        gotoxy(65,6+i); /* Comisiones */ 
        cprintf("%d%c", Empleado[i].Comisiones,'$');
    }
getch();
system("cls");
Planilla2();
getch();
system("cls");
Planilla3();
textbackground(BLACK);
getch();
}

void Planilla2(){
    int x,i;

    system("cls");
    /*Fondo Pantalla*/
    for(x = 0; x < 78; x++){
        textcolor(BLUE);
        gotoxy(2+x,2);
        cprintf("%c",219);
        gotoxy(2+x,3);
        cprintf("%c",219);
        gotoxy(2+x,4);
        cprintf("%c",219);
        gotoxy(2+x,5);
        cprintf("%c",219);
        gotoxy(2+x,6);
        cprintf("%c",219);
        gotoxy(2+x,7);
        cprintf("%c",219);
        gotoxy(2+x,8);
        cprintf("%c",219);
        gotoxy(2+x,9);
        cprintf("%c",219);
        gotoxy(2+x,10);
        cprintf("%c",219);
        gotoxy(2+x,11);
        cprintf("%c",219);
        gotoxy(2+x,12);
        cprintf("%c",219);
        gotoxy(2+x,13);
        cprintf("%c",219);
        gotoxy(2+x,14);
        cprintf("%c",219);
        gotoxy(2+x,15);
        cprintf("%c",219);
        gotoxy(2+x,16);
        cprintf("%c",219);
        gotoxy(2+x,17);
        cprintf("%c",219);
        gotoxy(2+x,18);
        cprintf("%c",219);
        gotoxy(2+x,19);
        cprintf("%c",219);
        gotoxy(2+x,20);
        cprintf("%c",219);
        gotoxy(2+x,21);
        cprintf("%c",219);
        gotoxy(2+x,22);
        cprintf("%c",219);
        gotoxy(2+x,23);
        cprintf("%c",219);
        gotoxy(2+x,24);
        cprintf("%c",219);
    }
    for(x = 0; x < 74; x++){
        textcolor(CYAN);
        textbackground(BLUE);
        gotoxy(3,2);
        cprintf("%c", 201);
        gotoxy(4+x,2);
        cprintf("%c", 205);
        gotoxy(78,2);
		cprintf("%c", 187);

        gotoxy(3,24);
        cprintf("%c", 200);
        gotoxy(4+x,24);
        cprintf("%c", 205);
        gotoxy(78,24);
		cprintf("%c", 188);
    }
    for(x = 0; x < 21; x++){ /*Marco cyan*/
        textcolor(CYAN);
        textbackground(BLUE);
        gotoxy(3,3+x);
        cprintf("%c",186);
        gotoxy(78,3+x);
        cprintf("%c", 186);
    }
    for(x = 0; x < 21; x++){ /*Lineas intermedias*/
        gotoxy(12,3+x);
        cprintf("%c", 179);
        gotoxy(28,3+x);
		cprintf("%c", 179);
        gotoxy(40,3+x);
		cprintf("%c", 179);
        gotoxy(52,3+x);
		cprintf("%c", 179);
        gotoxy(64,3+x);
        cprintf("%c", 179);
    }
    for(x = 0; x <73; x++){ /*Linea horizontal*/
        gotoxy(4+x,5);
        cprintf("%c", 196);
    }
    textcolor(YELLOW);
    gotoxy(5,4);
    cprintf("Carnet");
    gotoxy(17,4);
    cprintf("Nombre");
    gotoxy(32,3);
    cprintf("Total");
    gotoxy(31,4);cprintf("Ingresos");
    gotoxy(44,4);
    cprintf("INSS");
    gotoxy(57,4);
    cprintf("IR");
    gotoxy(69,3);
    cprintf("Total");     
    gotoxy(66,4);cprintf("Deducciones");

    for(i = 0; i < Cantidad; i++)
       {
        Lavadodedinero(i);
        textcolor(WHITE);
        gotoxy(7,6+i);
	    cprintf("%i", Empleado[i].Carnet);
        gotoxy(14,6+i); /*Nombre */
        cprintf("%s", nombre[i]);
		gotoxy(29,6+i);
        cprintf("%.2f%c", Empleado[i].Total_Ingresos,'$');
        gotoxy(43,6+i);
        cprintf("%.2f%c", Empleado[i].INNS_Laboral,'$');
		gotoxy(53,6+i);
        cprintf("%.2f%c", Empleado[i].IR,'$');
        gotoxy(66,6+i); 
        cprintf("%.2f%c", Empleado[i].Deducciones,'$');
    }
}

void Planilla3(){
    int x,i;

    system("cls");
    /*Fondo Pantalla*/
    for(x = 0; x < 78; x++){
        textcolor(BLUE);
        gotoxy(2+x,2);
        cprintf("%c",219);
        gotoxy(2+x,3);
        cprintf("%c",219);
        gotoxy(2+x,4);
        cprintf("%c",219);
        gotoxy(2+x,5);
        cprintf("%c",219);
        gotoxy(2+x,6);
        cprintf("%c",219);
        gotoxy(2+x,7);
        cprintf("%c",219);
        gotoxy(2+x,8);
        cprintf("%c",219);
        gotoxy(2+x,9);
        cprintf("%c",219);
        gotoxy(2+x,10);
        cprintf("%c",219);
        gotoxy(2+x,11);
        cprintf("%c",219);
        gotoxy(2+x,12);
        cprintf("%c",219);
        gotoxy(2+x,13);
        cprintf("%c",219);
        gotoxy(2+x,14);
        cprintf("%c",219);
        gotoxy(2+x,15);
        cprintf("%c",219);
        gotoxy(2+x,16);
        cprintf("%c",219);
        gotoxy(2+x,17);
        cprintf("%c",219);
        gotoxy(2+x,18);
        cprintf("%c",219);
        gotoxy(2+x,19);
        cprintf("%c",219);
        gotoxy(2+x,20);
        cprintf("%c",219);
        gotoxy(2+x,21);
        cprintf("%c",219);
        gotoxy(2+x,22);
        cprintf("%c",219);
        gotoxy(2+x,23);
        cprintf("%c",219);
        gotoxy(2+x,24);
        cprintf("%c",219);
    }
    for(x = 0; x < 74; x++){
        textcolor(CYAN);
        textbackground(BLUE);
        gotoxy(3,2);
        cprintf("%c", 201);
        gotoxy(4+x,2);
        cprintf("%c", 205);
        gotoxy(78,2);
		cprintf("%c", 187);

        gotoxy(3,24);
        cprintf("%c", 200);
        gotoxy(4+x,24);
        cprintf("%c", 205);
        gotoxy(78,24);
		cprintf("%c", 188);
    }
    for(x = 0; x < 21; x++){ /*Marco cyan*/
        textcolor(CYAN);
        textbackground(BLUE);
        gotoxy(3,3+x);
        cprintf("%c",186);
        gotoxy(78,3+x);
        cprintf("%c", 186);
    }
    for(x = 0; x < 21; x++){ /*Lineas intermedias*/
        gotoxy(12,3+x);
        cprintf("%c", 179);
        gotoxy(28,3+x);
		cprintf("%c", 179);
        gotoxy(45,3+x);
		cprintf("%c", 179);
        gotoxy(60,3+x);
		cprintf("%c", 179);
        gotoxy(75,3+x);
        cprintf("%c", 179);
    }
    for(x = 0; x <73; x++){ /*Linea horizontal*/
        gotoxy(4+x,5);
        cprintf("%c", 196);
    }
   
    textcolor(YELLOW);
    gotoxy(5,4);
    cprintf("Carnet");
    gotoxy(17,4);
    cprintf("Nombre");
    gotoxy(33,3);
    cprintf("Salario");
    gotoxy(35,4);cprintf("Neto");
    gotoxy(51,3);
    cprintf("INSS");
    gotoxy(49,4);cprintf("Patronal");
    gotoxy(65,4);
    cprintf("INATEC");
    for(i = 0; i < Cantidad; i++)
    {
        Lavadodedinero(i);
        textcolor(WHITE);
        gotoxy(7,6+i);
	    cprintf("%i", Empleado[i].Carnet);
        gotoxy(14,6+i); /*Nombre */
        cprintf("%s", nombre[i]);
        gotoxy(34,6+i);
        cprintf("%.2f%c", Empleado[i].Neto,'$');
        gotoxy(48,6+i);
        cprintf(" %.2f%c",Empleado[i].INSSPatrol,'$');
        gotoxy(62,6+i);
        cprintf("%.2f%c",Empleado[i].INATEC,'$');
    }
}