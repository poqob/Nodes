#ifndef YONETICILISTESINODE
#define YONETICILISTESINODE

#include <iostream>
#include "SatirListesi.hpp"
using namespace std;

class YoneticiListesiNode
{
public:
	SatirListesi *data;
	YoneticiListesiNode *next;
	YoneticiListesiNode *prev;
	double calculateAvarage;
	YoneticiListesiNode(SatirListesi *data, YoneticiListesiNode *next, YoneticiListesiNode *prev);
};

#endif
