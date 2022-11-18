#ifndef SATIRLISTESINODE
#define SATIRLISTESINODE

class SatirListesiNode
{
public:
    int data;
    SatirListesiNode *next;
    SatirListesiNode *prev;
    SatirListesiNode(const int, SatirListesiNode *, SatirListesiNode *);
    SatirListesiNode(const int, SatirListesiNode *);
    SatirListesiNode(const int);
};

#endif
