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
    int lastPage = (content->YoneticiList->Count() % 8 == 0 ? 0 : 1) + content->YoneticiList->Count() / 8;
    bool isLastPage = false;
    YLB yb = YLB(content->YoneticiList, page);
    TabBar tb = TabBar(page, isLastPage);
    LocationArrow la = LocationArrow(&yb);

    while (true)
    {
        char ch;
        system("cls");

        if (page == lastPage)
            isLastPage = true;
        tb.draw(page, isLastPage);
        yb.draw(page);
        la.draw(5);
        cin >> ch;
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
    }

    content->~Content();
    converter->~Converter();
    delete content;
    delete converter;
    return 0;
}