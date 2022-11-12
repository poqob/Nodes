#include <iostream>
#include "Converter.cpp"
#include "Content.cpp"
#include "StringMethod.cpp"
#include "SatirListesi.cpp"
#include "YoneticiListesi.cpp"
#include "Tabbar.cpp"
#include "YLB.cpp"
//#include "../include/ui/ListBuilders/yoneticiListBuilder.hpp"
using namespace std;
// todo: ui will be designed and functionalities will be added.
int main()
{
    Converter *converter = new Converter();
    Content *content = new Content();
    // read data from file.
    converter->readingFromFile(content);

    content->putInOrder();
    // YoneticiListesiBuilder yb = YoneticiListesiBuilder(content->YoneticiList, 0);
    TabBar tb = TabBar(1);
    YLB yb = YLB(content->YoneticiList, 1);

    content->~Content();
    converter->~Converter();
    delete content;
    delete converter;
    return 0;
}