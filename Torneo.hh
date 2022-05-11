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
	string nombre;
	int puntos;
	pair<int,int> juegos_gp;
	pair<int,int> sets_gp;
	pair<int,int> partidos_gp; //todos pierden uno (excepto el ganador) y ganan x
};

/** @class Torneo
 		@brief Almacena la información de un torneo y facilita su gestión.

		Gestiona la información de un torneo:
		<ul>
			<li>Identificador de su categoria</li>
			<li>Jugadores inscritos</li>
			<li>Cuadro de emparejamientos</li>
			<li>Cuadro de resultados</li>
			<li>Puntos ganados por los jugadores (y estadísticas "locales")</li>
		</ul>
*/

class Torneo
{
	private:
		//no es necesario guardar el nombre del torneo como atributo
		//ya que el map de torneos tiene como clave ese nombre.
		int categoria;
		vector<Participante> inscritos;
		map<string,int> edicion_anterior; 
		BinTree<int> enf;
		BinTree<string> resultados;
	
		/** @brief Función que confecciona el árbol binario de emparejamientos.
				\pre <em>a</em> es un árbol binario de enteros con un único nodo raíz con valor 1,
				<em>n</em> es el número de jugadores inscritos en el torneo y <em>prod</em> se trata
				de un valor que va almacenando potencias de dos en las llamadas recursivas, para 
				saber en que momento se debe parar la recursión. Por ende, el parámetro de la 
				llamada inicial debe ser 2.
				\post El árbol binario <em>a</em> ha sido modificado de forma que las hojas representan
				los emparejamientos iniciales.
		*/
		void modificar(BinTree<int>& a, int n, int prod);

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
				de los partidos pertinentes, y <em>a2</em> es un árbol binario de enteros donde en las
				hojas hay los jugadores del emparejamiento inicial y en los demas nodos los jugadores
				que han ganado del partido referente a los dos hijos del nodo.
				\post Han sido escritos por el canal standard de salida los resultados del torneo.
		*/
		void imprimir_res(const BinTree<string>& a1, const BinTree<int>& a2) const; 
		
		/** @brief Función que devuelve el ganador dado un resultado

		*/
		int ganador(const string& p) const;

		/** @brief Función que actualiza ciertas caracteristicas de los jugadores del torneo
				dado un resultado.

		*/
		void actualizar_est(int left, int right, const string& p);

		/** @brief Función que actualiza el árbol de enteros en base al árbol de resultados.
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
		*/
		void generar_enfr();

		/** @brief Función que actualiza el árbol de enfrentamientos en base a los resultados.
		 
		*/
		void actualizar_arbol_enf(const Cjt_categorias& c);
		
		/** @brief Función que resta los puntos a todos los jugadores de la edicion anterior.

		*/
		void restar_edicion_anterior(Cjt_jugadores& j);
		
		/** @brief Función que pone los puntos a 0 un jugador, en caso de existir en la 
		 		edicion anterior.

		*/
		void eliminar_puntos_jug(const string& p);
		
		/** @brief Función que actualiza los datos del conjunto de jugadores del circuito,
		 		restando los puntos de la edicion anterior y sumando las estadísticas de la edicion
				vigente.

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
				emparejamientos de los jugadores inscritos.
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
				\post El parámetro implícito ha sido modificado de forma que la estructura
				que se encarga de almacenar los puntos ganados por los jugadores ha sido 
				actualizada en base a los datos leídos. Además, también se ha modificado el 
				BinTree que almacena la información de los resultados.
		*/
		void leer_resultados();
};

#endif
