// yonetici listesini burada inşa edeceğiz
#include "../../other/Content.hpp"
#include "adressBuilder.cpp"
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
    stringstream longSpaces();
    // satırlar arası bosluku üreten metot.
    AdressBuilder *adr;

public:
    YoneticiListBuilder(YoneticiListesi *, int);
    ~YoneticiListBuilder();
    void draw(int);
};

YoneticiListBuilder::YoneticiListBuilder(YoneticiListesi *yoneticiListesi, int page)
{
    this->yoneticiListesi = yoneticiListesi;
    adr = new AdressBuilder(yoneticiListesi, page);
    draw(page);
}

stringstream YoneticiListBuilder::nodeAdressCurrent(int pageNum)
{
    // her sayfada yalnızca 8 adress yazdırma kodu.-sayfalar 0'dan baslar.
    stringstream yoneticiNodeAdresses;
    // YoneticiListesiNode *y = yoneticiListesi->head;
    // YoneticiListesiNode *itr = yoneticiListesi->head;
    /*for (int i = pageNum * 8; i < 8 + (pageNum * 8) && i < yoneticiListesi->Count() && itr->next != NULL; i++, itr = itr->next)
    {
        y = y->next;
        yoneticiNodeAdresses << "|" << yoneticiListesi << "|" << rowSpace;
    }*/
    /*
    adr->pageNum = 1;
    cout << adr->yonetici->head->next << "    " << endl;
    cout << *adr->yonetici->head->next->data << "    " << endl;
    cout << *adr << "    " << endl;
    adr->pageNum = 2;
    cout << *adr << "    ";
    adr->pageNum = 3;
    cout << *adr << "    ";
    adr->pageNum = 4;
    cout << *adr << "    ";*/

    adr->pageNum = pageNum;
    // cout << *adr->yonetici; // herbiri satır veriler.txt'deki satırlar.
    cout << adr->yonetici->head->next->data->elementAt(1); // satir listesi elemanını yazdırdı.
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
    cout << nodeAdressCurrent(1).str() << endl;

    // cout << longSpaces().str() << endl;
    // cout << nodeAdressCurrent(0).str() << endl;
    // cout << nodeAdressCurrent(1).str() << endl;
    // cout << nodeAdressCurrent(2).str() << endl;
    // cout << nodeAdressCurrent(3).str() << endl;
}

YoneticiListBuilder::~YoneticiListBuilder()
{
}

/*
Yonetici Liste yazdırma stili:



yonetici listesi node prev->next adresleri taransın
---------------------------------------------------
yonetici listesi node prev
---------------------------------------------------
yonetilistesi node içindeki satırListesi ortalama hespaları
---------------------------------------------------
yonetici listesi node next
---------------------------------------------------
*/