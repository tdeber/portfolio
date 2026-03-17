#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"
#include "Ficha.h"
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Window/Event.hpp>

class Juego {
public:
	Juego(Escena *e);
	void Iniciar();
	void Gameover();
	~Juego();
	void Cambiar_Escena(Escena *nueva_escena);
private:
	Escena *esc_actual, *m_proxima_escena=nullptr;
	sf::Music musica;
	sf::RenderWindow w;
	
};

#endif

