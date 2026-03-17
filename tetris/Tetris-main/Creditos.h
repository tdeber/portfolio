#ifndef CREDITOS_H
#define CREDITOS_H
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Creditos:public Escena {
public:
	Creditos();
	void Actualizar(Juego &J)override;
	void Dibujar(sf::RenderWindow &window)override;
private:
	sf::Font m_creditos;
	sf::Text m_Nombre1,m_Nombre2,m_creadores;
	sf::Texture m_imagen;
	sf::Sprite imagen;
	sf::RectangleShape Barra;
	sf::Music m_musica;
};

#endif

