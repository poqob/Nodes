#if !defined(YONETICIBUILDER)
#define YONETICIBUILDER

#include "../../other/Content.hpp"
#include "iostream"
#include "iomanip"
#include "sstream"
#include "../ostreams/ostream.cpp"
#include "../../list/YoneticiListesi.hpp"
using namespace std;

class YLB
{
private:
    YoneticiListesi *yoneticiListesi;
    string createAdresses(int);
    string createUnderline(string);
    string createPrevAdress(int);
    string createAvarages(int, string);
    string createNextAdress(int);
    double averageCalculator(SatirListesi *);

public:
    string lastUnderLine;
    YLB(YoneticiListesi *, int);
    void draw(YoneticiListesi *, int);
    ~YLB();
};

#endif // YONETICIBUILDER
