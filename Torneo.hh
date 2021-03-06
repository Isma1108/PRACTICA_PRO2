/** @file Torneo.hh
 		@brief Especificación de la clase Torneo
*/

#ifndef TORNEO_HH
#define TORNEO_HH

#include "Cjt_categorias.hh"
#include "Cjt_jugadores.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <map>
#endif

using namespace std;

/** @struct Participante
 		@brief Struct que almacena la información de un participante de un torneo.
*/

struct Participante {
	string nombre; //!< Nombre del participante.
	int puntos; //!< Puntos que ha ganado el participante en el torneo.
	pair<int,int> juegos_gp; //!< Par de juegos (ganados-perdidos) del participante en el torneo.
	pair<int,int> sets_gp; //!< Par de sets (ganados-perdidos) del participante en el torneo.
	pair<int,int> partidos_gp; //!< Par de partidos (ganados-perdidios) del participante en el torneo,
};

/** @class Torneo
 		@brief Almacena la información de un torneo y facilita su gestión.

		Gestiona la información de un torneo:
		<ul>
			<li>Identificador de su categoria</li>
			<li>Jugadores inscritos</li>
			<li>Cuadro de emparejamientos</li>
			<li>Cuadro de resultados</li>
			<li>Puntos ganados por los jugadores (y sus estadísticas "locales")</li>
		</ul>

		Además de esto, permite confeccionar los emparejamientos del torneo dados los participantes,
		leer los resultados del torneo, y acceder al conjunto de jugadores del circuito para hacer
		las modificaciones pertinentes en base a los puntos y las estadísticas ganadas durante el 
		transcurso del torneo en cuestión.
*/

class Torneo
{
	private:
		//no es necesario guardar el nombre del torneo como atributo
		//ya que el map de torneos tiene como llave ese nombre.
		int categoria; //!< Identificador numérico de la categoria del torneo.
		vector<Participante> participantes; //!< Vector de participantes del torneo vigente.
		/** @brief Map que almacena la información de la edición anterior del torneo, en caso
		 		de existir. Tiene como llave el nombre de los participantes de la edición anterior, 
				y como contenido los puntos que éstos habían ganado. (Como detalle, se usa un map
				para hacer más eficiente la búsqueda de un jugador en ediciones anteriores dado su 
				nombre, cuando éste es borrado del circuito, ya que el coste de búsqueda pasa a ser 
				logarítmico).
		*/
		map<string,int> edicion_anterior;
		BinTree<int> enf; //!< Árbol binario de enteros que almacena la información de los enfrentamientos.
		BinTree<string> resultados; //!< Árbol binario de strings que almacena información de los resultados.
	
		/** @brief Función que confecciona el árbol binario de emparejamientos.
				\pre <em>a</em> es un árbol binario de enteros con un único nodo raíz con valor 1,
				<em>n</em> es el número de jugadores inscritos en el torneo y <em>prod</em> se trata
				de un valor que va almacenando potencias de dos en las llamadas recursivas, para 
				saber en que momento se debe parar la recursión. Por ende, el parámetro de la 
				llamada inicial debe ser 2.
				\post El árbol binario <em>a</em> ha sido modificado de forma que las hojas representan
				los emparejamientos iniciales del torneo.
		*/
		void emparejamientos(BinTree<int>& a, int n, int prod);

		/** @brief Función que se encarga de imprimir los emparejamientos iniciales del torneo.
		 		\pre <em>a</em> es un árbol binario de enteros el cual sus hojas representan los 
				emparejamientos iniciales.
				\post Han sido escritos por el canal standard de salida los emparejamientos iniciales
				del torneo.
		*/
		void imprimir(const BinTree<int>& a) const;
	
		/** @brief Función que se encarga de leer los resultados del torneo y almacenar esta 
		 		información en un árbol binario de strings. 
				\pre <em>a</em> es un árbol binario de strings y estan disponibles en el canal standard
				de entrada los resultados del torneo en preorden.
				\post El árbol binario <em>a</em> ha sido modificado de forma que en todos los nodos hay
				la información del partido pertinente.
		*/
		void lectura_res(BinTree<string>& a);

