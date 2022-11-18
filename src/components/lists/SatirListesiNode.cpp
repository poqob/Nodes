/*
 * @SatirListesiNode.cpp
 * @cift yonlu bagli liste uygulamasi
 * @Veri Yapilari 1.Ogretim
 * @odev 1
 * @06.11.2022
 * @Mustafa BICER mustafa.bicer1@ogr.sakarya.edu.tr
 */
#include "../../../include/list/SatirListesiNode.hpp"

SatirListesiNode::SatirListesiNode(const int data, SatirListesiNode *next, SatirListesiNode *prev)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}

SatirListesiNode::SatirListesiNode(const int data, SatirListesiNode *next)
{
    this->data = data;
    this->next = next;
}

SatirListesiNode::SatirListesiNode(const int data)
{
    this->data = data;
}