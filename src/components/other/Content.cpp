#include "../../../include/other/Content.hpp"

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
void Content::writing()
{
    for (int i = 0; i < YoneticiList->Count(); i++)
    {
        cout << YoneticiList->elementAt(i).data << endl;
    }
}
// ortalamalara gore sirala
void Content::putInOrder()
{
    // yonetici listesi düzeyinde satır listelerinin ayrı ayrı ortalama hesabı.
    // ortalamalara göre siraya koy.
    swap(YoneticiList);

    for (int i = 0; i < YoneticiList->Count(); i++)
    {
        // cout << contentAvarageCalculator(YoneticiListesi->elementAt(i)) << endl;
        // Satir listesini kendi arasinda kucukten buyuge siralar.-satir içi büyüklüğe göre siraya koy
        swapInRow(YoneticiList->elementAt(i).data);
        // writing content's in desc order and list's list in desc averages order.
        // cout << *YoneticiListesi->elementAt(i) << " avg " << contentAvarageCalculator(YoneticiListesi->elementAt(i)) << endl;
    }
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

// cizimini yaptigimiz buyuk kucuk yer degistirme algoritmasi. -satir listesi icin
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
// cizimini yaptigimiz buyuk kucuk yer degistirme algoritmasi. -yonetici listesi icin
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
