
#include <tupapa.h>
#include <STRING.H>
#include <CTYPE.H>                                                                     
#include <stdbool.h>


#define ENTER 13
#define ESPACIO 32
#define ARRIBA 72
#define ABAJO 80

void prefijos (void);;  
void credenciales(void);
void agregaar(void);
void buscar(void);
void resulbusqueda(void);
void actualizar(void);
void eliminar (void);
void menu1(int);
void presentacion(void);
void mostrar(void);
void Inicializador();
void SeleccionPantalla(int);
void acsii(void);
void planilla(void);
void planilla1(void);
char tecla;

void main () 
{
    int seleccion = 1;
 
    prefijos();
	credenciales(); 
    Inicializador();
    system("cls");
    reset:
	system("cls");
    do
    {
       menu1(seleccion);

		tecla = getch();
		if ((tecla == 80)| (tecla == 72) | (tecla == 13)){
        	switch (tecla){
        	case ABAJO:
				seleccion++;
				if(seleccion >7){
					seleccion = 1;
				}
            	break;
        	case ARRIBA:
				seleccion--;
				if(seleccion < 1){
					seleccion = 7;
				}
            	break;
			case 13:
				SeleccionPantalla(seleccion);
				goto reset;
        	default:
            	break;
        	}
    	}

    } while(true);
}


