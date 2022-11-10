#if !defined(ADRESSBUILDER)
#define ADRESSBUILDER

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

#endif // ADRESSBUILDER
