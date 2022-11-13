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
    int a = 4;
    try
    {
        cout << *sb.findAdress(a, 1, content->YoneticiList) << "  " << content->contentAvarageCalculator(sb.findAdress(a, 1, content->YoneticiList)) << endl;
        cout << *sb.findAdress(a, 2, content->YoneticiList) << "  " << content->contentAvarageCalculator(sb.findAdress(a, 2, content->YoneticiList)) << endl;
        cout << *sb.findAdress(a, 3, content->YoneticiList) << "  " << content->contentAvarageCalculator(sb.findAdress(a, 3, content->YoneticiList)) << endl;
        cout << *sb.findAdress(a, 4, content->YoneticiList) << "  " << content->contentAvarageCalculator(sb.findAdress(a, 4, content->YoneticiList)) << endl;
        cout << *sb.findAdress(a, 5, content->YoneticiList) << "  " << content->contentAvarageCalculator(sb.findAdress(a, 5, content->YoneticiList)) << endl;
        cout << *sb.findAdress(a, 6, content->YoneticiList) << "  " << content->contentAvarageCalculator(sb.findAdress(a, 6, content->YoneticiList)) << endl;
        cout << *sb.findAdress(a, 7, content->YoneticiList) << "  " << content->contentAvarageCalculator(sb.findAdress(a, 7, content->YoneticiList)) << endl;
        cout << *sb.findAdress(a, 8, content->YoneticiList) << "  " << content->contentAvarageCalculator(sb.findAdress(a, 8, content->YoneticiList)) << endl;
        cout << *sb.findAdress(a, 9, content->YoneticiList) << "  " << content->contentAvarageCalculator(sb.findAdress(a, 9, content->YoneticiList)) << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    // content->writingAllElements();
    content->~Content();
    converter->~Converter();
    delete content;
    delete converter;
    return 0;
}
