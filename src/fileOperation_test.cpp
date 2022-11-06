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
    content->readingAllElements();
    content->~Content();
    delete content;
    delete converter;
    return 0;
}
