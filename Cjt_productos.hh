/** @file Cjt_productos.hh
 @brief Especificación de la clase Cjt_productos
*/

#ifndef CJT_PRODUCTOS_HH
#define CJT_PRODUCTOS_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#include <list>
#endif

using namespace std;

class Cjt_productos{
    private:
    /**
        @brief Mapa que relaciona el identificador de cada producto con su peso y volumen correspondiente.   
    */
    map<int, pair<int, int>> prod_peso_volumen;

    public:
    Cjt_productos();
    /**  
        @brief Inicializa el map de productos con sus correspondientes identificadores, y lo llenamos con sus pesos y volumenes correspondientes.
        \pre: Cierto.
        \post: -Registramos un map no vacío.
    */
    void inicializar_productos();
    /**  
        @brief Devuelve el número de productos direferentes que existen en la cuenca.
        \pre: Cierto.
        \post: -La función nos devuelve el numero de productos diferentes.
    */
    int num_total();
    /**  
        @brief Leeremos la instruccion y su peso y volumen respectivo.
        \pre: Cierto.
        \post: -Tendremos un nuevo producto, cuyo identificador será establecido por el ultimo producto del map, en nuestro conjunto de productos.
    */
    void nuevos_productos(int num_prod_nuevos);

    int peso(const int& ident_prod) const;

    int volumen(const int& ident_prod)const;

    /**  
    @brief Nos dice si el identificador del producto que hemos leido esta asociado a algun producto existente en la cuenca.
    @param ident_prod
    \pre: Cierto.
    \post: -La funcion nos devuelve si el producto existe.
*/
    bool existe_prod(const int& ident_prod) const;
};
#endif