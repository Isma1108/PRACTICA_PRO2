#include "Cjt_categorias.hh"

Cjt_categorias::Cjt_categorias() {}

bool Cjt_categorias::existe_categoria(int c) const 
{
    if (c >= 1 and c <= categorias.size()) return true;
    else return false;
}

int Cjt_categorias::puntos_categoria(int c, int k) const 
{
    return categorias[c - 1].puntuacion_por_nivel[k - 1];
}

string Cjt_categorias::consultar_nombre(int c) const 
{
    return categorias[c-1].nombre;
}

void Cjt_categorias::listar_categorias() const 
{
    int n = categorias.size();
    cout << n << ' ' << K << endl; 
    
    for (int i = 0; i < n; ++i) {
        cout << categorias[i].nombre;
        for (int j = 0; j < K; ++j) cout << ' ' << categorias[i].puntuacion_por_nivel[j];
        cout << endl;
    }
}

void Cjt_categorias::lectura_inicial() 
{
    int c, k;
    cin >> c >> k;
    K = k;
    categorias = vector<Categoria>(c);
    for (int i = 0; i < c; ++i) cin >> categorias[i].nombre;
    for (int i = 0; i < c; ++i) {
        categorias[i].puntuacion_por_nivel = vector<int>(k);
        for (int j = 0; j < k; ++j) {
            cin >> categorias[i].puntuacion_por_nivel[j];
        }
    }
}
