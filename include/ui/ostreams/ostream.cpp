#include "iostream"
#include "../ListBuilders/adressBuilder.hpp"
using namespace std;
ostream &operator<<(ostream &screen, AdressBuilder &rgt)
{
    int last = rgt.pageNum * 8;
    int itrNum = 0;
    int secItr = 0;
    YoneticiListesiNode *itr;
    /*for (YoneticiListesiNode *itr = rgt.yonetici->head; i < 8 + (rgt.pageNum * 8) && i < rgt.yonetici->Count() && itr != NULL; i++, itr = itr->next)
    {
        screen << itr->next << " <-> ";
    }*/
    // iterator

    /*for (YoneticiListesiNode *itr = rgt.yonetici->head; i < 8 + (rgt.pageNum * 8) && i < rgt.yonetici->Count() && itr != NULL; i++, itr = itr->next)
    {
        itr = itr->next;
    }
    int j = 0;
    // yazici
    for (YoneticiListesiNode *itr = rgt.yonetici->head; j < i && j < rgt.yonetici->Count() + i && itr != NULL; j++, itr = itr->next)
    {
        screen << itr->next << " <-> ";
    }
    screen << endl;*/

    for (itr = rgt.yonetici->head; itrNum < ((rgt.pageNum - 1) * 8) && itrNum < rgt.yonetici->Count() && itr != NULL; itrNum++, itr = itr->next)
    {
        itr = itr->next;
    }
    for (; secItr < 8 && secItr < rgt.yonetici->Count() && itr != NULL; secItr++, itr = itr->next)
    {
        screen << itr->next << " <-> ";
    }
    return screen;
}
/*
// node adress writer
ostream &operator<<(ostream &screen, YoneticiListesiNode *rgt)
{
    int j = 0;
    for (YoneticiListesiNode *itr = rgt; itr != NULL; itr = itr->next, j++)
    {
        if (j % 8 == 0)
            screen << endl;
        screen << itr->data << "    ";
    }
    screen << endl;
    return screen;
}*/
// todo::AGA BUNU KAC KERE CALISTIRACAGINI COZERSEN ODEV BITER-cozuyorum

ostream &operator<<(ostream &screen, YoneticiListesi &rgt)
{
    for (YoneticiListesiNode *itr = rgt.head; itr != NULL; itr = itr->next)
    {
        screen << itr->next << " <-> ";
    }
    screen << endl;
    return screen;
}

// cout << *adr->yonetici->head->next->data;//satir listesi içerik yazdırma
ostream &operator<<(ostream &screen, SatirListesi &rgt)
{
    for (SatirListesiNode *itr = rgt.head; itr != NULL; itr = itr->next)
    {
        screen << itr->data << " <-> ";
    }
    screen << endl;
    return screen;
}
