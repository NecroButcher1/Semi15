#ifndef LIST1_H_INCLUDED
#define LIST1_H_INCLUDED
#include <iostream>
#include "BitContainer.h"
using namespace std;
enum err{ERR_MEM=1,EMPTY_OBJ=2};
template<typename T>
class List1{
private:
    struct Node{
        T data;
        Node *next;
    };
    typedef Node *PNode;
    PNode ptr,head;
    int errcode;
    BitContainer<2> bit;
public:
    List1(){
        bit.Set(1);
        errcode = 0;
        ptr=NULL;
        head=NULL;
    }
    void err_clear(){
        errcode=0;
        bit.Clear();
    }
    int get_err(){
        if(bit.test(0))errcode=ERR_MEM;
        if(bit.test(1))errcode=EMPTY_OBJ;
        return errcode;
    }
    void Push(T _data){
        PNode p = new Node;
        bit.Clear(0);
        if(p==NULL)bit.Set(0);
        else{
            if(head==NULL){
                p->next=head;
                head=p;
                ptr=head;
            }
            else{
                p->next=ptr->next;
                ptr->next=p;
            }
        }
    }
    void pop(T &data){

    }

};

#endif // LIST1_H_INCLUDED
