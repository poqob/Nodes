#include "../../other/Content.hpp"
#include "iostream"
#include "iomanip"
#include "sstream"
#include "../ostreams/ostream.cpp"
using namespace std;

class YoneticiListesiBuilder
{
private:
    YoneticiListesi *yoneticiListesi;
    string rowSpace = "    ";
    stringstream nodeAdressWriter(int); // yonetici listesi elemanlarının adreslerini üreten metot.1
    stringstream longSpaces();
    // satırlar arası bosluku üreten metot.
    AdressBuilder *adr;

public:
    YoneticiListesiBuilder(YoneticiListesi *, int);
    ~YoneticiListesiBuilder();
    void draw(int);
};

YoneticiListesiBuilder::YoneticiListesiBuilder(YoneticiListesi *yoneticiListesi, int page)
{
    this->yoneticiListesi = yoneticiListesi;
    adr = new AdressBuilder(yoneticiListesi, page);
    draw(1);
    // draw(2);
}

stringstream YoneticiListesiBuilder::nodeAdressWriter(int pageNum)
{
    // her sayfada yalnızca 8 adress yazdırma kodu.-sayfalar 0'dan baslar.
    stringstream yoneticiNodeAdresses;
    /* YoneticiListesiNode *y = yoneticiListesi->head;
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

    // adr->pageNum = pageNum;
    //  cout << *adr->yonetici; // herbiri satır veriler.txt'deki satırlar.
    // cout << adr->yonetici->head->next->data->elementAt(1); // satir listesi elemanını yazdırdı.*/

    return yoneticiNodeAdresses;
}

stringstream YoneticiListesiBuilder::longSpaces()
{
    stringstream collumnSpacing;
    collumnSpacing << setw(110);
    return collumnSpacing;
}

void YoneticiListesiBuilder::draw(int pageNum)
{

    stringstream ss;
    // ss << adr->yonetici->head;
    // cout << ss.str().substr(0, pageNum * 100) << endl;
    cout << adr->yonetici->head;
}

YoneticiListesiBuilder::~YoneticiListesiBuilder()
{
    delete adr;
    delete this;
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