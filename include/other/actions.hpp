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
    static void controll(char &, int &, int &, int &, int &, bool &, Content *); // controlling key inputs and taking action to them.
    static void deleteNode(int &, int &, Content *);                             // i wrote it to prevent code repeating.
    static bool breakStatement;                                                  // program break statement.
    static char tempChar;                                                        // regedit char to controlling 'k' button. -if 'k' pressed twice delete current yl node-
};

#endif // ACTIONS
