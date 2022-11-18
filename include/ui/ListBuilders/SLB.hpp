#if !defined(SATIRBUILDER)
#define SATIRBUILDER

#include "../../list/YoneticiListesi.hpp"
class SLB
{
private:
    SatirListesi *sl;

public:
    SLB();
    void draw(YoneticiListesi *, int, int, std::string);
    int offset(std::string);
    int arrowLenght(std::string);
    std::string createUnderline(int);
    ~SLB();
};
#endif // SATIRBUILDER
