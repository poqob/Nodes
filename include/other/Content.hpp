#if !defined(CONTENT)
#define CONTENT
#include "../list/DoublyLinkedList.hpp"
class Content
{
public:
    DoublyLinkedList<DoublyLinkedList<int> *> *YoneticiListesi;
    DoublyLinkedList<int> *SatirListesi;
    Content();
    ~Content();
    void nextRow();
    void writingAllElements();
    void putInOrder();
    void swapInRow(DoublyLinkedList<int> *);
    void swap(DoublyLinkedList<DoublyLinkedList<int> *> *);
    double contentAvarageCalculator(DoublyLinkedList<int> *);
};

#endif // CONTENT
