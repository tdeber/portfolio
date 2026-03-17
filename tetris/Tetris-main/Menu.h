#ifndef MENU_H
#define MENU_H
#include "Juego.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Escena.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

using namespace std;
struct Gamer_{
	string jugador;
	string puntaje;
};
struct GamerBin_{
	char jugador[60];
	char puntaje[60];
};
class Menu :public Escena{
public:
	Menu();
	void Actualizar(Juego &J) override ;
	void Dibujar (sf::RenderWindow &w) override;
	
	//
	void LeerBinario();
	void CharToString();
	void DibujarTop();
	
	void DibujarHighScore();
	//
private:
	sf::RenderWindow &window;
	sf::Texture T;
	sf::Font m_font,m_font_titulo;
	sf::Text StartGame,m_Opciones,m_Creditos,m_titulo;
	int varible;
	sf::Text letras[6];
	sf::RectangleShape m_Cuadrado;
	sf::Clock tiempo;
	sf::Music m_music;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	//
	string archivo;
	vector<GamerBin_> TopBin;
	vector<Gamer_> Top;
	
	sf::Text m_HighScore;
	sf::RectangleShape m_border;
	sf::RectangleShape m_Rect1,m_Rect2,m_Rect3,m_Rect4,m_Rect5;
	sf::Color GrisClaro,GrisOscuro;
	vector<sf::Text> Tops;
	vector<sf::Text> Tops2;
	//
	
};

#endif

