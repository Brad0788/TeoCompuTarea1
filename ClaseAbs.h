#include <iostream>
#include <list>
#include <unordered_set>
#include <string>
using namespace std;

#ifndef CLASEABS_H
#define CLASEABS_H

class ClaseAbs{
    public:
        ClaseAbs();
        ClaseAbs(string tipo, list<int>);
        ClaseAbs(const ClaseAbs&);
        void create(list<int>);
        void setTipo(string);
        void setNums(list<int>);
        string getTipo();
        list<int> getNums();
    
    private:
        string tipo;
        list<int> nums;
};

#endif