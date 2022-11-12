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
    string createAvarages(int);
    string createNextAdress(int);
    double averageCalculator(SatirListesi *);
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

double YLB::averageCalculator(SatirListesi *satirListesi)
{
    double average = 0;
    for (int i = 0; i < satirListesi->Count(); i++)
    {
        average += satirListesi->elementAt(i);
    }
    return average / satirListesi->Count();
}

string YLB::createAdresses(int pageNum)
{
    stringstream result;
    string output;
    int i = 0;
    for (YoneticiListesiNode *itr = yoneticiListesi->head; itr != NULL; itr = itr->next)
    {
        result << " " << itr->next << "     ";
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
    int cizgi = 0;
    int bosluk = 0;
    for (int i = 0; i < input.length() - 1; i++)
    {
        if (input.at(i) != ' ')
        {
            underlines.append(string(bosluk, ' '));
            bosluk = 0;
            cizgi++;
            // underlines.push_back('-');
        }
        else
        {
            underlines.append(string(cizgi, '-'));
            cizgi = 0;
            bosluk++;
        }
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
        result << "|" << itr->prev << "|"
               << "    ";
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

string YLB::createNextAdress(int pageNum)
{
    stringstream result;
    string output;
    int i = 0;
    for (YoneticiListesiNode *itr = yoneticiListesi->head->next; itr != NULL; itr = itr->next)
    {
        result << "|" << itr->next << "|"
               << "    ";
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

string YLB::createAvarages(int pageNum)
{
    stringstream result;
    string output;
    int i = 0;
    for (YoneticiListesiNode *itr = yoneticiListesi->head; itr != NULL; itr = itr->next)
    {
        result << "|" << averageCalculator(yoneticiListesi->elementAt(i).data) << "|    ";
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
    cout << createAvarages(pageNum) << endl;
    cout << createUnderline(createAvarages(pageNum)) << endl;
    cout << createNextAdress(pageNum) << endl;
    cout << createUnderline(createNextAdress(pageNum)) << endl;
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