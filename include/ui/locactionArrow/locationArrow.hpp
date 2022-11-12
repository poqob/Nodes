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
    int startLoc = 0;
    int stopLoc = 0;
    char arrow = '^';
    void calculateLocations(int);
    string drawArrow(int, int);
    LocationArrow(YLB *);
    void draw(int);
    ~LocationArrow();
};

LocationArrow::LocationArrow(YLB *y)
{
    lunderl = y->lastUnderLine;
}

string LocationArrow::drawArrow(int startLoc, int stopLoc)
{
    stringstream output;
    string result;
    string arrow;
    output << setw(startLoc - 1);
    result = output.str();
    result.append(string(stopLoc - startLoc, '^'));
    return result;
}

void LocationArrow::calculateLocations(int whichSatirList)
{
    int firstLoc = 0;
    int secondLoc = 0;
    secondLoc = lunderl.find(" ", firstLoc + 1) - 1;
    for (int i = 0; i < whichSatirList; i++)
    {
        firstLoc = secondLoc;
        secondLoc = lunderl.find(" ", firstLoc);
    }
}

void LocationArrow::draw(int whereAmI)
{
    cout << drawArrow(0, 5);
}
LocationArrow::~LocationArrow()
{
}

#endif // LOCARROW
