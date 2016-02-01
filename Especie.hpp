/** @file Especie.hpp
	@brief Especificacion de la clase Especie.
*/

#ifndef ESPECIE_HPP
#define ESPECIE_HPP


#include "utils.PRO2"
#include <vector>
/** @class Especie
	@brief Representa una especie del ecosistema.
*/
class Especie {
    
private: 
	int Masa;
	int Calorias;
	int Npres; 
	vector <int> preferencias;
    
public:
    //constructoras//

/** @brief Creadora por defecto
	Solo se ejecutará al crear una especie.
  
	\pre: cierto
	\post: el p.i. es una especie sin inicializar
*/
    Especie();
/** @brief Destructora por defecto.
	\pre: cierto
	\post: elimina la especie
*/
    ~Especie();
    
    //Modificadoras//

    /** @brief Modifica las preferencias de lucha de una especie.
    
	//pre: n = número de especies que el p.i. ahora considerará como presas
	//post: se han modificado las preferencias de caza del p.i.
*/
	void cambia_preferencias(int n);

	//Consultoras//
    
    /** @brief Nos dice si el parámetro implícito es carnívoro.
    
	//pre: cierto
	//post: retorna true si el p.i. es un carnivoro y false si es herbivoro
*/
	bool es_carnivoro();

/** @brief Indica la masa de una especie.

	\pre: cierto
	\post: retorna la masa del p.i.
*/
	int masa();

/** @brief Consulta las calorias que proporciona la especie a sus depredadores.

	\pre: cierto
	\post: retorna las calorias que proporciona la especie
*/
	int calorias();

/** @brief Indica el número de presas de la especie que indica el p.i.

	\pre: cierto
	\post: retorna el número de presas del p.i.
*/
	int npres();


/** @brief Consulta el id de la especie iesima de sus preferencias.

	\pre: 0 <= i < preferencias.size()
	\post: retorna el ID de su presa iesima.
*/
	int presa_iesima(int i);

	//Lectura y escritura//

/** @brief Lee una especie del canal estandar de entrada.

	\pre: cierto
	\post: se ha leido la especie
*/
	void leer_especie();

	void escribir_especie();
    
};
#endif	

