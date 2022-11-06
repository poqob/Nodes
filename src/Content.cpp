#include "../include/other/Content.hpp"

Content::Content()
{
    YoneticiListesi = new DoublyLinkedList<DoublyLinkedList<int>>();
    SatirListesi = new DoublyLinkedList<int>();
}

Content::~Content()
{
    delete YoneticiListesi;
    delete SatirListesi;
    delete this;
}