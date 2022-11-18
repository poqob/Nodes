#if !defined(SATIRBUILDER)
#define SATIRBUILDER

#include "../../list/YoneticiListesi.hpp"
class SLB
{
private:
    SatirListesi *sl;

public:
    SLB(); // constructor

    void draw(YoneticiListesi *, int, int, std::string); // Satir listesi block drawer

    // creates offset along to the location arrow.
    // pass location arrow line as string input to calculate how far
    int offset(std::string);
    // returns locationArrow lenght
    int arrowLenght(std::string);
    // creates '-' as underline according to intager input.
    std::string createUnderline(int);
    ~SLB(); // destructor
};
#endif // SATIRBUILDER
