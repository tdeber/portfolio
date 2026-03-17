#ifndef FICHA_H
#define FICHA_H
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
class Ficha {
public:
	static const int tam=4;
	
	Ficha();
	int ver_color();
	void Dibujar_siguiente_ficha(sf::RenderWindow &w);
	int ver_fila();
	int ver_columna();
	void NuevaPieza();
	sf::Sprite ver_sprite();
	int ver_ficha(int i,int j);
	void ver_matriz();
	void Dibujar_pieza(sf::RenderWindow &w);
	int anchoPieza();
	void Bajar();
	int ver_direccion();
	int Regresar_columna(int i);
	void Regresar_movimiento(int i);
	void RotarP();
	void Mover_Izquierda();
	void Mover_Abajo();
	void Mover_Derecha();
	void Rotar();
	void efecto_movimiento(sf::RenderWindow &w);
	void velocidad_de_caida(int i);
	void mod_fila(int i);
	void mod_columna(int i);
	sf::Color color();
	void setColor(sf::Color x);
	void Dibujar_ficha_guardada(sf::RenderWindow &w);
private:
	sf::Sprite m_sprite,m_cuadri;
	sf::Texture m_texture,m_texture2;
	int matriz[tam][tam];
	int temp[4][4];
	int Color,caso,Direccion,Estado,Fila,Columna,P_ancho;
	sf::Color m_color;
	sf::Clock clock;
	std::vector<int>x;
};
#endif
