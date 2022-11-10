// yonetici listesini burada inşa edeceğiz
#include "../../other/Content.hpp"
#include "iostream"
#include "iomanip"
#include "sstream"
using namespace std;
class YoneticiListBuilder
{
private:
    YoneticiListesi *yoneticiListesi;
    string rowSpace = "    ";
    stringstream nodeAdressCurrent(int); // yonetici listesi elemanlarının adreslerini üreten metot.1
    stringstream longSpaces();           // satırlar arası bosluku üreten metot.

public:
    YoneticiListBuilder(YoneticiListesi *, int);
    ~YoneticiListBuilder();
    void draw(int);
};

YoneticiListBuilder::YoneticiListBuilder(YoneticiListesi *yoneticiListesi, int page)
{
    this->yoneticiListesi = yoneticiListesi;
    draw(page);
}

stringstream YoneticiListBuilder::nodeAdressCurrent(int pageNum)
{
    // her sayfada yalnızca 8 adress yazdırma kodu.-sayfalar 0'dan baslar.
    stringstream yoneticiNodeAdresses;
    YoneticiListesiNode *y = yoneticiListesi->head;
    YoneticiListesiNode *itr = yoneticiListesi->head;
    for (int i = pageNum * 8; i < 8 + (pageNum * 8) && i < yoneticiListesi->Count() && itr->next != NULL; i++, itr = itr->next)
    {
        y = y->next;
        yoneticiNodeAdresses << "|" << &y << "|" << rowSpace;
    }

    return yoneticiNodeAdresses;
}

stringstream YoneticiListBuilder::longSpaces()
{
    stringstream collumnSpacing;
    collumnSpacing << setw(110);
    return collumnSpacing;
}

void YoneticiListBuilder::draw(int pageNum)
{
    cout << nodeAdressCurrent(0).str() << endl;

    cout << longSpaces().str() << endl;
    cout << nodeAdressCurrent(2).str() << endl;
}

YoneticiListBuilder::~YoneticiListBuilder()
{
}
