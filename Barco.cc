/**
 *@file Barco.cc
 *@author Itsaso Olaizola Guereño
 *@brief Codigo de la clase Barco
 * 
*/

#include "Barco.hh"

    //CONSTRUCTORAS 
    Barco::Barco(){}
    
    void Barco::inicializar_barco(){
        cin >> id_prod_comp >> total_uni_comp >> id_prod_vend >> total_uni_vend;
    }

    //CONSULTORAS
    void Barco::escribir_barco(){
        cout << id_prod_comp << " " << total_uni_comp << " " << id_prod_vend << " " << total_uni_vend << endl;
        list<string>::iterator it = viajes.begin();
        while (it != viajes.end()) {
            cout << *it << endl;
            ++it;
        }
    }
    int Barco::consultar_id_prod_vend() {
        return id_prod_vend;
    }
    int Barco::consultar_id_prod_comp() {
        return id_prod_comp;
    }
    int Barco::consultar_cantidad_compra() {
        return total_uni_comp;
    }
    int Barco::consultar_cantidad_venta() {
        return total_uni_vend;
    }

    //MODIFICADORAS
    int Barco::modificar_barco(const int& ident_prod_comp, const int& ident_prod_vend, const int& cant_prod_comp, const int& cant_prod_vend, Cjt_productos& p){
        if (not p.existe_prod(ident_prod_comp) or not p.existe_prod(ident_prod_vend)) return 21;
        else {
            if(ident_prod_comp == ident_prod_vend) return 19;
            else {
                id_prod_comp = ident_prod_comp;
                total_uni_comp = cant_prod_comp;
                id_prod_vend = ident_prod_vend;
                total_uni_vend = cant_prod_vend;
                return 0;
            }
        }
    }
    void Barco::hacer_viaje(string ult_ciudad){
        viajes.push_back(ult_ciudad);
    }
    void Barco::actualizar_viajes() {
        viajes.clear();
    }
