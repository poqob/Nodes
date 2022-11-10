#include "../../src/YoneticiListesi.cpp"
#include "../../src/SatirListesi.cpp"
#include "../ui/ListBuilders/adressBuilder.cpp"
using namespace std;

int main()
{

    YoneticiListesi *y = new YoneticiListesi();
    SatirListesi *s = new SatirListesi();
    SatirListesi *s2 = new SatirListesi();
    SatirListesi *s3 = new SatirListesi();

    s->add(1);
    s->add(2);
    s->add(3);
    s2->add(4);
    s2->add(5);
    s2->add(6);
    s3->add(6);
    y->add(s);
    y->add(s2);
    y->add(s3);
    y->add(s3);
    AdressBuilder *adr = new AdressBuilder(y, 2);

    cout << "satirlistesi:" << s << endl;                                           // satir listesi adresi
    cout << "satirlistesi2:" << s2 << endl;                                         // satir listesi adresi
    cout << "satirlistesi2:" << *s2 << endl;                                        // satir listesi adresinin cozumlenmis hali
    cout << "yoneticiListesi:" << y << endl;                                        // yonetici listesi adresi
    cout << "*yoneticiListesiIci:" << *y << endl;                                   // yonetici listesinin içindeki yonetici listesi dugumu adresleri
    cout << "*head->next:" << *y->head->next->data << endl;                         // yonetici listesinin headinin nexti- yonetici listesi dugumu adresi dondurmekte 0. elemena denktir.
    cout << "*head->next->next->prev:" << *y->head->next->next->prev->data << endl; // 0. elemena denktir. bunlar yln
    cout << "adressBuilderFunc2: " << *adr->yonetici;
    cout << "adressBuilderFunc2: " << *adr;
    adr->pageNum = 1;
    cout << "adressBuilderFunc3: " << adr->yonetici->head << " " << adr->yonetici->head->next->next;
    cout << "adressBuilderFunc2: " << *adr;
    return 0;
}
// amac
// yonetici dugumun:
// prev+
// next+
// bilgilerine erismek+

// ikinci amac
// satir listesi için de aynısının yapılabilmesi
