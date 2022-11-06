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
// buradayız sıralama algoritması yazılacak :dddd
void Content::putInOrder()
{
    double tmp = 0;
    double enKucuk = contentAvarageCalculator(YoneticiListesi->elementAt(0));
    DoublyLinkedList<int> *sl = new DoublyLinkedList<int>();
    // yonetici listesi düzeyinde satır listelerinin ayrı ayrı ortalama hesabı.
    for (int i = 0; i < YoneticiListesi->Count(); i++)
    {
        tmp = contentAvarageCalculator(YoneticiListesi->elementAt(i));
        if (tmp < enKucuk)
        {
            enKucuk = tmp;
            sl = YoneticiListesi->elementAt(i);
            YoneticiListesi->removeAt(i);
            YoneticiListesi->insert(0, sl);
        }
    }
    for (int i = 0; i < YoneticiListesi->Count(); i++)
    {
        cout << contentAvarageCalculator(YoneticiListesi->elementAt(i)) << endl;
    }
    sl->~DoublyLinkedList();
    delete sl;
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
