#include "../../../include/ui/ListBuilders/YLB.hpp"

YLB::YLB(YoneticiListesi *yoneticiListesi, int page)
{
    this->yoneticiListesi = yoneticiListesi;
    // draw(page);
}

double YLB::averageCalculator(SatirListesi *satirListesi)
{
    double average = 0;
    for (int i = 0; i < satirListesi->Count(); i++)
    {
        average += satirListesi->elementAt(i);
    }
    return average / satirListesi->Count();
}

string YLB::createUnderline(string input)
{
    string underlines = "";
    int cizgi = 0;
    int bosluk = 0;
    for (int i = 0; i < input.length() - 1; i++)
    {
        if (input.at(i) != ' ')
        {
            underlines.append(string(bosluk, ' '));
            bosluk = 0;
            cizgi++;
            // underlines.push_back('-');
        }
        else
        {
            underlines.append(string(cizgi, '-'));
            cizgi = 0;
            bosluk++;
        }
    }
    return underlines;
}
// TODO: knks burayı zortlatmalıyız sıkıntı var
string YLB::createAdresses(int pageNum)
{
    stringstream result;
    string output;
    int i = 0;
    for (YoneticiListesiNode *itr = yoneticiListesi->head; itr != NULL; itr = itr->next)
    {
        result << " " << itr << "     ";
        i++;
        if (i % 8 == 0)
            result << endl;
    }
    result << endl;
    for (int j = 0; j < pageNum; j++)
    {
        getline(result, output);
    }
    return output;
}

string YLB::createPrevAdress(int pageNum)
{
    stringstream result;
    string output;
    stringstream tmp;
    string tmps = "";
    int i = 0;
    for (YoneticiListesiNode *itr = yoneticiListesi->head; itr != NULL; itr = itr->next)
    {
        tmp << itr->prev;
        tmps = tmp.str() == "0" ? "00000000" : tmp.str();
        result << "|" << tmps << "|"
               << "    ";
        tmp.str("");
        i++;
        if (i % 8 == 0)
            result << endl;
    }
    result << endl;
    for (int j = 0; j < pageNum; j++)
    {
        getline(result, output);
    }
    return output;
}

string YLB::createNextAdress(int pageNum)
{
    stringstream result;
    string output;
    stringstream tmps;
    string tmp;
    int i = 0;
    for (YoneticiListesiNode *itr = yoneticiListesi->head; itr != NULL; itr = itr->next)
    {
        tmps << itr->next;
        tmp = tmps.str() == "0" ? "00000000" : tmps.str();
        tmps.str("");

        result << "|" << tmp << "|"
               << "    ";
        i++;
        if (i % 8 == 0)
            result << endl;
    }
    result << endl;
    for (int j = 0; j < pageNum; j++)
    {
        getline(result, output);
    }
    return output;
}
// adres uzunluguna aglı olarak problem cikabilir.
string YLB::createAvarages(int pageNum, string prevLine)
{

    // satir listesi ortalamalarini yazdiracağimiz bolmenin/satirin genislik oryantasyonu.
    stringstream result;
    string output;
    result << "|";

    // sag '|' karakterleri yaratan metot.
    for (int k = 1; k < prevLine.length(); k++)
    {

        if (prevLine.at(k) != ' ' && prevLine.at(k + 1) == ' ')
        {
            result << "|";
        }
        else
            result << " ";
    }
    output = result.str();

    // sol '|' yaratmak.
    for (int k = prevLine.length() - 1; k > 1; k--)
    {
        if (prevLine.at(k) != ' ' && prevLine.at(k - 1) == ' ')
        {
            output.erase(k, 1);
            output.insert(k, "|");
        }
    }

    // avg hesabini yazdirmak.
    int firstlLoc = 1;
    string avg;
    int secondLoc;
    int dest = 8;
    for (int o = (pageNum - 1) * 8; o < (pageNum)*8 && o < yoneticiListesi->Count(); o++)
    {

        avg = to_string(averageCalculator(yoneticiListesi->elementAt(o).data));
        avg.erase(dest);
        output.erase(firstlLoc, avg.length());
        output.insert(firstlLoc, avg);
        firstlLoc = output.find('|', firstlLoc + 1);
        secondLoc = output.find('|', firstlLoc + 1);
        firstlLoc = output.find('|', secondLoc) + 1;
    }

    return output;
}

void YLB::draw(YoneticiListesi *yl, int pageNum)
{
    yoneticiListesi = yl;
    string adressOfCurrentYlNode = createAdresses(pageNum);
    string adressOfPrevNode = createPrevAdress(pageNum);
    string adressOfNextNode = createNextAdress(pageNum);
    string averagesOfSlNode = createAvarages(pageNum, adressOfPrevNode);
    cout << adressOfCurrentYlNode << endl;
    cout << createUnderline(adressOfCurrentYlNode) << endl;
    cout << adressOfPrevNode << endl;
    cout << createUnderline(adressOfPrevNode) << endl;
    cout << averagesOfSlNode << endl;
    cout << createUnderline(averagesOfSlNode) << endl;
    cout << adressOfNextNode << endl;
    cout << createUnderline(adressOfNextNode) << endl;
    lastUnderLine = createUnderline(adressOfNextNode);
}

YLB::~YLB()
{
    // delete this;
}

/*
Yonetici Liste yazdırma stili:

yonetici listesi node prev->next adresleri taransın
---------------------------------------------------
yonetici listesi node prev
---------------------------------------------------
yonetilistesi node içindeki satırListesi ortalama hespaları
---------------------------------------------------
yonetici listesi node next
---------------------------------------------------
*/

// ADRESS BELEKTE SILINDI MI TAKIP EDILSIN

// TODO: yazdırılan adresslerin sagına ve soluna birer - daha eklenecek
// yazdırılan prev adreslerinin basına ve sonuna | eklenecek