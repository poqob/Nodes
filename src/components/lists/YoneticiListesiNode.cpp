/*
 * @YoneticiListesiNode.cpp
 * @cift yonlu bagli liste uygulamasi
 * @Veri Yapilari 1.Ogretim
 * @odev 1
 * @06.11.2022
 * @Mustafa BICER, mustafa.bicer1@ogr.sakarya.edu.tr
 */
#include "../../../include/list/YoneticiListesiNode.hpp"
YoneticiListesiNode::YoneticiListesiNode(SatirListesi *data, YoneticiListesiNode *next, YoneticiListesiNode *prev)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}

YoneticiListesiNode::YoneticiListesiNode(SatirListesi *data, YoneticiListesiNode *next)
{
    this->data = data;
    this->next = next;
}
YoneticiListesiNode::YoneticiListesiNode(SatirListesi *data)
{
    this->data = data;
}