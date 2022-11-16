#include "locationArrow.hpp"
using namespace std;

int main()
{
    string lul = "---------    ------------               ----------------";
    string arrow = "";
    int loc1 = 0;
    int wantetPart = 2;

    for (int j = 0; j < wantetPart; j++)
    {
        if (wantetPart != 0)
            loc1 = lul.find(" -", loc1 + 1) + 1;
        else
            loc1 = 0;
    }

    for (int i = loc1; i < lul.length(); i++)
    {
        if (lul.at(i) != ' ')
        {
            arrow.append("^");
        }
        else
            break;
    }
    cout << lul << "\n"
         << string(loc1, ' ')
         << arrow << loc1 << " " << lul.length();
    return 0;
}