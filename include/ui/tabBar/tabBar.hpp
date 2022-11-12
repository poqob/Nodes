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
    string barArangement(int, bool);
    int pageIndex = 0;

public:
    void draw(int, bool);

    TabBar(int, bool);
};

#endif // TABBAR
