#if !defined(TABBAR)
#define TABBAR

// sayfa yönlendirici parçası burada çizdirilecek.
#include "iostream"
#include "iomanip"
#include "sstream"
using namespace std;
class TabBar
{
private:
    string barArangement(int, bool); // returns bar itself.
    int pageIndex = 0;               // storing page index, use this in draw() method.

public:
    void draw(int, bool); // draws bar-barArangement();
    TabBar();             // constructor
    // i didn't define constructor because i have not planned to use this class on heap.
};

#endif // TABBAR
