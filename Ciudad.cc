/**
 *@file Ciudad.cc
 *@author Itsaso Olaizola Guereño
 *@brief Codigo de la clase Ciudad
 * 
*/

#include "Ciudad.hh"

    //CONSTRUCTORAS
    Ciudad::Ciudad(){
        peso_total = 0;
        volumen_total = 0;
    }

    //CONSULTORAS
    bool Ciudad::existe_prod(const int& ident_prod) const{
        map<int, pair <int, int>>::const_iterator it = productos.find(ident_prod);
        if (it != productos.end()) return true;
        else return false;
    }
    void Ciudad::escribir_ciudad(){
        escribir_inventario();
        cout << peso_total << ' ' << volumen_total << endl;
    }
    void Ciudad::escribir_inventario(){
        map<int, pair <int, int>>::const_iterator it = productos.begin();
        while(it != productos.end()) {
            cout << it->first << ' ' << it->second.first << ' ' << it->second.second << endl;
            ++it; 
        }
    }
    void Ciudad::consultar_prod(const int& ident_prod) const{
        map<int, pair <int, int>>::const_iterator it = productos.find(ident_prod);
        cout << it->second.first << ' ' << it->second.second << endl;
    }
    bool Ciudad::inv_ciu_vacio() const{
        if (productos.empty()) return true;
        else return false;
    }

    //MODIFICADORAS
    void Ciudad::comerciar_prod(Ciudad& otra_ciudad){
        Cjt_productos p;
        map<int, pair <int, int>>::iterator it1 = productos.begin();
        map<int, pair <int, int>>::iterator it2 = otra_ciudad.productos.begin();
        while(it1 != productos.end() or it2 != otra_ciudad.productos.end()) {
            if (it1->first < it2->first) {
                ++it1;
            }
            else if (it1->first > it2->first) {
                ++it2;
            }
            else {
                int cant1 = it1->second.second - it1->second.first;
                int cant2 = it2->second.second - it2->second.first;
                if (cant1*cant2 >= 0) {
                    int intercambio = min(abs(cant1), abs(cant2));
                    bool poner = false;
                    if (cant1 < cant2) {
                        it1->second.first -= intercambio;
                        comerciar_ajustes(it1->first, intercambio, poner, p);
                        poner = true;
                        it2->second.first += intercambio;
                        comerciar_ajustes(it1->first, intercambio, poner, p);
                    }
                    else {
                        poner = true;
                        it1->second.first += intercambio;
                        comerciar_ajustes(it1->first, intercambio, poner, p);
                        poner = false;
                        it2->second.first -= intercambio;
                        comerciar_ajustes(it1->first, intercambio, poner, p);
                    }
                }
                ++it1;
                ++it2;
            }
        }
    }
    
    void Ciudad::modificar_prod(const int& ident_prod, int& uni_tiene, int& uni_quiere, Cjt_productos& p){
        map<int, pair <int, int>>::iterator it = productos.find(ident_prod);
        peso_total += (uni_tiene-(it->second.first))*p.peso(ident_prod);
        volumen_total += (uni_tiene-(it->second.first))*p.volumen(ident_prod);
        it->second.first = uni_tiene;
        it->second.second = uni_quiere;
    }
    void Ciudad::poner_prod(const int& ident_prod, const int& uni_tiene, const int& uni_quiere, Cjt_productos& p){
        productos.insert(make_pair(ident_prod, make_pair(uni_tiene, uni_quiere)));
        peso_total += uni_tiene*p.peso(ident_prod);
        volumen_total += uni_tiene*p.volumen(ident_prod);
    }
    void Ciudad::comerciar_ajustes(const int& ident_prod, int& intercambio, bool& poner, Cjt_productos& p) {
        map<int, pair <int, int>>::iterator it = productos.find(ident_prod);
        if(poner){
            peso_total += intercambio*p.peso(ident_prod);
            volumen_total += intercambio*p.volumen(ident_prod);
        }
        else{
            peso_total += intercambio*p.peso(ident_prod);
            volumen_total += intercambio*p.volumen(ident_prod);
        }
    }
    void Ciudad::quitar_prod(const int& ident_prod, Cjt_productos p){
        map<int, pair <int, int>>::const_iterator it = productos.find(ident_prod);
        int cant = it->second.first;
        peso_total -= cant*p.peso(ident_prod);
        volumen_total -= cant*p.volumen(ident_prod);
        productos.erase(it);
    }
    void Ciudad::eliminar_inventario(){
        productos.clear();
        peso_total = 0;
        volumen_total = 0;
    }