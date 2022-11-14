#include "../../../include/ui/ListBuilders/SLB.hpp"

SLB::SLB() {}

string SLB::createUnderline(int lenght)
{
    return string(lenght + 2, '-');
}

// we will make new underline method, old one screwed it up.
// TODO: update createUnderLine methods.-done
//  ..gain more true format-done
// ..last page's yonetici listesi draw problem still remains.- working on.

void SLB::draw(YoneticiListesi *yl, int whichSatirList, int page, string arrows)
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

SLB::~SLB()
{
}
