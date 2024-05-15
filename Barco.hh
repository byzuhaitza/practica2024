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

class Barco{
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
        @brief Productos que tiene la ciudad, junto con las unidades que tiene y necesita de cada uno de ellos.   
    */
        int total_uni_comp;
    /**
        @brief Productos que tiene la ciudad, junto con las unidades que tiene y necesita de cada uno de ellos.   
    */
        int total_uni_vend;
/**
    @brief Productos que tiene la ciudad, junto con las unidades que tiene y necesita de cada uno de ellos.   
*/
    list <string> viajes;

    public:
/**  
    @brief 
    \pre: Cierto.
    \post: 
*/
    Barco();

/**  
    @brief 
    @param
    \pre: Cierto.
    \post: 
*/
    void inicializar_barco();
/**  
    @brief 
    @param
    \pre: Cierto.
    \post: 
*/
    int modificar_barco(const int& ident_prod_comp, const int& ident_prod_vend, const int& cant_prod_comp, const int& cant_prod_vend, Cjt_productos& p);
/**  
    @brief 
    @param
    \pre: Cierto.
    \post: 
*/
    void hacer_viaje(string ult_ciudad, int ya_comprado, int ya_vendido);
/**  
    @brief 
    @param
    \pre: Cierto.
    \post: 
*/
    void escribir_barco();
    int consultar_cantidad_compra();
    int consultar_cantidad_venta();
    int consultar_id_prod_vend();
    int consultar_id_prod_comp();
};
#endif