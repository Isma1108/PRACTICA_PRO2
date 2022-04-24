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
 		@brief Pair que identifica las estadisticas de partidos y sets. (ganados-perdidos)
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
	 		\pre <em>g</em> es un entero que representa los partidos ganados y <em>p</em> los perdidos.
			\post El parámetro implícito pasa a tener <em>g</em> partidos ganados y <em>p</em> 
			partidos perdidos.
	*/
	void modificar_partidos(int g, int p);

	/** @brief Modificadora del par que almacena la información de los sets ganados/perdidos.
	 		\pre <em>g</em> es un entero que representa los sets ganados y <em>p</em> los perdidos.
			\post El parámetro implícito pasa a tener <em>g</em> sets ganados y <em>p</em> 
			sets perdidos.
	*/
	void modificar_sets(int g, int p);
	
	/** @brief Modificadora del par que almacena la información de los juegos ganados/perdidos.
	 		\pre <em>g</em> es un entero que representa los juegos ganados y <em>p</em> los perdidos.
			\post El parámetro implícito pasa a tener <em>g</em> juegos ganados y <em>p</em> 
			juegos perdidos.
	*/
	void modificar_juegos(int g, int p);

	/** @brief Modificadora del número de torneos disputados.
	 		\pre <em>cierto</em>
			\post El número de torneos disputados del parámetro implícito ha aumentado
			en una unidad.
	*/
	void nuevo_td();
		
	/** @brief Modificadora de los puntos del jugador.
			\pre <em>p</em> es un número >= 0
			\post El parámetro implícito pasa a tener <em>p</em> puntos.
		*/
	void modificar_puntos(int p);

	/** @brief Modificadora de la posicion del jugador.
			\pre <em>p</em> es un número >= 1 y <= num. jugadores del circuito. 
			\post El parámetro implícito pasa a tener posición <em>p</em>.
	*/
	void modificar_posicion(int p);
	
	//Consultoras
	
	/** @brief Consultora del número de torneos disputados. 
	 		\pre <em>cierto</em>
			\post El resultado es el número de torneos disputados del parámetro implícito.
	*/
	int consultar_td() const;
	

	/** @brief Consultora del número de partidos ganados. 
	 		\pre <em>cierto</em>
			\post El resultado es el número de partidos ganados del parámetro implícito.
	*/
	int consultar_pg() const;
	
	/** @brief Consultora del número de partidos perdidos.
	 		\pre <em>cierto</em>
			\post El resultado es el número de partidos perdidos del parámetro implícito.
	*/
	int consultar_pp() const;

	/** @brief Consultora del número de sets ganados. 
	 		\pre <em>cierto</em>
			\post El resultado es el número de sets ganados del parámetro implícito.
	*/
	int consultar_sg() const;

	/** @brief Consultora del número de sets perdidos. 
	 		\pre <em>cierto</em>
			\post El resultado es el número de sets perdidos del parámetro implícito.
	*/
	int consultar_sp() const;
	
	/** @brief Consultora del número de juegos ganados. 
	 		\pre <em>cierto</em>
			\post El resultado es el número de juegos ganados del parámetro implícito.
	*/
	int consultar_jg() const;

	/** @brief Consultora del número de juegos perdidos. 
	 		\pre <em>cierto</em>
			\post El resultado es el número de juegos perdidos del parámetro implícito.
	*/
	int consultar_jp() const;

	/** @brief Consultora de la posicion. 
	 		\pre <em>cierto</em>
			\post El resultado es el número que hace referencia a la posición del parámetro implícito dentro del ranking.
	*/
	int consultar_pos() const;
	
	/** @brief Consultora de los puntos. 
	 		\pre <em>cierto</em>
			\post El resultado es el número que hace referencia a los puntos del parámetro implícito.
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