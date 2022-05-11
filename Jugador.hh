/** @file Jugador.hh
 		@brief Especificación de la clase Jugador
*/

#ifndef JUGADOR_HH
#define JUGADOR_HH

#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;

/** @typedef Estadisticas
 		@brief Pair que identifica las estadisticas de partidos, sets y juegos. (ganados-perdidos)
*/
typedef pair<int,int> Estadisticas;

/** @class Jugador
 		@brief Representa un jugador del circuito de torneos de tenis.
		
		Dispone de ciertos atributos que definen al jugador.
		Como detalle, todas las operaciones son de <b>coste constante</b>.
*/

class Jugador 
{
private:
	//no es necesario guardar el nombre del jugador como atributo
	//ya que el map de jugadores tiene como clave ese nombre
	int torneos_disputados;
	int posicion;
	int puntos;
	Estadisticas partidos; //Par de partidos ganados y perdidos
	Estadisticas sets; //Par de sets ganados y perdidos
	Estadisticas juegos; //Par de juegos ganados y perdidos

public:
	//Constructoras
		
	/** @brief Creadora por defecto
			Se ejecuta automáticamente al declarar un jugador.
			\pre <em>cierto</em>
			\post El resultado es un jugador el cual todos sus atributos son cero. 
	*/
	Jugador();
	
	/** @brief Creadora con valores concretos.
			\pre <em>cierto</em>
			\post El resultado es un jugador con posición <em>p</em> y el resto de 
			estadisticas a cero. 
	*/
	Jugador(int p);

	//Modificadoras

	/** @brief Modificadora del par que almacena la información de los partidos ganados/perdidos.
	 		\pre <em>pr/em> es un par que tine como primer elemento un entero que representa los 
			partidos ganados y como segundo elemento uno que representa los perdidos.
			\post El parámetro implícito pasa a tener los partidos ganados que ya tenia +
			<em>pr.first()</em> y los perdidos que ya tenia + <em>pr.second()</em>.
	*/
	void modificar_partidos(pair<int,int> pr);

	/** @brief Modificadora del par que almacena la información de los sets ganados/perdidos.
	 		\pre <em>s/em> es un par que tine como primer elemento un entero que representa los 
			sets ganados y como segundo elemento uno que representa los perdidos.
			\post El parámetro implícito pasa a tener los sets ganados que ya tenia +
			<em>pr.first()</em> y los perdidos que ya tenia + <em>pr.second()</em>.
	*/
	void modificar_sets(pair<int,int> s);
	
	/** @brief Modificadora del par que almacena la información de los juegos ganados/perdidos.
	 		\pre <em>j/em> es un par que tine como primer elemento un entero que representa los 
			juegos ganados y como segundo elemento uno que representa los perdidos.
			\post El parámetro implícito pasa a tener los juegos ganados que ya tenia +
			<em>pr.first()</em> y los perdidos que ya tenia + <em>pr.second()</em>.
	*/
	void modificar_juegos(pair<int,int> j);

	/** @brief Modificadora del número de torneos disputados.
	 		\pre <em>cierto</em>
			\post El número de torneos disputados del parámetro implícito es aumentado
			en una unidad.
	*/
	void nuevo_td();
		
	/** @brief Modificadora de los puntos del jugador.
			\pre <em>p</em> es un entero
			\post El parámetro implícito pasa a tener los puntos que ya tenia + <em>p</em> puntos.
		*/
	void modificar_puntos(int p);

	/** @brief Modificadora de la posicion del jugador.
			\pre <em>p</em> es un número >= 1 y <= número de jugadores del circuito. 
			\post El parámetro implícito pasa a tener posición <em>p</em>.
	*/
	void modificar_posicion(int p);
	
	//Consultoras

	/** @brief Consultora de la posicion. 
	 		\pre <em>cierto</em>
			\post Se devuelve la posición del parámetro implícito.
	*/
	int consultar_pos() const;
	
	/** @brief Consultora de los puntos. 
	 		\pre <em>cierto</em>
			\post Se devuelven los puntos del parámetro implícito.
	*/
	int consultar_puntos() const;
	
	//Escritura del jugador	
	
	/** @brief Operación de escritura.
			\pre <em>cierto</em>
			\post Se han escrito los atributos del parámetro implícito en el canal standard de salida.
	*/
	void escribir() const;
};

#endif
