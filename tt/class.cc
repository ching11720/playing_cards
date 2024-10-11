#include "class.h"

using namespace std;

template <typename T>
Tclass<T>::Tclass(int s){
    size = s;
    array = new T[size];
}
template class Tclass<int>;
template class Tclass<float>;

template <typename T>
Tclass<T>::~Tclass(){
    delete[] array;
}

template <typename T>
T 
Tclass<T>::get(int i){
    return array[i];
}

template <typename T>
void 

Tclass<T>::set(int i, T v){
    array[i] = v;
}
