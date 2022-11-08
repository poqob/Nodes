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
    SatirListesiNode(const int data, SatirListesiNode *next = NULL, SatirListesiNode *prev = NULL)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

#endif
