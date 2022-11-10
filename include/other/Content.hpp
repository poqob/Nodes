#if !defined(CONTENT)
#define CONTENT
#include "../list/YoneticiListesi.hpp"
#include "../list/SatirListesi.hpp"

class Content
{
public:
    YoneticiListesi *YoneticiList;
    SatirListesi *SatirList;
    Content();
    ~Content();
    void nextRow();
    void writingAllElements();
    void writing();
    void putInOrder();
    void swapInRow(SatirListesi *);
    void swap(YoneticiListesi *);
    static double contentAvarageCalculator(SatirListesi *);
};

#endif // CONTENT
