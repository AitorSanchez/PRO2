/** @mainpage pro2
*/

/** @file pro2.cpp
    @brief Programa principal de la práctica.
*/


#include <vector>
#include "utils.PRO2"
#include "Cjt_areas.hpp"
#include "Cjt_especies.hpp"

/** @brief El progrma utilizara las clases Especie, Area, Cjt_especies y Cjt_areas
*/
int main() {
	Cjt_especies c;
	c.leer_cjt_especies();	
	int R = readint();
	int n = c.num_especies();
    Cjt_areas E(R,n) ;
	E.leer_cjt_areas();
    int accion = readint();
    while (accion != -6) {
		if (accion == -1) {
			E.lucha_especies(c);
		}
		else if (accion == -2) {
			int t = readint();
			int r = readint();
			int e = readint();
			int h = readint();
			int g = readint();
			Arbre<int> b = E.arbol_areas();
			if (t == 1) {
				if (r != b.arrel()) {
						Arbre <int> a1;
						Arbre <int> a2;
						b.fills(a1, a2);
					while (a1.arrel() != r and a2.arrel() != r) {
						Arbre <int> a3;
						a1 = a3;
						a2 = a3;
						b.fills(a1, a2);
					}
					if (a1.arrel() == r) b = a1;
					else b = a2;
				}	
				E.anade_especimenes(r, e, h*(-1));	
				E.migracion_a(b, r, e, h, g);
			}
			else {
				pair<bool, int> x;
				x = E.migracion_b(b, r, e, h, g);
			}
		}

		else if (accion == -3) {
			int m = readint();
			int e = readint();
			int r = readint();
			E.anade_especimenes(r, e, m);
		}
		else if (accion == -4) {
			int e = readint();
			int n = readint();
			c.cambia_preferencias(e, n);
		}
		else if (accion == -5) {
			E.escribir_cjt_areas();
		}
		cin >> accion;
    }
}
		
