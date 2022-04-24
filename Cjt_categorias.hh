/** @file Cjt_categorias.hh
    @brief Especificacion de la clase Cjt_categorias
*/

#ifndef CJT_CATEGORIAS_HH
#define CJT_CATEGORIAS_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif

using namespace std;

/** @struct Categoria
		@brief Struct que almacena información sobre una categoria. 
		
		Como atributos no se incluye el identificador entero entre 1
		y C porque éste será el índice del vector que almacene el 
		conjunto de categorias. El vector de enteros de puntuacion_por_nivel
		contiene la información de los puntos que ganaria un jugador en un 
		torneo de categoria c al llegar a un nivel k, siendo k un índice de
		este vector.
*/

struct Categoria {
	string nombre;
	vector<int> puntuacion_por_nivel;
};

/** @class Cjt_categorias
    @brief Facilita la gestión de un conjunto de categorias. (obj. 'Categoria')

		La clase tiene el propósito de gestionar un conjunto de categorias. Ésta permite

*/

class Cjt_categorias
{
private:
	vector<Categoria> categorias;
	int K; //(máximo de niveles)

public:
	//Constructoras
	
	/** @brief Creadora por defecto
	   	\pre <em>cierto</em>
			\post El resultado es un Cjt_categorias con su vector de Categoria
			no definido.
	*/
	Cjt_categorias();

	//Consultoras
	
	/** @brief Consultora que permite saber si existe una categoria en el conjunto.
	    \pre <em>c</em> es un entero
			\post Se devuelve true si existe una categoria con identificador <em>c</em> en 
			el conjunto, false en caso contrario.
	*/
	bool existe_categoria(int c) const;

	/** @brief Consultora que permite saber los puntos que debe un jugador que ha 
	    participado en un torneo de categoria <em>c</em> y que ha llegado a un
			nivel <em>k</em>.
			\pre <em>c</em> es un identificador de una categoria existente en el conjunto
			y <em>k</em> es un nivel >= 1 y <= K.
			\post se devuelve un entero que representa los puntos que debe ganar un jugador
			que ha llegado a un nivel <em>k</em> en un torneo de categoria <em>c</em>.
	*/
	int puntos_categoria(int c, int k) const;

	/**
	 

	*/
	string consultar_nombre(int c) const;
	
	//Escritura
	
	/** @brief Operación de escritura
	  	\pre <em>cierto</em>
			\post Se ha listado en el canal standard de salida, por orden creciente de
			identificador, el nombre y la tabla de puntos por niveles (en orden creciente
			de nivel) de cada categoria del conjunto.
	*/
	void listar_categorias() const;
	
	//Lectura 
	
	/** @brief Método que se encarga de inicializar los datos del conjunto,
	 		dados unos datos por el canal standard de entrada.
			\pre Está disponible en el canal standard de entrada un número de categorias C >= 0
			seguido de un número máximo de niveles K >= 4. Después hay una secuencia de C 
			strings con los nombres asociados a las categorías identificadas por los valores
			entre 1 y C en orden creciente (de identificador, no de nombre). Luego hay 
			disponibles C × K enteros mayores o iguales que 0, que serán los puntos por 
			categoría y nivel, ordenados crecientemente por categorías y dentro de cada 
			categoría ordenados crecientemente por nivel.
			\post El parámetro implícito ha sido modificado de forma que se han almacenado
			todas las categorias con su correspondiente información.
	*/
	void lectura_inicial();
};

#endif
