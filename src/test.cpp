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
    bool isLastPage = false;
    YLB yb = YLB(content->YoneticiList, page);
    TabBar tb = TabBar();
    LocationArrow la = LocationArrow();
    SLB sb = SLB();

    content->writingAllElements();
    content->~Content();
    converter->~Converter();
    delete content;
    delete converter;
    return 0;
}
