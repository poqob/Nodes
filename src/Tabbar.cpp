#include "../include/ui/tabBar/tabBar.hpp"

TabBar::TabBar(int page, bool lastPage = false)
{
    draw(page, lastPage);
}
string
TabBar::barArangement(int pageNum, bool lastPage)
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

void TabBar::draw(int page, bool lastPage)
{
    cout << barArangement(page, lastPage) << endl;
}