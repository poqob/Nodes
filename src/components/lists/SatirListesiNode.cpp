#include "../../../include/list/SatirListesiNode.hpp"

SatirListesiNode::SatirListesiNode(const int data, SatirListesiNode *next = NULL, SatirListesiNode *prev = NULL)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}