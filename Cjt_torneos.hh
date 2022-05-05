/** @file Cjt_torneos.hh
    @brief Especificación de la clase Cjt_torneos
*/

#ifndef CJT_TORNEOS_HH
#define CJT_TORNEOS_HH

#include "Torneo.hh"
#include "Cjt_jugadores.hh"
#include "Cjt_categorias.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif

using namespace std;

/** @class Cjt_torneos
    @brief Facilita la gestión de un conjunto de torneos (obj. 'Jugador')

		La clase tiene el propósito de gestionar un conjunto de torneos. Ésta permite
		añadir, dar de baja, iniciar y finalizar torneos, así como listarlos por 
		orden creciente de identificador (nombre).
*/

class Cjt_torneos
{
private:
	int T; //número total de torneos
	map<string, Torneo> torneos;

public:
	//Constructoras
	
	/** @brief Creadora por defecto
	    \pre <em>cierto</em>
			\post El resultado es un Cjt_torneos con el número total de torneos a 0
			y la estructura que se encarga de almacenar los torneos se encuentra 
			vacía, sin elementos.
	*/
	Cjt_torneos();

	//Modificadoras
	
	/** @brief Modificadora que añade un nuevo torneo al conjunto de torneos, 
	 		en caso que no exista ya uno igual que el que se desea añadir.
	    \pre <em>t</em> es un identificador válido de un torneo y <em>c</em> 
			es un entero entre 1 y C que hace referencia a una categoria válida de torneo.
			\post En caso de que el torneo con identificador <em>t</em> ya exista en
			el conjunto de torneos, no se hace nada y se devuelve false. En caso contrario,
			antes de devolver true, el número total de torneos se ha incrementado en uno, 
			y el torneo con identificador <em>t</em> de categoria <em>c</em> se ha añadido 
			al conjunto. Posteriormente a esto, se imprime por el canal standard de salida 
			el número total de torneos.
	*/
	bool nuevo_torneo(const string& t, int c);
	
	/** @brief Modificadora que da de baja a un torneo del conjunto de torneos, en caso
	 		de que éste exista en el conjunto.
	    \pre <em>t</em> es un identificador válido de un torneo.
			\post En caso de que no exista un torneo con identificador <em>t</em> en el 
			conjunto, no se hace nada y se devuelve false. En caso contrario, antes de devolver
			true, el ranking ha sido actualizado después de restar los puntos conseguidos
			por los jugadores de una posible edición pasada del torneo con identificador
			<em>t</em>, el número total de torneos ha decrementado en uno, y el torneo en
			cuestión ha sido eliminado del conjunto. Posteriormente a esto, se imprime
			por el canal standard de salida el número total de torneos.
	*/
	bool baja_torneo(const string& t, Cjt_jugadores& j);

	/** @brief Modificadora que se encarga de "iniciar" un torneo.
	    \pre <em>cierto</em>, ya que se garantiza que el torneo <em>t</em>
			existe en el circuito.
			\post Se ha leído la inscripción del torneo <em>t</em> y se ha confeccionado 
			e impreso el cuadro de emparejamientos de los jugadores inscritos.
	*/
	void iniciar_torneo(const string& t, const Cjt_jugadores& j);

	/** @brief Modificadora que se encarga de "finalizar" un torneo.
	    \pre <em>cierto</em>, ya que se garantiza que el torneo <em>t</em> 
			existe en el circuito y que previamente se ha ejecutado el comando
			<em>iniciar_torneo</em>.
			\post Se han leído los resultados del torneo <em>t</em>, se ha producido
			e impreso el cuadro oficial de resultados y se han listado los puntos para 
			el ránking ganados por cada uno de los participantes, por orden de ranking 
			en el momento de iniciar el torneo. Además, se han actualizado el ranking
			y las estadísticas de los jugdores.
	*/
	void finalizar_torneo(const string& t, Cjt_jugadores& j, const Cjt_categorias& c);

	void eliminar_puntos(const string& p);
	
	//Escritura
	
	/** @brief Operación de escritura
			\pre <em>cierto</em>
			\post Se ha listado en el canal standard de salida, por orden creciente de
			identificador (nombre), el nombre y la categoria de cada torneo del circuito.
	*/
	void listar_torneos(const Cjt_categorias& c) const;
	
	//Lectura
	
	/** @brief Método que se encarga de inicializar los atributos del conjunto,
	 		dados unos datos por el canal standard de entrada.
			\pre Está disponible en el canal standard de entrada un número T >= 0, seguido
			de una secuencia de T pares de string t y entero c, donde t será el nombre
			que identifica al torneo (sin repeticiones) y c la categoria entre 1 y C
			a la que pertenece el torneo.
			\post El parámetro implícito ha sido modificado de forma que se han almacenado
			T torneos en la estructura que se encarga de faciltar su gestión.
	*/
	void lectura_inicial();
};

#endif
