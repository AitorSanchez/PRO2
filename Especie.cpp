#include "Especie.hpp"

Especie::Especie() {
}

Especie::~Especie() {
}

void Especie::cambia_preferencias(int n) {
	Npres = n;
	preferencias = vector <int> (n);
	for (int i = 0; i < n; ++i) cin >> preferencias[i];
}

bool Especie::es_carnivoro() {
	bool b = false;
	if (Npres > 0) b = true;
	return b;
}

int Especie::masa() {
	return Masa;
}

int Especie::calorias() {
	return Calorias;
}

int Especie::npres() {
	return Npres;
}


int Especie::presa_iesima(int i) {
	return preferencias[i];
}

void Especie::leer_especie() {
	cin >> Masa;
	cin >> Npres;
	if (Npres>0){
		preferencias = vector<int> (Npres);
		for (int i = 0; i < Npres; ++i) {
			cin >> preferencias[i];
		}

		cin >> Calorias;
	}
}
	

void Especie::escribir_especie() {
	cout << Masa << " " << Npres << " ";
	if (Npres > 0) {
		for (int i = 0; i < Npres; ++i) {
			cout << preferencias[i] << " ";
		}
		cout << " " << Calorias << " ";
	}
	cout << endl;
}





