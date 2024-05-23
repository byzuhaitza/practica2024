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
 @brief El conjunto de ríos que forma la cuenca fluvial.

 Está definido por un árbol que contiene todas las ciudades, un mapa donde se relaciona cada identificador de ciudad con su correspondiente información y el número de productos diferentes, junto con sus características.
*/

class Cjt_rios {
    private:
    /**
        @brief Árbol que contiene todas las ciudades.   
    */
    BinTree<string> arbol;
    /**
        @brief Mapa que relaciona el identificador de cada ciudad con su información correspondiente.   
    */
    map<string, Ciudad> ciudades;

    /**  
        @brief Recorre todo el árbol, comerciando con las ciudades adyacentes, de derecha a izquierda.
        @param arbol, Cjt_productos
        \pre Todos los parámetros están inicializados y son ciertos.
        \post Llamada tras llamada actualiza la información de las ciudades que hayan estado involucradas en la acción de comerciar.
    */
    void redistribuir_rec(const BinTree<string>& a, const Cjt_productos& Cjt_productos);

    /**  
        @brief Recorre todas las ciudades de la cuenca, calculando el mejor camino para que el barco comercie el máximo posible.
        @param mejor_ruta, Barco, ya_comprado, ya_vendido, arbol
        \pre Todos los parámetros están inicializados y son ciertos.
        \post Llamada tras llamada pasa por todas las hojas de la cuenca y devuelve la mejor ruta.
    */
    int calcular_ruta_rec(vector<string>& mejor_ruta, Barco& b, int ya_comprado, int ya_vendido, const BinTree<string>& a);

    /**  
        @brief Crea el árbol, el cual representa el conjunto de ciudades.
        @param arbol
        \pre Todos los parámetros están inicializados y son ciertos.
        \post Llamada tras llamada registra la estructura de la cuenca.
    */
    void ini_cuenca(BinTree<string>& a);

    public:
    // CONSTRUCTORAS
    /**
        @brief Creador por defecto.
        \pre <em>Cierto</em>.
        \post El conjunto de ríos.   
    */
        Cjt_rios();

    /**  
        @brief Inicializa el árbol, es decir, crea el conjunto de ríos.
        \pre <em>Cierto</em>.
        \post Registramos un árbol no vacío, que será la estructura de la cuenca.
    */
        void inicializar_cuenca();

    // CONSULTORAS
    /**  
        @brief Dice si el identificador de ciudad que hemos leído está asociado a alguna ciudad de la cuenca.
        @param ident_ciudad
        \pre Todos los parámetros están inicializados.
        \post Devuelve si la ciudad existe o no.
    */
        bool existe_ciudad(const string& ident_ciudad) const; 

    /**  
        @brief Imprime el inventario de una ciudad.
        @warning Salta un error en caso de que la ciudad no exista.
        @param ident_ciudad, Cjt_productos
        \pre Todos los parámetros están inicializados.
        \post La función nos escribe todos los productos que hay en dicha ciudad, junto con la cantidad que tienen y necesitan de cada uno de sus productos.
    */
        int leer_inventario(const string& ident_ciudad, const Cjt_productos& Cjt_productos);

    /**  
        @brief Imprime los inventarios de las ciudades del río.
        @warning Salta un error en caso de que alguna de las ciudades no exista.
        @param Cjt_productos
        \pre Todos los parámetros están inicializados.
        \post La función nos escribe todos los productos que hay en dichas ciudades, junto con la cantidad que tienen y necesitan de cada uno de sus productos.
    */
        void leer_inventarios(const Cjt_productos& Cjt_productos);

    /**  
        @brief Imprime el inventario de la ciudad junto con el peso y el volumen de todos los productos almacenados.
        @warning Salta un error en caso de que la ciudad no exista.
        @param ident_ciudad
        \pre Todos los parámetros están inicializados.
        \post Devuelve todos los productos de la ciudad. También el peso y el volumen total.
    */
        int escribir_ciudad(const string& ident_ciudad);

    /**  
        @brief Indica si el producto que ha leído está en la ciudad indicada.
        @param ident_ciudad, ident_prod
        \pre Todos los parámetros están inicializados.
        \post Devuelve si existe dicho producto en la ciudad.
    */
        bool existe_prod_ciudad(const string& ident_ciudad, const int& ident_prod) const;

