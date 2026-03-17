#include "Creditos.h"
#include <SFML/Window/Keyboard.hpp>
#include "Menu.h"

Creditos::Creditos() {
	m_creditos.loadFromFile("Fuentes/tetris.ttf");
	
	sf::RectangleShape m_barra(sf::Vector2f(170,3));
	m_barra.setFillColor(sf::Color::White);
	Barra=m_barra;
	Barra.setPosition(285,435);
	
	m_Nombre1.setFont(m_creditos);
	m_Nombre1.setString("Alexis Meier");
	m_Nombre1.setFillColor({255,255,255});
	m_Nombre1.setPosition(260,500);
	m_Nombre1.setCharacterSize(30);
	
	m_Nombre2.setFont(m_creditos);
	m_Nombre2.setString("Tomas De Bernardi");
	m_Nombre2.setFillColor({255,255,255});
	m_Nombre2.setPosition(200,450);
	m_Nombre2.setCharacterSize(30);
	
	m_creadores.setFont(m_creditos);
	m_creadores.setString("Creadores");
	m_creadores.setFillColor({255,255,255});
	m_creadores.setPosition(270,400);
	m_creadores.setCharacterSize(30);
	
	m_imagen.loadFromFile("Images/Imagen.png");
	imagen.setTexture(m_imagen);
	imagen.scale(1.35,1.35);
	imagen.move(-10,0);
	
	//Musica
	m_musica.openFromFile("Sonidos/Menu.wav");
	m_musica.setLoop(true);
	m_musica.play();
}
void Creditos::Actualizar(Juego &J) {
	m_musica.setVolume(ver_volumen());
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
		J.Cambiar_Escena(new Menu());
	}
	
};
void Creditos::Dibujar(sf::RenderWindow &window) {
	window.clear();
	window.draw(imagen);
	window.draw(m_Nombre1);
	window.draw(m_Nombre2);
	window.draw(m_creadores);
	window.draw(Barra);
	window.display();
}

