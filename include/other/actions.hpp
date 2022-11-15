// anahtar karakterlerin aksiyonları burada bulunacak
// a-d sayfa değiştirme
// z-c sayfa içinde liste değiştirme
// k görüntülenen satır listesi içerisinden rastgele eleman silme aksiyon
// p  görüntülenen satır listesini yonetici listesinden silme aksiyonu

#if !defined(ACTIONS)
#define ACTIONS
#include "iostream"
#include "sstream"
#include "Content.hpp"
#include <stdlib.h>
using namespace std;
class Actions
{
public:
    static void controll(char &, int &, int &, int &, int &, bool &, Content *);
    static void deleteNode(int &, int &, Content *);
    static bool breakStatement;
    static char tempChar;
};

#endif // ACTIONS
