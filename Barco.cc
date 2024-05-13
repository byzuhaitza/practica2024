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

    //MODIFICADORAS
    void Barco::modificar_barco(const int& ident_prod_comp, const int& ident_prod_vend, const int& cant_prod_comp, const int& cant_prod_vend){
        id_prod_comp = ident_prod_comp;
        total_uni_comp = cant_prod_comp;
        id_prod_vend = ident_prod_vend;
        total_uni_vend = cant_prod_vend;
    }
