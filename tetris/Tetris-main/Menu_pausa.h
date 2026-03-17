#ifndef MENU_PAUSA_H
#define MENU_PAUSA_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"


class Menu_pausa: public Escena {
public:
	Menu_pausa();
	void Actualizar (Juego &J);
	void Dibujar (sf::RenderWindow &w) override;
	bool Pausar();
	int ver_variable();
private:
	sf::RenderWindow &window;
	sf::SoundBuffer buf;
	sf::Sound movimiento;
	sf::RectangleShape Barra1;
	sf::Font m_fuente;
	sf::Text m_resume, m_exit,m_pausa;
	int variable;
	bool estado; //variable para reanudar el juego
	sf::Clock Reloj;
};

#endif

