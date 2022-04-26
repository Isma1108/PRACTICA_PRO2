#include "Torneo.hh"

//######################################//
//     MÉTODOS PRIVADOS DE LA CLASE     //
//######################################//

void Torneo::modificar(BinTree<int>& a, int n, int prod) {
    if ((prod + 1 - a.value()) <= n) {
        BinTree<int> left(a.value());
        cout << '(';
        modificar(left, n, 2*prod);
        cout << ' ';
        BinTree<int>right(prod + 1 - a.value());
        modificar(right, n, 2*prod);
        cout << ')';
        a = BinTree<int>(a.value(), left, right);
    }
    else {
        int n = a.value();
        cout << n << '.' << inscritos[n-1].nombre;
    }
}

/*
void Torneo::imprimir(const BinTree<int>& a, const Cjt_jugadores& j) const {
    BinTree<int> left = a.left();
    if (not left.empty()) {
        cout << '(';
        imprimir(left, j);
        cout << ' ';
        imprimir(a.right(), j);
        cout << ')';
    }
    else {
        int n = a.value();
        string nombre = j.nombre_jugador(inscritos[n-1].consultar_pos());
        cout << n << '.' << nombre;
    }
}
*/

//######################################//
//    MÉTODOS PÚBLICOS DE LA CLASE      //
//######################################//

Torneo::Torneo() {}

Torneo::Torneo(int c) {
    categoria = c;
}

void Torneo::generar_enfr() {
    enf = BinTree<int>(1);
    modificar(enf, inscritos.size(), 2);
    cout << endl;
}

/*
vector<Participante> Torneo::info_participantes() const {
    //provisional;
    vector<Participante> v;
    return v;
}
*/

int Torneo::consultar_categoria() const {
    return categoria;
}

/*
void Torneo:: imprimir_enf(const Cjt_jugadores& j) const {
    imprimir(enf, j);
    cout << endl;
}
*/

void Torneo::imprimir_resultados() const {}

void Torneo::listar_puntos() const {}

void Torneo::leer_inscritos(const Cjt_jugadores& j) {
    int n;
    cin >> n;
    inscritos = vector<Participante>(n);
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        Participante x;
        x.nombre = j.nombre_jugador(p);
        x.puntos = x.juegos_gp.first = x.juegos_gp.second = 0;
        x.sets_gp.first = x.sets_gp.second = 0;
        x.partidos_gp.first = x.partidos_gp.second = 0;
        inscritos[i] = x;
    }
}

void Torneo::leer_resultados() {}

