#ifndef SATIRLISTESINODE
#define SATIRLISTESINODE

#include <iostream>
using namespace std;

class SatirListesiNode
{
public:
    int data;
    SatirListesiNode *next;
    SatirListesiNode *prev;
    SatirListesiNode(const int data, SatirListesiNode *next, SatirListesiNode *prev);
};

#endif
