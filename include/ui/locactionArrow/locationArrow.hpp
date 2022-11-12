// ^^^^^^^^^^'s sign.
#if !defined(LOCARROW)
#define LOCARROW
#include "iostream"
#include "iomanip"
#include "sstream"
#include "string.h"
#include "../ListBuilders/YLB.hpp"

using namespace std;
class LocationArrow
{
private:
    YLB *y;

public:
    string lunderl; // last under line
    LocationArrow();
    void draw(YLB *, int);
    ~LocationArrow();
};

LocationArrow::LocationArrow()
{
}
void LocationArrow::draw(YLB *y, int wantedSection)
{
    lunderl = y->lastUnderLine;
    string arrow = "";
    int loc = 0;
    // find
    for (int j = 0; j < wantedSection; j++)
    {
        if (wantedSection != 0)
            loc = lunderl.find(" -", loc + 1) + 1;
        else
            loc = 0;
    }
    // draw
    for (int i = loc; i < lunderl.length(); i++)
    {
        if (lunderl.at(i) != ' ')
        {
            arrow.append("^");
        }
        else
            break;
    }
    arrow.insert(0, string(loc, ' '));
    cout << arrow << endl;
}

LocationArrow::~LocationArrow()
{
}

#endif // LOCARROW
