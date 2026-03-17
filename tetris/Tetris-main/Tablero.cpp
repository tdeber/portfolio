#include "Tablero.h"
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Sleep.hpp>
using namespace std;
Tablero::Tablero() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			tablero[i][j] = 0;
		}
	}
	colorOriginal=sf::Color(255,255,255,255);
	puntos=0;
	nivel=1;
	lineas_necesarias=10;
	lineas=0;	// cantidad de lineas para pasar de nivel
	Ya_cambiada=0;
	Se_puede=true; //variable para saber si puedo cambiar de pieza
	mover=false;
	colocada=false;
	m_fuente.loadFromFile("Fuentes/tetris.ttf");
	m_level.setFont(m_fuente);
	m_level.setString("Nivel");
	m_level.setCharacterSize(20);
	m_level.setPosition(100,385);
	m_level.setFillColor({0,0,0});
	
	m_numero_level.setFont(m_fuente);
	m_numero_level.setString(std::to_string(nivel));
	m_numero_level.setCharacterSize(20);
	m_numero_level.setPosition(125,420);
	
	
	m_score.setFont(m_fuente);
	m_score.setString("Puntos");
	m_score.setCharacterSize(20);
	m_score.setPosition(80,503);
	m_score.setFillColor({0,0,0});
	
	m_hold.setFont(m_fuente);
	m_hold.setString("Hold");
	m_hold.setCharacterSize(20);
	m_hold.setPosition(80,55);
	
	m_puntos.setFont(m_fuente);
	m_puntos.setString(std::to_string(puntos));
	m_puntos.setCharacterSize(20);
	m_puntos.setPosition(110,540);
	
	m_next_piece.setFont(m_fuente);
	m_next_piece.setString("Next Piece");
	m_next_piece.setCharacterSize(20);
	m_next_piece.setPosition(540,50);
	
	m_proyec.loadFromFile("Images/ghost.png");
	m_sprite_proyec.setTexture(m_proyec);
	aux.loadFromFile("Images/jstris1.png");
	m_aux.setTexture(aux);
	cuadricula.loadFromFile("Images/board.png");
	m_cuadricula.setTexture(cuadricula);
	
	sf::RectangleShape Efecto1 (sf::Vector2f(30,30));
	Efecto=Efecto1;
	
	m_cuadricula.setTextureRect(sf::IntRect(30,2,30,30));
	sf::RectangleShape Barras_laterales_3(sf::Vector2f(10,600)); /*Creado de barras laterales del tablero con 4 rectangleshape,de puntos y nivel*/
	Barras_laterales_3.setPosition(190,30);
	Barras_laterales_1=Barras_laterales_3;
	
	sf::RectangleShape Barra_verticales_3(sf::Vector2f(320,10));
	Barra_verticales_3.setPosition(190,20);
	Barra_verticales_1=Barra_verticales_3;
	
	sf::RectangleShape Barra_verticales_4(sf::Vector2f(320,10));
	sf::RectangleShape Barra_laterales_4(sf::Vector2f(10,610));
	Barra_verticales_4.setPosition(190,630);
	Barra_laterales_4.setPosition(500,25);
	Barras_laterales_2=Barra_laterales_4;
	Barra_verticales_2=Barra_verticales_4;
	
	sf::RectangleShape Barra_de_level_aux(sf::Vector2f(120,30));
	Barra_de_level_aux.setPosition(80,380);
	Barra_de_level=Barra_de_level_aux;
	
	sf::RectangleShape Barra_de_puntos_aux(sf::Vector2f(150,30));
	Barra_de_puntos_aux.setPosition(50,500);
	Barra_de_puntos=Barra_de_puntos_aux;
	
	sf::RectangleShape Barra_next_pieza5(sf::Vector2f(126,3));
	Barra_next_pieza5.setPosition(547,98);
	Barra_next_pieza1=Barra_next_pieza5;
	
	sf::RectangleShape Barra_next_pieza6(sf::Vector2f(126,3));
	Barra_next_pieza6.setPosition(547,220);
	Barra_next_pieza2=Barra_next_pieza6;
	
	sf::RectangleShape Barra_next_pieza7(sf::Vector2f(3,120));
	Barra_next_pieza7.setPosition(547,100);
	Barra_next_pieza3=Barra_next_pieza7;
	
	sf::RectangleShape Barra_next_pieza_8 (sf::Vector2f(3,120));
	Barra_next_pieza_8.setPosition(670,100);
	Barra_next_pieza4=Barra_next_pieza_8;
	
	sf::RectangleShape Barra_ficha_hold5 (sf::Vector2f(3,122));
	Barra_ficha_hold5.setPosition(32,97);
	Barras_hold_pieza1=Barra_ficha_hold5;
	
	sf::RectangleShape Barra_ficha_hold6 (sf::Vector2f(3,122));
	Barra_ficha_hold6.setPosition(155,97);
	Barras_hold_pieza2=Barra_ficha_hold6;
	
	sf::RectangleShape Barra_ficha_hold7 (sf::Vector2f(126,3));
	Barra_ficha_hold7.setPosition(32,219);
	Barras_hold_pieza3=Barra_ficha_hold7;
	
	sf::RectangleShape Barra_ficha_hold8 (sf::Vector2f(126,3));
	Barra_ficha_hold8.setPosition(32,97);
	Barras_hold_pieza4=Barra_ficha_hold8;
	
	sf::RectangleShape Barra_superior1 (sf::Vector2f(300,20));
	Barra_superior1.setPosition(200,0);
	Barra_superior1.setFillColor(sf::Color::Black);
	Barra_superior=Barra_superior1;
	
	
	sf::RectangleShape Linea_completada1(sf::Vector2f(300,10));
	Linea_completada1.setPosition(200,200);
	Linea_Completada=Linea_completada1;
	
	
	sonido_mover.loadFromFile("Efectos/move.ogg");
	m_sonido_mover.setBuffer(sonido_mover);
	
	
	sonido_rotar.loadFromFile("Efectos/rotate.ogg");
	m_sonido_rotar.setBuffer(sonido_rotar);
	
	
	sonido_espacio.loadFromFile( "Efectos/harddrop.ogg");
	m_sonido_espacio.setBuffer(sonido_espacio);
	
	
	sonido_linea.loadFromFile ("Efectos/clearline.ogg");
	m_sonido_linea.setBuffer(sonido_linea);
	
	
	sonido_sube_nivel.loadFromFile("Efectos/levelup.ogg");
	m_sonido_sube_nivel.setBuffer(sonido_sube_nivel);
	
	
	sonido_level_5.loadFromFile("Efectos/level5.ogg");
	m_sonido_level_5.setBuffer(sonido_level_5);
	
	
	sonido_level_10.loadFromFile("Efectos/level10.ogg");
	m_sonido_level_10.setBuffer(sonido_level_10);
	
	
	sonido_level_15.loadFromFile("Efectos/level15.ogg");
	m_sonido_level_15.setBuffer(sonido_level_15);
	
	
	
	sonido_linea_3.loadFromFile("Efectos/clearline3.ogg");
	m_sonido_linea_3.setBuffer(sonido_linea_3);
	
	
	sonido_linea_4.loadFromFile("Efectos/clearline4.ogg");
	m_sonido_linea_4.setBuffer(sonido_linea_4);
	
	
	ladrillos.loadFromFile("Efectos/Ladrillos.ogg");
	m_ladrillos.setBuffer(ladrillos);
	
	
	cambio1.loadFromFile("Efectos/hold.ogg");
	m_cambio1.setBuffer(cambio1);
	
}

