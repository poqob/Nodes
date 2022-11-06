#include "../include/other/Converter.hpp"
#include "string.h"
#include "../include/other/Content.hpp"
using namespace std;

Converter::Converter()
{
}

Converter::~Converter()
{
}
void Converter::rowIntParser(string row, DoublyLinkedList<int> *SatirListesi)
{
    int firstSpaceLoc = 0;
    int till = 0;
    int firstNumLoc = 0;

    try
    {
        do
        {
            firstSpaceLoc = row.find(' ', firstNumLoc);
            till = firstSpaceLoc - firstNumLoc + 1;
            SatirListesi->add(stoi(row.substr(firstNumLoc, till)));
            firstNumLoc = firstSpaceLoc + 1;
        } while (row.find(' ', firstNumLoc) != -1);
        SatirListesi->add(stoi(row.substr(firstNumLoc, till)));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}