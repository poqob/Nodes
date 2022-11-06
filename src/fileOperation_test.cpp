#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Converter.cpp"
using namespace std;

string trim(string clause)
{
    // satirin basinda bosluk karakteri varsa siler.
    if (clause[0] == ' ')
    {
        clause = clause.substr(1, clause.length() - 1);
    }
    // satirin sonunda bosluk karakteri varsa siler.
    if (clause[clause.length() - 1] == ' ')
    {
        clause.pop_back();
    }
    return clause;
}
int main()
{
    string temp0;
    fstream read;
    Converter *c = new Converter();
    int rownum = 0;
    Content *co = new Content();

    // open products.txt file in read mode
    read.open("..//data//veriler.txt", ios::in);
    // sayıları dosyadan satır satır okumak.
    while (getline(read, temp0))
    {
        temp0 = trim(temp0);

        rownum++;
    }

    c->rowIntParser(temp0, co->SatirListesi);
    cout << *co->SatirListesi;
    read.close();
    co->~Content();
    delete co;
    return 0;
}
