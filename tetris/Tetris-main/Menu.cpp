#include "Menu.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Partida.h"
#include "Opciones.h"
#include "Creditos.h"


Menu::Menu():window(window) {
	
	archivo="points.dat";
	LeerBinario(); 
	CharToString();
	DibujarHighScore();
	
	//Inicializo fuente
	m_font.loadFromFile("Fuentes/tetris.ttf");
	//Inicializo texto
	m_font_titulo.loadFromFile("Fuentes/titulo.ttf");
	
	//Arreglo de colores
	sf::Color colores[] = {sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Yellow, sf::Color::Magenta,sf::Color::Cyan};
	
	//Algoritmo para letras de colores titulo
	for(int i=0;i<6;i++) { 
		letras[i].setFont(m_font_titulo);  
		letras[i].setString(std::string(1, "tetris"[i]));
		letras[i].setFillColor(colores[i]);
		letras[i].setPosition(125 + i *80, 80);
		letras[i].setCharacterSize(80);
	}
	letras[5].setPosition(125+6*80-90,80);
	

	StartGame.setFont(m_font);
	StartGame.setString("Jugar");
	StartGame.setFillColor({255,255,255});
	StartGame.setPosition(300,300);
	StartGame.setCharacterSize(30);
	
	
	m_Opciones.setFont(m_font);
	m_Opciones.setString("Opciones");
	m_Opciones.setFillColor({255,255,255});
	m_Opciones.setPosition(275,340);
	m_Opciones.setCharacterSize(30);
	
	m_Creditos.setFont(m_font);
	m_Creditos.setString("Creditos");
	m_Creditos.setFillColor({255,255,255});
	m_Creditos.setPosition(280,380);
	m_Creditos.setCharacterSize(30);
	
	//Cuadrado de Seleccion de Opcion
	T.loadFromFile("Images/jstris1.png");
	
	sf::RectangleShape Cuadrado(sf::Vector2f(15,15));
	Cuadrado.setTexture(&T);
	Cuadrado.setTextureRect(sf::IntRect(0,0,20,20));
	m_Cuadrado=Cuadrado;
	
	//Variable para selecion de opciones
	varible=0;
	//Muisca
	m_music.openFromFile("Sonidos/Menu.wav");
	m_music.setLoop(true);
	m_music.play();
	//Sonido
	buffer.loadFromFile("Sonidos/sonido-pop.wav");
	sound.setBuffer(buffer);
}
void Menu::Actualizar(Juego &J) {
	sound.setVolume(sonido_general);
	//Eleccion de Opcion.
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and varible!=0 and tiempo.getElapsedTime().asSeconds()>0.5){
		varible-=1;
		tiempo.restart();
		sound.play();
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and varible!=2 and tiempo.getElapsedTime().asSeconds()>0.5){
		varible+=1;
		tiempo.restart();
		sound.play();
	}
	//Actualizacion de color para la seleccion de opciones
	if (varible==0) {
		StartGame.setFillColor(sf::Color::Red);
		m_Opciones.setFillColor(sf::Color::White);
		m_Cuadrado.setPosition(250,312);
	}
	if (varible==1) {
		StartGame.setFillColor(sf::Color::White);
		m_Opciones.setFillColor(sf::Color::Red);
		m_Creditos.setFillColor(sf::Color::White);
		m_Cuadrado.setPosition(225,352);
	}
	if(varible==2) {
		StartGame.setFillColor(sf::Color::White);
		m_Creditos.setFillColor(sf::Color::Red);
		m_Opciones.setFillColor(sf::Color::White);
		m_Cuadrado.setPosition(230,392);
	}
	//Cambiar de escena al seleccionar opcion.
	if (varible==0 and sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		J.Cambiar_Escena(new Partida());
	}
	if (varible==1 and sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
		J.Cambiar_Escena(new Opciones());
	}
	if (varible==2 and sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
		J.Cambiar_Escena(new Creditos());
	}
	
	m_music.setVolume(ver_volumen());
}

void Menu::Dibujar(sf::RenderWindow &window) {
	window.clear();
	window.draw(m_Cuadrado);
	window.draw(StartGame);
	window.draw(m_Opciones);
	window.draw(m_Creditos);
	
	DibujarTop();
	
	window.draw(m_HighScore);
	window.draw(m_Rect1);
	window.draw(m_Rect2);
	window.draw(m_Rect3);
	window.draw(m_Rect4);
	window.draw(m_Rect5);
	window.draw(m_border);
	
	for(size_t i=0;i<Tops.size();i++) { 
		window.draw(Tops[i]);
		window.draw(Tops2[i]);
	}
	
	for (int i = 0; i < 6; i++) {
		window.draw(letras[i]);
	}
	window.display();
}

