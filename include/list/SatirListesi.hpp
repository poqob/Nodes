#ifndef SATIRLISTESI
#define SATIRLISTESI

#include "SatirListesiNode.hpp"

class SatirListesi
{
private:
    int size;

    SatirListesiNode *FindPreviousByPosition(int index);

public:
    SatirListesi();
    SatirListesiNode *head;
    int Count() const;
    bool isEmpty() const;
    void add(const int &item);
    void insert(int index, const int &item);
    const int &first();
    const int &last();
    int indexOf(const int &item);
    void remove(const int &item);
    void removeAt(int index);
    bool find(const int &item);
    void reverse();
    // siralama metodu-kucukten buyuge
    void swap(int index1, int index2);
    const int &elementAt(int index);
    void clear();
    friend ostream &operator<<(ostream &screen, SatirListesi &rgt);
    void printNodesFromPositionInReverseOrder(int index);
    void printReverseOrder();
    ~SatirListesi();
};

#endif
