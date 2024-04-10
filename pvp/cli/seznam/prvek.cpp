#include "prvek.h"

Prvek *Prvek::getDalsi() const
{
    return dalsi;
}

void Prvek::setDalsi(Prvek *newDalsi)
{
    dalsi = newDalsi;
}

Prvek::Prvek()
{
    data = 0;
    dalsi = nullptr;
}

Prvek::Prvek(int Data)
{
    data = Data;
    dalsi = nullptr;
}

int Prvek::getData(){
    return data;
}

void Prvek::setData(int Data){
    data = Data;
}
