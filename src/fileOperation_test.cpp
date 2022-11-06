#include <iostream>
#include "Converter.cpp"
#include "Content.cpp"
#include "StringMethod.cpp"
using namespace std;

int main()
{

    Converter *converter = new Converter();
    Content *content = new Content();
    converter->readingFromFile(content);
    // cout << content->contentAvarageCalculator(content->YoneticiListesi->elementAt(24)) << endl;
    //  content->writingAllElements();
    content->putInOrder(content->YoneticiListesi);
    content->~Content();
    delete content;
    delete converter;
    return 0;
}