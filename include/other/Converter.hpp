#if !defined(CONVERTER)
#define CONVERTER

#include <iostream>
#include <string>
#include "../list/DoublyLinkedList.hpp"

using namespace std;

class Converter
{
private:
    string message;

public:
    Converter(/* args */);
    ~Converter();
    void rowIntParser(string, DoublyLinkedList<int> *);
};

Converter::Converter(/* args */)
{
}

Converter::~Converter()
{
}

#endif // CONVERTER
