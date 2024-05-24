/**
 *@file Ciudad.cc
 *@author Itsaso Olaizola Guereño
 *@brief Codigo de la clase Ciudad
 * 
*/

#include "Ciudad.hh"

typedef map<int,pair<int, int>>::const_iterator constante; //ahorrar crear el mismo iterador una y otra vez
typedef map<int, pair <int, int>>::iterator iterador;

    //CONSTRUCTORAS
    Ciudad::Ciudad(){
        peso_total = 0;
        volumen_total = 0;
    }

    //CONSULTORAS
    bool Ciudad::existe_prod(const int& ident_prod) const{
        constante it = productos.find(ident_prod);
        if (it != productos.end()) return true;
        else return false;
    }
    void Ciudad::escribir_ciudad(){
        escribir_inventario();
        cout << peso_total << ' ' << volumen_total << endl;
    }
    void Ciudad::escribir_inventario(){
        constante it = productos.begin();
        while(it != productos.end()) {
            cout << it->first << ' ' << it->second.first << ' ' << it->second.second << endl;
            ++it; 
        }
    }
    void Ciudad::consultar_prod(const int& ident_prod) const{
        constante it = productos.find(ident_prod);
        cout << it->second.first << ' ' << it->second.second << endl;
    }
    bool Ciudad::inv_ciu_vacio() const{
        if (productos.empty()) return true;
        else return false;
    }
    int Ciudad::barco_puede_comprar(int id_producto, int max_compra_ciudad) const {
        auto it = productos.find(id_producto);
        if (it == productos.end()) {
            return 0; // El producto no está disponible en esta ciudad
        }
        else {
            int cantidad_disponible = it->second.second - it->second.first;
            if(cantidad_disponible < 0 and abs(cantidad_disponible) <= max_compra_ciudad) return abs(cantidad_disponible);
            else if(cantidad_disponible < 0) return max_compra_ciudad;
            else return 0;
        }
    }

    int Ciudad::barco_puede_vender(int id_producto, int max_venta_ciudad) const {
        auto it = productos.find(id_producto);
        if (it == productos.end()) {
            return 0; // El producto no está disponible en esta ciudad
        }
        else {
            int cantidad_disponible = it->second.second - it->second.first;
            if(cantidad_disponible > 0 and cantidad_disponible <= max_venta_ciudad) return abs(cantidad_disponible);
            else if(cantidad_disponible > 0) return max_venta_ciudad;
            else return 0;
        }
    }

    //MODIFICADORAS
    void Ciudad::comerciar_prod(Ciudad& otra_ciudad, const Cjt_productos& p ){
    iterador it1 = productos.begin();
    iterador it2 = otra_ciudad.productos.begin();
    // Iteramos sobre los productos de ambas ciudades
    while(it1 != productos.end() and it2 != otra_ciudad.productos.end()) {
/* \pre Las ciudades existen en la cuenca.
        Los inventarios de ambas ciudades no están vacios.
    \post Se efectua el intercambio de productos entre ciudades dependiendo de las necesidades de cada una.
*/
        if (it1->first < it2->first) {
            ++it1; // Avanzamos en el inventario de la primera ciudad
        }
        else if (it1->first > it2->first) {
            ++it2; // Avanzamos en el inventario de la otra ciudad
        }
        else {
            // Calculamos la cantidad que necesita cada ciudad
            int cant1 = it1->second.second - it1->second.first;
            int cant2 = it2->second.second - it2->second.first;
            if (cant1 * cant2 < 0) { // Si las necesidades son opuestas
                int intercambio = min(abs(cant1), abs(cant2)); // Calculamos la cantidad a intercambiar
                bool poner = false;
                if (cant1 < cant2) {
                    it1->second.first -= intercambio; // Actualizamos la primera ciudad
                    comerciar_ajustes(it1->first, intercambio, poner, p);
                    poner = true;
                    it2->second.first += intercambio; // Actualizamos la otra ciudad
                    otra_ciudad.comerciar_ajustes(it1->first, intercambio, poner, p);
                }
                else {
                    poner = true;
                    it1->second.first += intercambio; // Actualizamos la primera ciudad
                    comerciar_ajustes(it1->first, intercambio, poner, p);
                    poner = false;
                    it2->second.first -= intercambio; // Actualizamos la otra ciudad
                    otra_ciudad.comerciar_ajustes(it1->first, intercambio, poner, p);
                }
            }
            ++it1; // Avanzamos en ambos inventarios
            ++it2;
        }
    }
}

    
    void Ciudad::modificar_prod(const int& ident_prod, int& uni_tiene, int& uni_quiere, const Cjt_productos& p){
        iterador it = productos.find(ident_prod);
        peso_total += (uni_tiene-(it->second.first))*p.peso(ident_prod);
        volumen_total += (uni_tiene-(it->second.first))*p.volumen(ident_prod);
        it->second.first = uni_tiene;
        it->second.second = uni_quiere;
        cout << peso_total << ' ' << volumen_total << endl;
    }
    void Ciudad::poner_prod(const int& ident_prod, const int& uni_tiene, const int& uni_quiere, const Cjt_productos& p, bool& leer){
        productos.insert(make_pair(ident_prod, make_pair(uni_tiene, uni_quiere)));
        peso_total += uni_tiene*p.peso(ident_prod);
        volumen_total += uni_tiene*p.volumen(ident_prod);
        if(not leer) cout << peso_total << ' ' << volumen_total << endl;
    }
    void Ciudad::comerciar_ajustes(const int& ident_prod, int intercambio, bool& poner, const Cjt_productos& p) {
        int peso_prod = p.peso(ident_prod);
        int vol_prod = p.volumen(ident_prod);
        if(poner){
            peso_total += abs(intercambio)*peso_prod;
            volumen_total += abs(intercambio)*vol_prod;
        }
        else{
            peso_total -= abs(intercambio)*peso_prod;
            volumen_total -= abs(intercambio)*vol_prod;
        }
    }
    void Ciudad::quitar_prod(const int& ident_prod, Cjt_productos p){
        constante it = productos.find(ident_prod);
        int cant = it->second.first;
        peso_total -= cant*p.peso(ident_prod);
        volumen_total -= cant*p.volumen(ident_prod);
        productos.erase(it);
        cout << peso_total << ' ' << volumen_total << endl;
    }
    void Ciudad::eliminar_inventario(){
        productos.clear();
        peso_total = 0;
        volumen_total = 0;
    }
    int Ciudad::barco_comprar(int id_producto, int max_compra_ciudad, Cjt_productos& p) { //si el barco puede comprar es que la ciudad vende
        auto it = productos.find(id_producto);
        bool poner = false;
        if (it != productos.end()) {
            int intercambio = it->second.second - it->second.first;
            if(intercambio < 0){
                if(max_compra_ciudad-abs(intercambio) >= 0){
                    comerciar_ajustes(id_producto, intercambio, poner, p);
                    it->second.first += intercambio;
                    return max_compra_ciudad-abs(intercambio);
                }
                else {
                    comerciar_ajustes(id_producto, max_compra_ciudad, poner, p);
                    it->second.first -= max_compra_ciudad;
                    return 0;
                }
            }
        }
        return max_compra_ciudad;
    }
    int Ciudad::barco_vender(int id_producto, int max_vender_ciudad, Cjt_productos& p) { //si el barco puede vender es que la ciudad compra
        auto it = productos.find(id_producto);
        bool poner = true;
        if (it != productos.end()) {
            int intercambio = it->second.second - it->second.first;
            if(intercambio > 0){
                if(max_vender_ciudad-intercambio >= 0){
                    comerciar_ajustes(id_producto, intercambio, poner, p);
                    it->second.first += intercambio;
                    return max_vender_ciudad-intercambio;
                }
                else {
                    comerciar_ajustes(id_producto, max_vender_ciudad, poner, p);
                    it->second.first += max_vender_ciudad;
                    return 0;
                }
            }
        }
        return max_vender_ciudad;
    }