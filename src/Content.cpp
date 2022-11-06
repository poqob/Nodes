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
    // yonetici listesi düzeyinde satır listelerinin ayrı ayrı ortalama hesabı.
    for (int i = 0; i < YoneticiListesi->Count(); i++)
    {
        // cout << contentAvarageCalculator(YoneticiListesi->elementAt(i)) << endl;
        // Satir listesini kendi arasinda kucukten buyuge siralar.
        swap(YoneticiListesi->elementAt(i));
        cout << *YoneticiListesi->elementAt(i) << endl;
    }

    // cout << *YoneticiListesi->elementAt(3) << endl;
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

void Content::swap(DoublyLinkedList<int> *satir)
{
    // i kaçıncı periyotta olduğumuzu ifade ediyor.
    // j ise satır içerisinde gezdiğimiz elemanları.
    int n = satir->Count() - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            // cout << satir->elementAt(j) << " " << satir->elementAt(j + 1) << endl;
            if (satir->elementAt(j) > satir->elementAt(j + 1))
            {
                satir->swap(j, j + 1);
            }
        }
    }
}
// TODO: order yönetici listesi by avarage of its contents.
// only last one problem. avarage calculation done.
// the problem is ordering.
