
#ifndef YONETICILISTESI
#define YONETICILISTESI

#include "YoneticiListesiNode.hpp"

class YoneticiListesi
{
private:
    int size;
    YoneticiListesiNode *FindPreviousByPosition(int index);

public:
    YoneticiListesiNode *head;

    YoneticiListesi();
    int Count() const;
    bool isEmpty() const;
    void add(SatirListesi *&item);
    void insert(int index, SatirListesi *&item);
    SatirListesi *&first();
    SatirListesi *&last();
    int indexOf(const SatirListesi *&item);
    void remove(const SatirListesi *&item);
    void removeAt(int index);
    bool find(const SatirListesi *&item);
    void reverse();
    // siralama metodu-kucukten buyuge
    void swap(int index1, int index2);
    YoneticiListesiNode elementAt(int index);
    void clear();
    friend ostream &operator<<(ostream &screen, YoneticiListesi &rgt);
    void printNodesFromPositionInReverseOrder(int index);
    void printReverseOrder();
    ~YoneticiListesi();
};

#endif
