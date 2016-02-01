/** @file Cjt_especies.hpp
    @brief Especificacion de la clase Cjt_especies.
*/

#ifndef CJT_ESPECIES_HPP
#define CJT_ESPECIES_HPP


#include "Especie.hpp"

/** @class Cjt_especies
    @brief Representa un conjunto de especies del ecosistema.
*/
class Cjt_especies {
private:

int N;
int C;
vector<Especie> especies;
vector<int> turnos_alimentarios;// indica el orden a seguir en la operación lucha

public:


	//Constructoras//
/** @brief Creadora por defecto.
	Se ejecuta automáticamente al declarar un conjunto de especies

	\pre: cierto
	\post: El resultado es un conjunto de especies vacío.
*/
	Cjt_especies();

/** @brief Destructora por defecto.
	Elimina un conjunto de especies.

	\pre: cierto
	\post: el conjunto ha sido eliminado
*/
	~Cjt_especies();



	//Consultoras//

/** @brief Consulta la especie iesima del conjunto.

	\pre: cierto
	\post: retorna una copia de la especie con id = i del conjunto
*/
	Especie consultar_esp(int i);
  
/** @brief Operación que permite conocer el ID de la especie con turno iesimo de lucha.

	\pre: 0 <= i <= C
	\post: retorna el ID de la especie con turno alimentario = i
*/
	int turno_iesimo(int i);

/** @brief Indica el número de especies distintas que hay en el ecosistema.

	\pre: cierto
	\post: retorna en número de especies distintas
*/
	int num_especies();

/** @brief Consulta el número de especies carnívoras que hay en el ecosistema.

	\pre: cierto
	\post: retorna el número de especies carnívoras
*/
	int num_carnivoros();

	//Modificadoras//

/** @brief Cambia las preferencias alimentarias de la especie e. Ahora tendra n presas.

	\pre: 1 <= e <= N;
	\post: se han cambiado las preferencias de la especie
*/
	void cambia_preferencias(int e, int n);

	//Lectura y escritura//

/** @brief Se lee un conjunto de especies de tamaño N de la entrada estandar.

	\pre: cierto
	\post: se ha leido el conjunto de especies
*/
	void leer_cjt_especies();

/** @brief Se escribe un conjunto de especies por el canal estandar de salida.

	\pre: cierto
	\post: se ha escrito el conjunto en el canal estandar de salida
*/
	void escribir_cjt_especies();
};
#endif

