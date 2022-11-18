/*
 * @main.cpp
 * @cift yonlu bagli liste uygulamasi
 * @Veri Yapilari 1.Ogretim
 * @odev 1
 * @06.11.2022
 * @Mustafa BICER mustafa.bicer1@ogr.sakarya.edu.tr
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

    converter->readingFromFile(content);                                                                   // read data from file. then convert it to int.
    content->putInOrder();                                                                                 // oredering data - in Content class we can do some pre-manipulation like ordering~sorting data.
    int page = 1;                                                                                          // definition of start page
    int selection = 0;                                                                                     // definition of selection
    int maxSelectionOfCurrentPage = 7;                                                                     // 0...7-total 8
    int lastPage = (content->YoneticiList->Count() % 8 == 0 ? 0 : 1) + content->YoneticiList->Count() / 8; // calculating lastpage according to
    bool isLastPage = page >= lastPage ? true : false;                                                     // testing the page is last page or not.
    TabBar tb = TabBar();                                                                                  // tabbar
    YLB yb = YLB(content->YoneticiList, page);                                                             // YLB-yonetici listesi builder
    LocationArrow la = LocationArrow();                                                                    // location arrow
    SLB sb = SLB();                                                                                        // satir listesi builder

    // Action::breakStatement controlls the program.-break or continue(not keyword one).
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

    content->~Content();     // destructor for Content
    converter->~Converter(); // destrucor for Converter
    delete content;
    delete converter;
    return 0;
}
