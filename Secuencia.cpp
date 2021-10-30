#include "Secuencia.h"

void Secuencia::create(list<int> _nums) {
    std::unordered_set<int> s;
    for(int i : _nums){
        s.insert(i);
    }    
    list<int> news;
    news.assign(s.begin(), s.end());
    news.reverse();
    setTipo("Secuencia");
    setNums(news);
};

void Secuencia::print(){
    cout<<"El conjunto es: "<<getTipo()<<endl;
    cout<<"E incluye los numeros: ( ";
    for (int num : getNums())
    {
        cout<<num<<"  ";
    }
    cout<<") "<<endl;
    
}

void Secuencia::add(int num){
    unordered_set<int> s;
    for(int i : getNums()){
        s.insert(i);
    }
    s.insert(num);
    list<int> news;
    news.assign(s.begin(), s.end());
    news.reverse();
    setNums(news);
}

Set Secuencia::convert(){
    Set seq;
    seq.create(getNums());
    return seq;
}

bool Secuencia::equals(Secuencia set){
    int arr[set.getNums().size()];
    int arr2[getNums().size()];
    int k = 0;
    for (int nn : set.getNums())
    {
        arr[k++] = nn;
    }
    k = 0;
    for (int nn : getNums())
    {
        arr2[k++] = nn;
    }
    
    if (getNums().size() == set.getNums().size())
    {
        bool orden = true;
        for (int i = 0; i < getNums().size(); i++)
        {
            if (arr[i]!=arr2[i])
            {
                orden = false;
                return false;
            }
        }
        if (orden)
        {
            return true;
        } 
    }
    return false;
}

bool Secuencia::equals(Set seq){
    list<int> con = seq.getNums();
    con.sort();
    con.unique();
    if (con.size() == getNums().size())
    {
        if(equal(con.begin(),con.end(), getNums().begin())){
            return true;
        }
    }
    return false;
    
}

list<int> Secuencia::unionOp(Set set){
    list<int> uni = getNums();
    std::unordered_set<int> s;
    for(int i : set.getNums()){
        s.insert(i);
    }    
    list<int> news;
    news.assign(s.begin(), s.end());
    news.reverse();
    for(int num : news){
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
            uni.push_back(num);
        }   
    }
    cout<<"La union es: (  ";
    for (int num : uni)
    {
        cout<<num<<"  ";
    }
    cout<<") "<<endl;
    return uni;
}

list<int> Secuencia::intersecOp(Set set){
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
    cout<<"La interseccion es: (  ";
    for (int num : uni)
    {
        cout<<num<<"  ";
    }
    cout<<") "<<endl;
    return uni;
}

list<int> Secuencia::unionOp(Secuencia sec){
    list<int> uni = getNums();
    for(int num : sec.getNums()){
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
            uni.push_back(num);
        }    
    }
    cout<<"La union es: (  ";
    for (int num : uni)
    {
        cout<<num<<"  ";
    }
    cout<<") "<<endl;
    return uni;
}

list<int> Secuencia::intersecOp(Secuencia sec){
    
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
    cout<<"La interseccion es: (  ";
    for (int num : uni)
    {
        cout<<num<<"  ";
    }
    cout<<") "<<endl;
    return uni;
}