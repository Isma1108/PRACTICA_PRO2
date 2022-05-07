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
        cout << nl << '.' << edicion_anterior[nl-1].nombre << " vs ";
        cout << nr << '.' << edicion_anterior[nr-1].nombre << ' ' << a1.value();
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

void Torneo::actualizar_est(int left, int right, const string& p) {
    if (p.size() == 11) {
        inscritos[left].sets_gp.first += 2;
        inscritos[left].sets_gp.second += 1;
        inscritos[right].sets_gp.first += 1;
        inscritos[right].sets_gp.second += 2; 
    }
    else if (p.size() == 7) {
        inscritos[left].sets_gp.first += 2;
        inscritos[right].sets_gp.second += 2; 
    }
    inscritos[left].partidos_gp.first += 1;
    inscritos[right].partidos_gp.second += 1;
}

void Torneo::actualizar(const BinTree<string>& a1, BinTree<int>& a2, int n, const Cjt_categorias& c) {
    BinTree<int> l = a2.left();
    BinTree<int> r = a2.right();
    if (not (a1.left().empty() and a1.right().empty())) {
        if (not a1.left().empty()) actualizar(a1.left(), l, n + 1, c);
        actualizar(a1.right(), r, n + 1, c);
    }
    string p = a1.value();
    int left = l.value(), right = r.value();
    if (ganador(p) == 1) {
        actualizar_est(left - 1, right - 1 , p);  
        inscritos[right - 1].puntos = c.puntos_categoria(categoria, n);
        a2 = BinTree<int>(left, l, r);
    }
    else {
        actualizar_est(right - 1, left - 1, p);
        inscritos[left - 1].puntos = c.puntos_categoria(categoria, n);
        a2 = BinTree<int>(right, l, r);
    }
    int g1 = 0, g2 = 0;
    if (p.size() == 11) {
        g1 = (p[0] - '0') + (p[4] - '0') + (p[8] - '0');
        g2 = (p[2] - '0') + (p[6] - '0') + (p[10] - '0');
    }
    else if (p.size() == 7) {
        g1 = (p[0] - '0') + (p[4] - '0');
        g2 = (p[2] - '0') + (p[6] - '0');
    }
    inscritos[left - 1].juegos_gp.first += g1;
    inscritos[left - 1].juegos_gp.second += g2;
    inscritos[right - 1].juegos_gp.first += g2;
    inscritos[right - 1].juegos_gp.second += g1;
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


void Torneo::actualizar_arbol_enf(const Cjt_categorias& c, Cjt_jugadores& j) {
    int n = edicion_anterior.size();
    for (int i = 0; i < n; ++i) {
        j.restar_puntos(edicion_anterior[i].nombre, edicion_anterior[i].puntos);
    }
    actualizar(resultados, enf, 2, c);
    inscritos[enf.value() - 1].puntos = c.puntos_categoria(categoria, 1);
    edicion_anterior = inscritos;
}

void Torneo::restar_edicion_anterior(Cjt_jugadores& j) {
    if (edicion_anterior.size() > 0) {
        int n = edicion_anterior.size();
        for (int i = 0; i < n; ++i) {
            j.restar_puntos(edicion_anterior[i].nombre, edicion_anterior[i].puntos);
        }
        j.reordenar_ranking();
    }
}

void Torneo::eliminar_puntos_jug(const string& p) {
    int n = edicion_anterior.size(), i = 0;
    bool encontrado = false;
    while (not encontrado and i < n) {
        if (edicion_anterior[i].nombre == p) {
            edicion_anterior[i].puntos = 0;
            encontrado = true;
        }
        ++i;
    }
}


int Torneo::consultar_categoria() const {
    return categoria;
}

void::Torneo::imprimir_enf() const {
    imprimir(enf);
    cout << endl;
}


void Torneo::imprimir_resultados(Cjt_jugadores& j) const{
    imprimir_res(resultados, enf);
    cout << endl;
    int n = edicion_anterior.size();
    for (int i = 0; i < n; ++i) {
        j.actualizar_datos(edicion_anterior[i].nombre, edicion_anterior[i].puntos, 
                edicion_anterior[i].juegos_gp, edicion_anterior[i].sets_gp, 
                edicion_anterior[i].partidos_gp);
        if (edicion_anterior[i].puntos > 0) {
            cout << i + 1 << '.' << edicion_anterior[i].nombre << ' ' << edicion_anterior[i].puntos << endl;  
        }
    }
    j.reordenar_ranking();
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
    }
}

void Torneo::leer_resultados() {
    lectura_res(resultados);
}
