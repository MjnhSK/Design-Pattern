#include <iostream>

using namespace std;


template <class Type1, class Type2> //template preamble
Type2 ChooseFirst(Type1 x, Type2 y){
    if(x<y) return (Type2) x;
    else return y;
}

int main(){
    int value1 = 4, value2 = 7;
    float value3 = 5.67f;
    cout << "First: " <<ChooseFirst(value1, value3) << endl;
    cout << "First: " <<ChooseFirst(value2, value1) << endl;
}