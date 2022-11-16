/*
 * @YoneticiListesiNode.cpp
 * @cift yonlu bagli liste uygulamasi
 * @Veri Yapilari 1.Ogretim
 * @odev 1
 * @06.11.2022
 * @Mustafa BICER, mustafa.bicer1@ogr.sakarya.edu.tr
 */
#include "../../../include/list/YoneticiListesiNode.hpp"

YoneticiListesiNode::YoneticiListesiNode(SatirListesi *data, YoneticiListesiNode *next = NULL, YoneticiListesiNode *prev = NULL)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}