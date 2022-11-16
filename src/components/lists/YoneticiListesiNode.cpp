#include "../../../include/list/YoneticiListesiNode.hpp"

YoneticiListesiNode::YoneticiListesiNode(SatirListesi *data, YoneticiListesiNode *next = NULL, YoneticiListesiNode *prev = NULL)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}