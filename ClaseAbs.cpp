#include "ClaseAbs.h"

ClaseAbs::ClaseAbs() : tipo{""}, nums{0}{}

ClaseAbs::ClaseAbs(string _tipo, list<int> _nums) : tipo{_tipo}, nums{_nums}{}

ClaseAbs::ClaseAbs(const ClaseAbs& conj){
    tipo = conj.tipo;
    nums = conj.nums;
}

void ClaseAbs::create(list<int> _nums){
    nums = _nums;
}

void ClaseAbs::setTipo(string _tipo){
    tipo = _tipo;
}
void ClaseAbs::setNums(list<int> _nums){
    nums = _nums;
}

string ClaseAbs::getTipo(){
    return tipo;
}

list<int> ClaseAbs::getNums(){
    return nums;
}