#ifndef SORT1_H_INCLUDED
#define SORT1_H_INCLUDED
#include "List1.h"
#include <iostream>
using namespace std;
template<typename T>
int Sort(List1<T> &t){
    int out=0;
    T elem;
    List1<int> t2;
    List1<int> t3;
    if(t.isEmpty())out=1;
    else{
        t.move_beg();
        unsigned Loc_len=t.get_size();
        for(unsigned i=0;i<Loc_len;i++){
            t.Extract(elem);
            if(elem<0){
                t2.Insert(elem);
            }
            else{
                t3.Insert(elem);
            }
        }
        unsigned size2 = t2.get_size();
        unsigned size3 = t3.get_size();
        t.make_empty();
        for(unsigned i=0;i<size3;i++){
            t3.Extract(elem);
            t.Insert(elem);
        }
        for(unsigned i=0;i<size2;i++){
            t2.Extract(elem);
            t.Insert(elem);

        }
        //cout<<"LOLOLOLOLOLO"<<endl;
    }
    return out;
}
#endif // SORT1_H_INCLUDED
