/*
 * @Converter.cpp
 * @cift yonlu bagli liste uygulamasi
 * @Veri Yapilari 1.Ogretim
 * @odev 1
 * @06.11.2022
 * @Mustafa BICER mustafa.bicer1@ogr.sakarya.edu.tr
 */
#include "../../../include/other/Converter.hpp"
#include "StringMethod.hpp"
#include <string>
#include "fstream"

using namespace std;

Converter::Converter()
{
}

Converter::~Converter()
{
    delete this;
}
void Converter::rowIntParser(string row, SatirListesi *SatirList)
{
    int firstSpaceLoc = 0;
    int till = 0;
    int firstNumLoc = 0;

    try
    {
        do
        {
            if (row.find(' ', firstNumLoc) != string::npos)
            {
                firstSpaceLoc = row.find(' ', firstNumLoc);
                till = firstSpaceLoc - firstNumLoc + 1;
                SatirList->add(stoi(row.substr(firstNumLoc, till)));
                firstNumLoc = firstSpaceLoc + 1;
            }
            else
            {
                SatirList->add(stoi(row.substr(firstNumLoc, row.length() - firstNumLoc)));
                break;
            }

        } while (true);
    }
    catch (const std::exception &e)
    {
        // std::cerr << e.what() << '\n';
    }
}

void Converter::readingFromFile(Content *content)
{
    string temp0;
    fstream read;
    // open products.txt file in read mode
    // read.open("..//data//veriler.txt", ios::in);
    read.open("data/veriler.txt", ios::in);
    // sayıları dosyadan satır satır okumak.
    while (getline(read, temp0))
    {
        temp0 = StringMethod::trim(temp0);
        rowIntParser(temp0, content->SatirList);
        content->nextRow();
    }
    read.close();
}