int Tablero::ver_nivel(){
	return nivel;
}
void Tablero::calibrado_sonido_efectos(float volumen_efectos){
	//Actualizar el volumen al ser modificados en el menu
	m_ladrillos.setVolume(volumen_efectos);
	m_cambio1.setVolume(volumen_efectos);
	m_sonido_level_15.setVolume(volumen_efectos);
	m_sonido_linea_3.setVolume(volumen_efectos);
	m_sonido_sube_nivel.setVolume(volumen_efectos);
	m_sonido_espacio.setVolume(volumen_efectos);
	m_sonido_linea.setVolume(volumen_efectos);
	m_sonido_rotar.setVolume(volumen_efectos);
	m_sonido_level_5.setVolume(volumen_efectos);
	m_sonido_linea_4.setVolume(volumen_efectos);
	m_sonido_level_10.setVolume(volumen_efectos);
	m_sonido_mover.setVolume(volumen_efectos);
}
void Tablero::cambio(Ficha &ficha,Ficha &ficha_next, Ficha &hold_ficha){
	//Se utiliza para intercambiar las piezas del hold de next pieza y de pieza actual.
	//Se utiliza una variable ya cambiada para ver en que caso esta y otra variable Se_puede para vericar si el jugador ya cambio la pieza.
	float Tiempo_Anterior=m_reloj.getElapsedTime().asSeconds();
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::C)) and Ya_cambiada==0 and Tiempo_Anterior>0.15){
		Ya_cambiada=1;
		intercambio_de_ficha(ficha,ficha_next,hold_ficha);
		Se_puede=false;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::C)) and Ya_cambiada==1 and Tiempo_Anterior>0.15 and Se_puede==true){
		intercambio_de_ficha(hold_ficha,ficha);
		Se_puede=false;
		Ya_cambiada=2;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::C)) and Ya_cambiada==2 and Tiempo_Anterior>0.15 and Se_puede==true){
		intercambio_de_ficha(ficha,hold_ficha);
		Se_puede=false;
		Ya_cambiada=1;
	}
	
}
void Tablero::intercambio_de_ficha(Ficha &ficha,Ficha &hold_ficha){
	ficha.mod_fila(0);
	ficha.mod_columna(3);
	Ficha aux=ficha;
	ficha=hold_ficha;
	hold_ficha=aux;
	ficha.mod_fila(0);
	ficha.mod_columna(3);
	m_cambio1.play();
	
}
void Tablero::intercambio_de_ficha(Ficha &ficha, Ficha &next_ficha, Ficha &hold_ficha){
	hold_ficha=ficha;
	ficha=next_ficha;
	next_ficha.NuevaPieza();
	hold_ficha.mod_fila(0);
	hold_ficha.mod_columna(3);
	m_cambio1.play();
	
}
void Tablero::efecto_movimiento (sf::RenderWindow &w, Ficha &ficha){
	float tiempo=m_reloj.getElapsedTime().asSeconds();
	if (vuelta==1 and tiempo>0.1){
		ficha.setColor(colorOriginal);
		w.display();
		vuelta=0;
	}
	if (mover){
	sf::Color coloroscuro = sf::Color(ficha.color().r, ficha.color().g, ficha.color().b, 128);// Crea un nuevo color con un valor alpha más bajo
	ficha.setColor(coloroscuro);
	w.display();
	vuelta=1;
	
	}
}


