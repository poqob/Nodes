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
    string bosluk = "    ";
    stringstream nodeAdress(int);

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

stringstream YoneticiListBuilder::nodeAdress(int pageNum)
{
    stringstream yoneticiNodeAdresses;
    for (int i = pageNum * 8; i < 8 + (pageNum * 8) && i < yoneticiListesi->Count(); i++)
    {
        if (i % 8 == 0)
            yoneticiNodeAdresses << endl;
        yoneticiNodeAdresses << yoneticiListesi->elementAt(i).data << bosluk;
    }
    return yoneticiNodeAdresses;
}

void YoneticiListBuilder::draw(int pageNum)
{
    cout << nodeAdress(pageNum).str();
}

YoneticiListBuilder::~YoneticiListBuilder()
{
}
