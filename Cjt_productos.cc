/**
 *@file Cjt_productos.cc
 *@author Itsaso Olaizola Guereño
 *@brief Codigo de la clase Cjt_productos
 * 
*/

#include "Cjt_productos.hh"

    //CONSTRUCTORA
    Cjt_productos::Cjt_productos(){}

    void Cjt_productos::inicializar_productos(){
        int num_prod;
        cin >> num_prod;
        for(int i = 1; i <= num_prod; ++i) {
            int peso, volumen;
            cin >> peso >> volumen;
            prod_peso_volumen.insert(make_pair(i, make_pair(peso, volumen)));
        }
    }

    //CONSULTORA
    int Cjt_productos::num_total(){
        return prod_peso_volumen.size();
    }

    int Cjt_productos::peso(const int& ident_prod)const {
        map<int, pair<int, int>>::const_iterator it = prod_peso_volumen.find(ident_prod);
        return it->second.first;
    }

    int Cjt_productos::volumen(const int& ident_prod)const {
        map<int, pair<int, int>>::const_iterator it = prod_peso_volumen.find(ident_prod);
        return it->second.second;
    }

    bool Cjt_productos::existe_prod(const int& ident_prod) const{
        map<int, pair <int, int>>::const_iterator it = prod_peso_volumen.find(ident_prod);
        if (it != prod_peso_volumen.end()) return true;
        else return false;
    }

    //MODIFICADORA
    void Cjt_productos::nuevos_productos(int num_prod_nuevos){
        int nuevo = prod_peso_volumen.size()+1;
        int i = 0;
        while (i <  num_prod_nuevos) {
            int peso_prod, vol_prod;
            cin >> peso_prod >> vol_prod;

            prod_peso_volumen.insert(make_pair(nuevo, make_pair(peso_prod, vol_prod)));
            ++i;
            ++nuevo;
        }
    }