void Tablero::efecto_barra(sf::RenderWindow &w,Ficha &ficha, Ficha &next_ficha){
	
	if (mover_espacio()) {
		sf::Vector2i pos_actual=w.getPosition();
		w.setPosition(sf::Vector2i(pos_actual.x,pos_actual.y+5)); /*puesto aca para que se pueda mover la ventana*/
		sf::sleep(sf::milliseconds(50)); 
		w.setPosition(sf::Vector2i(pos_actual.x,pos_actual.y));
		funcion_espacio(ficha);
		ficha.NuevaPieza();
		ficha=next_ficha;
		
	}
	
	
}

void Tablero::funcion_espacio(Ficha &ficha) {
	//Mientras la pieza no colisione con el fondo del tablero que siga bajando.
	//Cuando colisiona se fija la ficha
	while (!colisionar_fondo(ficha)){
		if(colisionar_espacio(ficha)){
			break;
		}else{
			ficha.Bajar();
		}
		
	}
	agregar_ficha(ficha);
}

void Tablero::iniciar_Interfaz(sf::RenderWindow &w) {
	
	w.draw(Barra_verticales_1);
	w.draw(Barra_verticales_2);
	w.draw(Barra_de_level);
	w.draw(m_hold);
	w.draw(m_next_piece);
	w.draw(m_level);
	w.draw(Barras_laterales_1);
	w.draw(Barra_de_puntos);
	m_puntos.setString(std::to_string(puntos));
	w.draw(m_score);
	w.draw(Barras_laterales_2);
	w.draw(m_puntos);
	m_numero_level.setString(std::to_string(nivel));
	w.draw(m_numero_level);
	w.draw(Barra_next_pieza1);
	w.draw(Barra_next_pieza2);
	w.draw(Barra_next_pieza3);
	w.draw(Barra_next_pieza4);
	w.draw(Barras_hold_pieza1);
	w.draw(Barras_hold_pieza2);
	w.draw(Barras_hold_pieza3);
	w.draw(Barras_hold_pieza4);
	w.draw(Barra_superior);
	
	
}
void Tablero::efecto_colocacion(Ficha &ficha,sf::RenderWindow &w){
	int var=200;
	int var2=-30;
	for (int i = 0; i < ficha.tam; i++) {
		for (int j = 0; j < ficha.tam; j++) {
			if (ficha.ver_ficha(i, j) != 0) {
				Efecto.setPosition((ficha.ver_columna() + j) * 30 + var, (ficha.ver_fila() + i) * 30 + var2);
				Efecto.setFillColor(sf::Color(255,255,255,128));
				w.draw(Efecto);
			}
		}
	}
	w.display();
	sf::sleep(sf::milliseconds(50));
	
}
void Tablero::agregar_ficha(Ficha &Ficha){
	
	for(int i=0;i<4;i++) { 
		for(int j=0;j<4;j++) { 
			if(Ficha.ver_ficha(i,j)!=0) {
				
				tablero[Ficha.ver_fila()+i][Ficha.ver_columna()+j]=Ficha.ver_color();
				
			}
			
		}
	}
	puntos=puntos+10;
	Se_puede=true; // entero para saber si se uso HOLD para que se use una vez nomas
	colocada=true;
	
}
void Tablero::mod_puntos(int i){
	puntos=puntos+i;
}
// Esta funcion comprueba si una ficha dada colisiona con otras fichas o con los bordes del tablero en su posición actual.
bool Tablero::colisionar_bordes(Ficha &ficha) {
	int columna_ficha = ficha.ver_columna();
	
	for (int i = 0; i < ficha.tam; i++) {
		for (int j = 0; j < ficha.tam; j++) {
			if (ficha.ver_ficha(i, j) != 0) {
				int columna_actual = columna_ficha + j;
				
				if (columna_actual <= 0 or columna_actual >= Columna) {
					return true; //colision con el borde del tablero
				}
			}
		}
	}
	return false; // No se colision
}
void Tablero::dibujar_efectos_linea_completada(sf::RenderWindow &w){
	
	Linea_Completada.setPosition(200,Fila_completada*30-15);
	w.draw(Linea_Completada); 
	w.display();// funcion que dibuja un barra blanca haciendo el efecto de linea completada
	sf::sleep(sf::milliseconds(30));
	
	
}
	
