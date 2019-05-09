#ifndef LIST1_H_INCLUDED
#define LIST1_H_INCLUDED
#include "BitContainer.h"
#include <iostream>
enum err{ERR_MEM=1,EMPTY_OBJ=2,END=3};
template<typename T>
class List1{
private:
    struct Node{
        T Data;
        Node* next;
    };
    typedef Node *PNode;
    BitContainer<3> bit;
    PNode Head,Ptr;
    unsigned errorcode;
    unsigned Size;
public:
    List1(){
        Head=NULL;
        Ptr=NULL;
        bit.Set(1);
        Size=0;
    }
    unsigned err_get(){
        if(bit.test(0))errorcode=ERR_MEM;
        if(bit.test(1))errorcode=EMPTY_OBJ;
        if(bit.test(2))errorcode=END;
        return errorcode;
    }
    void err_clear(){
        bit.Clear();
        errorcode=0;
    }
    bool isEmpty(){
        bool e=false;
        if(Head==NULL)e=true;
        return e;
    }
    void make_empty(){
        PNode p;
        while(Head!=NULL){
             p=Head;
             Head=p->next;
        }
        Ptr=NULL;
        Head=NULL;
        bit.Set(1);
    }
    bool isEnd(){
        bool e=false;
        if(Ptr==NULL){
            if(Head==NULL){
                e=true;
            }
            else e=false;
        }
        else{
            if(Ptr->next==NULL)e=true;
            else e=false;
        }
        return e;
    }
    void Extract(T &_Data){
        bit.Clear(1);
        bit.Clear(2);
        PNode p;
        if(isEmpty())bit.Set(1);
        else{
            if(isEnd()){
                bit.Set(1);
                p=Head;
            }
            else{
                p=Ptr->next;
                Ptr->next=p->next;
                Size--;
            }
            _Data=p->Data;
        }
        delete p;
    }
    void Insert(T _Data){
        PNode p = new Node;
        bit.Clear(0);
        bit.Clear(1);
        if(p==NULL)bit.Set(0);
        else{
            p->Data=_Data;
            p->next=NULL;
            Size++;
            if(Head==NULL){
                p->next=Head;
                Head=p;
                Ptr=p;
            }
            else{
                p->next=Ptr->next;
                Ptr->next=p;
            }
        }
    }
    unsigned get_size(){
        return Size;
    }
    void move_forward(){
        bit.Clear(1);
        bit.Clear(2);
        if(isEmpty())bit.Set(1);
        else{
            if(isEnd())bit.Set(2);
            else{
                Ptr=Ptr->next;
            }
        }
    }
    void move_beg(){
        bit.Clear(1);
        if(isEmpty())bit.Set(1);
        else{
            Ptr=Head;
        }
    }
     void get(T &_Data){
        bit.Clear(1);
        bit.Clear(2);
        if(isEmpty())bit.Set(1);
        else{
            PNode p;
            if(isEnd()){
                bit.Set(2);
                p=Head;
            }
            else{
                p=Ptr->next;
            }
            _Data=p->Data;
        }
    }
    void put(T _Data){
        bit.Clear(1);
        bit.Clear(2);
        if(isEmpty())bit.Set(1);
        else{
            PNode p;
            if(isEnd()){
                bit.Set(2);
                p=Head;
            }
            else{
                p=Ptr->next;
            }
            p->Data=_Data;
        }
    }
    void move_end(){
        bit.Clear(1);
        if(isEmpty())bit.Set(1);
        else{
            while(Ptr->next)Ptr=Ptr->next;
        }
    }
};

#endif // LIST1_H_INCLUDED
