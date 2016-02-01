#include "Cjt_areas.hpp"
#include "Arbre.hpp"


Cjt_areas::Cjt_areas(int r, int n) {
	R = r;
	N = n;
	areas = vector<Area> (R, Area(N));
}

Cjt_areas::~Cjt_areas() {
}

bool Cjt_areas::es_planicie(int a) {
	bool b = false;
	if (a == Planicie) b = true;
	return b;
}

int Cjt_areas::consultar_especie(int i, int e) {
	return areas[i].num_especimenes(e);
}


void Cjt_areas::lucha_especies(Cjt_especies c) {
	for (int i = 0; i < R; ++i) {
		areas[i].lucha_region(c);
	}
}

void Cjt_areas::anade_especimenes(int a, int e, int n) 	{
	areas[a - 1].nacimiento(e,n);
}

void Cjt_areas::leer_cjt_areas() {
	leer_arbol(a, 0);
	Planicie = a.arrel();
	for (int i = 0; i < R; ++i) {
		areas[i].leer_area(N);
	}
}

void Cjt_areas::escribir_cjt_areas() {
	for (int i = 0; i < R; ++i) {
		areas[i].escribir_area(N);
	}
	cout << endl;
}

void Cjt_areas::leer_arbol(Arbre<int>& a, int marca){
  Arbre<int> a1;
  Arbre<int> a2;
  int x;
  cin >> x;
  if (x!= marca) {
    leer_arbol(a1, marca);
    leer_arbol(a2, marca);
    a.plantar(x,a1,a2);
  }
}
bool Cjt_areas::es_periferia(int r, Arbre<int> a) {
	Arbre<int> a1;
	Arbre<int> a2;
	a.fills(a1, a2);
	return a1.es_buit();
}

void Cjt_areas::migracion_a(Arbre<int> a, int r, int e, int h, int g) {
	if (not es_periferia(r, a) and h >= g) {
		Arbre <int> a1;
		Arbre <int> a2;
		a.fills(a1, a2);
		if (a2.es_buit()) {
			if (not a1.es_buit()) {
				areas[r - 1].nacimiento(e, h/2);
				r = a1.arrel();
				h = h - (h/2);	
				migracion_a(a1, r, e, h, g);
			}
			else areas[r-1].nacimiento(e, h);
		}
		else {
			int k = h - h/2;
			h = h/2;
			r = a1.arrel();
			migracion_a(a1, r, e, k, g);
			r = a2.arrel();
			migracion_a(a2, r, e, h, g);
		}
	}
	else {
		areas[r - 1].nacimiento(e, h);
	}
}

pair<bool, int> Cjt_areas::migracion_b(Arbre<int> a, int r, int e, int h, int g) {
	pair<bool, int> b;
	if (a.arrel() != r) {
		Arbre<int> a1; 
		Arbre<int> a2;
		int raiz = a.arrel();
		a.fills(a1, a2);
		if (not a1.es_buit()) {
			b = migracion_b(a1, r, e, h, g);
			if (b.first)  {
				if (es_planicie(raiz)) {
					areas[raiz - 1].nacimiento(e, b.second);
				}
				else {
					if (b.second >= g) {
						areas[raiz - 1].nacimiento(e, b.second/2);
						b.second -= b.second/2;
						b.first = true;
					}
					else {
						areas[raiz - 1].nacimiento(e, b.second);
						b.first = false;
						b.second = 0;
					}
				}
			}	
			else {
				if (not a2.es_buit()) {
					b = migracion_b(a2, r, e, h, g);
					if (b.first)  {
						if (es_planicie(raiz)) {
							areas[raiz - 1].nacimiento(e, b.second);
						}
						else {
							if (h >= g) {
								areas[raiz - 1].nacimiento(e, b.second/2);
								b.second -= b.second/2;
								b.first = true;
							}
							else {
								areas[raiz - 1].nacimiento(e, b.second);
								b.first = false;
								b.second = 0;
							}
						}
					}
				}
			}
		}		
	}

	else {
		areas[r - 1].nacimiento(e, h*(-1));
		b.first = true;
		b.second = h;
	}
	return b;
}
	

Arbre<int> Cjt_areas::arbol_areas() {
	return a;
}
		
