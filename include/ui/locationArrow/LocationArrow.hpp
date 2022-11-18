// ^^^^^^^^^^'s sign.
#if !defined(LOCARROW)
#define LOCARROW

#include "../ListBuilders/YLB.hpp"

using namespace std;
class LocationArrow
{
private:
    YLB *y;

public:
    string lunderl;        // last under line, location arrows previous line
    string arrowLine;      // the arrow line that will be printed to screen
    LocationArrow();       // constructor
    void draw(YLB *, int); // draw location arrow
    ~LocationArrow();      // destructor
};
#endif // LOCARROW
