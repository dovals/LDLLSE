#ifndef LDL_H_INCLUDED
#define LDL_H_INCLUDED

#include <iostream>
#include <iostream>

template<class T>
class LDLLSE;

template<class T>
class nodo{
public:
    T data;
    nodo<T>* sig;
    nodo<T>* ant;

    nodo():sig(nullptr), ant(nullptr){};
    friend class LDLLSE<T>;
};

template<class T>
class LDLLSE{
public:
    nodo<T>* ancla;
    LDLLSE(): ancla(nullptr){};
    bool vacia()const;
    nodo<T>* primero()const;
    nodo<T>* ultimo()const;
    nodo<T>* anterior(nodo<T>*)const;
    nodo<T>* siguiente(nodo<T>* )const;
    nodo<T>* localiza(T)const;
    T recupera(nodo<T>* )const;
    void imprime()const;
    void anula();
    void inserta(nodo<T>* pos, T elem);
    void elimina(nodo<T>* pos);
};

template<class T>
void LDLLSE<T>::inserta(nodo<T>* pos, T elem){
    nodo<T>* nuevo = new nodo<T>;
    nuevo->data = elem;

    if(pos == nullptr){ // insertar al principio
        nuevo->ant = nullptr;
        nuevo->sig = ancla;
        if(ancla != nullptr){
            ancla->ant = nuevo;
        }
        ancla = nuevo;
    }
    else{ // insertar después de pos
        nuevo->sig = pos->sig;
        nuevo->ant = pos;
        if(pos->sig != nullptr){
            pos->sig->ant = nuevo;
        }
        pos->sig = nuevo;
    }
}

template<class T>
void LDLLSE<T>::elimina(nodo<T>* pos){
    if(pos != nullptr){
        if(pos->ant != nullptr){
            pos->ant->sig = pos->sig;
        }
        else{
            ancla = pos->sig;
        }
        if(pos->sig != nullptr){
            pos->sig->ant = pos->ant;
        }
        delete pos;
    }

}

template<class T>
nodo<T>* LDLLSE<T>::primero()const{
    return ancla;
}

template<class T>
nodo<T>* LDLLSE<T>::ultimo()const{
    if(vacia()){
        return ancla;
    }
    else{
        nodo<T>* aux=ancla;
        while(aux->sig!=nullptr){
            aux=aux->sig;
        }
        return aux;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::anterior(nodo<T>* pos)const{
    if(vacia()|| pos==nullptr){
        return nullptr;
    }
    else{
        return pos->ant;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::siguiente(nodo<T>* pos)const{
    if(vacia()|| pos==nullptr){
        return nullptr;
    }
    else{
        return pos->sig;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::localiza(T elem)const{
    nodo<T>* aux=ancla;
    while(aux!=nullptr && aux->data!=elem){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
T LDLLSE<T>::recupera(nodo<T>* pos)const{
    if(vacia()|| pos==nullptr){

    }
    else{
        return pos->data;
    }
}


template<class T>
bool LDLLSE<T>::vacia()const{
    if(ancla==nullptr){
        return true;
    }
    return false;
}

template<class T>
void LDLLSE<T>::imprime()const{
    if(!vacia()){
        nodo<T>* aux=ancla;
        while(aux!=nullptr){
            std::cout<<aux->data<<std::endl;
            aux=aux->sig;
        }
    }
}

template<class T>
void LDLLSE<T>::anula(){
    nodo<T>* aux;
    while(ancla!=nullptr){
        aux=ancla;
        ancla=aux->sig;
        delete aux;
    }
}
#endif // LDL_H_INCLUDED
