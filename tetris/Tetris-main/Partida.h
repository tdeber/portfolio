#ifndef PARTIDA_H
#define PARTIDA_H
#include "Tablero.h"
#include "Ficha.h"
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/System/Clock.hpp>
#include "Menu_pausa.h"
#include "Game_Over.h"

class Partida :public Escena{
public:
	Partida();
	void Actualizar(Juego &j)override; 
	void Dibujar(sf::RenderWindow &w)override; 
private:
	Tablero tablero;
	Menu_pausa menu;
	Ficha ficha,next_ficha,hold_ficha;
	sf::Music m_musica_partida,m_musica_partida_fast;
	sf::SoundBuffer damage;
	sf::Sound m_game_ov;
	sf::SoundBuffer game_ov;
	sf::Sound m_damage;
	sf::SoundBuffer enter;
	sf::Sound m_enter;
	int caso_inicio;
	bool cambio;
	bool pausa;
	bool terminado;
	sf::Clock m_reloj;
};

#endif

