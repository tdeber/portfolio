#include "Partida.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Sleep.hpp>


Partida::Partida() {				
	next_ficha.NuevaPieza();
	ficha.NuevaPieza();
	cambio=false;
	m_musica_partida.openFromFile("Sonidos/Tetris 99.wav");
	m_musica_partida.setLoop(true);
	m_musica_partida.setVolume(ver_volumen()); 			//Iniciacion de valores y cargado de sonidos.
	m_musica_partida.play();
	caso_inicio=0; //valor para la primera pieza hold
	
	m_musica_partida_fast.openFromFile("Sonidos/Tetris 99 OST.wav");
	m_musica_partida_fast.setLoop(true);
	m_musica_partida_fast.setVolume(ver_volumen());
	terminado=false;
	pausa=false;
	damage.loadFromFile("Efectos/damage_alert.ogg");
	m_damage.setBuffer(damage);
	m_damage.setVolume(ver_sonido());
	
	game_ov.loadFromFile("Efectos/gameover.ogg");
	m_game_ov.setBuffer(game_ov);
	m_game_ov.setVolume(ver_sonido());
	tablero.calibrado_sonido_efectos(ver_sonido());
	
	enter.loadFromFile("Efectos/pause_start.ogg");
	m_enter.setBuffer(enter);
	m_enter.setVolume(ver_sonido());
	
}
void Partida::Actualizar(Juego &J) {
	
	if(tablero.Game_over()!=true){
		if(menu.Pausar()){ //Funcion para saber cuando despausar y cuando pausa, usa un booleano para cambiar de estado.
		m_enter.play();
		pausa=not (pausa);	
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) and menu.ver_variable()==0 and pausa==true){
			pausa=false;
		}
		
		if(pausa!=true){
		m_musica_partida.setVolume(ver_volumen());
		m_musica_partida_fast.setVolume(ver_volumen());
		if (cambio==false and tablero.ver_nivel()==10){ //Efectos de sonido y Musica, se utiliza el booleano "cambio" para cambiar la musica en el nivel 10
			m_damage.play(); // 						
			sf::sleep(sf::seconds(0.5));
			m_musica_partida_fast.play();
			m_musica_partida.stop();
			cambio=true;
		}
		if(tablero.colisionar_fondo(ficha)  or tablero.colisionar_ficha_abajo(ficha)){ //Condicional para ver colisones, si devuelve true entonces se agrega la pieza al tablero
			float delay=m_reloj.getElapsedTime().asSeconds(); // delay para que la pieza no se coloque inmediatamente cuando toque a otra
			if(delay>1){
				tablero.agregar_ficha(ficha);
				m_reloj.restart();
			}else{
				tablero.Control_movimientos(ficha);
			}
			
		}else{
			if(tablero.colisionar_ficha_lateral(ficha)) {		//Metodos que controlan las colisiones laterales y el control de los movimientos
				
			}else{
				tablero.Control_movimientos(ficha);
				
			}
		}
		tablero.cambio(ficha,next_ficha,hold_ficha);		//Funciones que comprueban si hay alguna linea completada, y si el usuario solicito guardar una ficha 
		tablero.ComprobarLinea();}else{
			menu.Actualizar(J);
			if (cambio){
				m_musica_partida_fast.setVolume(ver_volumen()-230); // En el menu de pausa el nivel de musica se reduce 
			}else{
				m_musica_partida.setVolume(ver_volumen()-230);
			}
		}
	}else{
		terminado=true;
		tablero.mod_puntos(-10);		//El juego completo esta dentro de un bucle if en se pregunta si la las lineas superiores estan siendo ocupadas por un numero !=0
		m_musica_partida.stop(); 		
		m_musica_partida_fast.stop();
		m_game_ov.play();
		
		J.Cambiar_Escena(new Game_Over(tablero.ver_puntos()));
	}

}
void Partida::Dibujar(sf::RenderWindow &w) {
	
	if(terminado){
		w.clear();
		tablero.iniciar_Interfaz(w);
		tablero.Dibujar_tablero(w);
		next_ficha.Dibujar_siguiente_ficha(w); //El booleano "terminado" representa si el juego se ha concluido para proceder a hacer la animacion
		hold_ficha.Dibujar_ficha_guardada(w);
		tablero.Fin(w);
		sf::sleep(sf::seconds(1));
	}else{
		w.clear();
	if(pausa){
		menu.Dibujar(w);
		w.display();
	}else{
	tablero.Dibujar_tablero(w);
	tablero.iniciar_Interfaz(w);
	tablero.efecto_barra(w,ficha,next_ficha); 
	if(tablero.colocada){
		tablero.efecto_colocacion(ficha,w); //Efectos visuales
		ficha=next_ficha;
		next_ficha.NuevaPieza();
	}else{
		ficha.Dibujar_pieza(w);
		tablero.efecto_movimiento(w,ficha);		//Mas Efectos visuales. Movimiento, dibujado de proyecciones para ver en donde va a caer la pieza
		tablero.iniciar_Interfaz(w);
		tablero.dibujar_proyecciones(w,ficha);
	}
	if (tablero.completada){
		tablero.dibujar_efectos_linea_completada(w); //Efecto de linea completada, se dibuja una linea blanca en la fila la cual completo la linea
	}
	next_ficha.Dibujar_siguiente_ficha(w);
	hold_ficha.Dibujar_ficha_guardada(w);
	w.display();
	}
	}

}
