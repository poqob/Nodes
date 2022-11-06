#include "../include/other/Content.hpp"

Content::Content()
{
    YoneticiListesi = new DoublyLinkedList<DoublyLinkedList<int> *>();
    SatirListesi = new DoublyLinkedList<int>();
}

Content::~Content()
{
    for (int i = 0; i < YoneticiListesi->Count(); i++)
    {
        YoneticiListesi->elementAt(i)->~DoublyLinkedList();
    }
    SatirListesi->~DoublyLinkedList();
    delete YoneticiListesi;
    delete SatirListesi;
    delete this;
}

void Content::nextRow()
{
    YoneticiListesi->add(SatirListesi);
    SatirListesi = new DoublyLinkedList<int>();
}

void Content::readingAllElements()
{
    for (int i = 0; i < YoneticiListesi->Count(); i++)
    {
        cout << *YoneticiListesi->elementAt(i) << endl;
    }
}