		/** @brief Función que se encarga de imprimir los resultados del torneo.
		 		\pre <em>a1</em> es un árbol binario de strings que tiene en sus nodos la información
				de los partidos del torneo, y <em>a2</em> es un árbol binario de enteros donde en las
				hojas hay los jugadores del emparejamiento inicial y en los demás nodos los jugadores
				que han ganado el partido que enfrentaba a los dos hijos del nodo. En otras palabras,
				el árbol <em>a2</em> tiene un nivel mas que el <em>a1</em> y para cada nodo del árbol 
				<em>a1</em> hay el resultado de el partido que enfrentaba a los jugadores que se 
				identifican en los hijos del nodo paralelo en el árbol <em>a2</em>.
				\post Han sido escritos por el canal standard de salida los resultados del torneo.
		*/
		void imprimir_res(const BinTree<string>& a1, const BinTree<int>& a2) const; 
		
		/** @brief Función que devuelve el ganador dado un resultado.
		 		\pre <em>p</em> es un string que hace referencia a un resultado de un partido entre 
				dos jugadores del torneo.
				\post Identificando el partido como un enfrentamiento entre a y b, donde a está a la 
				izquierda del cuadro y b a la derecha, de devuelve 1 si gana a y 2 si gana b.
		*/
		int ganador(const string& p) const;

		/** @brief Función que actualiza las estadísticas "locales" de los jugadores del torneo
				dado un resultado.
				\pre <em>left</em> y <em>right</em> son identificadores de jugadores del torneo (sú índice
				dentro del vector de participantes), <em>p</em> es un string que hace referencia a un 
				resultado y <em>orden</em> es un booleano que indica si left es el jugador a del resultado
				entre a y b, donde a esta a la izquierda del cuadro y b a la derecha. (Se usa para 
				actualizar correctamente los juegos ganados por los jugadores, que son independientes de 
				quién gana y quien pierde, a diferencia del resto de estadisticas).
		*/
		void actualizar_est(int left, int right, const string& p, bool orden);

		/** @brief Función que actualiza el árbol de enteros que hace referencia a los enfrentamiento
		 		en base a un árbol de strings referente a los resultados, además de actualizar las 
				estadisticas "locales" de cada participante (sin sumar los puntos al ganador).
				\pre <em>a1</em> es un árbol binario de strings que contiene en cada nodo un resultado 
				que enfrenta a dos jugadores. <em>a2</em> es un árbol binario de enteros donde en las 
				hojas hay los emparejamientos iniciales. <em>n</em> es un entero que hace referencia al 
				nivel del árbol en que un jugador se encuentra, por lo que debe ser inicialmente un 2 
				(el nivel que va después del ganador del torneo). <em>c</em> es el conjunto de categorias
				del circuito.
				\post El árbol binario de enteros <em>a2</em> ha sido actualizado en base al árbol de 
				resultados <em>a1</em> de forma que en cada nodo hay el ganador de los hijos de ese nodo,
				a excepción de las hojas, donde ya hay los jugadores colocados en función del 
				emparejamiento inicial. Además, a cada jugador del torneo (excepto al ganador) se le ha 
				sumado los puntos correspondientes al nivel que ha llegado y la categoria del torneo, 
				además de las otras estadisticas.
		*/
		void actualizar(const BinTree<string>& a1, BinTree<int>& a2, int n, const Cjt_categorias& c);
	
	public:
		//Constructoras
	
		/** @brief Creadora por defecto.
		 		\pre <em>cierto</em>
				\post El resultado es un torneo sin categoria definida, y el resto 
				de atributos son vacíos.
		*/
		Torneo();

		/** @brief Creadora con valores concretos.
				\pre <em>c</em> es una categoria válida entre 1 y C
				\post El resultado es un torneo de categoria <em>c</em> y con el nombre
				de la categoria correspondiente. El resto de atributos son vacíos.
		*/
		Torneo(int c);

		//Modificadoras

		/** @brief Modificadora del cuadro de emparejamientos
		 		\pre Ya se han leído los participantes del torneo.
				\post El árbol binario encargado de almacenar la información de los
				emparejamientos ha sido inicializado en base a la información de los jugadores. 
				Concretamente, las hojas del árbol representan los enfrentamientos iniciales del torneo.
		*/
		void generar_enfr();

