/*
 * @LocationArrow.cpp
 * @cift yonlu bagli liste uygulamasi
 * @Veri Yapilari 1.Ogretim
 * @odev 1
 * @06.11.2022
 * @Mustafa BICER mustafa.bicer1@ogr.sakarya.edu.tr
 */
#include "../../../include/ui/locationArrow/LocationArrow.hpp"
LocationArrow::LocationArrow() {}

// moves and draws location arrow
void LocationArrow::draw(YLB *y, int wantedSection)
{
    lunderl = y->lastUnderLine;
    string arrow = "";
    int loc = 0;
    // find
    for (int j = 0; j < wantedSection; j++)
    {
        if (wantedSection != 0)
            loc = lunderl.find(" -", loc + 1) + 1;
        else
            loc = 0;
    }
    // draw
    for (int i = loc; i < lunderl.length(); i++)
    {
        if (lunderl.at(i) != ' ')
        {
            arrow.append("^");
        }
        else
            break;
    }
    arrow.insert(0, string(loc, ' '));
    arrowLine = arrow; // according to this locArrowLine we will create SatirListesi Objects.
    std::cout << arrow << std::endl;
}

LocationArrow::~LocationArrow() {}
