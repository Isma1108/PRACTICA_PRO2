OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o Jugador.o Cjt_jugadores.o Torneo.o Cjt_torneos.o Cjt_categorias.o
	g++ -o program.exe *.o

Jugador.o: Jugador.cc Jugador.hh
	g++ -c Jugador.cc $(OPCIONS) 

Cjt_jugadores.o: Cjt_jugadores.cc Cjt_jugadores.hh Jugador.hh
	g++ -c Cjt_jugadores.cc $(OPCIONS)
 
Torneo.o: Torneo.cc Torneo.o Cjt_categorias.hh Cjt_jugadores.hh BinTree.hh
	g++ -c Torneo.cc $(OPCIONS) 

Cjt_torneos.o: Cjt_torneos.cc Cjt_torneos.hh Torneo.hh Cjt_jugadores.hh Cjt_categorias.hh
	g++ -c Cjt_torneos.cc $(OPCIONS) 

Cjt_categorias.o: Cjt_categorias.cc Cjt_categorias.hh
	g++ -c Cjt_categorias.cc $(OPCIONS) 

program.o: program.cc Cjt_jugadores.hh Cjt_categorias.hh Cjt_torneos.hh
	g++ -c program.cc $(OPCIONS) 

practica.tar: Jugador.hh Cjt_jugadores.hh Torneo.hh Cjt_torneos.hh Cjt_categorias.hh program.cc Jugador.cc Cjt_jugadores.cc Torneo.cc Cjt_torneos.cc Cjt_categorias.cc Makefile
	tar -cvf practica.tar Jugador.hh Cjt_jugadores.hh Torneo.hh Cjt_torneos.hh Cjt_categorias.hh program.cc Jugador.cc Cjt_jugadores.cc Torneo.cc Cjt_torneos.cc Cjt_categorias.cc Makefile 

clean:
	rm *.o
	rm *.exe
