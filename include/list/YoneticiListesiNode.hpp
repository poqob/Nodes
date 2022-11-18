#ifndef YONETICILISTESINODE
#define YONETICILISTESINODE

#include "SatirListesi.hpp"

class YoneticiListesiNode
{
public:
	SatirListesi *data;
	YoneticiListesiNode *next;
	YoneticiListesiNode *prev;
	double calculateAvarage;
	YoneticiListesiNode(SatirListesi *, YoneticiListesiNode *, YoneticiListesiNode *);
	YoneticiListesiNode(SatirListesi *, YoneticiListesiNode *);
	YoneticiListesiNode(SatirListesi *);
};

#endif
