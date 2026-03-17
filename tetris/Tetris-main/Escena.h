#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics/RenderWindow.hpp>


class Juego;
class Escena {
public:
	Escena();
	virtual void Actualizar(Juego &J)=0;
	virtual void Dibujar (sf::RenderWindow &w)=0;
	virtual void Procesar_evento(sf::Event &d){};
	void mod_volumen(float vol);
	void mod_sonido(float sonido);
	float ver_volumen();
	float ver_sonido();
	virtual  ~Escena();
	
	static float volumen_general;
	static float sonido_general;
	
	
};

#endif

