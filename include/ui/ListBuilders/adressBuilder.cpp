#include <iostream>
#include "../../list/YoneticiListesi.hpp"
#include "../../list/YoneticiListesiNode.hpp"
using namespace std;

class AdressBuilder
{
public:
    YoneticiListesi *yonetici;
    int pageNum;
    YoneticiListesiNode nodes(AdressBuilder &);
    AdressBuilder(YoneticiListesi *, int);
    ~AdressBuilder();
};

AdressBuilder::AdressBuilder(YoneticiListesi *yonetici, int pageNum)
{
    this->yonetici = yonetici;
    this->pageNum = pageNum;
}

AdressBuilder::~AdressBuilder()
{
}

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

YoneticiListesiNode AdressBuilder::nodes(AdressBuilder &rgt)
{
    YoneticiListesiNode *currentNode;
    int i = rgt.pageNum * 8;
    for (YoneticiListesiNode *itr = rgt.yonetici->head; i < 8 + (rgt.pageNum * 8) && i < rgt.yonetici->Count() && itr != NULL; i++, itr = itr->next)
    {
        itr = itr->next;
    }
    int j = 0;
    // yazici
    for (YoneticiListesiNode *itr = rgt.yonetici->head; j < i && j < rgt.yonetici->Count() + i && itr != NULL; j++, itr = itr->next)
    {
        currentNode = itr->next->prev;
    }
    return *currentNode;
}