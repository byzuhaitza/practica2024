/** @file Ciudad.hh
 @brief Especificación de la clase Ciudad
*/

#ifndef CIUDAD_HH
#define CIUDAD_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#endif
#include "Cjt_productos.hh"

using namespace std;

class Ciudad {
    private:
    /**
        @brief Productos que tiene la ciudad, junto con las unidades que tiene y necesita de cada uno de ellos.   
    */
    map<int, pair<int, int>> productos;
    /**
        @brief Peso total de la ciudad.   
    */
    int peso_total;
    /**
        @brief Volumen total de la ciudad.   
    */
    int volumen_total;

    public:
    // CONSTRUCTORAS
    /**
        @brief Creador por defecto.
        \pre <em>Cierto</em>.
        \post Toda la información que tenemos sobre la ciudad.   
    */
        Ciudad();

    // CONSULTORAS
    /**  
        @brief Mira si el producto que hemos leído está en el inventario de la ciudad.
        @param ident_prod
        \pre Todos los parámetros están inicializados.
        \post La función nos devuelve si el producto existe en la ciudad.
    */
        bool existe_prod(const int& ident_prod) const;
    /**  
        @brief Imprime toda la información que tenemos de la ciudad.
        \pre <em>Cierto</em>.
        \post La función devuelve toda la información del inventario, junto con el peso y el volumen total.
    */
        void escribir_ciudad();
    /**  
        @brief Imprime todos los datos de los productos almacenados en esta ciudad.
        \pre <em>Cierto</em>.
        \post La función devuelve toda la información del inventario.
    */
        void escribir_inventario();
    /**  
        @brief Escribe la información del producto que hemos leído.
        @param ident_prod
        \pre Todos los parámetros están inicializados.
        \post La función nos devuelve las unidades que tiene y necesita esta ciudad de dicho producto.
    */
        void consultar_prod(const int& ident_prod) const;
    /**  
        @brief Mira si el inventario de la ciudad está vacío.
        \pre <em>Cierto</em>.
        \post Devuelve si hay algo en el inventario o no.
    */
        bool inv_ciu_vacio() const;
    /**  
        @brief Mira si el barco puede comprar algo en esta ciudad.
        @param id_producto, max_compra
        \pre Todos los parámetros están inicializados.
        \post En caso de que pueda, se devuelve el máximo que se podía comprar menos lo que ha comprado en la ciudad, y si no, devuelve el máximo que se podía comprar.
    */
        int barco_puede_comprar(int id_producto, int max_compra) const;
    /**  
        @brief Mira si el barco puede vender algo en esta ciudad.
        @param id_producto, max_venta
        \pre Todos los parámetros están inicializados.
        \post En caso de que pueda, se devuelve el máximo que se podía vender menos lo que ha vendido en la ciudad, y si no, devuelve el máximo que se podía vender.
    */
        int barco_puede_vender(int id_producto, int max_venta) const;

    // MODIFICADORAS
    /**  
        @brief Comercia productos entre dos ciudades según la necesidad de cada una de ellas.
        @param otra, p
        \pre Todos los parámetros están inicializados.
        \post El proceso de intercambio entre ciudades habrá terminado.
    */
        void comerciar_prod(Ciudad& otra, const Cjt_productos& p);
    /**  
        @brief Cambia las unidades que tiene y que quiere del producto requerido.
        @param ident_prod, uni_tiene, uni_quiere, p
        \pre Todos los parámetros están inicializados y uni_quiere > 0.
        \post La función nos devuelve el peso y volumen total de la ciudad una vez cambiada, debido al posible cambio de las unidades que tiene la ciudad.
    */
        void modificar_prod(const int& ident_prod, int& uni_tiene, int& uni_quiere, const Cjt_productos& p);
    /**  
        @brief Añade el producto que leemos, junto con las unidades que tendrá esta ciudad y las que necesita.
        @param ident_prod, uni_tiene, uni_quiere, p, leer
        \pre Todos los parámetros están inicializados.
        \post La función nos devuelve el peso y volumen total de la ciudad una vez cambiada, debido al posible cambio de las unidades que tiene la ciudad.
    */
        void poner_prod(const int& ident_prod, const int& uni_tiene, const int& uni_quiere, const Cjt_productos& p, bool& leer);
    /**  
        @brief Elimina todos los datos que tenemos del producto que acabamos de leer.
        @param ident_prod, p
        \pre Todos los parámetros están inicializados.
        \post La función nos devuelve el peso y volumen total de la ciudad una vez cambiada, debido al cambio de las unidades que tiene la ciudad.
    */
        void quitar_prod(const int& ident_prod, Cjt_productos p);
    /**  
        @brief Hace todos los cambios necesarios en las ciudades después de haber comerciado.
        @param ident_prod, intercambio, poner, p
        \pre Todos los parámetros están inicializados.
        \post La ciudad tiene toda la información actualizada.
    */
        void comerciar_ajustes(const int& ident_prod, int intercambio, bool& poner, const Cjt_productos& p);
    /**  
        @brief Eliminamos el inventario.
        \pre <em>Cierto</em>.
        \post El inventario está vacío, y el peso y volumen total de la ciudad son 0.
    */
        void eliminar_inventario();
    /**  
        @brief Las operaciones calculadas en la función barco_puede_comprar se hacen aquí.
        @param id_producto, max_compra_ciudad, p
        \pre Todos los parámetros están inicializados.
        \post La ciudad habrá cambiado su inventario tras comerciar con el barco.
    */
        int barco_comprar(int id_producto, int max_compra_ciudad, Cjt_productos& p);
    /**  
        @brief Las operaciones calculadas en la función barco_puede_vender se hacen aquí.
        @param id_producto, max_venta_ciudad, p
        \pre Todos los parámetros están inicializados.
        \post La ciudad habrá cambiado su inventario tras comerciar con el barco.
    */
        int barco_vender(int id_producto, int max_venta_ciudad, Cjt_productos& p);
};
#endif