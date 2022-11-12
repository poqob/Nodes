#include "iostream"
using namespace std;

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
/*
ostream &operator<<(ostream &screen, YoneticiListesi &rgt)
{
    for (YoneticiListesiNode *itr = rgt.head; itr != NULL; itr = itr->next)
    {
        screen << itr->next << " <-> ";
    }
    screen << endl;
    return screen;
}
*/

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
