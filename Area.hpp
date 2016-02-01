/** @file Area.hpp
	@brief Especificación de la clase Area.
*/

#ifndef AREA_HPP
#define AREA_HPP

#include "Especie.hpp"
#include "Cjt_especies.hpp"

/** @class Area
	@brief Representa un territorio del ecosistema.
*/

class Area {
private:
	vector<int>especies;//v[i-1] = num.especie con ID = i en el área.

public:
	//Constructoras//
/** @brief Creadora por defecto.
	Se ejecuta automáticamente al declarar un área

	\pre: cierto
	\post: El resultado es un área vacía cuyo vector de especies será de tamaño N.
*/
	Area(int n);

/** @brief Destructora por defecto.
	Elimina el área.

	\pre: cierto
	\post: el area ha sido eliminada
*/
	~Area();

	//Consultoras//


/** @brief Indica el número de indivíduos de una especie en el área.

	\pre: cierto
	\post: retorna el número de especímenes en el área
*/

	int num_especimenes(int e);

	//Modificadoras//

/** @brief Realiza una lucha en la región p.i.

	\pre: cierto
	\post: se ha realizado la lucha en la región
*/
	void lucha_region(Cjt_especies e);

/** @brief Operación que aumenta en n el número de individuos de una especie e en el p.i.

    \pre: cierto
	\post: se ha incrementado el numero de individuos de la especie e en el p.i.
*/
	void nacimiento(int e, int n);

	//Lectura y escritura//

/** @brief Lee un area del canal estandar de lectura.

	\pre: cierto
	\post: se ha leido la especie con exito
*/
	void leer_area(int k);

/** @brief Escribe por pantalla las especies y sus especímeness del area p.i.

	\pre: cierto
	\post: se ha escrito en el canal estandar de salida
*/
	void escribir_area(int k);

};
#endif
