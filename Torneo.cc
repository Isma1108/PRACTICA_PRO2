#include "Torneo.hh"

//######################################//
//     MÉTODOS PRIVADOS DE LA CLASE     //
//######################################//

void Torneo::modificar(BinTree<int>& a, int n, int prod) {
    if ((prod + 1 - a.value()) <= n) {
        BinTree<int> left(a.value());
        modificar(left, n, 2*prod);
        BinTree<int>right(prod + 1 - a.value());
        modificar(right, n, 2*prod);
        a = BinTree<int>(a.value(), left, right);
    }
}


void Torneo::imprimir(const BinTree<int>& a) const {
    BinTree<int> left = a.left();
    if (not left.empty()) {
        cout << '(';
        imprimir(left);
        cout << ' ';
        imprimir(a.right());
        cout << ')';
    }
    else {
        int n = a.value();
        cout << n << '.' << inscritos[n-1].nombre;
    }
}

void Torneo::lectura_res(BinTree<string>& a) {
    string p;
    cin >> p;
    if (p != "0") {
        BinTree<string> left, right;
        lectura_res(left);
        lectura_res(right);
        a = BinTree<string>(p, left, right);
    }
}

void Torneo::imprimir_res(const BinTree<string>& a1, const BinTree<int>& a2) const {
    if (not a1.empty()) {
        int nl = a2.left().value();
        int nr = a2.right().value();
        cout << '(';
        cout << nl << '.' << inscritos[nl-1].nombre << " vs ";
        cout << nr << '.' << inscritos[nr-1].nombre << ' ' << a1.value();
        imprimir_res(a1.left(), a2.left());
        imprimir_res(a1.right(), a2.right());
        cout << ')';
    }
}

int Torneo::ganador(const string& p) const {
    int n = p.size();
    if (p[n-3] > p[n-1]) return 1;
    else return 2;
}

void Torneo::actualizar(const BinTree<string>& a1, BinTree<int>& a2) {
    BinTree<int> l = a2.left();
    BinTree<int> r = a2.right();
    if (not (a1.left().empty() and a1.right().empty())) {
        if (not a1.left().empty()) actualizar(a1.left(), l);
        actualizar(a1.right(), r);
    }
    string p = a1.value();
    if (ganador(p) == 1) a2 = BinTree<int>(l.value(), l, r);
    else a2 = BinTree<int>(r.value(), l, r);
}



//######################################//
//     MÉTODOS PÚBLICOS DE LA CLASE     //
//######################################//

Torneo::Torneo() {}

Torneo::Torneo(int c) {
    categoria = c;
}

void Torneo::generar_enfr() {
    enf = BinTree<int>(1);
    modificar(enf, inscritos.size(), 2);
}


void Torneo::actualizar_arbol_enf() {
    actualizar(resultados, enf);
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

void::Torneo::imprimir_enf() const {
    imprimir(enf);
    cout << endl;
}


void Torneo::imprimir_resultados() const{
    imprimir_res(resultados, enf);
    cout << endl;
}

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
        x.actualizado = false;
    }
}

void Torneo::leer_resultados() {
    lectura_res(resultados);
}
