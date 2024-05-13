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

    void Cjt_rios::leer_inventario(const string& ident_ciudad, Cjt_productos& Cjt_productos){
        map<string, Ciudad>::iterator itc = ciudades.find(ident_ciudad);
        itc->second.eliminar_inventario();
        int num;
        cin >> num;
        for(int i = 1; i <= num; ++i) {
            int ident_prod, uni_tiene, uni_quiere;
            cin >> ident_prod >> uni_tiene >> uni_quiere;
            int peso = Cjt_productos.peso(ident_prod);
            int volumen = Cjt_productos.volumen(ident_prod);;
            itc->second.poner_prod(ident_prod, uni_tiene, uni_quiere, peso, volumen);
            
        }
    }

    void Cjt_rios::leer_inventarios(Cjt_productos& Cjt_productos){
        string ident_ciudad;
        while(cin >> ident_ciudad and ident_ciudad != "#"){
            leer_inventario(ident_ciudad, Cjt_productos);
        }
    }

    void Cjt_rios::escribir_ciudad(const string& ident_ciudad) {
        (ciudades.find(ident_ciudad))->second.escribir_ciudad();
    }

    bool Cjt_rios::existe_prod_ciudad(const string& ident_ciudad, const int& ident_prod) const{
        return (ciudades.find(ident_ciudad))->second.existe_prod(ident_prod);
    }

    void Cjt_rios::consultar(const string& ident_ciudad, const int& ident_prod) const{
        return (ciudades.find(ident_ciudad))->second.consultar_prod(ident_prod);
    }
    bool Cjt_rios::inv_ciu_vacio(const string& ident_ciudad)const {
        return (ciudades.find(ident_ciudad))->second.inv_ciu_vacio();
    }

    //MODIFICADORAS

    void Cjt_rios::modificar_prod(const string& ident_ciudad, const int& ident_prod, int& uni_tiene, int& uni_quiere, Cjt_productos& Cjt_productos){
        int peso = Cjt_productos.peso(ident_prod);
        int volumen = Cjt_productos.volumen(ident_prod);
        (ciudades.find(ident_ciudad))->second.modificar_prod(ident_prod, uni_tiene, uni_quiere, peso, volumen);
    }

    void Cjt_rios::poner_prod(const string& ident_ciudad, const int& ident_prod, const int& uni_tiene, const int& uni_quiere, Cjt_productos& Cjt_productos) {
        int peso = Cjt_productos.peso(ident_prod);
        int volumen = Cjt_productos.volumen(ident_prod);
        (ciudades.find(ident_ciudad))->second.poner_prod(ident_prod, uni_tiene, uni_quiere, peso, volumen);
    }

    void Cjt_rios::quitar_prod(const string& ident_ciudad, const int& ident_prod, Cjt_productos& Cjt_productos){
        int peso = Cjt_productos.peso(ident_prod);
        int volumen = Cjt_productos.volumen(ident_prod);
        (ciudades.find(ident_ciudad))->second.quitar_prod(ident_prod, peso, volumen);
    }

    void Cjt_rios::comerciar(const string& ident_ciudad_1, const string& ident_ciudad_2){
        map<string, Ciudad>::iterator it1 = ciudades.find(ident_ciudad_1);
        map<string, Ciudad>::iterator it2 = ciudades.find(ident_ciudad_2);
        it1->second.comerciar_prod(it2->second);
    }

    void Cjt_rios::redistribuir(){

    }
    
    void Cjt_rios::hacer_viaje(Barco& b){

    }