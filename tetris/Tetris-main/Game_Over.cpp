#include "Game_Over.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <SFML/Window/Event.hpp>
#include <string>
#include "Menu.h"
#include <algorithm>
#include <cstring>
using namespace std;

Game_Over::Game_Over(int puntos_obt):Player_name(m_fuente) {
	variable = 0;
	CargarArchivo();
	puntaje_mayor=false;
	m_fuente.loadFromFile("Fuentes/tetris.ttf");
	InputText Player_name1(m_fuente,30,sf::Color::White);
	Player_name=Player_name1;
	puntaje_final=puntos_obt;
	cout<<puntaje_final<<"--"<<endl;
	Player_name.setSingleWord(true); // una sola palabra
	
	Terminado.openFromFile("Sonidos/Game over.wav");
	Terminado.setVolume(ver_volumen());
	
	Victory.openFromFile("Sonidos/victory.ogg");
	Victory.setVolume(ver_volumen());
	
	aplausos.loadFromFile("Efectos/applause.ogg");
	m_aplausos.setBuffer(aplausos);
	m_aplausos.setVolume(ver_sonido()-30);
	
	complete.loadFromFile("Efectos/complete.ogg");
	m_complete.setBuffer(complete);
	m_complete.setVolume(ver_sonido());
	
	enter.loadFromFile("Efectos/pause_start.ogg");
	m_enter.setBuffer(enter);
	m_enter.setVolume(ver_sonido());
	
	Player_name.setMaxChars(8);
	Texto_vuelve.setFont(m_fuente);
	Texto_vuelve.setString("No pudiste entrar al Top 5");
	Texto_vuelve.setCharacterSize(20);
	Texto_vuelve.setPosition(190,265);
	Texto_vuelve.setFillColor({255,255,255});
	
	Texto_vuelve2.setFont(m_fuente);
	Texto_vuelve2.setString("Por favor vuelve a intentarlo");
	Texto_vuelve2.setCharacterSize(20);
	Texto_vuelve2.setPosition(180,300);
	Texto_vuelve2.setFillColor({255,255,255});
	puntaje_mayor=false;
	
	Presiona.setFont(m_fuente);
	Presiona.setString("Presiona ENTER para volver al menu");
	Presiona.setCharacterSize(20);
	Presiona.setPosition(130,385);
	Presiona.setFillColor({255,255,255});
	
	
	Game.setFont(m_fuente);
	Game.setString("GAME OVER");
	Game.setCharacterSize(40);
	Game.setPosition(210,105);
	Game.setFillColor({255,0,0});
	
	
	Felicitaciones.setFont(m_fuente);
	Felicitaciones.setString("FELICITACIONES!!!");
	Felicitaciones.setCharacterSize(40);
	Felicitaciones.setPosition(130,105);
	Felicitaciones.setFillColor({0,255,0});
	
	
	Ingresaste.setFont(m_fuente);
	Ingresaste.setString("Ingresaste al Top 5");
	Ingresaste.setCharacterSize(20);
	Ingresaste.setPosition(240,305);
	Ingresaste.setFillColor({255,255,255});
	
	efectos=false;
	Al_top.setFont(m_fuente);
	Al_top.setString("Por favor ingresa tu nombre:");
	Al_top.setCharacterSize(20);
	Al_top.setPosition(170,405);
	Al_top.setFillColor({255,255,255});
	
	Player_name.setPosition(285,475);
	
	Guardado.setFont(m_fuente);
	Guardado.setString("Hemos guardado con exito tu nombre");
	Guardado.setCharacterSize(25);
	Guardado.setPosition(50,375);
	Guardado.setFillColor({0,255,0});
	
	variable2 = 0;
}
void Game_Over::CargarArchivo(){
	///Cargo el vector Binario
	ifstream puntos("points.dat",ios::binary|ios::ate);
	int tam=puntos.tellg();
	int cant=tam/sizeof(GamerBin);
	puntos.seekg(0);
	
	GamerBin pi;
	
	for (int i=0;i<cant;i++) {
		puntos.read(reinterpret_cast<char*>(&pi),sizeof(pi));
		TopBin.push_back(pi);
	}
	puntos.close();
	
	///Binario a String
	for(size_t i=0;i<TopBin.size();i++) { 
		Gamer x;
		x.jugador=TopBin[i].jugador;
		x.puntaje=TopBin[i].puntaje;
		Top.push_back(x);
	}
}
bool Game_Over::Mejor_puntuacion(){

	///Comparo
	
	R.puntaje = to_string(puntaje_final);  // Funcion que compara todos los puntajes y devuelve si el usuario a superado algun jugador previo del top 5
	for(size_t i=0;i<Top.size();i++) { 
		int aux = stoi(Top[i].puntaje);
		if(aux < puntaje_final){
			Pos=i;
			puntaje_mayor = true;
			break;
		}
	}
	return puntaje_mayor ;
}
void Game_Over::insertar(){
	Top.resize(Top.size()+1);
	for(int i=Top.size()-1;i>Pos;i--){
		Top[i]=Top[i-1];
	}
	Top[Pos]=R;
	Top.resize(Top.size()-1);
}
void Game_Over::ActualizarArchivo(){
	///String a Binario
	
	GamerBin y;
	
	for(size_t i=0;i<Top.size();i++) { 
		
		strcpy(y.jugador,Top[i].jugador.c_str());
		strcpy(y.puntaje,Top[i].puntaje.c_str());
		
		TopBin[i]=y;
		
	}
	
	
	///Actualizo Archivo
	
	ofstream arch("points.dat", ios::binary);
	for(size_t i=0;i<TopBin.size();i++) { 
		arch.write(reinterpret_cast<char*>(&TopBin[i]),sizeof(TopBin[i]));
	}
	arch.close();
}
void Game_Over::Actualizar (Juego & J) {
	if (puntaje_mayor and variable==0) {
		if(efectos==false and variable==0){ //variable booleana "Efectos" utilizada junto con variable para reproducir efectos de sonido
			m_aplausos.play();
			Victory.play();
			efectos=true;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
			variable=1;
			sf::sleep(sf::seconds(1));
		}
		
		if (Player_name.processEvent(e_v)) {						//Funcion que se utiliza para ver la entrada de texto, en donde se agrega lo ingresado a un string
			std::string string_ingresado = Player_name.getValue();
			palabras += "\n\t";
			palabras += string_ingresado;
			Player_name.setString(palabras);
			R.jugador = string_ingresado;
			sf::sleep(sf::seconds(0.17));
		}
		if(variable==1){										//En el caso que el jugador supere algun puntaje del top 5, variable pasa su valor a 1 y se inserta en el top
		insertar();
		m_complete.play();
		Presiona.setPosition(130,485);
		ActualizarArchivo();
		variable=2;}
	} else {
		if (Mejor_puntuacion()==false and variable2==0) {
			sf::sleep(sf::seconds(2));						//En el caso de game over se pide solamente que el jugador presione return para volver al menu
			Terminado.play();
			variable2 = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			J.Cambiar_Escena(new Menu());
			m_enter.play();
			sf::sleep(sf::seconds(0.3));
		}
	}
}

void Game_Over::Procesar_evento(sf::Event &e) { //Me guardo el evento actual, para poder modificarlo cuando tenga entrada de texto
	e_v=e;
}
void Game_Over::Dibujar (sf::RenderWindow & w) {
	w.clear();
	if(puntaje_mayor and variable==0){		//Segun el valor de "variable" y el estado del booleano "puntaje_mayor" se dibuja una ventana de game over u otra.
	w.draw(Felicitaciones);
	w.draw(Ingresaste);
	w.draw(Al_top);
	Player_name.update();
	w.draw(Player_name);}
	else if(puntaje_mayor and variable==2){
		w.draw(Felicitaciones);
		w.draw(Guardado);
		w.draw(Presiona);
	}
	else{
		w.draw(Game);
		w.draw(Texto_vuelve);
		w.draw(Presiona);
		w.draw(Texto_vuelve2);
	}
	w.display();
}

