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

/** @typedef map_it
 		@brief Iterador que apunta a elementos de un map que tiene como llave un string
		(que representa el nombre del jugador) y como contenido un objeto de tipo 'Jugador'.
*/
typedef map<string,Jugador>::iterator map_it;

/** @class Cjt_jugadores
 		@brief Facilita la gestión de un conjunto de jugadores (obj. 'Jugador')

		La clase tiene el propósito de gestionar un conjunto de jugadores. Ésta permite
		añadir y dar de baja jugadores, así como listarlos, ya sea en conjunto o de forma
		individual. Además almacena en un ranking a los jugadores en función de sus puntos
		y permite listar a los jugadores en función de su posición en el ranking.
*/

class Cjt_jugadores
{
private:
	int P; //!< Número total de jugadores del circuito.
	map<string,Jugador> jugadores; //!< Map que almacena a los jugadores del circuito en orden lexicográfico.

	/** @brief Vector de iteradores que apuntan a los jugadores del 
	 		circuito siguiendo un orden basado en us puntos, funcionando como un ranking.
	*/
	vector<map_it> ranking; 

	/** @brief Función booleana estática que se usa para ordenar el vector de iteradores 
	 		<em>ranking</em>.
			\pre <em>a</em> y <em>b</em> son iteradores que apuntan a jugadores existentes y
			distintos del map de jugadores.
			\post se devuelve true o false en función de si el jugador apuntado por <em>a</em>
			deberia ir por delante en el ranking que el jugador apuntado por <em>b</em>
	*/
	static bool comp(const map_it& a, const map_it& b);

public:
	//Constructoras
	
	/** @brief Creadora por defecto
	 		\pre <em>cierto</em>
			\post El resultado es un Cjt_jugadores con el numero total de jugadores a 0
			y las estructuras que se encargan de almacenar los datos de los jugadores se 
			encuentran vacías.
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
			Además, se imprime por el canal standard de salida el número total de jugadores.
	*/
	bool nuevo_jugador(const string& p);

	/** @brief Modificadora que da de baja un jugador del conjunto de jugadores, en caso de
	 		que éste exista en él previamente.
	 		\pre <em>p</em> es un identificador de un jugador (no tiene porque ser del conjunto).
			\post Se devuelve false en caso de que no exista un jugador con identificador <em>p</em>
			en el conjunto, y en caso contrario, a parte de devolver true, el ranking ha sido 
			actualizado desplazando una posición hacia arriba a los jugadores siguientes del ranking, 
			el número total de jugadores ha decrementado en uno, y el jugador con identificador 
			<em>p</em> ha sido eliminado del conjunto. Además, se imprime por el canal standard de
			salida el número total de jugadores.
	*/
	bool baja_jugador(const string& p);

	/** @brief Modificadora que se encarga de restar puntos a un jugador.
	 		\pre <em>p</em> es un string que identifica a un jugador, que puede o no existir 
			en el conjunto de jugadores, y <em>n</em> los puntos que se le deberia restar. 
			\post En caso de que exista un jugador con nombre <em>p</em> en el conjunto de
			jugadores este pasa a tener <em>n</em> puntos menos.
	*/
	void restar_puntos(const string& p, int n);

	/** @brief Modificadora que se encarga de actualizar ciertos datos de un jugador del conjunto
	 		dado su nombre.
			\pre <em>p</em> es un identificador de un jugador existente en el conjunto, <em>pts</em>
			es un entero que representa los puntos que hay que sumarle, y <em>j</em>, <em>s</em> y 
			<em>pr</em> son pares que almacenan información de los juegos, sets y partidos (ganados - 
			perdidos) que se deberian sumar a las estadísticas del jugador.
			\post Las estadísticas del jugador con nombre <em>p</em> han sido actualizadas en base a la 
			información pasada por parámetro.
	*/
	void actualizar_datos(const string& p, int pts, pair<int,int> j, pair<int,int> s, 
			pair<int,int> pr);

	/** @brief Modificadora que se encarga de reordenar el vector de iteradores del conjunto
	 		que representa el ranking del circuito.
			\pre <em>cierto</em>
			\post El ranking del circuito ha sido reordenado de forma que aparecen primero los 
			jugadores con mas puntos y, en caso de empate, los que ocupaban una mejor posición antes
			del reordenamiento.
	*/
	void reordenar_ranking();

	//Consultoras
		
	/** @brief Consultora que devuelve el nombre de un jugador del conjunto dada su posicion
	 		en el ranking.
			\pre <em>pos</em> es un entero que representa una posicion entre 1 y el numero de jugadores
			del circuito, ambos incluidos.
			\post Se devuelve el nombre del jugador que ocupa la posicion <em>p</em> en el ranking.
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
			<em>p</em>, y en caso contrario, se devuelve true y se lista en el canal standard 
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
