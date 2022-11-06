#include <iostream>
#include <fstream>
#include <iomanip>
#include "Converter.cpp"
#include "Content.cpp"
#include "StringMethod.cpp"
using namespace std;

int main()
{
    string temp0;
    fstream read;
    Converter *c = new Converter();
    Content *co = new Content();

    // open products.txt file in read mode
    read.open("..//data//veriler.txt", ios::in);
    // sayıları dosyadan satır satır okumak.
    while (getline(read, temp0))
    {
        temp0 = StringMethod::trim(temp0);
        c->rowIntParser(temp0, co->SatirListesi);
        }

    cout << *co->SatirListesi;
    read.close();
    co->~Content();
    delete co;
    delete c;
    return 0;
}
