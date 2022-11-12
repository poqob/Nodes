#include <iostream>
#include "Converter.cpp"
#include "Content.cpp"
#include "StringMethod.cpp"
#include "SatirListesi.cpp"
#include "YoneticiListesi.cpp"
#include "Tabbar.cpp"
#include "YLB.cpp"
#include "../include/ui/locactionArrow/locationArrow.hpp"
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
    int lastPage = (content->YoneticiList->Count() % 8 == 0 ? 0 : 1) + content->YoneticiList->Count() / 8;
    bool isLastPage = false;
    YLB yb = YLB(content->YoneticiList, page);
    TabBar tb = TabBar(page, isLastPage);
    LocationArrow la = LocationArrow();

    while (true)
    {
        char ch;
        system("cls");

        if (page == lastPage)
            isLastPage = true;
        tb.draw(page, isLastPage);
        yb.draw(page);
        la.draw(&yb, selection);
        cin >> ch;
        // controll of inter pages.
        if (ch == 'a' && page != 1)
        {
            page--;
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
        }
        // controll of inter selection TODO: not 8, one page may have elements less than 8.
        if (ch == 'c' && selection != 8)
        {
            selection++;
        }
        else if (ch == 'z' && selection != 0)
        {
            selection--;
        }
    }

    content->~Content();
    converter->~Converter();
    delete content;
    delete converter;
    return 0;
}