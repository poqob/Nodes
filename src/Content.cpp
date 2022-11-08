#include "../include/other/Content.hpp"

Content::Content()
{
    YoneticiList = new YoneticiListesi();
    SatirList = new SatirListesi();
}

Content::~Content()
{
    // clearing-freed satir list members
    for (int i = 0; i < YoneticiList->Count(); i++)
    {
        YoneticiList->elementAt(i).data->~SatirListesi();
    }
    SatirList->~SatirListesi();
    delete YoneticiList;
    delete SatirList;
    delete this;
}

// works after one line readed from veriler.txt
// attemts readed numbers list -SatirList- to YoneticiList
void Content::nextRow()
{
    YoneticiList->add(SatirList);
    SatirList = new SatirListesi();
}

// LOOK HERE AFTER ADAPTATION
void Content::writingAllElements()
{
    for (int i = 0; i < YoneticiList->Count(); i++)
    {
        cout << *YoneticiList->elementAt(i).data << " avg " << contentAvarageCalculator(YoneticiList->elementAt(i).data) << endl;
    }
}
// buradayız sıralama algoritması yazılacak :dddd
void Content::putInOrder()
{
    // ortalamalara göre siraya koy.
    swap(YoneticiList);
    // yonetici listesi düzeyinde satır listelerinin ayrı ayrı ortalama hesabı.
    for (int i = 0; i < YoneticiList->Count(); i++)
    {
        // cout << contentAvarageCalculator(YoneticiListesi->elementAt(i)) << endl;
        // Satir listesini kendi arasinda kucukten buyuge siralar.-satir içi büyüklüğe göre siraya koy
        swapInRow(YoneticiList->elementAt(i).data);
        // writing content's in desc order and list's list in desc averages order.
        // cout << *YoneticiListesi->elementAt(i) << " avg " << contentAvarageCalculator(YoneticiListesi->elementAt(i)) << endl;
    }

    // cout << *YoneticiListesi->elementAt(3) << endl;
}

// satır listesi düzeyinde liste içeriklerinin ortalama hesabı
double Content::contentAvarageCalculator(SatirListesi *satirListesi)
{
    double avarage = 0;
    for (int i = 0; i < satirListesi->Count(); i++)
    {
        avarage += satirListesi->elementAt(i);
    }

    return avarage / satirListesi->Count();
}

void Content::swapInRow(SatirListesi *satir)
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

void Content::swap(YoneticiListesi *yoneticiListesi)
{
    int n = yoneticiListesi->Count() - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            // cout << satir->elementAt(j) << " " << satir->elementAt(j + 1) << endl;
            if (contentAvarageCalculator(yoneticiListesi->elementAt(j).data) > contentAvarageCalculator(yoneticiListesi->elementAt(j + 1).data))
            {
                yoneticiListesi->swap(j, j + 1);
            }
        }
    }
}