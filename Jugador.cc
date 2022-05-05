#include "Jugador.hh"

Jugador::Jugador() {}

Jugador::Jugador(int p) {
    posicion = p;
    torneos_disputados = puntos = 0;
    partidos.first = partidos.second = 0;
    sets.first = sets.second = 0;
    juegos.first = juegos.second = 0;
}


void Jugador::modificar_partidos(pair<int,int> pr) {
    partidos.first += pr.first;
    partidos.second += pr.second;
}

void Jugador::modificar_sets(pair<int,int> s) {
    sets.first += s.first;
    sets.second += s.second;
}

void Jugador::modificar_juegos(pair<int,int> j) {
    juegos.first += j.first;
    juegos.second += j.second;
}

void Jugador::nuevo_td() {
    ++torneos_disputados;
}

void Jugador::modificar_puntos(int p) {
    puntos += p;
}

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

