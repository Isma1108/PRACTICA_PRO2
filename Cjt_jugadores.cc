#include "Cjt_jugadores.hh"

typedef map<string,Jugador>::iterator map_it;

Cjt_jugadores::Cjt_jugadores() {}

bool Cjt_jugadores::nuevo_jugador(const string& p) {
    pair<map_it,bool> ret = jugadores.insert(make_pair(p, Jugador(P+1)));
    if (ret.second == false) return false;
    else {
        ranking.push_back(ret.first);
        ++P;
        cout << P << endl;
        return true;
    }
}

bool Cjt_jugadores::baja_jugador(const string& p) {
    map_it it = jugadores.find(p); //búsqueda con coste logn
    if (it == jugadores.end()) return false;
    else {
        int pos = it->second.consultar_pos(); //coste constante para acceder al vector;
        jugadores.erase(it);
        //ahora hay que eliminar el jugador del ranking
        for (int i = pos; i < P; ++i) {
            ranking[i]->second.modificar_posicion(i);
            ranking[i-1] = ranking[i];
        }
        ranking.pop_back();
        --P;
        cout << P << endl;
        return true;
    }
}

//void Cjt_jugadores::restar_puntos(const vector<Jugador>& datos) {}

//void Cjt_jugadores::actualizar_ranking(const vector<Jugador>& datos) {}

bool Cjt_jugadores::existe_jugador(const string& p) const {
    if (jugadores.find(p) == jugadores.end()) return false;
    else return true;
}

string Cjt_jugadores::nombre_jugador(int pos) const {
    return ranking[pos-1]->first; 
}
    
void Cjt_jugadores::listar_ranking() const {
    for (int i = 0; i < P; ++i) {
        cout << i+1 << ' ' << ranking[i]->first << ' ';
        cout << ranking[i]->second.consultar_puntos() << endl;
    }
}

void Cjt_jugadores::listar_jugadores() const {
    cout << P << endl;
    map<string,Jugador>::const_iterator it = jugadores.begin();
    while (it != jugadores.end()) {
        cout << it->first << ' ';
        it->second.escribir();
        ++it;
    }
}

bool Cjt_jugadores::consultar_jugador(const string& p) const {
    map<string,Jugador>::const_iterator it = jugadores.find(p);
    if (it == jugadores.end()) return false;
    else {
        cout << it->first << ' ';
        it->second.escribir();
        return true;
    }
}

void Cjt_jugadores::lectura_inicial() {
    int p;
    cin >> p;
    P = p;
    ranking = vector<map_it>(p);
    for (int i = 0; i < p; ++i) {
        string jug;
        cin >> jug;
        pair<map_it,bool> ret = jugadores.insert(make_pair(jug, Jugador(i+1)));
        // La función insert de los maps en c++ devuelve un pair con pair::first
        // siendo un iterador que apunta al nuevo elemento insertado y pair::second
        // un valor booleano en función de si ya existia o no un elemento con esa llave.
        ranking[i] = ret.first;
    }
}
