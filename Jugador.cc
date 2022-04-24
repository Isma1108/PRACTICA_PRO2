#include "Jugador.hh"

Jugador::Jugador() {}

Jugador::Jugador(int p) {
    posicion = p;
    torneos_disputados = puntos = 0;
    partidos.first = partidos.second = 0;
    sets.first = sets.second = 0;
    juegos.first = juegos.second = 0;
}


//void Jugador::modificar_partidos(int g, int p) {}

//void Jugador::modificar_sets(int g, int p) {}

//void Jugador::modificar_juegos(int g, int p) {}

//void Jugador::nuevo_td() {}

//void Jugador::modificar_puntos(int p) {}

void Jugador::modificar_posicion(int p) {
    posicion = p;
}
//int Jugador::consultar_td() const {}

//int Jugador::consultar_pg() const {}

//int Jugador::consultar_pp() const {}

//int Jugador::consultar_sg() const {}

//int Jugador::consultar_sp() const {}

//int Jugador::consultar_jg() const {}

//int Jugador::consultar_jp() const {}

int Jugador::consultar_pos() const {
    return posicion;
}

int Jugador::consultar_puntos() const {
    return puntos;
}

void Jugador::escribir() const {
    cout << "Rk:" << posicion << " Ps:" << puntos << " Ts:" << torneos_disputados;
    cout << " WM:" << partidos.first << " LM:" << partidos.second;
    cout << " WS:" << sets.first << " LS:" << sets.second;
    cout << " WG:" << juegos.first << " LG:" << juegos.second << endl;
}

