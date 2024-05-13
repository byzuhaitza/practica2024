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
    
    }
    
    void Ciudad::modificar_prod(const int& ident_prod, int& uni_tiene, int& uni_quiere, int &peso, int& volumen){
        map<int, pair <int, int>>::iterator it = productos.find(ident_prod);
        peso_total += (uni_tiene-(it->second.first))*peso;
        volumen_total += (uni_tiene-(it->second.first))*volumen;
        it->second.first = uni_tiene;
        it->second.second = uni_quiere;
    }
    void Ciudad::poner_prod(const int& ident_prod, const int& uni_tiene, const int& uni_quiere, int& peso, int& volumen){
        productos.insert(make_pair(ident_prod, make_pair(uni_tiene, uni_quiere)));
        peso_total += uni_tiene*peso;
        volumen_total += uni_tiene*volumen;
    }
    void Ciudad::quitar_prod(const int& ident_prod, int &peso, int& volumen){
        map<int, pair <int, int>>::const_iterator it = productos.find(ident_prod);
        int cant = it->second.first;
        peso_total -= cant*peso;
        volumen_total -= cant*volumen;
        productos.erase(it);
    }
    void Ciudad::eliminar_inventario(){
        productos.clear();
        peso_total = 0;
        volumen_total = 0;
    }