#if !defined(TABBAR)
#define TABBAR

// sayfa yönlendirici parçası burada çizdirilecek.
#include "iostream"
#include "iomanip"
#include "sstream"
using namespace std;

// 10 karakter liste goruntuleme
// bir sayfada yan yana 8 liste=80 karakter
// bu listelerin arasındaki boşluklar 4 karakter olsa =4*7=28 karakter.
// baş ve sondan 1'er karakter boşluk bıraksak=2 karakter -listeler için-
// toplam=110 karakterlik bir yapı.
// bu 110 karakterlik yapıya 110 karakterlik bir de üst çizgi-tabbar-gider :D
class TabBar
{
private:
    string barArangement(int, bool);
    int pageIndex = 0;

public:
    void draw(int, bool);
};

string TabBar::barArangement(int pageNum, bool lastPage)
{
    stringstream result;
    stringstream first;
    if (pageNum == 0)
        first << "ilk sayfa";
    else if (lastPage && pageNum != 0)
        first << pageNum << " sonuncu sayfa";
    else
        first << pageNum << ".sayfa";

    string second =
        (lastPage) ? "<---" : "--->";

    result << first.str() << setw(110 - first.str().length() - 4) << second;
    return result.str();
}

void TabBar::draw(int page, bool lastPage = false)
{
    cout << barArangement(page, lastPage) << endl;
}

#endif // TABBAR
