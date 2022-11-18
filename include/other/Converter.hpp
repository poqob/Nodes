#if !defined(CONVERTER)
#define CONVERTER

#include "Content.hpp"
using namespace std;

class Converter
{

public:
    Converter();                               // constructor
    ~Converter();                              // destructor
    void readingFromFile(Content *);           // read datas from file *data klasorunun icerisine veriler.txt- yol ve adlandırma bu sekilde olmalı
    void rowIntParser(string, SatirListesi *); // it makes string to int conversion and adds to SatirListesi that is parameter.
};

#endif // CONVERTER