void SeleccionPantalla(int seleccion)
{
	switch (seleccion)
    {
	case 1:
		agregaar();
		break;
	case 2:
		actualizar();
		break;
	case 3:
		buscar();
        resulbusqueda();
        getch();
		break;
	case 4:
		eliminar();
		break;
	case 5:
		planilla1();
		break;
	case 6:
        acsii();
        exit(EXIT_SUCCESS);
		break;
	case 7:
		presentacion();
        getch();
		break;
	default:
		break;
	}
}
void menu1(int seleccion)
{
		switch (seleccion)
        {
		case 1:
            textcolor(YELLOW);
            gotoxy(24,2); cprintf("CONTROL DE ESCLAVISMO DEL PALI");
            textcolor(RED); gotoxy(34,4); cprintf("(1) ");
            textcolor(GREEN); gotoxy(36,4); cprintf(" AGREGAR ESCLAVO");
            textcolor(YELLOW); gotoxy(34,6); cprintf("(2) ");
            textcolor(WHITE); gotoxy(36,6); cprintf(" ACTUALIZAR");
            textcolor(YELLOW); gotoxy(34,8); cprintf("(3) ");
            textcolor(WHITE); gotoxy(36,8); cprintf(" BUSCAR");
            textcolor(YELLOW); gotoxy(34,10); cprintf("(4) ");
            textcolor(WHITE); gotoxy(36,10); cprintf(" LIBERAR");
            textcolor(YELLOW); gotoxy(34,12); cprintf("(5) ");
            textcolor(WHITE); gotoxy(36,12); cprintf(" MOSTRAR NUMERO DE ESCLAVOS");
            textcolor(YELLOW); gotoxy(34,14); cprintf("(6) ");
            textcolor(WHITE); gotoxy(36,14); cprintf(" DENUNCIAR AL PALI");
            textcolor(YELLOW); gotoxy(34,16); cprintf("(7) ");
            textcolor(WHITE); gotoxy(36,16); cprintf(" CAPATACES");
			break;
		case 2:
			textcolor(YELLOW);
            gotoxy(24,2); cprintf("CONTROL DE ESCLAVISMO DEL PALI");
            textcolor(YELLOW); gotoxy(34,4); cprintf("(1) ");
            textcolor(WHITE); gotoxy(36,4); cprintf(" AGREGAR ESCLAVO");
            textcolor(RED); gotoxy(34,6); cprintf("(2) ");
            textcolor(GREEN); gotoxy(36,6); cprintf(" ACTUALIZAR");
            textcolor(YELLOW); gotoxy(34,8); cprintf("(3) ");
            textcolor(WHITE); gotoxy(36,8); cprintf(" BUSCAR");
            textcolor(YELLOW); gotoxy(34,10); cprintf("(4) ");
            textcolor(WHITE); gotoxy(36,10); cprintf(" LIBERAR");
            textcolor(YELLOW); gotoxy(34,12); cprintf("(5) ");
            textcolor(WHITE); gotoxy(36,12); cprintf(" MOSTRAR NUMERO DE ESCLAVOS");
            textcolor(YELLOW); gotoxy(34,14); cprintf("(6) ");
            textcolor(WHITE); gotoxy(36,14); cprintf(" DENUNCIAR AL PALI");
            textcolor(YELLOW); gotoxy(34,16); cprintf("(7) ");
            textcolor(WHITE); gotoxy(36,16); cprintf(" CAPATACES");
			break;
		case 3:
		  textcolor(YELLOW);
            gotoxy(24,2); cprintf("CONTROL DE ESCLAVISMO DEL PALI");
            textcolor(YELLOW); gotoxy(34,4); cprintf("(1) ");
            textcolor(WHITE); gotoxy(36,4); cprintf(" AGREGAR ESCLAVO");
            textcolor(YELLOW); gotoxy(34,6); cprintf("(2) ");
            textcolor(WHITE); gotoxy(36,6); cprintf(" ACTUALIZAR");
            textcolor(RED); gotoxy(34,8); cprintf("(3) ");
            textcolor(GREEN); gotoxy(36,8); cprintf(" BUSCAR");
            textcolor(YELLOW); gotoxy(34,10); cprintf("(4) ");
            textcolor(WHITE); gotoxy(36,10); cprintf(" LIBERAR");
            textcolor(YELLOW); gotoxy(34,12); cprintf("(5) ");
            textcolor(WHITE); gotoxy(36,12); cprintf(" MOSTRAR NUMERO DE ESCLAVOS");
            textcolor(YELLOW); gotoxy(34,14); cprintf("(6) ");
            textcolor(WHITE); gotoxy(36,14); cprintf(" DENUNCIAR AL PALI");
            textcolor(YELLOW); gotoxy(34,16); cprintf("(7) ");
            textcolor(WHITE); gotoxy(36,16); cprintf(" CAPATACES");
			break;
		case 4:
	        textcolor(YELLOW);
            gotoxy(24,2); cprintf("CONTROL DE ESCLAVISMO DEL PALI");
            textcolor(YELLOW); gotoxy(34,4); cprintf("(1) ");
            textcolor(WHITE); gotoxy(36,4); cprintf(" AGREGAR ESCLAVO");
            textcolor(YELLOW); gotoxy(34,6); cprintf("(2) ");
            textcolor(WHITE); gotoxy(36,6); cprintf(" ACTUALIZAR");
            textcolor(YELLOW); gotoxy(34,8); cprintf("(3) ");
            textcolor(WHITE); gotoxy(36,8); cprintf(" BUSCAR");
            textcolor(RED); gotoxy(34,10); cprintf("(4) ");
            textcolor(GREEN); gotoxy(36,10); cprintf(" LIBERAR");
            textcolor(YELLOW); gotoxy(34,12); cprintf("(5) ");
            textcolor(WHITE); gotoxy(36,12); cprintf(" MOSTRAR NUMERO DE ESCLAVOS");
            textcolor(YELLOW); gotoxy(34,14); cprintf("(6) ");
            textcolor(WHITE); gotoxy(36,14); cprintf(" DENUNCIAR AL PALI");
            textcolor(YELLOW); gotoxy(34,16); cprintf("(7) ");
            textcolor(WHITE); gotoxy(36,16); cprintf(" CAPATACES");
			break;
		case 5:
			textcolor(YELLOW);
            gotoxy(24,2); cprintf("CONTROL DE ESCLAVISMO DEL PALI");
            textcolor(YELLOW); gotoxy(34,4); cprintf("(1) ");
            textcolor(WHITE); gotoxy(36,4); cprintf(" AGREGAR ESCLAVO");
            textcolor(YELLOW); gotoxy(34,6); cprintf("(2) ");
            textcolor(WHITE); gotoxy(36,6); cprintf(" ACTUALIZAR");
            textcolor(YELLOW); gotoxy(34,8); cprintf("(3) ");
            textcolor(WHITE); gotoxy(36,8); cprintf(" BUSCAR");
            textcolor(YELLOW); gotoxy(34,10); cprintf("(4) ");
            textcolor(WHITE); gotoxy(36,10); cprintf(" LIBERAR");
            textcolor(RED); gotoxy(34,12); cprintf("(5) ");
            textcolor(GREEN); gotoxy(36,12); cprintf(" MOSTRAR NUMERO DE ESCLAVOS");
            textcolor(YELLOW); gotoxy(34,14); cprintf("(6) ");
            textcolor(WHITE); gotoxy(36,14); cprintf(" DENUNCIAR AL PALI");
            textcolor(YELLOW); gotoxy(34,16); cprintf("(7) ");
            textcolor(WHITE); gotoxy(36,16); cprintf(" CAPATACES");
			break;
		case 6:
			textcolor(YELLOW);
            gotoxy(24,2); cprintf("CONTROL DE ESCLAVISMO DEL PALI");
            textcolor(YELLOW); gotoxy(34,4); cprintf("(1) ");
            textcolor(WHITE); gotoxy(36,4); cprintf(" AGREGAR ESCLAVO");
            textcolor(YELLOW); gotoxy(34,6); cprintf("(2) ");
            textcolor(WHITE); gotoxy(36,6); cprintf(" ACTUALIZAR");
            textcolor(YELLOW); gotoxy(34,8); cprintf("(3) ");
            textcolor(WHITE); gotoxy(36,8); cprintf(" BUSCAR");
            textcolor(YELLOW); gotoxy(34,10); cprintf("(4) ");
            textcolor(WHITE); gotoxy(36,10); cprintf(" LIBERAR");
            textcolor(YELLOW); gotoxy(34,12); cprintf("(5) ");
            textcolor(WHITE); gotoxy(36,12); cprintf(" MOSTRAR NUMERO DE ESCLAVOS");
            textcolor(RED); gotoxy(34,14); cprintf("(6) ");
            textcolor(GREEN); gotoxy(36,14); cprintf(" DENUNCIAR AL PALI");
            textcolor(YELLOW); gotoxy(34,16); cprintf("(7) ");
            textcolor(WHITE); gotoxy(36,16); cprintf(" CAPATACES");
			break;
		case 7:
		    textcolor(YELLOW);
            gotoxy(24,2); cprintf("CONTROL DE ESCLAVISMO DEL PALI");
            textcolor(YELLOW); gotoxy(34,4); cprintf("(1) ");
            textcolor(WHITE); gotoxy(36,4); cprintf(" AGREGAR ESCLAVO");
            textcolor(YELLOW); gotoxy(34,6); cprintf("(2) ");
            textcolor(WHITE); gotoxy(36,6); cprintf(" ACTUALIZAR");
            textcolor(YELLOW); gotoxy(34,8); cprintf("(3) ");
            textcolor(WHITE); gotoxy(36,8); cprintf(" BUSCAR");
            textcolor(YELLOW); gotoxy(34,10); cprintf("(4) ");
            textcolor(WHITE); gotoxy(36,10); cprintf(" LIBERAR");
            textcolor(YELLOW); gotoxy(34,12); cprintf("(5) ");
            textcolor(WHITE); gotoxy(36,12); cprintf(" MOSTRAR NUMERO DE ESCLAVOS");
            textcolor(YELLOW); gotoxy(34,14); cprintf("(6) ");
            textcolor(WHITE); gotoxy(36,14); cprintf(" DENUNCIAR AL PALI");
            textcolor(RED); gotoxy(34,16); cprintf("(7) ");
            textcolor(GREEN); gotoxy(36,16); cprintf(" CAPATACES");
			break;
		default:
			break;
		}
}        