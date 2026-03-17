
#include "Juego.h"
#include "Partida.h"
#include "Menu.h"
#include "Creditos.h"
#include "Opciones.h"
int main(int argc, char *argv[]){
	Juego J(new  Menu);
	J.Iniciar();
	return 0;
}
	
