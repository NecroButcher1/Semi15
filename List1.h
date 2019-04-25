#ifndef LIST1_H_INCLUDED
#define LIST1_H_INCLUDED
#include <iostream>
#include "BitContainer.h"
using namespace std;
enum err{ERR_MEM=1,EMPTY_OBJ=2,END=3};
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
    BitContainer<3> bit;
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
        if(bit.test(2))errcode=END;
        return errcode;
    }
    bool isEmpty(){
        bool t=false;
        if(head==NULL)t=true;
        return t;
    }
    bool inTheEnd(){
        bool t=false;
        if(ptr->next==NULL)t=true;
        return t;
    }
    void Push(T _data){
        PNode p = new Node;
        bit.Clear(0);
        if(p==NULL)bit.Set(0);
        else{
            p->data=_data;
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
    void pop(T &_data){
        bit.Clear(1);
        bit.Clear(2);
        if(isEmpty())bit.Set(1);
        else{
            if(inTheEnd())bit.Set(2);
            else{
                PNode p;
                p=ptr->next;
                ptr->next=p->next;
                _data=p->data;
            }
        }
    }
    void move_forward(){
        bit.Clear(1);
        bit.Clear(2);
        if(isEmpty())bit.Set(1);
        else{
                if(ptr->next)ptr=ptr->next;
                else bit.Set(2);
            }
        }
};

#endif // LIST1_H_INCLUDED
