#if !defined(CONTENT)
#define CONTENT
#include "../list/DoublyLinkedList.hpp"
class Content
{
public:
    DoublyLinkedList<DoublyLinkedList<int>> *YoneticiListesi;
    DoublyLinkedList<int> *SatirListesi;
    Content();
    ~Content();
};

#endif // CONTENT
