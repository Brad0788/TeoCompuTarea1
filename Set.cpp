#include "Set.h"


void Set::create(list<int> _nums) {
    setTipo("Set");
    setNums(_nums);
};

void Set::print(){
    cout<<"El conjunto es: "<<getTipo()<<endl;
    cout<<"E incluye los numeros: {  ";
    for (int num : getNums())
    {
        cout<<num<<"  ";
    }
    cout<<"} "<<endl;
    
}

void Set::add(int num){
    list<int> l = getNums();
    l.push_back(num);
    setNums(l);
}

Secuencia Set::convert(){
    std::unordered_set<int> s;
    for(int i : getNums()){
        s.insert(i);
    }    
    list<int> news;
    news.assign(s.begin(), s.end());
    news.reverse();
    Secuencia seq;
    seq.create(news);
    return seq;
}


bool Set::equals(Set set){
    for(int num : set.getNums()){
        bool found = false;
        for(int num2 : getNums()){
            if (!found)
            {
                if (num==num2)
                {
                    found = true;
                }
            }  
        }
        if (!found)
        {
            return false;
        }
        
    }
    return true;
    
}

bool Set::equals(Secuencia seq){
    for(int num : seq.getNums()){
        bool found = false;
        for(int num2 : getNums()){
            if (!found)
            {
                if (num==num2)
                {
                    found = true;
                }
            }  
        }
        if (!found)
        {
            return false;
        }
        
    }
    return true;
    
}

list<int> Set::unionOp(Set set){
    list<int> uni = getNums();
    for(int num : set.getNums()){
        uni.push_back(num);
    }
    cout<<"La union es: {  ";
    for (int num : uni)
    {
        cout<<num<<"  ";
    }
    cout<<"} "<<endl;
    return uni;
}

list<int> Set::intersecOp(Set set){
    list<int> uni;
    for(int num : getNums()){
        bool found = false;
        for(int num2 : set.getNums()){
            if (!found)
            {
                if (num==num2)
                {
                    uni.push_back(num);
                    found = true;
                }
            }  
        }
    }
    for(int num : set.getNums()){
        bool found = false;
        for(int num2 : getNums()){
            if (!found)
            {
                if (num==num2)
                {
                    uni.push_back(num);
                    found = true;
                }
            } 
        }
    }
    cout<<"La interseccion es: {  ";
    for (int num : uni)
    {
        cout<<num<<"  ";
    }
    cout<<"} "<<endl;
    return uni;
}

list<int> Set::unionOp(Secuencia sec){
    list<int> uni = getNums();
    for(int num : sec.getNums()){
        uni.push_back(num);
    }
    cout<<"La union es: {  ";
    for (int num : uni)
    {
        cout<<num<<"  ";
    }
    cout<<"} "<<endl;
    return uni;
}

list<int> Set::intersecOp(Secuencia sec){
    
    list<int> uni;
    for(int num : getNums()){
        bool found = false;
        for(int num2 : sec.getNums()){
            if (!found)
            {
                if (num==num2)
                {
                    uni.push_back(num);
                    found = true;
                }
            }  
        }
    }
    for(int num : sec.getNums()){
        bool found = false;
        for(int num2 : getNums()){
            if (!found)
            {
                if (num==num2)
                {
                    uni.push_back(num);
                    found = true;
                }
            } 
        }
    }
    cout<<"La interseccion es: {  ";
    for (int num : uni)
    {
        cout<<num<<"  ";
    }
    cout<<"} "<<endl;
    return uni;
}