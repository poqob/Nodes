#if !defined(SATIRBUILDER)
#define SATIRBUILDER

#include "../../list/YoneticiListesi.hpp"
#include "sstream"
#include "iomanip"

class SLB
{
private:
    SatirListesi *sl;

public:
    SLB();
    void draw(YoneticiListesi *, int, int, string);
    int offset(string);
    int arrowLenght(string);
    string createUnderline(int);
    ~SLB();
};
#endif // SATIRBUILDER