		/** @brief Función que actualiza el árbol de enfrentamientos en base a los resultados, además
		 		de actualizar las estadísticas "locales" de cada participante.
				\pre <em>c</em> es el conjunto de categorias del circuito y los emparejamientos iniciales
				ya se han confeccionado.
				\post El árbol binario de enteros de enfrentamientos ha sido actualizado en base al árbol 
				de resultados de forma que en cada nodo hay el ganador de los hijos de ese nodo,
				a excepción de las hojas, donde ya hay los jugadores colocados en función del 
				emparejamiento inicial. Además, a cada jugador del torneo se le han sumado los puntos 
				correspondientes al nivel que ha llegado y la categoria del torneo, además de las 
				otras estadisticas.
		 
		*/
		void actualizar_arbol_enf(const Cjt_categorias& c);
		
		/** @brief Función que se encarga de restar los puntos pertinentes a todos los jugadores
		 		de una posible edición anterior del torneo.
				\pre <em>j</em> es el conjunto de jugadores del circuito.
				\post El conjunto de jugadores ha sido actualizado de modo que a los jugadores de una 
				posible edición anterior del torneo se les ha restado los puntos que ganaron, y 
				posteriormente el ranking es actualizado.
		*/
		void restar_edicion_anterior(Cjt_jugadores& j);
		
		/** @brief Función que pone los puntos a 0 un jugador, en caso de existir en la 
		 		edicion anterior.
				\pre <em>p</em> es un string que identifica a un jugador que puede o no estar en
				la edición anterior del torneo.
				\post En caso de que <em>p</em> sea un jugador presente en la edición anterior del
				torneo, el entero que hace referencia a los puntos que habia ganado pasa a ser 0.
		*/
		void eliminar_puntos_jug(const string& p);
		
		/** @brief Función que actualiza los datos del conjunto de jugadores del circuito,
		 		restando los puntos de la edicion anterior y sumando las estadísticas de la edicion
				vigente.
				\pre <em>j</em> j es el conjunto de jugadores del circuito.
				\post En caso de existir edición anterior del torneo, se ha eliminado a todos los 
				jugadores de esa edición los puntos que habían ganado, y se han actualizado las 
				estadísticas de los jugadores de la presente edición, así como los puntos que han ganado,
				sets, partidos juegos ... Además se asegura que el ranking ha sido actualizado en base 
				a las nuevas estadísticas de los jugadores.
		*/
		void actualizar_datos(Cjt_jugadores& j);

		//Consultoras
		
		/** @brief Consultora que devuelve la categoria del torneo.
		 		\pre <em>cierto</em>
				\post Se devuelve la categoria del torneo (identificador entero)
		*/
		int consultar_categoria() const;

		//Escritura
			
		/** @brief Operación de escritura
		 		\pre <em>cierto</em>
				\post Se ha imprimido por el canal standard de salida el cuadro de
				emparejamientos de los participantes del torneo.
		*/
		void imprimir_enf() const;


		/** @brief Operación de escritura
		 		\pre Se han leído previamente los resultados.
				\post Se ha imprimido por el canal standard de salida el cuadro de
				resultados, una vez finalizado el torneo.
		*/
		void imprimir_resultados() const;

		//Lectura

		/** @brief Lectura de los jugadores inscritos en el torneo. Éstos quedan registrados como
		 		participantes en el torneo y su identificador es su nombre, ya que la posición puede
				variar entre el inicio y el final del torneo, de modo que al actualizar las estadísticas
				se podria estar accediendo a una posicion incorrecta.
		 		\pre Esta disponible en el canal standard de entrada la información 
				de los jugadores inscritos, concretamente un número n de jugadores inscritos,
				seguido de n enteros con sus posiciones en el ranking vigente, ordenadas
				crecientemente. El parámetro <em>j</em> es el conjunto de jugadores del circuito,
				ya que es necesario para tener acceso al nombre de los jugadores dada su posicion.
				\post El parámetro implícito ha sido modificado de forma que la estructura
				que se encarga de almacenar los jugadores inscritos ha sido inicializada con
				los jugadores leídos.
		*/
		void leer_inscritos(const Cjt_jugadores& j);	

		/** @brief Lectura de los resultados del torneo.
				\pre Está disponible en el canal standard de entrada la información de los 
				resultados del torneo, en forma de árbol binario de strings, concretamente 
				en preorden.
				\post El árbol binario de strings que almacena la información de los resultados
				del torneo ha sido actualizado en base a los resultados leídos.
		*/
		void leer_resultados();
};

#endif
