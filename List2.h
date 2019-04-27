#ifndef LIST2_H_INCLUDED
#define LIST2_H_INCLUDED
#include "BitContainer.h"
template<typename T>
class List2{
private:
    struct Node{
        T Data;
        Node *next,*prev;
    };
    typedef Node *PNode;
    BitContainer<3> bit;
    PNode head,tail,ptr;
    int errcode;
public:
    List2(){
        head=NULL;
        ptr=NULL;
        tail=NULL;
        errcode=0;
        bit.Set(1);
    }
    void err_clear(){
        errcode=0;
        bit.Clear();
    }
    int get_err(){
        if(bit.test(0))errcode=ERR_MEM;
        if(bit.test(1))errcode=EMPTY_OBJ;
        if(bit.test(2))errcode=END;
        return errcode;
    }

};

#endif // LIST2_H_INCLUDED
