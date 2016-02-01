#include "Area.hpp"
#include "Especie.hpp"

Area::Area(int n) {
	especies = vector<int> (n);
}

Area::~Area() {
}

int Area::num_especimenes(int e) {
	return especies[e-1];
}

void Area::lucha_region(Cjt_especies e) {
	for (int i = 0; i < e.num_carnivoros(); ++i) { 
		int n = e.turno_iesimo(i);
		int k = especies[n-1];
		Especie o = e.consultar_esp(n);
		int it = 0;
		while (k > 0) {
			int cal = o.calorias();
			while (cal > 0 and it < o.npres()) {
				int j = o.presa_iesima(it);
				if (especies[j - 1] > 0) {
					Especie g = e.consultar_esp(j);
					--especies[j - 1];
					cal = cal - g.masa();
					 
				}
				else ++it; 
			}	
			if (cal > 0) --especies[n - 1];
			--k;
		}			
	}
}

void Area::nacimiento(int e, int n) {
	especies[e - 1] += n;
}


void Area::leer_area(int k) {
	for (int i = 0; i < k; ++i) {
			especies[i] = readint();
	}
}

void Area::escribir_area(int k) {
	for (int i = 0; i < k; ++i) {
		cout << especies[i] << " ";
	}
	cout << endl;
}