    /**  
        @brief Busca en la ciudad un determinado producto y mira la información que tenemos sobre él.
        @warning Salta un error en caso de que el producto no exista, la ciudad no exista o el producto no exista en dicha ciudad.
        @param ident_ciudad, ident_prod, Cjt_productos
        \pre Todos los parámetros están inicializados.
        \post Devuelve cuántas unidades tiene y necesita la ciudad de este producto.
    */
        int consultar(const string& ident_ciudad, const int& ident_prod, const Cjt_productos& Cjt_productos) const;

    /**  
        @brief Busca en la ciudad un determinado producto y mira la información que tenemos sobre él.
        @param ident_ciudad
        \pre Todos los parámetros están inicializados.
        \post Devuelve cuántas unidades tiene y necesita la ciudad.
    */
        bool inv_ciu_vacio(const string& ident_ciudad) const;

    // MODIFICADORAS
    /**  
        @brief Busca una ciudad y cambia las unidades que tiene y que quiere del producto requerido.
        @warning Salta un error en caso de que el producto no exista, la ciudad no exista o el producto no exista en dicha ciudad.
        @param ident_ciudad, ident_prod, uni_tiene, uni_quiere, Cjt_productos
        \pre Todos los parámetros están inicializados.
        \post Devuelve el peso y volumen total de la ciudad una vez cambiada, debido al posible cambio de las unidades que tiene la ciudad.
    */
        int modificar_prod(const string& ident_ciudad, const int& ident_prod, int& uni_tiene, int& uni_quiere, const Cjt_productos& Cjt_productos);

    /**  
        @brief Va a la ciudad indicada y añade el producto que lee, junto con las unidades que tendrá esta ciudad y las que necesita.
        @warning Salta un error en caso de que el producto no exista, la ciudad no exista o en caso de que el producto ya exista en dicha ciudad.
        @param ident_ciudad, ident_prod, uni_tiene, uni_quiere, Cjt_productos
        \pre Todos los parámetros están inicializados.
        \post Devuelve el peso y volumen total de la ciudad una vez cambiada, debido al posible cambio de las unidades que tiene la ciudad.
    */
        int poner_prod(const string& ident_ciudad, const int& ident_prod, const int& uni_tiene, const int& uni_quiere, const Cjt_productos& Cjt_productos);

    /**  
        @brief Va a la ciudad indicada y elimina todos los datos que tiene del producto que acaba de leer.
        @warning Salta un error en caso de que el producto no exista, la ciudad no exista o el producto no exista en dicha ciudad.
        @param ident_ciudad, ident_prod, Cjt_productos
        \pre Todos los parámetros están inicializados.
        \post Devuelve el peso y volumen total de la ciudad una vez cambiada, debido al posible cambio de las unidades que tiene la ciudad.
    */
        int quitar_prod(const string& ident_ciudad, const int& ident_prod, const Cjt_productos& Cjt_productos);

    /**  
        @brief Intercambia productos entre las dos ciudades que recibe.
        @warning Salta un error en caso de que los identificadores sean iguales o en caso de que alguna de las dos ciudades no exista.
        @param ident_ciudad_1, ident_ciudad_2, Cjt_productos
        \pre Todos los parámetros están inicializados.
        \post En caso de poder comerciar algo entre las ciudades, la información de cada una de ellas es actualizada, en caso contrario, seguirán con la misma información.
    */
        int comerciar(const string& ident_ciudad_1, const string& ident_ciudad_2, const Cjt_productos& Cjt_productos);

    /**  
        @brief Intercambia productos entre las ciudades de la cuenca, siempre y cuando no tengan un inventario vacío.
        @param Cjt_productos
        \pre Todos los parámetros están inicializados.
        \post En caso de poder comerciar algo entre las ciudades, la información de cada una de ellas es actualizada, en caso contrario, seguirán con la misma información.
    */
        void redistribuir(const Cjt_productos& Cjt_productos);

    /**  
        @brief El barco viaja a través del río, calculando la ruta por donde puede intercambiar el máximo de productos.
        @param Barco, Cjt_productos
        \pre Todos los parámetros están inicializados.
        \post Devuelve la suma del total de productos comprados y vendidos por el barco.
    */
        int hacer_viaje(Barco& b, const Cjt_productos& Cjt_productos);

    /**  
        @brief Viaja a través de la ruta calculada.
        @param mejor_ruta, Barco, Cjt_productos
        \pre Todos los parámetros están inicializados.
        \post Devuelve la última ciudad visitada y actualiza la información de las ciudades que hayan hecho algún tipo de intercambio con el barco.
    */
        string viajar_ruta(vector<string>& mejor_ruta, Barco& b, Cjt_productos Cjt_productos);
};
#endif
