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
    void draw(YoneticiListesi *, int, int, string);
    string createNextAdress(int);    // TODO
    string createContent(int);       // TODO
    string createCurrentAdress(int); // TODO
    int offset(string);
    int arrowLenght(string);
    void creator(YoneticiListesi *, int, int, string);
    SatirListesi *findAdress(int, int, YoneticiListesi *);
    string createUnderline(string);

    ~SLB();
};

SLB::SLB() {}

SatirListesi *SLB::findAdress(int pageNum, int selection, YoneticiListesi *yl)
{
    int elementAt = ((pageNum - 1) * 8) + selection;
    int i = 0;
    SatirListesi *satirListesiAdresi;
    for (YoneticiListesiNode *itr = yl->head; itr != NULL, i < elementAt; itr = itr->next, i++)
    {
        satirListesiAdresi = itr->data;
    }
    return satirListesiAdresi;
}

string SLB::createUnderline(string input)
{
    stringstream result;
    result << string("-", (arrowLenght(input))) << endl;
    return result.str();
}

// we will make new underline method, old one screwed it up.
// TODO: update createUnderLine methods.
//  ..gain more true format
// ..last page's yonetici listesi draw problem still remains.

void SLB::creator(YoneticiListesi *yl, int whichSatirList, int page, string arrows)
{
    stringstream output;
    stringstream tmps;
    string tmp;
    int current = (page - 1) * 8 + whichSatirList;
    int i = 0;
    for (SatirListesiNode *itr = yl->elementAt(current).data->head; itr != NULL; itr = itr->next)
    {
        tmps << itr->data;

        output << setw(offset(arrows)) << " " << itr << endl;

        output << setw(offset(arrows)) << "|" << itr->data << setw(arrowLenght(arrows) - tmps.str().length()) << "|" << endl;

        output << setw(offset(arrows)) << "|" << itr->next << "|" << endl;

        tmps.str("");
    }

    cout << output.str();
}

int SLB::offset(string arrow)
{
    // return arrow.length();
    return arrow.find("^");
}

int SLB::arrowLenght(string arrow)
{
    return arrow.length() - (arrow.find("^") + 2);
}

void SLB::draw(YoneticiListesi *yl, int whichSatirList, int page, string arrows)
{
    creator(yl, whichSatirList, page, arrows);
}
SLB::~SLB()
{
}

#endif // SATIRBUILDER
