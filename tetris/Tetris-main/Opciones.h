#ifndef OPCIONES_H
#define OPCIONES_H
#include "Escena.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "Juego.h"

using namespace std;

class Opciones : public Escena {
public:
	Opciones();
	void Actualizar (Juego &j);
	void Dibujar (sf::RenderWindow & w);
private:
	sf::Font m_font;
	sf::Text Controles,m_effect,Down,Right,Left,Drop,Rotate,Save,m_music,m_volumen,Control_derecha,Control_Izquierda,Control_Caer,Control_Abajo,Control_Rotar,Control_Guardar;
	sf::Texture T;
	sf::RectangleShape barra_volumen,barra_interna,efectos;
	sf::RectangleShape barra_volumen2,barra_interna2;
	sf::Sprite Barra1,Barra;
	int mover,max_volumen,min_volumen,volumen_act;
	int max_sonido,min_sonido,sonido_act;
	sf::Clock m_time;
	sf::Music m_musica;
	sf::SoundBuffer buffer,buffer2;
	sf::Sound sound,sound2;
	
};

#endif

