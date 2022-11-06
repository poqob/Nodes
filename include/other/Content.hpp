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

Content::Content(/* args */)
{
    YoneticiListesi = new DoublyLinkedList<DoublyLinkedList<int>>();
    SatirListesi = new DoublyLinkedList<int>();
}

Content::~Content()
{
    delete YoneticiListesi;
    delete SatirListesi;
    delete this;
}

#endif // CONTENT
