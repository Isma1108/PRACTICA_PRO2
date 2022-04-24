/** @file Torneo.hh
 		@brief Especificación de la clase Torneo
*/

#ifndef TORNEO_HH
#define TORNEO_HH

#include "Cjt_categorias.hh"
#include "Cjt_jugadores.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
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
	pair<int,int> partidos_gp;
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
		BinTree<int> enf;
		BinTree<string> resultados;
	
		/** @brief Función que confecciona el árbol binario de emparejamientos e imprime 
		 		estos de forma paralela.
				\pre <em>a</em> es un árbol binario de enteros con un único nodo raíz con valor 1,
				<em>n</em> es el número de jugadores inscritos en el torneo y <em>prod</em> se trata
				de un valor que va almacenando potencias de dos en las llamadas recursivas, para 
				saber en que momento se debe parar la recursión. Por ende, el parámetro de la 
				llamada inicial debe ser 2.
				\post El árbol binario <em>a</em> ha sido modificado de forma que las hojas representan
				los emparejamientos iniciales.
		*/
		void modificar(BinTree<int>& a, int n, int prod);
		//void imprimir(const BinTree<int>& a, const Cjt_jugadores& j) const;
	
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

		//Consultoras
		
		/** @brief Consultora que devuelve la estructura que almacena la información de 
		 		los participantes del torneo. (tiene el objetivo de poder acceder a ésta
				información desde otra clase, para poder actualizar de forma adecuada el 
				ranking y las estadísticas de los jugadors, ya que luego ésta información se 
				pierde al leer los nuevos participantes de la posible nueva edición).
				\pre <em>cierto</em>
				\post Se devuelve la estructura que almacena toda la información de los jugadores
				del torneo.
		*/
		vector<Participante> info_participantes() const;
		
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
		void imprimir_enf(const Cjt_jugadores& j) const;


		/** @brief Operación de escritura
		 		\pre Se han leído previamente los resultados.
				\post Se ha imprimido por el canal standard de salida el cuadro de
				resultados, una vez finalizado el torneo.
		*/
		void imprimir_resultados() const;

		/** @brief Operación de escritura
		 		\pre <em>cierto</em>
				\post Se han listado por el canal standard de salida los puntos para el 
				ranking ganados por cada uno de los participantes, por orden del ranking
				de los jugadores en el momento de iniciar el torneo. 
		*/
		void listar_puntos() const;

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
