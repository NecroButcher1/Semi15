#ifndef SORT1_H_INCLUDED
#define SORT1_H_INCLUDED
#include "List1.h"
#include <iostream>
using namespace std;
template<typename T>
int Sort(List1<T> &t){
    int out=0;
    T elem;
    if(t.isEmpty())out=1;
    else{
        t.move_beg();
        unsigned Loc_len=t.get_size();
        for(unsigned i=0;i<Loc_len;i++){
            t.get(elem);
            t.move_forward();
            if(elem<0){
                t.Extract(elem);
                t.move_beg();
                t.Insert(elem);
                for(unsigned j=0;j<i;j++){
                    t.move_forward();
                }
            }
            else{
                t.Extract(elem);
                t.move_end();
                t.Insert(elem);
                t.move_beg();
                for(unsigned j=0;j<i;j++){
                    t.move_forward();
                }
            }
            cout<<elem;
        }
    }
    return out;
}
#endif // SORT1_H_INCLUDED
