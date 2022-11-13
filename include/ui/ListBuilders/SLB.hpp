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
    string createNextAdress(int);    // TODO
    string createContent(int);       // TODO
    string createCurrentAdress(int); // TODO
    int offset(string);
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

int SLB::offset(string arrow)
{
    return arrow.length();
}

void SLB::draw(YoneticiListesi *yl, int whichSatirList, string arrows)
{
    // test-looks like this
    cout << setw(offset(arrows)) << "#adressOfSatir" << endl;
    cout << setw(offset(arrows)) << "#|-----------|" << endl;
    cout << setw(offset(arrows)) << "#|content    |" << endl;
    cout << setw(offset(arrows)) << "#|-----------|" << endl;
    cout << setw(offset(arrows)) << "#|nextAdress |" << endl;
    cout << setw(offset(arrows)) << "#" << endl;
    cout << setw(offset(arrows)) << "#adressOfSatir" << endl;
    cout << setw(offset(arrows)) << "#|-----------|" << endl;
    cout << setw(offset(arrows)) << "#|content    |" << endl;
    cout << setw(offset(arrows)) << "#|-----------|" << endl;
    cout << setw(offset(arrows)) << "#|nextAdress |" << endl;
}
SLB::~SLB()
{
}

#endif // SATIRBUILDER
