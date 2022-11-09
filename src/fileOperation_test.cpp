#include <iostream>
#include "Converter.cpp"
#include "Content.cpp"
#include "StringMethod.cpp"
#include "SatirListesi.cpp"
#include "YoneticiListesi.cpp"
#include "../include/ui/ListBuilders/yoneticiListBuilder.hpp"
using namespace std;
// todo: ui will be designed and functionalities will be added.
int main()
{
    Converter *converter = new Converter();
    Content *content = new Content();
    // read data from file.
    converter->readingFromFile(content);

    content->putInOrder();
    YoneticiListBuilder yb = YoneticiListBuilder(content->YoneticiList, 0);

    // content->writingAllElements();
    content->~Content();
    converter->~Converter();
    delete content;
    delete converter;
    return 0;
}