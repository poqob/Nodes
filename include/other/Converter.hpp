#if !defined(CONVERTER)
#define CONVERTER

#include <iostream>
#include <fstream>
#include <string>
#include "Content.hpp"
#include "StringMethod.hpp"

using namespace std;

class Converter
{

public:
    Converter();
    ~Converter();
    void readingFromFile(Content *);
    void rowIntParser(string, SatirListesi *);
};

#endif // CONVERTER
