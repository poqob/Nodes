// satir listesini burada inşa edeceğiz.

// LocationArrow row 51 look for it.

#if !defined(SATIRBUILDER)
#define SATIRBUILDER

#include "../../list/YoneticiListesi.hpp"
#include "sstream"

class SLB
{
private:
    SatirListesi *sl;

public:
    SLB();
    void draw(YoneticiListesi *, int, string);
    string createNextAdress(int);
    string findAdress(int, YoneticiListesi *);
    string createUnderline(string);
    ~SLB();
};

SLB::SLB() {}

void SLB::draw(YoneticiListesi *yl, int whichSatirList, string arrows)
{
}

string SLB::findAdress(int pageNum, YoneticiListesi *yl)
{
    stringstream result;
    string output;
    int i = 0;
    for (YoneticiListesiNode *itr = yl->head; itr != NULL; itr = itr->next)
    {
        result << " " << itr->next->data << "     ";
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

string SLB::createUnderline(string input)
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

SLB::~SLB()
{
}

#endif // SATIRBUILDER
