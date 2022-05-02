#include "Cjt_torneos.hh"

typedef map<string,Torneo>::iterator torneos_it;

Cjt_torneos::Cjt_torneos() {
    T = 0;
}

bool Cjt_torneos::nuevo_torneo(const string& t, int c) {
    pair<torneos_it,bool> ret = torneos.insert(make_pair(t, Torneo(c)));
    if (ret.second == false) return false;
    else {
        ++T;
        cout << T << endl;
        return true;
    }
}

bool Cjt_torneos::baja_torneo(const string& t, Cjt_jugadores& j) {
    torneos_it it = torneos.find(t); //búsqueda con coste logn
    if (it == torneos.end()) return false;
    else {
        --T;
        torneos.erase(it);
        cout << T << endl;

        //provisional, se deberia restar puntos en caso que se haya dado
        //a cabo una versión anterior del torneo
        Cjt_jugadores prov = j;
        return true;
    }
}

void Cjt_torneos::iniciar_torneo(const string& t, const Cjt_jugadores& j) {
    map<string,Torneo>::iterator it = torneos.find(t);
    it->second.leer_inscritos(j);
    it->second.generar_enfr();
    it->second.imprimir_enf();
    //No es necesario imprimir el cuadro de emparejamientos, ya que el método
    //generar se encarga de confeccionar el cuadro e imprimirlo de forma paralela.
}

void Cjt_torneos::finalizar_torneo(const string& t, Cjt_jugadores& j) {
    map<string,Torneo>::iterator it = torneos.find(t);
    it->second.leer_resultados();
    cout << endl;
    it->second.imprimir_resultados();
    Cjt_jugadores xd = j;
}

void Cjt_torneos::listar_torneos(const Cjt_categorias& c) const {
    cout << T << endl;
    map<string,Torneo>::const_iterator it = torneos.begin();
    while (it != torneos.end()) {
        int cat = it->second.consultar_categoria();
        cout << it->first << ' ' << c.consultar_nombre(cat) << endl; 
        ++it;
    }
}

void Cjt_torneos::lectura_inicial() {
    //no es necesario especificar un orden para el map de torneos, ya que el orden
    //por defecto es creciente para el valor de la llave.
    int t;
    cin >> t;
    T = t;
    for (int i = 0; i < t; ++i) {
        string p;
        int c;
        cin >> p >> c;
        torneos.insert(make_pair(p, Torneo(c))); //se inserta el Torneo leído
    }
}
