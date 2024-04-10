#ifndef PRVEK_H
#define PRVEK_H
class Prvek
{
private:
    int data;
    Prvek *dalsi;
public:
    Prvek();
    Prvek(int Data);
    int getData();
    void setData(int Data);
    Prvek *getDalsi() const;
    void setDalsi(Prvek *newDalsi);
};
#endif
