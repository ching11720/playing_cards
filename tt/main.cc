#include <iostream>
#include "class.h"
using namespace std;

int main(){
    Tclass<int> intArr(10);
    Tclass<float> floatArr(5);
    
    for (int i = 0; i < 6; i++){
        intArr.set(i, i);
    }
    
    for (int i = 0; i < 6; i++){
        cout<< intArr.get(i) <<" ";
    }
    cout<<endl;
    
    for (int i = 0; i < 6; i++){
        cout<< floatArr.get(i) <<" ";
    }
    cout<<endl;
    
    return 0;
}
