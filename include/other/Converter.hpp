#if !defined(CONVERTER)
#define CONVERTER

#include "Content.hpp"
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
