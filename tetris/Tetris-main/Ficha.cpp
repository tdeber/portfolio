#include "Ficha.h"
#include <cstdlib>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <ctime>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include <SFML/System/Sleep.hpp>
using namespace std;

Ficha::Ficha() {
	m_texture.loadFromFile("Images/jstris1.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(0,0,30,30));
	m_texture2.loadFromFile("Images/board.png");
	m_cuadri.setTexture(m_texture2);
	m_cuadri.setTextureRect(sf::IntRect(1,2,30,30));
	
	m_color=m_sprite.getColor();
	
	
	Direccion=0;
	Fila=0;
	Columna=3;
	x.resize(7);
	for(int i=0;i<7;i++) { 
		x[i]=i;
	}
	for(int i=0;i<4;i++) { 
		for(int j=0;j<4;j++) { 
			matriz[i][j]=0;
		}
	}
	//genere una pieza vacia.
}
sf::Sprite Ficha::ver_sprite(){
	return m_sprite;
}
void Ficha::mod_fila(int i) {
	Fila=i;
}
void Ficha::Dibujar_siguiente_ficha(sf::RenderWindow &w) {
	
	for(int i=0;i<tam;i++) { 
		for(int j=0;j<tam;j++) { 
			if(matriz[i][j]!=0){
				m_sprite.setPosition((Columna + j)*30+460, (Fila+i)*30 + 100);
				w.draw(m_sprite);
			}else
				m_cuadri.setPosition((Columna+j)*30+460, (Fila+i)*30+100);
			w.draw(m_cuadri);
		}
	}
}
void Ficha::mod_columna(int i){
	Columna=i;
}
void Ficha::Dibujar_ficha_guardada(sf::RenderWindow &w){
	for(int i=0;i<tam;i++) { 
		for(int j=0;j<tam;j++) { 
			if(matriz[i][j]!=0){
				m_sprite.setPosition(j*30+35, i*30 + 100);
				w.draw(m_sprite);
			}else
				m_cuadri.setPosition(j*30+35, i*30+100);
			w.draw(m_cuadri);
		}
	}
}
void Ficha::Dibujar_pieza(sf::RenderWindow &w) {
	int var=200;
	int var2=-30;
	m_sprite.setColor(m_color);
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {
			if (matriz[i][j] != 0) {
				// Se dibuja un cuadrado de color en la posicion correspondiente
				m_sprite.setPosition((Columna + j) * 30+var, (Fila + i) * 30+var2);
				w.draw(m_sprite);
				
			}
		}
	}
	
}
sf::Color Ficha::color(){
	return m_color;
}
void Ficha::setColor(sf::Color x){
	m_color=x;
}
void Ficha::Regresar_movimiento(int i){
	Fila=Fila+i;
}
void Ficha::Bajar(){
	Fila++;
}

void Ficha::velocidad_de_caida(int i){
	//Se actualiza la velocidad conforme sube la dificultad
	Direccion=0;
	float tiempo_actual = clock.getElapsedTime().asSeconds();
	static const std::vector<float> tiempos_limite {
		1.0f, 0.9f, 0.8f, 0.7f, 0.6f, 0.56f, 0.5f, 0.46f,
			0.42f, 0.38f, 0.34f, 0.3f, 0.26f, 0.22f, 0.2f, 0.18f,
			0.16f, 0.14f, 0.12f, 0.1f
	};
	if (tiempo_actual > tiempos_limite.at(i-1)) {
		Bajar();
		clock.restart();
	}
}
vector<int> rellenar(vector<int>&x) {
	for(int i=0;i<7;i++) { 
		x[i]=i;
	}	
}

