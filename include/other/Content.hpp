#if !defined(CONTENT)
#define CONTENT
#include "../list/YoneticiListesi.hpp"
#include "../list/SatirListesi.hpp"

/*
this classes purpose is gathering all changeables together
and manipulating them.
manipulate: swap() -for yonetici listesi- ,sawpInRow() -satir listesi addition func*-, putInOrder() -sorting-
display: writing(),writingAllElements(),
*/
class Content
{
public:
    YoneticiListesi *YoneticiList;
    SatirListesi *SatirList;
    Content();                                              // constructor
    ~Content();                                             // destructor
    void nextRow();                                         // works after one line readed from veriler.txt
    void writingAllElements();                              // writes avg of satirListesi elements
    void writing();                                         // writes satir listesi of elements
    void putInOrder();                                      // sort according to avgs
    void swapInRow(SatirListesi *);                         // sorting numbers from lower to larger that is in satir listesi
    void swap(YoneticiListesi *);                           // sorting yonetici listesi nodes according to it's child's(satir listesi) averages.
    static double contentAvarageCalculator(SatirListesi *); // calculating averages of satir listesi that was input
};

#endif // CONTENT
