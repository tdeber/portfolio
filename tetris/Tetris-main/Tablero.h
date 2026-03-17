#ifndef TABLERO_H
#define TABLERO_H
#include "Ficha.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

class Tablero {
public:
	Tablero();
	static const int Fila=22;
	static const int Columna=10;
	int ver_tablero();
	bool Game_over();
	void agregar_ficha(Ficha &Ficha);
	bool colisionar_ficha_abajo(Ficha &Ficha);
	void iniciar_Interfaz(sf::RenderWindow &w);
	bool colisionar_bordes(Ficha &Ficha);
	bool colisionar_fondo(Ficha &Ficha);
	bool colisionar_espacio(Ficha &Ficha);
	void dibujar_proyecciones(sf::RenderWindow &w, Ficha &Ficha);
	void Dibujar_tablero(sf::RenderWindow &w);
	void ComprobarLinea();
	bool colisionar_ficha_lateral(Ficha &Ficha);
	bool mover_espacio();
	
	void funcion_espacio(Ficha &ficha);
	int ver_puntos();
	void Control_movimientos(Ficha &ficha);
	void ritmo_de_juego(Ficha &ficha);
	bool puede_rotar(Ficha &ficha);
	bool completada,colocada;
	void dibujar_efectos_linea_completada(sf::RenderWindow &w);
	void intercambio_de_ficha(Ficha &ficha,Ficha &hold_ficha);
	void intercambio_de_ficha(Ficha &ficha,Ficha &next_ficha,Ficha &hold_ficha);
	void cambio(Ficha &ficha, Ficha &next_ficha, Ficha &hold_ficha);
	void efecto_barra(sf::RenderWindow &w, Ficha &ficha, Ficha &next_ficha);
	void efecto_movimiento(sf::RenderWindow &w,Ficha &ficha);
	void efecto_colocacion(Ficha &ficha,sf::RenderWindow &w);
	int ver_nivel();
	void Fin(sf::RenderWindow &w);
	void mod_puntos(int i);
	void calibrado_sonido_efectos(float volumen_efectos);

private:
	sf::Clock m_reloj;
	sf::RectangleShape Barras_laterales_1,Barra_verticales_1,Barras_laterales_2,Barra_verticales_2,Barra_de_puntos,Barra_de_level,Barra_next_pieza1,Barra_next_pieza2,Barra_next_pieza3,Barra_next_pieza4,Linea_Completada;
	sf::RectangleShape Barras_hold_pieza1,Barras_hold_pieza2,Barras_hold_pieza3,Barras_hold_pieza4,Barra_superior,Efecto;
	int puntos,lineas,nivel,tiempo_pasado,velocidad,lineas_necesarias,Fila_completada,Ya_cambiada,vuelta;
	int tablero[Fila][Columna];
	sf::Texture m_proyec,cuadricula,aux;
	sf::Sprite m_sprite_proyec,m_aux,m_cuadricula;
	sf::Text m_level,m_score,m_next_piece,m_puntos,m_numero_level,m_hold;
	sf::Font m_fuente;
	bool Se_puede,mover;
	sf::SoundBuffer ladrillos,cambio1;
	sf::Sound m_ladrillos, m_cambio1;
	sf::Color colorOriginal;
	sf::SoundBuffer sonido_mover,sonido_rotar,sonido_espacio,sonido_linea,sonido_sube_nivel,sonido_level_5,sonido_level_10,sonido_level_15,sonido_linea_3,sonido_linea_4;
	sf::Sound m_sonido_mover,m_sonido_rotar,m_sonido_espacio,m_sonido_linea,m_sonido_sube_nivel,m_sonido_level_5,m_sonido_level_10,m_sonido_level_15,m_sonido_linea_3,m_sonido_linea_4;
	
};
#endif
