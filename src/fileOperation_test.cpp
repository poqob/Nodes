#include <iostream>
#include "Converter.cpp"
#include "Content.cpp"
#include "StringMethod.cpp"
#include "SatirListesi.cpp"
#include "YoneticiListesi.cpp"
#include "Tabbar.cpp"
#include "YLB.cpp"
#include "LocationArrow.cpp"
#include "../include/ui/ListBuilders/SLB.hpp"
using namespace std;
int main()
{
    Converter *converter = new Converter();
    Content *content = new Content();
    // read data from file.
    converter->readingFromFile(content);

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

    while (true)
    {
        content->putInOrder();
        char ch;

        system("cls");
        if (page == lastPage)
            isLastPage = true;
        tb.draw(page, isLastPage);
        yb.draw(content->YoneticiList, page);
        la.draw(&yb, selection);
        sb.draw(content->YoneticiList, selection, page, la.arrowLine);
        cin >> ch;
        // controll of inter pages.
        if (ch == 'a' && page != 1)
        {
            page--;
            selection = maxSelectionOfCurrentPage;
            isLastPage = false;
        }
        else if (ch == 'd')
        {
            if (page == lastPage)
            {
                isLastPage = true;
                continue;
            }
            else
            {
                isLastPage = false;
                page++;
            }
            selection = 0;
        }
        // controll of inter selection TODO: not 8, one page may have elements less than 8.
        if (ch == 'c' && selection != maxSelectionOfCurrentPage)
        {
            selection++;
        }
        else if (ch == 'z' && selection != 0)
        {
            selection--;
        }
        else if (ch == 'c' && selection == maxSelectionOfCurrentPage)
        {
            if (page != lastPage)
            {
                page++;
                selection = 0;
            }
        }
        else if (ch == 'z' && selection == 0)
        {
            if (page - 1 != 0)
            {
                page--;
                selection = maxSelectionOfCurrentPage;
            }
        }
        maxSelectionOfCurrentPage = (content->YoneticiList->Count() - 8 * (page - 1) >= 7 ? 7 : (8 - abs(content->YoneticiList->Count() - 8 * page)) - 1);
    }

    content->~Content();
    converter->~Converter();
    delete content;
    delete converter;
    return 0;
}
