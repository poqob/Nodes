#if !defined(YONETICIBUILDER)
#define YONETICIBUILDER

#include "../../other/Content.hpp"
#include "iostream"
#include "iomanip"
#include "sstream"
#include "../../list/YoneticiListesi.hpp"
using namespace std;

class YLB
{
private:
    YoneticiListesi *yoneticiListesi;
    string createAdresses(int);         // produce current yoneticiListesiNode's adress.
    string createUnderline(string);     // it basicly creates '-' line series for dividing rows from each other.
    string createPrevAdress(int);       // This method produces current yoneticiListesiNode's previous yoneticiListesiNode adress.
    string createAvarages(int, string); // callculating and creating(in format) avarages of each YoneticiListesiNode~SatirListesi
    string createNextAdress(int);       // produce-create current yoneticiListesiNode's next node adress.

    double averageCalculator(SatirListesi *); // it calculates and returns avarage of its parameter-SatirListesi

public:
    string lastUnderLine;
    YLB(YoneticiListesi *, int);       // constructor
    void draw(YoneticiListesi *, int); // draw all created outputs
    ~YLB();                            // destructor
};

#endif // YONETICIBUILDER