//Abre el archivo, lee los datos y los carga en un vector.
void Menu::LeerBinario(){
	ifstream puntos("points.dat",ios::binary|ios::ate);
	int tam=puntos.tellg();
	int cant=tam/sizeof(GamerBin);
	puntos.seekg(0);
	
	GamerBin_ pi;
	
	for (int i=0;i<cant;i++) {
		puntos.read(reinterpret_cast<char*>(&pi),sizeof(pi));
		TopBin.push_back(pi);
	}
	puntos.close();
}
//El vector tipo char con los datos del archivo pasan a tipo string.
void Menu::CharToString(){
	vector<Gamer_> ListaTop;
	for(size_t i=0;i<TopBin.size();i++) { 
		Gamer_ x;
		x.jugador=TopBin[i].jugador;
		x.puntaje=TopBin[i].puntaje;
		ListaTop.push_back(x);
	}
	for(size_t i=0;i<ListaTop.size();i++) { 
		Top.push_back(ListaTop[i]);
		cout<<ListaTop[i].jugador<<endl;
	}
}
//Recuadros del HighScore
void Menu::DibujarHighScore(){
	GrisClaro=sf::Color(50,50,50,255);
	GrisOscuro=sf::Color(30,30,30,255);
	
	sf::RectangleShape border(sf::Vector2f(305.f, 202.f)); //235 a 285
	border.setFillColor(sf::Color::Transparent);
	border.setOutlineColor(GrisClaro);
	border.setOutlineThickness(1.f);
	border.setPosition(210,440);
	m_border=border;
	
	
	sf::RectangleShape RectGrisOscuro(sf::Vector2f(275.f,28.f));
	RectGrisOscuro.setFillColor(GrisOscuro);
	RectGrisOscuro.setPosition(225,479);
	m_Rect1=RectGrisOscuro;
	
	sf::RectangleShape RectGrisClaro(sf::Vector2f(275.f,28.f));
	RectGrisClaro.setFillColor(GrisClaro);
	RectGrisClaro.setPosition(225,510);
	m_Rect2=RectGrisClaro;
	
	m_Rect3=RectGrisOscuro;
	m_Rect3.setPosition(225,541);
	
	m_Rect4=RectGrisClaro;
	m_Rect4.setPosition(225,572);
	
	m_Rect5=RectGrisOscuro;
	m_Rect5.setPosition(225,603);
	
	m_HighScore.setFont(m_font);
	m_HighScore.setString("HighScore");
	m_HighScore.setFillColor({255,255,255});
	m_HighScore.setPosition(283,445);
	m_HighScore.setCharacterSize(25);
	
	
}

void Menu::DibujarTop(){
	string tmp;
	int y=0;
	for(size_t i=0;i<Top.size();i++) {
		//Coloco el jugador en la posicion correspondiente del highscore
		sf::Text x;
		tmp = to_string(i+1);
		tmp += ". ";
		tmp += Top[i].jugador;
		
		x.setFont(m_font);
		x.setString(tmp);
		x.setFillColor({255, 255, 255});
		x.setPosition(228, 490 + y);
		x.setCharacterSize(15);
		y += 30;
		
		Tops.push_back(x);
	}
	y=0;
	for(size_t i=0;i<Top.size();i++) {
		//Coloco el puntaje en la posicion correspondiente del highscore
		sf::Text f;
		tmp = Top[i].puntaje;
		
		f.setFont(m_font);
		f.setString(tmp);
		f.setFillColor({255, 255, 255});
		
		int puntos = std::stoi(tmp);
		
		//Codigo para que la puntuacion quede simetrica.
		if (puntos > 99){
			f.setPosition(467, 490 + y);
			if (puntos > 999){
				f.setPosition(454, 490 + y);
				if (puntos > 9999){
					f.setPosition(441, 490 + y);
					if (puntos > 99999){
						f.setPosition(428, 490 + y);
					}
				}
			}
		}else {
			f.setPosition(480, 490 + y);
		}
		f.setCharacterSize(15);
		y += 30;
		
		Tops2.push_back(f);
	}
}
