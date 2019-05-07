#pragma once
#ifndef BITCONTAINER_H_INCLUDED
#define BITCONTAINER_H_INCLUDED
template<unsigned N>
class BitContainer{
private:
    bool bits[N];

public:
    BitContainer(){
        Clear();
    }
    void Clear(){
        for(unsigned i=0;i<N;i++)bits[i]=0x00;
    }
    void Clear(unsigned i){
        bits[i] = 0x00;
    }
    void Set(){
        for(unsigned i=0;i<N;i++)bits[i]=0x01;
    }
    void Set(unsigned i){
        bits[i] = 0x01;
    }
    bool test(unsigned i){
        return bits[i];
    }
};

#endif // BITCONTAINER_H_INCLUDED
