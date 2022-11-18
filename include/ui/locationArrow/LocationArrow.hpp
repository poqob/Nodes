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
    string lunderl; // last under line
    string arrowLine;
    LocationArrow();
    void draw(YLB *, int);
    ~LocationArrow();
};
#endif // LOCARROW
