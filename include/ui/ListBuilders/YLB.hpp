#include "../../other/Content.hpp"
#include "iostream"
#include "iomanip"
#include "sstream"
#include "../ostreams/ostream.cpp"
using namespace std;

class YLB
{
private:
    YoneticiListesi *yoneticiListesi;
    AdressBuilder *adr;

public:
    YLB(YoneticiListesi *, int);
    ~YLB();
    void draw(int);
};

YLB::YLB(YoneticiListesi *yoneticiListesi, int page)
{
    this->yoneticiListesi = yoneticiListesi;
    adr = new AdressBuilder(yoneticiListesi, page);
    draw(0);
    draw(1);
    draw(2);
    draw(3);
}

// BURADA KALDIK-AMAC: 0 ve 1 indexli sayfalar için yonetici listesi adreslerini sağlıklı bir şekilde ekrana bastırmak.
void YLB::draw(int pageNum)
{
    int last = pageNum * 8;
    int itrNum = 0;
    int secItr = 0;

    int suSayi = 0;
    yoneticiListesi->Count() % 8 == 0 ? suSayi = ((pageNum - 1) * 8) : suSayi = yoneticiListesi->Count() % 8;

    YoneticiListesiNode *itr;
    stringstream output;
    for (itr = yoneticiListesi->head; itrNum <= suSayi && itr != NULL; itrNum++, itr = itr->next)
    {
        itr = itr->next;
    }

    for (; secItr < 8 && itrNum < yoneticiListesi->Count() && itr != NULL; secItr++, itr = itr->next)
    {
        output << itr->next << "    ";
    }
    cout << output.str() << endl;
}

YLB::~YLB()
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

// ADRESS BELEKTE SILINDI MI TAKIP EDILSIN