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
    Converter();
    ~Converter();
    void rowIntParser(string, DoublyLinkedList<int> *);
};

#endif // CONVERTER
