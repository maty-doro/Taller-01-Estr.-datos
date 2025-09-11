#include <iostream>


template <typename T>
class NodoGral{
    public:
    T valor;
    NodoGral<T>* sgt;
    
    NodoGral(T valor){
        this->valor = valor;
        this->sgt = nullptr;
    }
    
    
};