#pragma once
#include <iostream>
#include "ClaseAbs.h"
#include "Set.h"

using namespace std;

class Set;

class Secuencia : public ClaseAbs{
    public:
        void create(list<int>);
        void print();
        void add(int);
        Set convert();
        bool equals(Set);
        bool equals(Secuencia);
        list<int> unionOp(Secuencia);
        list<int> intersecOp(Secuencia);
        list<int> unionOp(Set);
        list<int> intersecOp(Set);
};