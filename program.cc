/**
    @mainpage Comercio fluvial

    Este programa nos permite simular el comercio dado en una cuenca fluvial, con sus correspondientes rios, ciudades y un barco.
*/

/**
    @file program.cc
    @author Itsaso Olaizola Guereño
    @brief Programa princicpal para la practica <em>Comercio fluvial</em>.
    @date 02/05/2024
*/

#include "Cjt_rios.hh"
#include "Barco.hh"
#include "Cjt_productos.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif
using namespace std;


/**
    @brief Controla todas las operaciones que se pueden realizar en la cuenca fluvial.
*/

int main() {
    Cjt_rios r;
    Barco b;
    Cjt_productos p;
    p.inicializar_productos();
    r.inicializar_cuenca();
    b.inicializar_barco();
    string op;
    while (cin >> op and op != "fin") {
        if(op == "//"){
            string comentario;
            getline(cin,comentario);
        }
        else if (op == "leer_rio" or op == "lr") {
            cout << "#" << op << endl;
            r.inicializar_cuenca();
        }
        else if (op == "leer_inventario" or op == "li") {
            string ident_ciudad;
            cin >> ident_ciudad;
            cout << "#" << op << " " <<  ident_ciudad << endl;
            if (not r.existe_ciudad(ident_ciudad)) {
                cout << "error: no existe la ciudad" << endl;
            }
            else r.leer_inventario(ident_ciudad, p);
        }
        else if (op == "leer_inventarios" or op == "ls") {
            cout << "#" << op << endl;
            r.leer_inventarios(p);
        }
        else if (op == "modificar_barco" or op == "mb") {
            int ident_prod_comp;
            int ident_prod_vend;
            int cant_prod_comp, cant_prod_vend;
            cin >> ident_prod_comp >> cant_prod_comp >> ident_prod_vend >> cant_prod_vend;
            cout << "#" << op << endl;
            if (not p.existe_prod(ident_prod_comp) or not p.existe_prod(ident_prod_vend)) {
                cout << "error: no existe el producto" << endl;
            }
            else {
                if(ident_prod_comp == ident_prod_vend) {
                    cout << "error: no se puede comprar y vender el mismo producto" << endl;
                }
                else {
                    b.modificar_barco(ident_prod_comp, ident_prod_vend, cant_prod_comp, cant_prod_vend);
                }
            }
        }
        else if (op == "escribir_barco" or op == "eb") {
            cout << "#" << op << endl;
            b.escribir_barco();
        }
        else if (op == "consultar_num" or op == "cn") {
            cout << "#" << op << endl;
            cout << p.num_total() << endl;
        }
        else if (op == "agregar_productos" or op == "ap") {
            int num_prod_nuevos;
            cin >> num_prod_nuevos;
            cout << "#" << op << ' ' << num_prod_nuevos << endl;
            p.nuevos_productos(num_prod_nuevos);
        }
        else if (op == "escribir_producto" or op == "ep") {
            int ident_prod;
            cin >> ident_prod;
            cout << "#" << op << " " << ident_prod << endl;
            if (not p.existe_prod(ident_prod)) {
                cout << "error: no existe el producto" << endl;
            }
            else{
                cout << ident_prod << ' ' << p.peso(ident_prod) << ' ' << p.volumen(ident_prod) << endl;
            }
        }
        else if (op == "escribir_ciudad" or op == "ec") {
            string ident_ciudad;
            cin >> ident_ciudad;
            cout << "#" << op << " " << ident_ciudad << endl;
            if (not r.existe_ciudad(ident_ciudad)) {
                cout << "error: no existe la ciudad" << endl;
            }
            else{
                r.escribir_ciudad(ident_ciudad);
            }
        }
        else if (op == "poner_prod" or op == "pp") {
            string ident_ciudad;
            int ident_prod;
            int uni_tiene, uni_quiere;
            cin >> ident_ciudad >> ident_prod >> uni_tiene >> uni_quiere;
            cout << "#" << op << " " << ident_ciudad << " " << ident_prod << endl;
            if (not p.existe_prod(ident_prod)) {
                cout << "error: no existe el producto" << endl;
            }
            else {
                if (not r.existe_ciudad(ident_ciudad)) {
                    cout << "error: no existe la ciudad" << endl;
                }
                else{
                    if (r.existe_prod_ciudad(ident_ciudad, ident_prod)){
                    cout << "error: la ciudad ya tiene el producto" << endl;
                    }
                    else {
                        r.poner_prod(ident_ciudad, ident_prod, uni_tiene, uni_quiere, p);
                    }
                }
            }
        }
        else if (op == "modificar_prod" or op == "mp") {
            string ident_ciudad;
            int ident_prod;
            int uni_tiene, uni_quiere;
            cin >> ident_ciudad >> ident_prod >> uni_tiene >> uni_quiere;
            cout << "#" << op << " " << ident_ciudad << " " << ident_prod << endl;
            if (not p.existe_prod(ident_prod)) {
                cout << "error: no existe el producto" << endl;
            }
            else {
                if (not r.existe_ciudad(ident_ciudad)) {
                    cout << "error: no existe la ciudad" << endl;
                }
                else{
                    if (not r.existe_prod_ciudad(ident_ciudad, ident_prod)){
                    cout << "error: la ciudad no tiene el producto" << endl;
                    }
                    else {
                        r.modificar_prod(ident_ciudad, ident_prod, uni_tiene, uni_quiere, p);
                    }
                }
            }
        }
        else if (op == "quitar_prod" or op == "qp") {
            string ident_ciudad;
            int ident_prod;
            cin >> ident_ciudad >> ident_prod;
            cout << "#" << op << " " << ident_ciudad << " " << ident_prod << endl;
            if (not p.existe_prod(ident_prod)) {
                cout << "error: no existe el producto" << endl;
            }
            else {
                if (not r.existe_ciudad(ident_ciudad)) {
                    cout << "error: no existe la ciudad" << endl;
                }
                else{
                    if (not r.existe_prod_ciudad(ident_ciudad, ident_prod)){
                    cout << "error: la ciudad no tiene el producto" << endl;
                    }
                    else {
                        r.quitar_prod(ident_ciudad, ident_prod, p);
                    }
                }
            }
        }
        else if (op == "consultar_prod" or op == "cp") {
            string ident_ciudad;
            int ident_prod;
            cin >> ident_ciudad >> ident_prod;
            cout << "#" << op << " " << ident_ciudad << " " << ident_prod << endl;
            if (not p.existe_prod(ident_prod)) {
                cout << "error: no existe el producto" << endl;
            }
            else {
                if (not r.existe_ciudad(ident_ciudad)) {
                    cout << "error: no existe la ciudad" << endl;
                }
                else{
                    if (not r.existe_prod_ciudad(ident_ciudad, ident_prod)){
                    cout << "error: la ciudad no tiene el producto" << endl;
                    }
                    else {
                        r.consultar(ident_ciudad, ident_prod);
                    }
                }
                
            }
        }
        else if (op == "comerciar" or op == "co") {
            string ident_ciudad_1, ident_ciudad_2;
            cin >> ident_ciudad_1 >> ident_ciudad_2;
            cout << "#" << op << " " << ident_ciudad_1 << " " << ident_ciudad_2 << endl;
            if (r.comerciar(ident_ciudad_1, ident_ciudad_2) == 23) cout << "error: no existe la ciudad" << endl;
            else if (r.comerciar(ident_ciudad_1, ident_ciudad_2) == 22) cout << "error: ciudad repetida" << endl;
        }
        else if (op == "redistribuir" or op == "re") {
            cout << "#" << op << endl;
            r.redistribuir();
        }
        else if (op == "hacer_viaje" or op == "hv") {
            cout << "#" << op << endl;
            r.hacer_viaje(b);
        }
    }
}