#include <iostream>
#include "Converter.cpp"
#include "Content.cpp"
#include "YoneticiListesi.cpp"
#include "StringMethod.cpp"
using namespace std;
// todo: ui will be designed and functionalities will be added.
int main()
{

    Converter *converter = new Converter();
    Content *content = new Content();
    // read data from file.
    converter->readingFromFile(content);

    content->putInOrder();
    content->writingAllElements();
    content->~Content();
    converter->~Converter();
    delete content;
    delete converter;
    return 0;
}