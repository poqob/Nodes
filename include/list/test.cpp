#include "../../src/YoneticiListesi.cpp"
#include "../../src/SatirListesi.cpp"
using namespace std;

int main()
{

    YoneticiListesi *y = new YoneticiListesi();
    SatirListesi *s = new SatirListesi();
    SatirListesi *s2 = new SatirListesi();

    s->add(1);
    s->add(2);
    s->add(3);
    s2->add(4);
    s2->add(5);
    s2->add(6);
    y->add(s);
    y->add(s2);
    y->add(s);

    cout << "satirlistesi:" << s << endl;                                    // satir listesi adresi
    cout << "satirlistesi2:" << s2 << endl;                                  // satir listesi adresi
    cout << "satirlistesi2:" << *s2 << endl;                                 // satir listesi adresinin cozumlenmis hali
    cout << "yoneticiListesi:" << y << endl;                                 // yonetici listesi adresi
    cout << "*yoneticiListesiIci:" << *y << endl;                            // yonetici listesinin içindeki yonetici listesi dugumu adresleri
    cout << "*head->next:" << y->head->next << endl;                         // yonetici listesinin headinin nexti- yonetici listesi dugumu adresi dondurmekte 0. elemena denktir.
    cout << "*head->next->next->prev:" << y->head->next->next->prev << endl; // 0. elemena denktir. bunlar yln
    cout << "*yoneticiListesiNode:" << endl;
    return 0;
}
// amac
// yonetici dugumun:
// prev+
// next+
// bilgilerine erismek+

// ikinci amac
// satir listesi için de aynısının yapılabilmesi
