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
	double avarage;

	YoneticiListesiNode(SatirListesi *data, YoneticiListesiNode *next = NULL, YoneticiListesiNode *prev = NULL)
	{
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};

#endif
