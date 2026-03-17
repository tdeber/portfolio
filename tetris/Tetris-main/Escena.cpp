#include "Escena.h"
float Escena::volumen_general = 240.0f;
float Escena::sonido_general = 240.0f;

Escena::Escena() {
	
}
void Escena::mod_volumen(float v) {
	
	volumen_general=v;
}
float Escena::ver_volumen() {
	return volumen_general;
}
void Escena::mod_sonido(float s) {
	
	sonido_general=s;
}
float Escena::ver_sonido() {
	return sonido_general;
}
Escena::~Escena() {
	
}
