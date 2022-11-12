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

public:
    YLB(YoneticiListesi *, int);
    string createAdresses(int);
    string createUnderline(string);
    string createPrevAdress(int);
    ~YLB();
    void draw(int);
};

YLB::YLB(YoneticiListesi *yoneticiListesi, int page)
{
    this->yoneticiListesi = yoneticiListesi;
    /* prints related page
    draw(1);
    draw(2);
    draw(3);
    draw(4);
    */
    draw(page);
}
string YLB::createAdresses(int pageNum)
{
    stringstream result;
    string output;
    int i = 0;
    for (YoneticiListesiNode *itr = yoneticiListesi->head; itr != NULL; itr = itr->next)
    {
        result << itr->next << "     ";
        i++;
        if (i % 8 == 0)
            result << endl;
    }
    result << endl;
    for (int j = 0; j < pageNum; j++)
    {
        getline(result, output);
    }
    return output;
}

string YLB::createUnderline(string input)
{
    string underlines = "";
    for (int i = 0; i < input.length(); i++)
    {
        if (input.at(i) != ' ')
            underlines.push_back('-');
        else
            underlines.push_back(' ');
    }
    return underlines;
}

string YLB::createPrevAdress(int pageNum)
{
    stringstream result;
    string output;
    int i = 0;
    for (YoneticiListesiNode *itr = yoneticiListesi->head->next; itr != NULL; itr = itr->next)
    {
        result << itr->prev << "     ";
        i++;
        if (i % 8 == 0)
            result << endl;
    }
    result << endl;
    for (int j = 0; j < pageNum; j++)
    {
        getline(result, output);
    }
    return output;
}

void YLB::draw(int pageNum)
{
    cout << createAdresses(pageNum) << endl;
    cout << createUnderline(createAdresses(pageNum)) << endl;
    cout << createPrevAdress(pageNum) << endl;
    cout << createUnderline(createPrevAdress(pageNum)) << endl;
}

YLB::~YLB()
{
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

// TODO: yazdırılan adresslerin sagına ve soluna birer - daha eklenecek
// yazdırılan prev adreslerinin basına ve sonuna | eklenecek