void Tablero::Fin(sf::RenderWindow &w) {
	int var = 200;
	int var2 = 30;
	
	for (int i = 0; i < 20; i++) {
		
		for (int j = 0; j < 10; j++) {
			m_aux.setPosition(j * 30+var,i * 30+var2);
			m_aux.setTextureRect(sf::IntRect(210,0,30,30));
			w.draw(m_aux);
			sf::sleep(sf::seconds(0.015)); 
		}
		m_ladrillos.play();
		w.display();
		
	}
}
bool Tablero::colisionar_fondo(Ficha &ficha){
	int fila_ficha = ficha.ver_fila();
	for (int i = 0; i < ficha.tam; i++) {
		for (int j = 0; j < ficha.tam; j++) {
			if (ficha.ver_ficha(i, j) != 0) {
				int fila_actual = fila_ficha + i;
				
				if (fila_actual < 0 or fila_actual >= Fila) {
					ficha.Regresar_movimiento(-1);
					return true; //colision con el borde del tablero
				}
			}
		}
	}
	return false; // No se colisio
}
bool Tablero::colisionar_ficha_abajo(Ficha &ficha){
	int fila_ficha = ficha.ver_fila();
	int columna_ficha = ficha.ver_columna();
	for (int i = 0; i < ficha.tam; i++) {
		for (int j = 0; j < ficha.tam; j++) {
			if (ficha.ver_ficha(i, j) != 0) {
				int fila_actual = fila_ficha + i;
				int columna_actual = columna_ficha + j;
				if(tablero[fila_actual][columna_actual] != 0 and ficha.ver_direccion()==0) {
					ficha.Regresar_movimiento(-1);
					return true; //colision con otra ficha
				}
				
			}
		}
	}
	return false; // No se colisio
}

