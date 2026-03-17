#include "Juego.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
Juego::Juego(Escena *e):w(sf::VideoMode(700,650),"Tetris the game!") {
	esc_actual=e;
}
void Juego::Iniciar() {
	while(w.isOpen()) {
		sf::Event e;
		while(w.pollEvent(e)) {
			if(e.type == sf::Event::Closed){
				w.close();}else{
				esc_actual->Procesar_evento(e);
			}
		}
		esc_actual->Actualizar(*this); // Me avisan que debo cambiar de escena, la anoto pero no la cambio;
		esc_actual->Dibujar(w);
		if (m_proxima_escena) { 
			delete esc_actual;
			esc_actual=m_proxima_escena;
			m_proxima_escena=nullptr; // Aca borro la vieja y pongo la nueva 
			
		} 
	}
}
Juego::~Juego() {
	delete esc_actual;
}
void Juego::Cambiar_Escena(Escena *nueva_escena){
	m_proxima_escena=nueva_escena;
}
