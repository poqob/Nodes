/*
 * @main.cpp
 * @cift yonlu bagli liste uygulamasi
 * @Veri Yapilari 1.Ogretim
 * @odev 1
 * @06.11.2022
 * @Mustafa BICER mustafa.bicer1@ogr.sakarya.edu.tr
 */
/*
#include <iostream>
#include "components/lists/SatirListesiNode.cpp"
//#include "components/lists/YoneticiListesiNode.cpp"
#include "components/other/Converter.cpp"
#include "components/other/Content.cpp"
//#include "components/other/StringMethod.cpp"
#include "components/lists/SatirListesi.cpp"
#include "components/lists/YoneticiListesi.cpp"
#include "ui/tabbar/tabBar.cpp"
#include "ui/listBuilders/YLB.cpp"
#include "ui/listBuilders/SLB.cpp"
#include "ui/locationArrow/LocationArrow.cpp"
#include "components/other/Actions.cpp"
*/
#include "../include/list/SatirListesiNode.hpp"
#include "../include/list/YoneticiListesiNode.hpp"
#include "../include/other/Converter.hpp"
#include "../include/other/Content.hpp"
#include "../include/other/StringMethod.hpp"
#include "../include/list/SatirListesi.hpp"
#include "../include/list/YoneticiListesi.hpp"
#include "../include/ui/tabBar/tabBar.hpp"
#include "../include/ui/ListBuilders/YLB.hpp"
#include "../include/ui/ListBuilders/SLB.hpp"
#include "../include/ui/locationArrow/LocationArrow.hpp"
#include "../include/other/Actions.hpp"

using namespace std;
int main()
{
    Converter *converter = new Converter();
    Content *content = new Content();
    // read data from file.
    converter->readingFromFile(content);
    // oredering data
    content->putInOrder();
    int page = 1;
    int selection = 0;
    int maxSelectionOfCurrentPage = 7; // 0...7-total 8
    int lastPage = (content->YoneticiList->Count() % 8 == 0 ? 0 : 1) + content->YoneticiList->Count() / 8;
    bool isLastPage = page >= lastPage ? true : false;
    TabBar tb = TabBar();
    YLB yb = YLB(content->YoneticiList, page);
    LocationArrow la = LocationArrow();
    SLB sb = SLB();

    while (!Actions::breakStatement)
    {
        char ch;
        lastPage = (content->YoneticiList->Count() % 8 == 0 ? 0 : 1) + content->YoneticiList->Count() / 8;
        isLastPage = page >= lastPage ? true : false;
        content->putInOrder();
        system("cls");
        if (page == lastPage)
            isLastPage = true;
        tb.draw(page, isLastPage);
        yb.draw(content->YoneticiList, page);
        la.draw(&yb, selection);
        sb.draw(content->YoneticiList, selection, page, la.arrowLine);
        cin >> ch;
        // Controlls the character input-ch and program state.
        Actions::controll(ch, page, selection, maxSelectionOfCurrentPage, lastPage, isLastPage, content);
    }

    content->~Content();
    converter->~Converter();
    delete content;
    delete converter;
    return 0;
}