bool Tablero::colisionar_espacio(Ficha &ficha){
	int fila_ficha = ficha.ver_fila();
	int columna_ficha = ficha.ver_columna();
	for (int i = 0; i < ficha.tam; i++) {
		for (int j = 0; j < ficha.tam; j++) {
			if (ficha.ver_ficha(i, j) != 0) {
				int fila_actual = fila_ficha + i;
				int columna_actual = columna_ficha + j;
				if(tablero[fila_actual][columna_actual] != 0 ) {
					ficha.Regresar_movimiento(-1);
					return true; //colision con otra ficha
				}
				
			}
		}
	}
	return false; // No se colisio
}
bool Tablero::colisionar_ficha_lateral(Ficha &ficha) {
	
	int fila_ficha = ficha.ver_fila();
	int columna_ficha = ficha.ver_columna();
	for (int i = 0; i < ficha.tam; i++) {
		for (int j = 0; j < ficha.tam; j++) {
			if (ficha.ver_ficha(i, j) != 0) {
				int fila_actual = fila_ficha + i;
				int columna_actual = columna_ficha + j;
				if (tablero[fila_actual][columna_actual]!=0 and ficha.ver_direccion()==1) {
					ficha.Regresar_columna(-1);
					return true;
					
				}
				if(tablero[fila_actual][columna_actual]!=0 and ficha.ver_direccion()==2) {
					ficha.Regresar_columna(1);
					return true;
				}
				
			}
		}
	}
	return false; // No se colisio
	
}


void Tablero::dibujar_proyecciones(sf::RenderWindow &w, Ficha &Ficha){ 
	int var=200;
	int var2=-30;
	int filaProyeccion = Ficha.ver_fila();
	bool sigueBajando = true;
	while (sigueBajando) {
		filaProyeccion++;
		for (int i = 0; i < Ficha.tam; i++) {
			for (int j = 0; j < Ficha.tam; j++) {
				if (Ficha.ver_ficha(i, j) != 0) {
					int fila = filaProyeccion - Ficha.ver_fila() + i;// fila y columna en donde esta la ficha
					int columna = Ficha.ver_columna() + j;
					if (fila <= 0 or fila >= Fila or tablero[fila][columna] != 0) {
						// Colisión detectada, nos quedamos con la posición anterior
						filaProyeccion--;
						sigueBajando = false;
						break;
					}
				}
			}
			if (!sigueBajando) {
				break;
			}
		}
	}
	
	// Dibujar la proyección de la ficha en la posición encontrada
	for (int i = 0; i < Ficha.tam; i++) {
		for (int j = 0; j < Ficha.tam; j++) {
			if (Ficha.ver_ficha(i,j) != 0) {
				int fila = filaProyeccion - Ficha.ver_fila() + i;
				int columna = Ficha.ver_columna() + j;
				m_sprite_proyec.setPosition((columna * 30)+var, fila * 30+var2);
				m_sprite_proyec.setTextureRect(sf::IntRect((Ficha.ver_color()*30)-30,0,30,30));
				w.draw(m_sprite_proyec);
			}
		}
	}
}
void Tablero::ritmo_de_juego(Ficha &ficha){
	if(lineas>lineas_necesarias and nivel<20) {
		nivel++;
		if(nivel==5) {
			m_sonido_level_5.play();
		}
		if(nivel==10){
			m_sonido_level_10.play();
		}
		if(nivel==15){
			m_sonido_level_15.play();
		}
		m_sonido_sube_nivel.play();
		lineas_necesarias+=10;
	}
	
	ficha.velocidad_de_caida(nivel);
}

