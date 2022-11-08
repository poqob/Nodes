#include <iostream>
#include "YoneticiListesi.hpp"
#include "SatirListesi.hpp"

using namespace std;
int main()
{
    SatirListesi *a = new SatirListesi();

    a->add(1);
    a->add(2);
    a->add(3);
    cout << *a << endl;

    YoneticiListesi *y = new YoneticiListesi();
    y->add(a);
    cout << *y->first();
    return 0;
}