/** @mainpage Circuito de Torneos de Tenis.

El programa principal se encuentra en el módulo <em>main.cc</em>.
En base a los datos proporcionados por el enunciado, se ha considerado necesaria la existencia de exactamente 5 clases:
<ul>
	<li>Jugador</li>
	<li>Cjt_jugadores</li>
	<li>Torneo</li>
	<li>Cjt_torneos</li>
	<li>Cjt_categorias</li>
</ul>
*/

/** @file program.cc
 		@brief Programa principal para la práctica de PRO2: <em>Circuito de Torneos de Tenis</em>.
		
		Como bien da a entender el enunciado, se supone que los datos leídos siempre son correctos, de modo que no se incluyen comprobaciones al respecto.
*/

//Para que el diagrama modular quede bien se han escrito includes redundantes;
//en algunos ficheros .hh de la documentación de las clases ocurre lo mismo;
#include "Cjt_categorias.hh"
#include "Cjt_jugadores.hh"
#include "Cjt_torneos.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;

/** @brief Programa principal para la práctica de PRO2: <em>Circuito de Torneos de Tenis</em>.
*/
int main() 
{
	Cjt_categorias c;
	Cjt_torneos t;
	Cjt_jugadores j;
	
	c.lectura_inicial();
	t.lectura_inicial();
	j.lectura_inicial();
	
	string cm;
	cin >> cm;
	while (cm != "fin") {
		string p;
		if (cm == "nuevo_jugador" or cm == "nj") {
			cin >> p;
			cout << '#' << cm << ' ' << p << endl;
			if (not j.nuevo_jugador(p)) cout << "error: ya existe un jugador con ese nombre" << endl;
		}
		else if (cm == "nuevo_torneo" or cm == "nt") {
			int cat;
			cin >> p >> cat;
			cout << '#' << cm << ' ' << p << ' ' << cat << endl;
			if (not c.existe_categoria(cat)) cout << "error: la categoria no existe" << endl;
			else if (not t.nuevo_torneo(p, cat)) cout << "error: ya existe un torneo con ese nombre" << endl;
		}
		else if (cm == "baja_jugador" or cm == "bj") {
			cin >> p;
			cout << '#' << cm << ' ' << p << endl;
			if (not j.baja_jugador(p)) cout << "error: el jugador no existe" << endl;
		}
		else if (cm == "baja_torneo" or cm == "bt") {
			cin >> p;
			cout << '#' << cm << ' ' << p << endl;
			if (not t.baja_torneo(p, j)) cout << "error: el torneo no existe" << endl;
		}
		else if (cm == "iniciar_torneo" or cm == "it") {
			cin >> p;
			cout << '#' << cm << ' ' << p << endl;
			t.iniciar_torneo(p, j);
		}
		else if (cm == "finalizar_torneo" or cm == "ft") {
			cin >> p;
			cout << '#' << cm << ' ' << p << endl;  
			t.finalizar_torneo(p, j);
		}
		else if (cm == "listar_ranking" or cm == "lr") {
			cout << '#' << cm << endl;
			j.listar_ranking();
		}
		else if (cm == "listar_jugadores" or cm == "lj") {
			cout << '#' << cm << endl;
			j.listar_jugadores();
		}
		else if (cm == "consultar_jugador" or cm == "cj") {
			cin >> p;
			cout << '#' << cm << ' ' << p << endl;
			if (not j.consultar_jugador(p)) cout << "error: el jugador no existe" << endl;
		}
		else if (cm == "listar_torneos" or cm == "lt") {
			cout << '#' << cm << endl;
			t.listar_torneos(c);
		}
		else if (cm == "listar_categorias" or cm == "lc") {
			cout << '#' << cm << endl;
			c.listar_categorias();
		}
		cin >> cm;
	}
}
