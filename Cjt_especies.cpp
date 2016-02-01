#include "Cjt_especies.hpp"

Cjt_especies::Cjt_especies(){
}

Cjt_especies::~Cjt_especies(){
}

Especie Cjt_especies::consultar_esp(int i) {
	return especies[i - 1];
}

int Cjt_especies::turno_iesimo(int i) {
	return turnos_alimentarios[i];
}

void Cjt_especies::cambia_preferencias(int e, int n) {
	especies[e-1].cambia_preferencias(n);
}

void Cjt_especies::leer_cjt_especies() {
	N = readint();
	C = readint();
	turnos_alimentarios = vector<int> (C);
	especies = vector<Especie> (N);
	for (int i = 0; i < N; ++i) {
		especies[i].leer_especie();
	}
	for (int i = 0; i < C; ++i) {
		cin >> turnos_alimentarios[i];
	}
}

void Cjt_especies::escribir_cjt_especies() {
	for (int i = 0; i < N; i++) {
		especies[i].escribir_especie();
	}
	for (int i = 0; i < C; ++i) {
		cout << turnos_alimentarios[i] << " ";
	}
	cout << endl;
}

int Cjt_especies::num_especies() {
	return N;
}

int Cjt_especies::num_carnivoros() {
	return C;
}
