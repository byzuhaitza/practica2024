/**
 *@file Cjt_rios.cc
 *@author Itsaso Olaizola Guereño
 *@brief Codigo de la clase Cjt_rios
 * 
*/

#include "Cjt_rios.hh"

    //CONSTRUCTORAS
    Cjt_rios::Cjt_rios(){}

    void Cjt_rios::inicializar_cuenca() {
        ciudades.clear();
        ini_cuenca(arbol);
    }
    
    void Cjt_rios::ini_cuenca(BinTree<string>& a) {
        string x;
        cin >> x;
        if (x != "#") {
            Ciudad c;
            ciudades.insert(make_pair(x, c));
            
            BinTree<string> left, right;
            ini_cuenca(left);
            ini_cuenca(right);    
            a = BinTree<string>(x, left, right);
            
        }
    }

    //CONSULTORAS

    bool Cjt_rios::existe_ciudad(const string& ident_ciudad) const{
        map<string, Ciudad>::const_iterator it = ciudades.find(ident_ciudad);
        if (it != ciudades.end()) return true;
        else return false;
    }

    int Cjt_rios::leer_inventario(const string& ident_ciudad, Cjt_productos& Cjt_productos){
        if (not existe_ciudad(ident_ciudad)) return 23;
            else{
                map<string, Ciudad>::iterator itc = ciudades.find(ident_ciudad);
                itc->second.eliminar_inventario();
                int num;
                cin >> num;
                for(int i = 1; i <= num; ++i) {
                    int ident_prod, uni_tiene, uni_quiere;
                    cin >> ident_prod >> uni_tiene >> uni_quiere;
                    bool leer = true;
                    itc->second.poner_prod(ident_prod, uni_tiene, uni_quiere, Cjt_productos, leer);
                }
                return 0;
            }
    }

    void Cjt_rios::leer_inventarios(Cjt_productos& Cjt_productos){
        string ident_ciudad;
        while(cin >> ident_ciudad and ident_ciudad != "#"){
            leer_inventario(ident_ciudad, Cjt_productos);
        }
    }

    int Cjt_rios::escribir_ciudad(const string& ident_ciudad) {
        if(not existe_ciudad(ident_ciudad)) return 23;
        else {
            (ciudades.find(ident_ciudad))->second.escribir_ciudad();
            return 0;
        } 
    }

    bool Cjt_rios::existe_prod_ciudad(const string& ident_ciudad, const int& ident_prod) const{
        return (ciudades.find(ident_ciudad))->second.existe_prod(ident_prod);
    }

    int Cjt_rios::consultar(const string& ident_ciudad, const int& ident_prod, Cjt_productos& Cjt_productos) const{
        if (not Cjt_productos.existe_prod(ident_prod)) return 21;
        else {
            if (not existe_ciudad(ident_ciudad)) return 23;
            else{
                if (not existe_prod_ciudad(ident_ciudad, ident_prod)) return 20; 
                else {
                    (ciudades.find(ident_ciudad))->second.consultar_prod(ident_prod);
                    return 0;
                }   
            }
        }
    }
    bool Cjt_rios::inv_ciu_vacio(const string& ident_ciudad)const {
        return (ciudades.find(ident_ciudad))->second.inv_ciu_vacio();
    }

    //MODIFICADORAS

    int Cjt_rios::modificar_prod(const string& ident_ciudad, const int& ident_prod, int& uni_tiene, int& uni_quiere, Cjt_productos& Cjt_productos){
        if (not Cjt_productos.existe_prod(ident_prod)) return 21;
        else {
            if (not existe_ciudad(ident_ciudad)) return 23;
            else{
                if (not existe_prod_ciudad(ident_ciudad, ident_prod)) return 20; 
                else {
                    (ciudades.find(ident_ciudad))->second.modificar_prod(ident_prod, uni_tiene, uni_quiere, Cjt_productos);
                    return 0;
                }
            }
        }
    }

    int Cjt_rios::poner_prod(const string& ident_ciudad, const int& ident_prod, const int& uni_tiene, const int& uni_quiere, Cjt_productos& Cjt_productos) {
        if (not Cjt_productos.existe_prod(ident_prod)) return 21;
        else {
             if (not existe_ciudad(ident_ciudad)) return 23;
                else{
                    if (existe_prod_ciudad(ident_ciudad, ident_prod)) return 18;
                    else {
                        bool leer = false;
                        (ciudades.find(ident_ciudad))->second.poner_prod(ident_prod, uni_tiene, uni_quiere, Cjt_productos, leer);
                        return 0;
                    }
            }
        }
    }

    int Cjt_rios::quitar_prod(const string& ident_ciudad, const int& ident_prod, Cjt_productos& Cjt_productos){
        if (not Cjt_productos.existe_prod(ident_prod)) return 21;
        else {
            if (not existe_ciudad(ident_ciudad)) return 23;
            else{
                if (not existe_prod_ciudad(ident_ciudad, ident_prod)) return 20; 
                else {
                    (ciudades.find(ident_ciudad))->second.quitar_prod(ident_prod, Cjt_productos);
                    return 0;
                }
            }
        }
    }

    int Cjt_rios::comerciar(const string& ident_ciudad_1, const string& ident_ciudad_2){
        if(ident_ciudad_1 == ident_ciudad_2) return 22;
        map<string, Ciudad>::iterator it1 = ciudades.find(ident_ciudad_1);
        if (it1 == ciudades.end()) return 23;
        map<string, Ciudad>::iterator it2 = ciudades.find(ident_ciudad_2);
        if (it2 == ciudades.end()) return 23;
        it1->second.comerciar_prod(it2->second);
        return 0;
    }

    void Cjt_rios::redistribuir(BinTree<string> a, const string& ciudad_ahora){
        if (a.empty()) {
            return;
        }

        string ciudad_ahora = a.value();
        string ciudad_izquierda = a.left().value();
        string ciudad_derecha = a.right().value();

        if (ciudad_izquierda != "#") {
            comerciar(ciudad_ahora, ciudad_izquierda);
            redistribuir(a.left(), ciudad_ahora);
        }

        if (ciudad_derecha != "#") {
            comerciar(ciudad_ahora, ciudad_derecha);
            redistribuir(a.right(), ciudad_ahora);
        }
    }
    
    void Cjt_rios::hacer_viaje(Barco& b){
        Barco c = b;
    }