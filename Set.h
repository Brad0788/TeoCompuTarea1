#pragma once
#include <iostream>
#include "ClaseAbs.h"
#include "Secuencia.h"
using namespace std;

class Secuencia;

class Set : public ClaseAbs{
    public:
        void create(list<int>);
        void print();
        void add(int);
        Secuencia convert();
        bool equals(Set);
        bool equals(Secuencia);
        list<int> unionOp(Set);
        list<int> intersecOp(Set);
        list<int> unionOp(Secuencia);
        list<int> intersecOp(Secuencia);
};