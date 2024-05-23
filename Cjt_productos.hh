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

class Cjt_productos {
    private:
    /**
        @brief Mapa que relaciona el identificador de cada producto con su peso y volumen correspondiente.   
    */
        map<int, pair<int, int>> prod_peso_volumen;

    public:
    //CONSTRUCTORAS
    /**
        @brief Creador por defecto.
        \pre <em>Cierto</em>.
        \post El conjunto de productos.   
    */
        Cjt_productos();
    /**  
        @brief Inicializa el map de productos con sus correspondientes identificadores, y lo llenamos con sus pesos y volúmenes correspondientes.
        \pre <em>Cierto</em>.
        \post Registramos un map no vacío.
    */
        void inicializar_productos();

    //CONSULTORAS
    /**  
        @brief Devuelve el número de productos diferentes que existen en la cuenca.
        \pre <em>Cierto</em>.
        \post La función nos devuelve el número de productos diferentes.
    */
        int num_total();
    /**  
        @brief Consultamos el peso de un producto.
        @param ident_prod
        \pre Todos los parámetros están inicializados.
        \post Devuelve el peso del producto.
    */
        int peso(const int& ident_prod) const;
    /**  
        @brief Consultamos el volumen de un producto.
        @param ident_prod
        \pre Todos los parámetros están inicializados.
        \post Devuelve el volumen del producto.
    */
        int volumen(const int& ident_prod) const;
    /**  
        @brief Nos dice si el identificador del producto que hemos leído está asociado a algún producto existente en la cuenca.
        @param ident_prod
        \pre Todos los parámetros están inicializados.
        \post La función nos devuelve si el producto existe.
    */
        bool existe_prod(const int& ident_prod) const;

    //MODIFICADORAS
    /**  
        @brief Leeremos la instrucción, y añadirá el/los producto/s con su/s peso/s y volumen/es correspondiente/s.
        @param num_prod_nuevos
        \pre Todos los parámetros están inicializados.
        \post Tendremos un/os nuevo/s producto/s en nuestro conjunto de productos, cuyo/s identificador/es será/n establecido/s por el último producto del map.
    */
        void nuevos_productos(int num_prod_nuevos);
};
#endif
