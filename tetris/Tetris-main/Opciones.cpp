#include "Opciones.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include "Menu.h"


Opciones::Opciones() {
	int var=50;
	int size1=25;
	int size2=20;
	m_font.loadFromFile("Fuentes/tetris.ttf");
	Controles.setFont(m_font);
	Controles.setString("Controles");
	Controles.setFillColor({255,255,255});
	Controles.setPosition(30,var-5);
	Controles.setCharacterSize(40);
	
	Right.setFont(m_font);
	Right.setString("Derecha");
	Right.setFillColor({255,255,255});
	Right.setPosition(30,var*2);
	Right.setCharacterSize(size1);
	
	Control_derecha.setFont(m_font);
	Control_derecha.setString("Flecha derecha");
	Control_derecha.setFillColor({255,255,255});
	Control_derecha.setPosition(200,var*2+4);
	Control_derecha.setCharacterSize(20);
	
	
	Left.setFont(m_font);
	Left.setString("Izquierda");
	Left.setFillColor({255,255,255});
	Left.setPosition(30,var*3);
	Left.setCharacterSize(size1);
	
	Control_Izquierda.setFont(m_font);
	Control_Izquierda.setString("Flecha izquierda");
	Control_Izquierda.setFillColor({255,255,255});
	Control_Izquierda.setPosition(200,var*3+4);
	Control_Izquierda.setCharacterSize(size2);

	
	Down.setFont(m_font);
	Down.setString("Abajo");
	Down.setFillColor({255,255,255});
	Down.setPosition(30,var*4);
	Down.setCharacterSize(size1);
	
	
	Control_Abajo.setFont(m_font);
	Control_Abajo.setString("Flecha abajo");
	Control_Abajo.setFillColor({255,255,255});
	Control_Abajo.setPosition(200,var*4+4);
	Control_Abajo.setCharacterSize(size2);
	
	Drop.setFont(m_font);
	Drop.setString("Caer");
	Drop.setFillColor({255,255,255});
	Drop.setPosition(30,var*5);
	Drop.setCharacterSize(size1);
	
	Control_Caer.setFont(m_font);
	Control_Caer.setString("Espacio");
	Control_Caer.setFillColor({255,255,255});
	Control_Caer.setPosition(200,var*5+4);
	Control_Caer.setCharacterSize(size2);
	
	Rotate.setFont(m_font);
	Rotate.setString("Rotar");
	Rotate.setFillColor({255,255,255});
	Rotate.setPosition(30,var*6);
	Rotate.setCharacterSize(size1);
	
	Control_Rotar.setFont(m_font);
	Control_Rotar.setString("R");
	Control_Rotar.setFillColor({255,255,255});
	Control_Rotar.setPosition(200,var*6+4);
	Control_Rotar.setCharacterSize(size2);
	
	Control_Guardar.setFont(m_font);
	Control_Guardar.setString("C");
	Control_Guardar.setFillColor({255,255,255});
	Control_Guardar.setPosition(200,var*7+4);
	Control_Guardar.setCharacterSize(size2);
	
	Save.setFont(m_font);
	Save.setString("Guardar");
	Save.setFillColor({255,255,255});
	Save.setPosition(30,var*7);
	Save.setCharacterSize(size1);
	
	
	
	Barra.setTexture(T);
	Barra.setTextureRect(sf::IntRect(0,0,210,2));
	Barra.setPosition(35,90);
	
	sf::RectangleShape m_barra_volumen(sf::Vector2f(250,15));
	m_barra_volumen.setFillColor(sf::Color::White);
	barra_volumen=m_barra_volumen;
	barra_volumen.setPosition(220,464);
	
	
	sf::RectangleShape m_barra_interna(sf::Vector2f(volumen_general,10));
	m_barra_interna.setFillColor(sf::Color::Red);
	barra_interna=m_barra_interna;
	barra_interna.setPosition(225,466);
	max_volumen=240;
	max_sonido=240;
	min_volumen=0;
	min_sonido=0;
	///
	sf::RectangleShape m_barra_volumen2(sf::Vector2f(250,15));
	m_barra_volumen2.setFillColor(sf::Color::White);
	barra_volumen2=m_barra_volumen2;
	barra_volumen2.setPosition(320,514);
	
	sf::RectangleShape m_barra_interna2(sf::Vector2f(sonido_general,10));
	m_barra_interna2.setFillColor(sf::Color::Red);
	barra_interna2=m_barra_interna2;
	barra_interna2.setPosition(325,516);
	
	///
	m_music.setFont(m_font);
	m_music.setString("Musica");
	m_music.setFillColor({255,255,255});
	m_music.setPosition(30,(var*8)-5);
	m_music.setCharacterSize(40);
	
	Barra1.setTexture(T);
	Barra1.setTextureRect(sf::IntRect(0,0,160,2)); //subrayado
	Barra1.setPosition(30,440);
	
	m_volumen.setFont(m_font);
	m_volumen.setString("Volumen");
	m_volumen.setFillColor({255,255,255});
	m_volumen.setPosition(30,var*9+4);
	m_volumen.setCharacterSize(size1);
	
	m_effect.setFont(m_font);
	m_effect.setString("Efectos de sonido");
	m_effect.setFillColor({255,255,255});
	m_effect.setPosition(30,var*10+4);
	m_effect.setCharacterSize(size1);
	mover=0;
	
	//Musica
	m_musica.openFromFile("Sonidos/Menu.wav");
	m_musica.setLoop(true);
	m_musica.play();
	//sonido
	buffer.loadFromFile("Sonidos/sonido-pop.wav");
	sound.setBuffer(buffer);
	buffer2.loadFromFile("Sonidos/sonido-pop2.wav");
	sound2.setBuffer(buffer2);
}
void Opciones::Actualizar (Juego &J) {

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and mover!=0 and m_time.getElapsedTime().asSeconds()>0.3){
		mover--;
		sound.play();
		m_time.restart();
		
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and mover!=1 and m_time.getElapsedTime().asSeconds()>0.3 ) {
		mover++;
		sound.play();
		m_time.restart();
		
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
		J.Cambiar_Escena(new Menu());
	}
	if(mover==0) {
		
		Rotate.setFillColor(sf::Color::White);
		m_volumen.setFillColor(sf::Color::Red);
		m_effect.setFillColor(sf::Color::White);
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and volumen_general<max_volumen and m_time.getElapsedTime().asSeconds()>0.2){
			barra_interna.setSize(sf::Vector2f(volumen_general+20,10));
			volumen_general=volumen_general+10;
			m_time.restart();
			mod_volumen(ver_volumen()+10);
			sound2.play();
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and volumen_general>min_volumen and m_time.getElapsedTime().asSeconds()>0.2) {
			barra_interna.setSize(sf::Vector2f(volumen_general-20,10));
			volumen_general=volumen_general-10;
			m_time.restart();
			mod_volumen(ver_volumen()-10);
			sound2.play();
		}
	}
	if(mover==1) {
		m_volumen.setFillColor(sf::Color::White);
		m_effect.setFillColor(sf::Color::Red);
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and sonido_general<max_sonido and m_time.getElapsedTime().asSeconds()>0.2){
			barra_interna2.setSize(sf::Vector2f(sonido_general+20,10));
			sonido_general=sonido_general+10;
			m_time.restart();
			mod_sonido(ver_sonido()+10);
			sound2.play();
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and sonido_general>min_sonido and m_time.getElapsedTime().asSeconds()>0.2) {
			barra_interna2.setSize(sf::Vector2f(sonido_general-20,10));
			sonido_general=sonido_general-10;
			m_time.restart();
			mod_sonido(ver_sonido()-10);
			sound2.play();
		}
		
	}
	m_musica.setVolume(ver_volumen());
	sound.setVolume(ver_sonido());
	sound2.setVolume(ver_sonido());
}
void Opciones::Dibujar (sf::RenderWindow & window) {
	window.clear();
	window.draw(Control_derecha);
	window.draw(Barra);
	window.draw(Barra1);
	window.draw(barra_volumen);
	window.draw(Control_Guardar);
	window.draw(Save);
	window.draw(barra_volumen2);
	window.draw(m_volumen);
	window.draw(Controles);
	window.draw(Control_Izquierda);
	window.draw(Control_Abajo);
	window.draw(Control_Caer);
	window.draw(Control_Rotar);
	window.draw(barra_interna);
	window.draw(barra_interna2);
	window.draw(Down);
	window.draw(Right);
	window.draw(Left);
	window.draw(Drop);
	window.draw(Rotate);
	window.draw(m_effect);
	window.draw(m_music);
	window.display();
}
