#ifndef SATIRLISTESI
#define SATIRLISTESI

#include "SatirListesiNode.hpp"
#include <iomanip>
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

    void swap(int index1, int index2); // siralama metodu-kucukten buyuge
    const int &elementAt(int index);
    void clear();
    friend std::ostream &operator<<(std::ostream &screen, SatirListesi &rgt);
    ~SatirListesi();
};

#endif
