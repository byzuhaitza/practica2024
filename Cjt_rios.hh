/** @file Cjt_rios.hh
 @brief Especificación de la clase Cjt_rios
*/

#ifndef CJT_RIOS_HH
#define CJT_RIOS_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#include <set>
#include "BinTree.hh"
#endif

#include "Ciudad.hh"
#include "Barco.hh"
#include "Cjt_productos.hh"

using namespace std;

/**
 @class Cjt_rios.
 @brief El conjunto de rios que forma la cuenca fluvial.

 Está definido por un árbol que contiene todas las ciudades, un mapa donde se relaciona cada identificador de ciudad con su correspondiente información y el número de productos diferentes, junto con sus caracteristicas.
*/

class Cjt_rios{
    private:
    /**
        @brief Árbol que contiene todas las ciudades.   
    */
    BinTree<string> arbol;
    /**
        @brief Mapa que relaciona el identificador de cada ciudad con su informacion correspondiente.   
    */
    map<string, Ciudad> ciudades;
    

    public:
    //CONSTRUCTORAS
/**
    @brief Creador por defecto.
    \pre: Cierto.
    \post: El conjunto de rios.   
*/
    Cjt_rios();
/**  
    @brief Inicializa el árbol, es decir, crea el conjunto de rios.
    \pre: Cierto.
    \post: -Si el árbol está vacio, se devuelve un -1.
          -Registramos un árbol no vacío.
*/
    void inicializar_cuenca();
/**  
    @brief Inicializa el árbol, es decir, crea el conjunto de rios.
    \pre: Cierto.
    \post: -Si el árbol está vacio, se devuelve un -1.
          -Registramos un árbol no vacío.
*/
    void ini_cuenca(BinTree<string>& a);

    //CONSULTORAS

/**  
    @brief Nos dice si el identificador de ciudad que hemos leido esta asociado a alguna ciudad de la cuenca.
    @param ident_ciudad
    \pre: Cierto.
    \post: -La funcion nos devuelve si la ciudad existe.
*/
    bool existe_ciudad(const string& ident_ciudad) const; 
/**  
    @brief Imprime el inventario de una ciudad.
    @param ident_ciudad
    \pre: Cierto.
    \post: -La funcion nos escribe todos los productos que hay en la dicha ciudad, junto con la cantidad que tienen y necesitan de dicho producto.
*/
    void leer_inventario(const string& ident_ciudad, Cjt_productos& Cjt_productos);
/**  
    @brief Imprime los inventarios de las ciudades del rio.
    \pre: Cierto.
    \post: ?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
*/
    void leer_inventarios(Cjt_productos& Cjt_productos) ;
/**  
    @brief Imprime el inventario de la ciudad junto con el peso y el volumen de todos los productos almacenados.
    @param ident_ciudad
    \pre: Cierto.
    \post: -La funcion nos devuelve todos los productos de la ciudad. Tambien el peso y el volumen total.
*/
    void escribir_ciudad(const string& ident_ciudad);
/**  
    @brief Indica si el producto que acabamos de leer esta en la ciudad indicada.
    @param ident_ciudad, ident_prod
    \pre: Cierto.
    \post: -La función devuelve si existe dicho producto en la ciudad.
*/
    bool existe_prod_ciudad(const string& ident_ciudad, const int& ident_prod) const;
/**  
    @brief Busca en la ciudad un determinado producto y miramos la informacion que tenemos sobre el.
    @param ident_ciudad, ident_prod
    \pre: Cierto.
    \post: -La funcion devuelve cuantas unidades tiene y necesita la ciudad.
*/
    void consultar(const string& ident_ciudad, const int& ident_prod) const;
    bool inv_ciu_vacio(const string& ident_ciudad) const;

    //MODIFICADORA


/**  
    @brief Busca una ciudad y cambia las unidades que tiene y que quiere del producto requerido.
    @param ident_ciudad, ident_prod, uni_tiene, uni_quiere
    \pre: Cierto.
    \post: -La funcion nos devuelve el peso y volumen total de la ciudad una vez cambiada, debido al posible cambio de las unidades que tiene la ciudad.
*/
    void modificar_prod(const string& ident_ciudad, const int& ident_prod, int& uni_tiene, int& uni_quiere, Cjt_productos& Cjt_productos);
/**  
    @brief Vamos a la ciudad establecida y añadimos el producto que leemos, junto con las unidades que tendra esta ciudad y las que necesita.
    @param ident_ciudad, ident_prod, uni_tiene, uni_quiere
    \pre: Cierto.
    \post: -La funcion nos devuelve el peso y volumen total de la ciudad una vez cambiada, debido al posible cambio de las unidades que tiene la ciudad.
*/
    void poner_prod(const string& ident_ciudad, const int& ident_prod, const int& uni_tiene, const int& uni_quiere, Cjt_productos& Cjt_productos) ;
/**  
    @brief Vamos a la ciudad establecida y eliminamos todos los datos que tenemos del producto que acabamos de leer.
    @param ident_ciudad, ident_prod
    \pre: Cierto.
    \post: -La funcion nos devuelve el peso y volumen total de la ciudad una vez cambiada, debido al posible cambio de las unidades que tiene la ciudad.
*/
    void quitar_prod(const string& ident_ciudad, const int& ident_prod, Cjt_productos& Cjt_productos) ;
/**  
    @brief 
    @param ident_ciudad_1, ident_ciudad_2
    \pre: Cierto.
    \post: 
*/
    int comerciar(const string& ident_ciudad_1, const string& ident_ciudad_2);
/**  
    @brief 
    \pre: Cierto.
    \post: 
*/
    void redistribuir();

    void hacer_viaje(Barco& b);
};
#endif