void Tablero::Control_movimientos(Ficha &ficha) {
	mover=false;
	colocada=false;
	ritmo_de_juego(ficha);
	float Tiempo_Anterior = m_reloj.getElapsedTime().asSeconds();
	int x = ficha.anchoPieza();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and Tiempo_Anterior>0.09 and ficha.ver_columna()>0){
		ficha.Mover_Izquierda();
		m_reloj.restart();
		mover=true;
		puntos++;
		m_sonido_mover.play();
		
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and Tiempo_Anterior>0.09 and x+ficha.ver_columna()<10){
		ficha.Mover_Derecha();
		m_reloj.restart();
		mover=true;
		puntos++;
		m_sonido_mover.play();
		
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and Tiempo_Anterior>0.09){
		ficha.Mover_Abajo();
		m_reloj.restart();
		puntos++;
		mover=true;
		m_sonido_mover.play();
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) and Tiempo_Anterior>0.15){
		if (puede_rotar(ficha)) {
			ficha.Rotar();
			puntos++;
		}
		mover=true;
		m_sonido_rotar.play();
		m_reloj.restart();
	}
	
}
bool Tablero::Game_over(){
	for(int i=0;i<10;i++) { 
		if(tablero[2][i]!=0){
			return true;
		}
	}
	return false;
}
void Tablero::Dibujar_tablero(sf::RenderWindow &w){
	int var=200;
	int var2=-30;
	for(int i=0;i<Fila;i++) { 
		for(int j=0;j<Columna;j++) {  
			if(tablero[i][j]==1){
				m_aux.setPosition(j * 30+var,i * 30+var2);
				m_aux.setTextureRect(sf::IntRect(0,0,30,30));
				w.draw(m_aux);
			};
			if(tablero[i][j]==2){
				m_aux.setPosition(j * 30+var,i * 30+var2);
				m_aux.setTextureRect(sf::IntRect(30,0,30,30));
				w.draw(m_aux);
			}
			if(tablero[i][j]==3){
				m_aux.setPosition(j * 30+var,i * 30+var2);
				m_aux.setTextureRect(sf::IntRect(60,0,30,30));
				w.draw(m_aux);
			}
			if(tablero[i][j]==4){
				m_aux.setPosition(j * 30+var,i * 30+var2);
				m_aux.setTextureRect(sf::IntRect(90,0,30,30));
				w.draw(m_aux);
			}
			if(tablero[i][j]==5){
				m_aux.setPosition(j * 30+var,i * 30+var2);
				m_aux.setTextureRect(sf::IntRect(120,0,30,30));
				w.draw(m_aux);
			}
			if(tablero[i][j]==6){
				m_aux.setPosition(j * 30+var,i * 30+var2);
				m_aux.setTextureRect(sf::IntRect(150,0,30,30));
				w.draw(m_aux);
			}
			if(tablero[i][j]==7){
				m_aux.setPosition(j * 30+var,i * 30+var2);
				m_aux.setTextureRect(sf::IntRect(180,0,30,30));
				w.draw(m_aux);
			}
			if(tablero[i][j]==0) {
				m_cuadricula.setPosition(j*30+var,i*30+var2);
				w.draw(m_cuadricula);
			}
		}
	}
}
void Tablero::ComprobarLinea() {
	bool linea_completa = false;
	completada=false;
	int multiplicador=0;
	for (int i = 0; i < 22; i++) {
		bool completa = true;
		for (int j = 0; j < 10; j++) {
			if (tablero[i][j] == 0) {
				completa = false;
				break;
			}
			
		}
		if (completa) {
			multiplicador++;
			linea_completa = true;
			completada=true;
			Fila_completada=i;
			// Borrar la linea completa
			for (int j = 0; j < 10; j++) {
				tablero[i][j] = 0;
			/*	puntos=puntos+12;*/
			}
			// Hacer caer las piezas de arriba
			
			for (int k = i; k > 0; k--) {
				for (int j = 0; j < 10; j++) {
					tablero[k][j] = tablero[k-1][j];
					
				}
				
			}
			lineas++;
	
			
		}
		
	}
	if(multiplicador==4){
		puntos=900+puntos;
		m_sonido_linea_4.play();
		
	}
	if(multiplicador==3){
		puntos=600+puntos;
		m_sonido_linea_3.play();
		
	}
	if(multiplicador==2){
		puntos=300+puntos;
		m_sonido_linea.play();
		
	}
	if(multiplicador==1){
		puntos=100+puntos;
		m_sonido_linea.play();
	}
}
bool Tablero::mover_espacio() {
	
	float tiempo_pasado=m_reloj.getElapsedTime().asSeconds();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and tiempo_pasado>0.3){
		m_sonido_espacio.play();
		m_reloj.restart();
		return true;
		
	}else{
		return false;
	}
	
}

int Tablero::ver_puntos(){
	return puntos;
}
int Tablero::ver_tablero(){
	for(int j=0;j<20;j++) {
		for(int i=0;i<10;i++) {
			cout<<tablero[j][i]<<" ";
		}
		cout<<endl;}
}
bool Tablero::puede_rotar(Ficha &ficha) {
	Ficha copia = ficha; // copia de la ficha
	
	// rotar la ficha copiada
	copia.Rotar();
	
	// verificar si la ficha copiada colisiona con otras fichas o los bordes del tablero
	int fila_ficha = copia.ver_fila();
	int columna_ficha = copia.ver_columna();
	
	for (int i = 0; i < copia.tam; i++) {
		for (int j = 0; j < copia.tam; j++) {
			if (copia.ver_ficha(i, j) != 0) {
				int fila_actual = fila_ficha + i;
				int columna_actual = columna_ficha + j;
				
				if (fila_actual < 0 or fila_actual >= Fila or columna_actual < 0 or columna_actual >= Columna or tablero[fila_actual][columna_actual] != 0) {
					return false; // colisiona con otra ficha o el borde del tablero
				}
			}
		}
	}
	
	return true; // no colisiona con otras fichas o el borde del tablero
}


