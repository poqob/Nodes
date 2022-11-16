/*
 * @SLB.cpp-satir listesi builder
 * @cift yonlu bagli liste uygulamasi
 * @Veri Yapilari 1.Ogretim
 * @odev 1
 * @06.11.2022
 * @Mustafa BICER mustafa.bicer1@ogr.sakarya.edu.tr
 */
#include "../../../include/ui/ListBuilders/SLB.hpp"

SLB::SLB() {}

string SLB::createUnderline(int lenght)
{
    return string(lenght + 2, '-');
}

void SLB::draw(YoneticiListesi *yl, int whichSatirList, int page, string arrows)
{
    stringstream output;
    stringstream tmps;
    // for null controlling
    string tmp1;
    stringstream tmps1;
    int current = (page - 1) * 8 + whichSatirList;
    int i = 0;
    for (SatirListesiNode *itr = yl->elementAt(current).data->head; itr != NULL; itr = itr->next)
    {
        tmps << itr->data;
        tmps1 << itr->next;
        tmp1 = tmps1.str() == "0" ? "00000000" : tmps1.str();
        tmps1.str("");
        output << setw(offset(arrows) + 1) << " " << itr << endl;
        output << setw(offset(arrows) + arrowLenght(arrows) + 2) << createUnderline(arrowLenght(arrows)) << endl;
        output << setw(offset(arrows) + 1) << "|" << itr->data << setw(arrowLenght(arrows) - tmps.str().length() + 1) << "|" << endl;
        output << setw(offset(arrows) + arrowLenght(arrows) + 2) << createUnderline(arrowLenght(arrows)) << endl;
        output << setw(offset(arrows) + 1) << "|" << tmp1 << "|" << endl;
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

SLB::~SLB()
{
}
