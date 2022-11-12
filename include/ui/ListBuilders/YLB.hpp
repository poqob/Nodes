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
    void draw(int);
    string createAdresses(int);
    string createUnderline(string);
    string createPrevAdress(int);
    string createAvarages(int, string);
    string createNextAdress(int);
    double averageCalculator(SatirListesi *);

public:
    YLB(YoneticiListesi *, int);
    ~YLB();
};

#endif // YONETICIBUILDER
