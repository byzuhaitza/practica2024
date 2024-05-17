/**
 *@file Cjt_rios.cc
 *@author Itsaso Olaizola Guereño
 *@brief Codigo de la clase Cjt_rios
 * 
*/

#include "Cjt_rios.hh"

typedef map<string, Ciudad>::const_iterator fijo;
typedef map<string, Ciudad>::iterator no_fijo;

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
        fijo it = ciudades.find(ident_ciudad);
        if (it != ciudades.end()) return true;
        else return false;
    }

    int Cjt_rios::leer_inventario(const string& ident_ciudad, const Cjt_productos& Cjt_productos){
        if (not existe_ciudad(ident_ciudad)) return 23;
            else{
                no_fijo itc = ciudades.find(ident_ciudad);
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

    void Cjt_rios::leer_inventarios(const Cjt_productos& Cjt_productos){
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

    int Cjt_rios::consultar(const string& ident_ciudad, const int& ident_prod, const Cjt_productos& Cjt_productos) const{
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

    int Cjt_rios::modificar_prod(const string& ident_ciudad, const int& ident_prod, int& uni_tiene, int& uni_quiere, const Cjt_productos& Cjt_productos){
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

    int Cjt_rios::poner_prod(const string& ident_ciudad, const int& ident_prod, const int& uni_tiene, const int& uni_quiere, const Cjt_productos& Cjt_productos) {
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

    int Cjt_rios::quitar_prod(const string& ident_ciudad, const int& ident_prod, const Cjt_productos& Cjt_productos){
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

    int Cjt_rios::comerciar(const string& ident_ciudad_1, const string& ident_ciudad_2, const Cjt_productos& Cjt_productos){
        if(ident_ciudad_1 == ident_ciudad_2) return 22;
        no_fijo it1 = ciudades.find(ident_ciudad_1);
        if (it1 == ciudades.end()) return 23;
        no_fijo it2 = ciudades.find(ident_ciudad_2);
        if (it2 == ciudades.end()) return 23;
        it1->second.comerciar_prod(it2->second, Cjt_productos);
        return 0;
    }

    void Cjt_rios::redistribuir(const Cjt_productos& p){
        redistribuir_rec(arbol,p);
    }
    
    void Cjt_rios::redistribuir_rec(const BinTree<string>& a, const Cjt_productos& Cjt_productos){
        if(not a.empty() and not a.left().empty()){
            string ciudad_ahora = a.value();
            string ciudad_izquierda = a.left().value();
            string ciudad_derecha = a.right().value();

            comerciar(ciudad_ahora, ciudad_izquierda,Cjt_productos);
            redistribuir_rec(a.left(), Cjt_productos);

            comerciar(ciudad_ahora, ciudad_derecha,Cjt_productos);
            redistribuir_rec(a.right(), Cjt_productos);
        }
    }

    int Cjt_rios::hacer_viaje(Barco& b, const Cjt_productos& Cjt_productos){
        vector<string> mejor_ruta;
        int ya_comprado = 0;
        int ya_vendido = 0;
        int total_compvend = calcular_ruta_rec(mejor_ruta, b, ya_comprado, ya_vendido, arbol);
        if(total_compvend != 0) {
           string ult_ciudad = viajar_ruta(mejor_ruta,b,Cjt_productos); //recorrer la ruta y ir comprando y vendiendo sin superar el maximo del barco
            b.hacer_viaje(ult_ciudad);//actualizar las cantidades de los productos y guardar la ultima ciudad. no cambia cantidad
        }
        return total_compvend;
    }

    int Cjt_rios::calcular_ruta_rec(vector<string>& mejor_ruta, Barco& b, int ya_comprado, int ya_vendido, const BinTree<string>& a) {
        //ya_comprado es lo que mis ascendientes ya han comprado
        //ya_vendido es lo que mis ascendientes ya han vendido
        // return tiene q ser lo que yo y mis hijos hemos comprado + lo que hemos vendido
        int max_compra = b.consultar_cantidad_compra();
        int max_venta = b.consultar_cantidad_venta();
        if(not a.empty() and (ya_comprado < max_compra or ya_vendido < max_venta)){
            //interaccion con la ciudad, a.value(), --> c, v a la ciudad (teniendo en cuenta el maximo del barco)
            map<string,Ciudad>::iterator it =  ciudades.find(a.value());
            int comprado_aqui = it->second.barco_puede_comprar(b.consultar_id_prod_comp(), (max_compra-ya_comprado));
            ya_comprado += comprado_aqui;
            int vendido_aqui = it->second.barco_puede_vender(b.consultar_id_prod_vend(), (max_venta-ya_vendido));
            ya_vendido += vendido_aqui;
            vector<string> ruta1, ruta2;
            int total1 = calcular_ruta_rec(ruta1,b,ya_comprado,ya_vendido,a.left());
            int total2 = calcular_ruta_rec(ruta2,b,ya_comprado,ya_vendido,a.right());
            //comparaciones de las dos rutas 1 y 2
            if (total1 > total2 or (total1 == total2 and ruta1.size() <= ruta2.size())) {
                mejor_ruta = ruta1;
                int total = total1 + comprado_aqui + vendido_aqui;
                if(total > 0) mejor_ruta.insert(mejor_ruta.begin(), a.value());
                return total;
            } 
            else {
                mejor_ruta = ruta2;
                int total = total2 + comprado_aqui + vendido_aqui;
                if(total > 0) mejor_ruta.insert(mejor_ruta.begin(), a.value());
                return total;
            }
        }
        return 0;
    }
    string Cjt_rios::viajar_ruta(vector<string>& mejor_ruta, Barco& b, Cjt_productos Cjt_productos) {
               //simplemente cambio las cantidades de la ciudad, porque se supone que el barco no tengo que tocarlo.
        int max_compra_ciudad = b.consultar_cantidad_compra();
        int max_venta_ciudad = b.consultar_cantidad_venta();
        for(int i = 0; i < mejor_ruta.size(); ++i) {
            int nuevo1 = ciudades.find(mejor_ruta[i])->second.barco_comprar(b.consultar_id_prod_comp(), max_compra_ciudad, Cjt_productos);
            max_compra_ciudad = nuevo1;
            int nuevo2 = ciudades.find(mejor_ruta[i])->second.barco_vender(b.consultar_id_prod_vend(), max_venta_ciudad, Cjt_productos);
            max_venta_ciudad = nuevo2;
        }
        return mejor_ruta[mejor_ruta.size()-1];
    }