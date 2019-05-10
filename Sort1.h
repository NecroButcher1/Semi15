#ifndef SORT1_H_INCLUDED
#define SORT1_H_INCLUDED
#include "List1.h"
#include <iostream>
using namespace std;
template<typename T>
int Sort(List1<T> &t){
    int out=0;
    T elem;
    List1<T> t2;
    List1<T> t3;
    if(t.isEmpty())out=1;
    else{
        t.move_beg();
        t.err_clear();
        //unsigned Loc_len=t.get_size();
        while(t.err_get()!=EMPTY_OBJ){
            t.Extract(elem);
            if(elem<0){
                t2.Insert(elem);
            }
            else{
                t3.Insert(elem);
            }
        }
        //unsigned size2 = t2.get_size();
        //unsigned size3 = t3.get_size();
        t.make_empty();
        while(t3.err_get()!=EMPTY_OBJ){
            t3.Extract(elem);
            t.Insert(elem);
        }
        while(t2.err_get()!=EMPTY_OBJ){
            t2.Extract(elem);
            t.Insert(elem);
        }
        t2.make_empty();
        t3.make_empty();
        t.err_clear();
        //cout<<"LOLOLOLOLOLO"<<endl;
    }
    return out;
}
#endif // SORT1_H_INCLUDED
