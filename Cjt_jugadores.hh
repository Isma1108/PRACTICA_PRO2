/** @file Cjt_jugadores.hh
 		@brief Especificación de la clase Cjt_jugadores
*/

#ifndef CJT_JUGADORES_HH
#define CJT_JUGADORES_HH

#ifndef NO_DIAGRAM
#include <vector>
#include <map>
#endif

#include "Jugador.hh"

using namespace std;

typedef map<string,Jugador>::iterator map_it;

/** @class Cjt_jugadores
 		@brief Facilita la gestión de un conjunto de jugadores (obj. 'Jugador')

		La clase tiene el propósito de gestionar un conjunto de jugadores. Ésta permite
		añadir y dar de baja jugadores, así como listarlos, ya sea en conjunto o de forma
		individual. Además almacena en un ranking a los jugadores en función de sus puntos.
*/

class Cjt_jugadores
{
private:
	int P; //numero total de jugadores
	map<string,Jugador> jugadores;
	vector<map_it> ranking;

public:
	//Constructoras
	
	/** @brief Creadora por defecto
	 		\pre <em>cierto</em>
			\post El resultado es un Cjt_jugadores con el numero total de jugadores a 0
			y las estructuras que se encargan de almacenar los datos de los jugadores se 
			encuentran vacías, sin elementos.
	*/
	Cjt_jugadores();
	
	//Modificadoras

	/** @brief Modificadora que añade un nuevo jugador al conjunto de jugadores, en caso de 
	 		que éste no exista en él previamente.
			\pre <em>p</em> es un identificador de un jugador (no tiene porque ser del conjunto).
			\post Se devuelve false en caso de que ya exista un jugador con identificador
			<em>p</em>, y en caso contrario, a parte de devolver true, el número total 
			de jugadores se ha incrementado en uno, y el jugador con identificador <em>p</em> 
			se ha añadido al conjunto, con estadísticas a cero y última posición en el ranking. 
			Además, se imprime por el canalstandard de salida el número 
			total de jugadores.
	*/
	bool nuevo_jugador(const string& p);

	/** @brief Modificadora que da de baja un jugador del conjunto de jugadores, en caso de
	 		que éste exista en él previamente.
	 		\pre <em>p</em> es un identificador de un jugador (no tiene porque ser del conjunto).
			\post Se devuelve false en caso de que no exista un jugador con identificador <em>p</em>
			en el conjunto, y en caso contrario, a parte de devolver true, el ranking ha sido 
			actualizado desplazando una posición hacia arriba a los jugadores siguientes del ranking, 
			el número total de jugadores ha decrementado en uno, y el jugador con identificador 
			<em>p</em> ha sido eliminado del conjunto.
	*/
	bool baja_jugador(const string& p);

	/** @brief Modificadora que se encarga de restar puntos a ciertos jugadores
	 		dado un vector con es información, además de mantener el orden definido
			para el ranking.
			\pre <em>datos</em> es un vector de Jugadores que tiene la información de todas 
			sus estadísticas en un torneo concreto.
			\post Se han restado a los jugadores respectivos del conjunto de jugadores los 
			puntos que habían ganado en el torneo en cuestión (información disponible en el
			vector), además de que se mantiene el orden definido para el ranking.
	*/
	void restar_puntos(const vector<Jugador>& datos);

	/** @brief Modificadora que se encarga de actualizar las estadísticas de ciertos 
	    jugadores dado un vector con esa información, además de mantener el orden 
			definido para el ranking.
			\pre <em>datos</em> es un vector de Jugadores que tiene la información de todas 
			sus estadísticas en un torneo concreto.
			\post Se han actualizado las estadísticas de los jugadores respectivos del
			conjunto de jugadores, además de que se mantiene el orden definido para el ranking.
	*/
	void actualizar_ranking(const vector<Jugador>& datos);

	//Consultoras
		
	/** @brief Consultora que permite saber si un jugador ya existe en el conjunto
	 		\pre <em>p</em> es un identificador válido de un jugador.
			\post Se devuelve true en caso de que el jugador con identificador <em>p</em>
			exista en el conjunto, false en caso contrario.
	*/
	bool existe_jugador(const string& p) const;

	/**
	
	*/
	string nombre_jugador(int pos) const;

	//Escritura	
	
	/**	@brief Operación de escritura
			\pre <em>cierto</em>
			\post Se ha listado en el canal standard de salida, por orden creciente del 
			ranking vigente, la posicion, el nombre y los puntos de cada jugador del conjunto.
	*/
	void listar_ranking() const;

	/**	@brief Operación de escritura
			\pre <em>cierto</em>
			\post Se ha listado en el canal standard de salida, por orden creciente de
			identificador (nombre), la posición en el ranking, los puntos y el resto 
			de estadísticas de cada jugador del conjunto.
	*/
	void listar_jugadores() const;

	/**	@brief Operación de escritura
			\pre <em>p</em> es un identificador válido de un jugador existente en el conjunto.
			\post Se devuelve false en caso de que no exista un jugador con identificador
			<em>p</em>, y en caso contrario, se devuelve true y se ha listado en el canal standard 
			de salida el nombre, la posición en el ranking, los puntos y el resto de estadísticas 
			del jugador con identificador <em>p</em>.
	*/
	bool consultar_jugador(const string& p) const;

	//Lectura

	/** @brief Método que se encarga de inicializar los atributos del conjunto,
			dados unos datos por el canal standard de entrada.
			\pre Está disponible en el canal standard de entrada un número P >= 0, seguido de una
			secuencia de P strings con los nombres que identifican a los jugadores (sin repeticiones).
			\post El parámetro implícito ha sido modificado de forma que se han almacenado P jugadores
			en las estructuras que se encargan de facilitar su gestión. Todas las estadísticas de los jugadores,
			a excepción de su posición en el ranking, son inicializadas a cero.
	*/
	void lectura_inicial();
};

#endif
