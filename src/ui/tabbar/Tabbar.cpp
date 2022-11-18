/*
 * @Tabbar.cpp
 * @cift yonlu bagli liste uygulamasi
 * @Veri Yapilari 1.Ogretim
 * @odev 1
 * @06.11.2022
 * @Mustafa BICER mustafa.bicer1@ogr.sakarya.edu.tr
 */
#include "../../../include/ui/tabBar/tabBar.hpp"

TabBar::TabBar()
{
}
string // aranges bar according to pageNum and lastPage-bool-
TabBar::barArangement(int pageNum, bool lastPage)
{
    stringstream result;
    stringstream first;
    if (pageNum == 0)
        first << "ilk sayfa";
    else if (lastPage && pageNum != 0)
        first << pageNum << " sonuncu sayfa";
    else
        first << pageNum << ".sayfa";

    string second =
        (lastPage) ? "<---" : "--->";

    result << first.str() << setw(110 - first.str().length() - 4) << second;
    return result.str();
}
// drawing to screen.
void TabBar::draw(int page, bool lastPage)
{
    cout << barArangement(page, lastPage) << endl;
}