
#ifndef YONETICILISTESI
#define YONETICILISTESI

#include "YoneticiListesiNode.hpp"

class YoneticiListesi
{
private:
    int size;
    YoneticiListesiNode *FindPreviousByPosition(int);

public:
    YoneticiListesiNode *head;

    YoneticiListesi();
    int Count() const;
    bool isEmpty() const;
    void add(SatirListesi *&);
    void insert(int index, SatirListesi *&);
    SatirListesi *&first();
    SatirListesi *&last();
    int indexOf(const SatirListesi *&);
    void remove(const SatirListesi *&);
    void removeAt(int);
    bool find(const SatirListesi *&);
    void reverse();
    // siralama metodu-kucukten buyuge
    void swap(int, int);
    YoneticiListesiNode elementAt(int);
    void clear();
    // friend ostream &operator<<(ostream &screen, YoneticiListesi &rgt);
    void printNodesFromPositionInReverseOrder(int);
    void printReverseOrder();
    ~YoneticiListesi();
};

#endif
