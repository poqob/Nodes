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
    string createAdresses(int);
    string parseAdress();
    ~YLB();
    void draw(int);
};

YLB::YLB(YoneticiListesi *yoneticiListesi, int page)
{
    this->yoneticiListesi = yoneticiListesi;
    adr = new AdressBuilder(yoneticiListesi, page);
    // prints related page
    draw(1);
    draw(2);
    draw(3);
    draw(4);
}
string YLB::createAdresses(int row)
{
    stringstream result;
    string output;
    int i = 0;
    for (YoneticiListesiNode *itr = yoneticiListesi->head; itr != NULL; itr = itr->next)
    {
        result << itr->next << " ";
        i++;
        if (i % 8 == 0)
            result << endl;
    }
    result << endl;
    for (int j = 0; j < row; j++)
    {
        getline(result, output);
    }
    return output;
}

string YLB::parseAdress()
{
    string result = "";
    return result;
}

// BURADA KALDIK-AMAC: 0 ve 1 indexli sayfalar için yonetici listesi adreslerini sağlıklı bir şekilde ekrana bastırmak.
void YLB::draw(int pageNum)
{

    cout << createAdresses(pageNum) << endl;
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