void eliminar(vector<int>& x, int &caso) {
	if(x[caso]==9){
		caso=rand()%7;
		eliminar(x,caso);
	}else{
		x[caso]=9;
	}
	int cont=0;
	for(int i=0;i<7;i++) { 
		if(x[i]==9){
			cont++;
		}
	}
	if (cont==7){
		rellenar(x);
	}
}
void Ficha::NuevaPieza() {
	Fila=0;
	Columna=3;
	Estado=0;
	caso= rand()%7;
	eliminar(x,caso);
	//Genero una matriz auxiliar
	for(int i=0;i<4;i++) { 
		for(int j=0;j<4;j++) { 
			matriz[i][j]=0;
		}
	}
	//Se genera un caso al azar para generar una pieza. 
	//Se le asigna un "Color" para definir que ficha es
	switch(caso){
	case 0:
		// figura del cuadrado
		// 0 0 0 0
		// 1 1 0 0
		// 1 1 0 0
		// 0 0 0 0 
		// Cambiaremos el 0 por el uno;
		matriz[1][0]=matriz[2][0]=matriz[1][1]=matriz[2][1]=1;
		m_sprite.setTextureRect(sf::IntRect(0,0,30,30));
		Color=1;
		break;
	case 1:
		// Figura de L
		// 1 0 0 0
		// 1 0 0 0
		// 1 1 0 0
		// 0 0 0 0 
		matriz[0][0]=matriz[1][0]=matriz[2][0]=matriz[2][1]=2;
		m_sprite.setTextureRect(sf::IntRect(30,0,30,30));
		Color=2;
		break;
	case 2:
		// Figura de J
		// 0 1 0 0
		// 0 1 0 0
		// 1 1 0 0
		// 0 0 0 0
		matriz [2][0]=matriz[0][1]=matriz[1][1]=matriz[2][1]=3;
		m_sprite.setTextureRect(sf::IntRect(60,0,30,30));
		Color=3;
		break;
	case 3:
		// Figura de T
		// 0 1 0 0
		// 1 1 1 0
		// 0 0 0 0
		// 0 0 0 0 
		matriz[0][1]=matriz[1][0]=matriz[1][1]=matriz[1][2]=4;
		m_sprite.setTextureRect(sf::IntRect(90,0,30,30));
		Color=4;
		break;
	case 4:
		// Figura de I
		// 0 0 0 0
		// 1 1 1 1
		// 0 0 0 0
		// 0 0 0 0
		matriz[1][0]=matriz[1][1]=matriz[1][2]=matriz[1][3]=5;
		m_sprite.setTextureRect(sf::IntRect(120,0,30,30));
		Color=5;
		break;
	case 5:
		//Figura de Z
		// 1 0 0 0
		// 1 1 0 0
		// 0 1 0 0
		// 0 0 0 0
		//		matriz[0][1]=matriz[1][1]=matriz[1][2]=matriz[2][2]=7;
		matriz[0][0]=matriz[1][0]=matriz[1][1]=matriz[2][1]=6;
		m_sprite.setTextureRect(sf::IntRect(150,0,30,30));
		Color=6;
		break;
	case 6: 
		// Figura de Z invertida
		// 0 1 0 0
		// 1 1 0 0
		// 1 0 0 0
		// 0 0 0 0
		matriz[0][1]=matriz[1][1]=matriz[1][0]=matriz[2][0]=7;
		m_sprite.setTextureRect(sf::IntRect(180,0,30,30));
		Color=7;
	}
	
}
//
int Ficha::ver_ficha(int i,int j){	
	return matriz[i][j]; 
}
void Ficha::ver_matriz(){
	for(int j=0;j<4;j++) {
		for(int i=0;i<4;i++) {
			cout<<matriz[j][i]<<" ";
		}
		cout<<endl;}
}
void Ficha::Mover_Izquierda(){
	Direccion=2; // 2 para mov izquierda , 1 para mov derecha, 0 para fila
	Columna--;
}
void Ficha::Mover_Derecha(){
	Direccion=1;
	Columna++;	
}
void Ficha::Mover_Abajo(){
	Direccion=0;
	Fila++;
	
}
void Ficha::Rotar(){
	//Se genera una ficha auxiliar rotada, se verifica que no se salga de los limites,
	//y no se superponga con otra pieza.
	RotarP();
	bool es_valido = true;
	for(int i=0;i<tam;i++) { 
		for(int j=0;j<tam;j++) { 
			if(temp[i][j]!=0){
				if(Fila + i < 0 or Fila + i >= 20){
					es_valido=false;
				}
				if(Columna+j>=10){
					Columna--;
					es_valido=true;
				}
			}
			
		}
	}
	if (es_valido) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matriz[i][j] = temp[i][j];
			}
		}
	}
}
int Ficha::ver_direccion(){
	return Direccion;
}
int Ficha::ver_columna(){
	return Columna;
}
int Ficha::ver_fila(){
	return Fila;
}
int Ficha::ver_color(){
	return Color;
}
//
int Ficha::Regresar_columna(int i) {
	Columna=Columna+i;
	
}
int Ficha::anchoPieza() {
	//La utilizo para verificar que la pieza no salga del tablero.
	int ancho = 0;
	for (int i = 0; i < 4; i++) {
		bool columnaVacia = true; // verificar si la columna esta vacia
		for (int j = 0; j < 4; j++) {
			if (matriz[j][i] != 0) {
				columnaVacia = false;
				break; // salir del bucle si se encuentra un bloque en la columna
			}
		}
		if (!columnaVacia) { // si la columna no esta vacia aumentar el ancho
			ancho++;
		}
	}
	return ancho;
}
void Ficha::RotarP(){
	for(int i=0;i<4;i++) { 
		for(int j=0;j<4;j++) { 
			temp[i][j]=0;
		}
	}
	//La ficha posee 4 estados de rotacion.
	//Cada vez que se llama a la funcion el estado aumenta para asi seleccionar la nueva posicion de la ficha
	//Cada ficha tiene rotacion distinta
	Estado++;
	if(Estado>3){
		Estado=0;
	}
	switch(Color){
	case 1:
		// figura del cuadrado
		// 0 0 0 0
		// 1 1 0 0
		// 1 1 0 0
		// 0 0 0 0 
		temp[1][0]=temp[1][1]=temp[2][0]=temp[2][1]=Color;
		
		break;
	case 2:
		// Figura de L
		// 1 0 0 0
		// 1 0 0 0
		// 1 1 0 0
		// 0 0 0 0 
		switch(Estado){
		case 0:
			// 1 0 0 0
			// 1 0 0 0
			// 1 1 0 0
			// 0 0 0 0 
			
			temp[0][0]=temp[1][0]=temp[2][0]=temp[2][1]=Color;
			break;
		case 1:
			// 0 0 0 0
			// 0 0 1 0
			// 1 1 1 0
			// 0 0 0 0 
			
			temp[1][2]=temp[2][0]=temp[2][1]=temp[2][2]=Color;
			break;
		case 2:
			// 0 0 0 0
			// 1 1 0 0
			// 0 1 0 0
			// 0 1 0 0 
			
			temp[1][0]=temp[1][1]=temp[2][1]=temp[3][1]=Color;
			break;
		case 3:
			// 0 0 0 0
			// 1 1 1 0
			// 1 0 0 0
			// 0 0 0 0 
			
			temp[1][0]=temp[2][0]=temp[1][1]=temp[1][2]=Color;
			break;
		}
		break;
	case 3:
		// Figura de J
		// 0 1 0 0
		// 0 1 0 0
		// 1 1 0 0
		// 0 0 0 0
		switch(Estado){
		case 0:
			// 0 1 0 0
			// 0 1 0 0
			// 1 1 0 0
			// 0 0 0 0 
			temp[2][0]=temp[0][1]=temp[1][1]=temp[2][1]=Color;
			break;
		case 1:
			// 0 0 0 0
			// 1 1 1 0
			// 0 0 1 0
			// 0 0 0 0 
			temp[1][0]=temp[1][1]=temp[1][2]=temp[2][2]=Color;
			break;
		case 2:
			// 0 0 0 0
			// 1 1 0 0
			// 1 0 0 0
			// 1 0 0 0 
			temp[1][0]=temp[1][1]=temp[2][0]=temp[3][0]=Color;
			break;
		case 3:
			// 0 0 0 0
			// 1 0 0 0
			// 1 1 1 0
			// 0 0 0 0 
			temp[1][0]=temp[2][0]=temp[2][1]=temp[2][2]=Color;
			break;
		}
		break;
	case 4:
		// Figura de T
		// 0 1 0 0
		// 1 1 1 0
		// 0 0 0 0
		// 0 0 0 0 
		switch(Estado){
		case 0:
			// 0 1 0 0
			// 1 1 1 0
			// 0 0 0 0
			// 0 0 0 0 
			temp[0][1]=temp[1][0]=temp[1][1]=temp[1][2]=Color;
			break;
		case 1:
			// 0 1 0 0
			// 1 1 0 0
			// 0 1 0 0
			// 0 0 0 0 
			temp[0][1]=temp[1][0]=temp[1][1]=temp[2][1]=Color;
			break;
		case 2:
			// 0 0 0 0
			// 1 1 1 0
			// 0 1 0 0
			// 0 0 0 0 
			temp[1][0]=temp[1][1]=temp[1][2]=temp[2][1]=Color;
			break;
		case 3:
			// 1 0 0 0
			// 1 1 0 0
			// 1 0 0 0
			// 0 0 0 0 
			temp[0][0]=temp[1][0]=temp[2][0]=temp[1][1]=Color;
			break;
		}
		
		break;
	case 5:
		// Figura de I
		// 0 0 0 0
		// 1 1 1 1
		// 0 0 0 0
		// 0 0 0 0
		switch(Estado){
		case 0:
			// 0 0 0 0
			// 1 1 1 1
			// 0 0 0 0
			// 0 0 0 0 
			temp[1][0]=temp[1][1]=temp[1][2]=temp[1][3]=Color;
			break;
		case 1:
			// 1 0 0 0
			// 1 0 0 0
			// 1 0 0 0
			// 1 0 0 0 
			temp[0][0]=temp[1][0]=temp[2][0]=temp[3][0]=Color;
			break;
		case 2:
			// 0 0 0 0
			// 0 0 0 0
			// 1 1 1 1
			// 0 0 0 0 
			temp[2][0]=temp[2][1]=temp[2][2]=temp[2][3]=Color;
			break;
		case 3:
			// 1 0 0 0
			// 1 0 0 0
			// 1 0 0 0
			// 1 0 0 0 
			temp[0][0]=temp[1][0]=temp[2][0]=temp[3][0]=Color;
			break;
		}
		
		break;
	case 6:
		//Figura de Z
		// 1 0 0 0
		// 1 1 0 0
		// 0 1 0 0
		// 0 0 0 0
		switch(Estado){
		case 0:
			// 1 0 0 0
			// 1 1 0 0
			// 0 1 0 0
			// 0 0 0 0
			temp[0][0]=temp[1][0]=temp[1][1]=temp[2][1]=Color;
			break;
		case 1:
			// 0 1 1 0
			// 1 1 0 0
			// 0 0 0 0
			// 0 0 0 0 
			temp[0][1]=temp[0][2]=temp[1][0]=temp[1][1]=Color;
			break;
		case 2:
			// 1 0 0 0
			// 1 1 0 0
			// 0 1 0 0
			// 0 0 0 0 
			temp[0][0]=temp[1][0]=temp[2][1]=temp[1][1]=Color;
			break;
		case 3:
			// 0 1 1 0
			// 1 1 0 0
			// 0 0 0 0
			// 0 0 0 0 
			temp[0][1]=temp[0][2]=temp[1][0]=temp[1][1]=Color;
			break;
		}
		
		break;
	case 7: 
		// Figura de Z invertida
		// 0 1 0 0
		// 1 1 0 0
		// 1 0 0 0
		// 0 0 0 0
		switch(Estado){
		case 0:
			// 0 1 0 0
			// 1 1 0 0
			// 1 0 0 0
			// 0 0 0 0 
			temp[0][1]=temp[1][0]=temp[1][1]=temp[2][0]=Color;
			break;
		case 1:
			// 1 1 0 0
			// 0 1 1 0
			// 0 0 0 0
			// 0 0 0 0 
			temp[0][0]=temp[0][1]=temp[1][1]=temp[1][2]=Color;
			break;
		case 2:
			// 0 1 0 0
			// 1 1 0 0
			// 1 0 0 0
			// 0 0 0 0 
			temp[0][1]=temp[1][0]=temp[1][1]=temp[2][0]=Color;
			break;
		case 3:
			// 1 1 0 0
			// 0 1 1 0
			// 0 0 0 0
			// 0 0 0 0 
			temp[0][0]=temp[0][1]=temp[1][1]=temp[1][2]=Color;
			break;
		}
		
	}
	
}
