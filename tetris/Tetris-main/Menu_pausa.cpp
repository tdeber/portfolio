#include "Menu_pausa.h"
#include <SFML/Window/Keyboard.hpp>
#include "Partida.h"
#include "Menu.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Sleep.hpp>

Menu_pausa::Menu_pausa():window(window) {
	//inicializo la fuente
	m_fuente.loadFromFile("Fuentes/tetris.ttf");
	
	//Paso fuente a las variables text y acomodo
	
	m_exit.setFont(m_fuente);
	m_exit.setString("Salir");
	m_exit.setFillColor({255,255,255});
	m_exit.setPosition(320,350);
	m_exit.setCharacterSize(30);
	
	m_resume.setFont(m_fuente);
	m_resume.setString("Reanudar");
	m_resume.setFillColor({255,255,255});
	m_resume.setPosition(270,300);
	m_resume.setCharacterSize(30);
	m_resume.setColor(sf::Color::Red);
	
	m_pausa.setFont(m_fuente);
	m_pausa.setString("Pausa");
	m_pausa.setFillColor({255,255,255});
	m_pausa.setPosition(270,170);
	m_pausa.setCharacterSize(50);
	m_pausa.setColor(sf::Color::White);
	
	//Variable auxiliar para saber en que opcion estoy
	variable=0;
	estado=false;
	
	sf::RectangleShape m_barra1(sf::Vector2f(130,2));
	m_barra1.setFillColor(sf::Color::White);
	Barra1=m_barra1;
	Barra1.setPosition(300,232);
	
	
}
void Menu_pausa::Dibujar(sf::RenderWindow &w) {
	w.draw(m_exit);
	w.draw(m_resume);
	w.draw(Barra1);
	w.draw(m_pausa);
	
}
bool Menu_pausa::Pausar(){
	float tiempo_delay=Reloj.getElapsedTime().asSeconds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) and tiempo_delay>0.4){
		Reloj.restart();									// Metodo que retorna true o false dependiendo si el tiempo de delay es optimo y se a presionado la tecla "Return o Escape"
		return true;
	}else{
		return false;
	}
}
void Menu_pausa::Actualizar( Juego &J){
	float tiempo_delay=Reloj.getElapsedTime().asSeconds();
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and variable==0 and tiempo_delay>0.5){
		variable=1;
		m_resume.setColor(sf::Color::White);
		m_exit.setColor(sf::Color::Red);
		Reloj.restart();
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and variable==1 and tiempo_delay>0.5) { //Opciones del menu de pausa, para pasar a distintos estados, se uso una variable auxiliar
		variable=0;																			//Para saber en que caso se estaba, al igual que en las clases "Opciones" y "Menu"
		m_resume.setColor(sf::Color::Red);
		m_exit.setColor(sf::Color::White);
		Reloj.restart();
	}
	if( variable==1 and sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		J.Cambiar_Escena(new Menu());
		sf::sleep(sf::seconds(0.2));
		Reloj.restart();
	}
}
int Menu_pausa::ver_variable(){   //Funcion que utiliza ver en que variable se esta, para volver a la partida.
	return variable;
}

