/** @file Cjt_areas.hpp
    @brief Especificacion de la clase Cjt_areas.
*/

#ifndef CJT_AREAS_HPP
#define CJT_AREAS_HPP

#include "utils.PRO2"
#include "Area.hpp"
#include <vector>
#include "Arbre.hpp"
#include "Cjt_especies.hpp"

/** @class Cjt_areas
    @brief Representa el conjunto de areas que forman el ecosistema.
*/
class Cjt_areas {
private:

int Planicie;
int R; //número de áreas que hay en el ecosistema
int N;//numero de especies q habra en cada area
vector<Area> areas;//vector que contiene una serie de áreas con sus respectivos datos
Arbre<int> a;//arbol que simula las ramificaciones del ecosistema(los nodos tienen el valor de los ID de las áreas del ecosistema)


public:
	//Constructoras//

/** @brief Creadora por defecto.
	Se ejecuta automáticamente al declarar un área

	\pre: cierto
	\post: El resultado es un conjunto de áreas vacías.
*/
	Cjt_areas(int R, int N);

/** @brief Destructora por defecto.
	Elimina el conjunto de áreas.

	\pre: cierto
	\post: el conjunto ha sido eliminado
*/
	~Cjt_areas();

	//Consultoras//



/** @brief Indica si el área a es la planicie central.

	\pre: cierto
	\post: retorna true si a es la planicie central
*/
	bool es_planicie(int a);
/** @brief Consulta la especie con id = e del área iesima del conjunto.

	\pre:  0 <= i <= R y 0 <= j <= C
	\post: retorna el nº de habitantes de la especie especificada en el área especificada
*/
	int consultar_especie(int i, int e);

/** @brief Indica si una región es periférica o no.

	\pre: cierto
	\post: retorna true si r es region periférica, false si no
*/
	bool es_periferia(int r, Arbre<int> a);

/** @brief Consulta el identificador del área planicie central.

	\pre: cierto
	\post: retorna el ID de la planicie central
*/
	int planicie();

/** @brief Operación que consulta la estructura del ecosistema en forma de arbol.

	\pre: cierto
	\post: retorna el arbol que describe el ecosistema
*/
	Arbre<int> arbol_areas();

	//Modificadoras//


	

/** @brief Desencadena una lucha por la supervivencia de las especies en todo el conjunto de áreas.

	\pre: cierto
	\post: la lucha ha finalizado
*/
	void lucha_especies(Cjt_especies c);

/** @brief Se lleba a cabo una migración de tipo 1, desde un área r, de un número de indivíduos h de una especie e, teniendo en cuenta un factor g.

	\pre: cierto
	\post: se ha realizado la migración
*/
	void migracion_a(Arbre<int> a, int r, int e, int h, int g);

/** @brief Se lleba a cabo una migración de tipo 2, desde un área r, de un número de indivíduos h de una especie e, teniendo en cuenta un factor g.

	\pre: cierto
	\post: se ha realizado la migración
*/
	pair<bool, int> migracion_b(Arbre<int> a, int r, int e, int h, int g);

/** @brief Operación que incrementa los indivíduos de una especie e, del área a en n.

	\pre: 1 <= a <= R; 1 <= e <= N
	\post: se ha modificado el numero de individuos de e en a
*/
	void anade_especimenes(int a, int e, int n);

	//Lectura y escritura//

/** @brief Operación para leer el arbol que describe el ecosistema.

	\Pre: a esta bacio; el canal estandar de entrada contiene el recorrido en preorden de un arbol binario A de enteros marcado con "marca"  
	\Post: a = A
*/
	void leer_arbol(Arbre<int>& a, int marca);

/** @brief Se lee un conjunto de áreas del canal estandar de entrada.

	\pre: R indica el tamañano del conjunto
	\post: Se ha leido el conjunto
*/
	void leer_cjt_areas();

/** @brief Imprime por pantalla todas las áreas del ecosistema.

	\pre: cierto
	\post: se han imprimido por pantalla todas las áreas
*/
	void escribir_cjt_areas();
	

};
#endif
	

