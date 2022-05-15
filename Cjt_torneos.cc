#include "Cjt_torneos.hh"

Cjt_torneos::Cjt_torneos() 
{
    T = 0;
}

bool Cjt_torneos::nuevo_torneo(const string& t, int c) 
{
    pair<torneos_it,bool> ret = torneos.insert(make_pair(t, Torneo(c)));
    if (ret.second == false) return false;
    else {
        ++T;
        cout << T << endl;
        return true;
    }
}

bool Cjt_torneos::baja_torneo(const string& t, Cjt_jugadores& j) 
{
    torneos_it it = torneos.find(t); //búsqueda con coste logn
    if (it == torneos.end()) return false;
    else {
        --T;
        it->second.restar_edicion_anterior(j);
        torneos.erase(it);
        cout << T << endl;
        return true;
    }
}

void Cjt_torneos::iniciar_torneo(const string& t, const Cjt_jugadores& j) 
{
    torneos_it it = torneos.find(t);
    it->second.leer_inscritos(j);
    it->second.generar_enfr();
    it->second.imprimir_enf();
}

void Cjt_torneos::finalizar_torneo(const string& t, Cjt_jugadores& j, const Cjt_categorias& c) 
{
    torneos_it it = torneos.find(t);
    it->second.leer_resultados();
    it->second.actualizar_arbol_enf(c);
    it->second.actualizar_datos(j);
    it->second.imprimir_resultados();
}

void Cjt_torneos::eliminar_puntos(const string& p) 
{
    torneos_it it = torneos.begin();
    while (it != torneos.end()) {
        it->second.eliminar_puntos_jug(p);      
        ++it;
    }
}

void Cjt_torneos::listar_torneos(const Cjt_categorias& c) const 
{
    cout << T << endl;
    map<string,Torneo>::const_iterator it = torneos.begin();
    while (it != torneos.end()) {
        int cat = it->second.consultar_categoria();
        cout << it->first << ' ' << c.consultar_nombre(cat) << endl; 
        ++it;
    }
}

void Cjt_torneos::lectura_inicial() 
{
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
