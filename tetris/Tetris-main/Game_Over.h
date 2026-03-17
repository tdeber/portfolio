#ifndef GAME_OVER_H
#define GAME_OVER_H
#include "Escena.h"
#include <string>
#include <fstream>
#include <vector>
#include <SFML/Graphics/Text.hpp>
#include "InputBox.h"
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
using namespace std;

struct Gamer{
	string jugador;
	string puntaje;
};
struct GamerBin{
	char jugador[60];
	char puntaje[60];
};
class Game_Over : public Escena {
public:
	Game_Over(int puntos);
	void Actualizar (Juego & J);
	void Dibujar (sf::RenderWindow & w);
	void Procesar_evento(sf::Event &e);
	bool Mejor_puntuacion();
	void ActualizarArchivo();
	void CargarArchivo();
	void insertar();
private:
	int variable;
	int variable2;

	Gamer R;
	int Pos;
	bool puntaje_mayor,efectos;
	std::string string_ingresado;
	string PlayerName;
	fstream Archivo;
	int puntaje_final;
	sf::Music Terminado,Victory;
	sf::Text Texto_vuelve,Presiona,Texto_vuelve2,Felicitaciones,Ingresaste,Al_top,Game,Guardado;
	std::string palabras;
	sf::Event e_v;
	sf::Font m_fuente;
	InputText Player_name;
	sf::Text texto;
	std::string nombreUsuario;
	
	sf::SoundBuffer enter,complete,aplausos;
	sf::Sound m_enter,m_complete,m_aplausos;
	
	vector<GamerBin> TopBin;
	vector<Gamer> Top;
};

#endif

