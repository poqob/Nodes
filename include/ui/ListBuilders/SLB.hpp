// satir listesini burada inşa edeceğiz.

// LocationArrow row 51 look for it.

#if !defined(SATIRBUILDER)
#define SATIRBUILDER

#include "../../list/YoneticiListesi.hpp"
#include "sstream"
#include "iomanip"

class SLB
{
private:
    SatirListesi *sl;

public:
    SLB();
    void draw(YoneticiListesi *, int, int, string);
    int offset(string);
    int arrowLenght(string);
    void creator(YoneticiListesi *, int, int, string);
    SatirListesi *findAdress(int, int, YoneticiListesi *);
    string createUnderline(int);

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

string SLB::createUnderline(int lenght)
{
    return string(lenght + 2, '-');
}

// we will make new underline method, old one screwed it up.
// TODO: update createUnderLine methods.-done
//  ..gain more true format-done
// ..last page's yonetici listesi draw problem still remains.- working on.

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

        output << setw(offset(arrows) + 1) << " " << itr << endl;
        output << setw(offset(arrows) + arrowLenght(arrows) + 2) << createUnderline(arrowLenght(arrows)) << endl;
        output << setw(offset(arrows) + 1) << "|" << itr->data << setw(arrowLenght(arrows) - tmps.str().length() + 1) << "|" << endl;
        output << setw(offset(arrows) + arrowLenght(arrows) + 2) << createUnderline(arrowLenght(arrows)) << endl;
        output << setw(offset(arrows) + 1) << "|" << itr->next << "|" << endl;
        output << setw(offset(arrows) + arrowLenght(arrows) + 2) << createUnderline(arrowLenght(arrows)) << endl;
        output << endl;
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
