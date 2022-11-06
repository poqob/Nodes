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

void Content::writingAllElements()
{
    for (int i = 0; i < YoneticiListesi->Count(); i++)
    {
        cout << *YoneticiListesi->elementAt(i) << endl;
    }
}

void Content::putInOrder(DoublyLinkedList<DoublyLinkedList<int> *> *yoneticiListesi)
{
    double enKucuk = 0;
    // yonetici listesi düzeyinde satır listelerinin ayrı ayrı ortalama hesabı.
    for (int i = 0; i < yoneticiListesi->Count(); i++)
    {
        cout << contentAvarageCalculator(yoneticiListesi->elementAt(i)) << endl;
    }
}
// satır listesi düzeyinde liste içeriklerinin ortalama hesabı
double Content::contentAvarageCalculator(DoublyLinkedList<int> *satirListesi)
{
    double avarage = 0;
    for (int i = 0; i < satirListesi->Count(); i++)
    {
        avarage += satirListesi->elementAt(i);
    }

    return avarage / satirListesi->Count();
}

// TODO: order yönetici listesi by avarage of its contents.
// only last one problem. avarage calculation done.
// the problem is ordering.
