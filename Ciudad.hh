/** @file Ciudad.hh
 @brief Especificación de la clase Ciudad
*/

#ifndef CUIDAD_HH
#define CIUDAD_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#endif
#include "Cjt_productos.hh"


using namespace std;

class Ciudad{
    private:
    /**
        @brief Productos que tiene la ciudad, junto con las unidades que tiene y necesita de cada uno de ellos.   
    */
    map<int, pair <int, int>> productos;
    /**
        @brief Peso total de la ciudad.   
    */
    int peso_total;
    /**
        @brief Volumen total de la ciudad.   
    */
    int volumen_total;

    public:
    //CONSTRUCTORAS
/**
    @brief Creador por defecto.
    \pre: Cierto.
    \post: Toda la informacion que tenemos sobre la ciudad.   
*/
    Ciudad();

    //CONSULTORAS
/**  
    @brief Nos dice si el producto que hemos leido esta en el inventario de la ciudad.
    @param ident_prod
    \pre: Cierto.
    \post: -La funcion nos devuelve si el producto existe en la ciudad.
*/
    bool existe_prod(const int& ident_prod) const;
/**  
    @brief Imprime toda la informacion que tenemos de la ciudad.
    \pre: Cierto.
    \post: -La funcion devuelve toda la informacion del inventario, junto con el peso y el volumen total.
*/
    void escribir_ciudad();
/**  
    @brief Imprime todos los datos de los productos almacenados en esta ciudad.
    \pre: Cierto.
    \post: -La funcion devuelve toda la informacion del inventario.
*/
    void escribir_inventario();
/**  
    @brief Nos dice la informacion del producto que hemos leido.
    @param ident_prod
    \pre: Cierto.
    \post: -La funcion nos devuelve las unidades que tiene y necesita esta ciudad.
*/
    void consultar_prod(const int& ident_prod) const;
    bool inv_ciu_vacio() const;

    //MODIFICADORAS
/**  
    @brief 
    \pre: Cierto.
    \post: 
*/
    void comerciar_prod(Ciudad& otra, const Cjt_productos& p);//comerciar?
/**  
    @brief Cambia las unidades que tiene y que quiere del producto requerido.
    @param ident_prod, uni_tiene, uni_quiere, peso, volumen
    \pre: Cierto.
    \post: -La funcion nos devuelve el peso y volumen total de la ciudad una vez cambiada, debido al posible cambio de las unidades que tiene la ciudad.
*/
    void modificar_prod(const int& ident_prod, int& uni_tiene, int& uni_quiere, const Cjt_productos& p);
/**  
    @brief Añadimos el producto que leemos, junto con las unidades que tendra esta ciudad y las que necesita.
    @param ident_prod, uni_tiene, uni_quiere, peso, volumen
    \pre: Cierto.
    \post: -La funcion nos devuelve el peso y volumen total de la ciudad una vez cambiada, debido al posible cambio de las unidades que tiene la ciudad.
*/
    void poner_prod(const int& ident_prod,const int& uni_tiene, const int& uni_quiere, const Cjt_productos& p, bool& leer);
/**  
    @brief Eliminamos todos los datos que tenemos del producto que acabamos de leer.
    @param ident_prod, peso, volumen
    \pre: Cierto.
    \post: -La funcion nos devuelve el peso y volumen total de la ciudad una vez cambiada, debido al posible cambio de las unidades que tiene la ciudad.
*/
    void quitar_prod(const int& ident_prod, Cjt_productos p);
    void comerciar_ajustes(const int& ident_prod, int intercambio, bool& poner, const Cjt_productos& p);
    void eliminar_inventario();
    int barco_puede_comprar(int id_producto, int max_compra) const;
    int barco_puede_vender(int id_producto, int max_venta) const;
    int barco_comprar(int id_producto, int max_compra_ciudad, Cjt_productos& p);
    int barco_vender(int id_producto, int max_venta_ciudad, Cjt_productos& p);
};
#endif