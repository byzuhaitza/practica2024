/** @file Barco.hh
 @brief Especificación de la clase Barco
*/

#ifndef BARCO_HH
#define BARCO_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#include <list>
#endif
#include "Cjt_productos.hh"

using namespace std;

class Barco {
    private:
    /**
        @brief ID del producto que el barco quiere comprar.   
    */
        int id_prod_comp;
    /**
        @brief ID del producto que el barco quiere vender.   
    */
        int id_prod_vend;
    /**
        @brief Cantidad de dicho producto que el barco quiere vender.   
    */
        int total_uni_comp;
    /**
        @brief Cantidad de dicho producto que el barco quiere comprar.   
    */
        int total_uni_vend;
    /**
        @brief Productos que tiene la ciudad, junto con las unidades que tiene y necesita de cada uno de ellos.   
    */
        list<string> viajes;

    public:
    // CONSTRUCTORAS
    /**
        @brief Creador por defecto.
        \pre <em>Cierto</em>.
        \post El barco.   
    */
        Barco();

    /**  
        @brief Inicializa todos los atributos privados que almacenan la información de los productos que tiene y quiere el barco. 
        \pre <em>Cierto</em>.
        \post Se inicializan los identificadores de los productos que el barco quiere comprar y vender, junto con sus cantidades correspondientes.
    */
        void inicializar_barco();

    // CONSULTORAS
    /**  
        @brief Imprime toda la información que tenemos, es decir, los identificadores de los productos que el barco quiere comprar y vender, junto con sus cantidades correspondientes y la lista, que contiene la última ciudad por la que se pasa en cada viaje.
        \pre <em>Cierto</em>.
        \post Imprime todos los atributos privados de la clase.
    */
        void escribir_barco();
    /**  
        @brief Consulta cuánta cantidad queremos comprar de este producto.
        \pre <em>Cierto</em>.
        \post Devuelve la cantidad que queremos comprar de este producto.
    */
        int consultar_cantidad_compra();
    /**  
        @brief Consulta cuánta cantidad queremos vender de este producto.
        \pre <em>Cierto</em>.
        \post Devuelve la cantidad que queremos vender de este producto.
    */
        int consultar_cantidad_venta();
    /**  
        @brief Consulta cuál es el producto que queremos vender.
        \pre <em>Cierto</em>.
        \post Devuelve el identificador del producto que queremos vender.
    */
        int consultar_id_prod_vend();
    /**  
        @brief Consulta cuál es el producto que queremos comprar.
        \pre <em>Cierto</em>.
        \post Devuelve el identificador del producto que queremos comprar.
    */
        int consultar_id_prod_comp();

    // MODIFICADORAS
    /**  
        @brief Actualiza todos los datos del barco, estos siendo, los identificadores de los productos que el barco quiere comprar y vender, junto con sus cantidades correspondientes.
        \warning Salta un error en caso de que alguno de los dos productos no exista o en el caso de que intentemos comprar y vender el mismo producto.
        @param ident_prod_comp, ident_prod_vend, cant_prod_comp, cant_prod_vend, Cjt_productos 
        \pre Todos los parámetros están inicializados.
        \post Todos los atributos privados, sin contar con la lista, son actualizados.
    */
        int modificar_barco(const int& ident_prod_comp, const int& ident_prod_vend, const int& cant_prod_comp, const int& cant_prod_vend, Cjt_productos& p);
    /**  
        @brief Añade la última ciudad del recorrido a nuestro registro de viajes realizados por el barco.
        @param ult_ciudad
        \pre Todos los parámetros están inicializados.
        \post La lista viajes tiene un elemento nuevo.
    */
        void hacer_viaje(string ult_ciudad);
    /**  
        @brief Vaciamos la lista de viajes.
        \pre <em>Cierto</em>.
        \post Se elimina el contenido de la lista de viajes.
    */
        void actualizar_viajes();
};
#endif
