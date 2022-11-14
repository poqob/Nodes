#include "../../../include/list/SatirListesi.hpp"
using namespace std;
SatirListesiNode *SatirListesi::FindPreviousByPosition(int index)
{
    if (index < 0 || index > size)
        throw "No Such Element";
    SatirListesiNode *prv = head;
    int i = 1;
    for (SatirListesiNode *itr = head; itr->next != NULL && i != index; itr = itr->next, i++)
    {
        prv = prv->next;
    }
    return prv;
}

SatirListesi::SatirListesi()
{
    head = NULL;
    size = 0;
}

int SatirListesi::Count() const
{
    return size;
}
bool SatirListesi::isEmpty() const
{
    return size == 0;
}
void SatirListesi::add(const int &item)
{
    insert(size, item);
}
void SatirListesi::insert(int index, const int &item)
{
    if (index < 0 || index > size)
        throw "Index out of Range";
    if (index == 0)
    {
        head = new SatirListesiNode(item, head);
        if (head->next != NULL)
            head->next->prev = head;
    }
    else
    {
        SatirListesiNode *prv = FindPreviousByPosition(index);
        prv->next = new SatirListesiNode(item, prv->next, prv);
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}
const int &SatirListesi::first()
{
    if (isEmpty())
        throw "No Such Element";
    return head->data;
}
const int &SatirListesi::last()
{
    if (isEmpty())
        throw "No Such Element";
    return FindPreviousByPosition(size)->data;
}
int SatirListesi::indexOf(const int &item)
{
    int index = 0;
    for (SatirListesiNode *itr = head; itr != NULL; itr = itr->next)
    {
        if (itr->data == item)
            return index;
        index++;
    }
    throw "No Such Element";
}
void SatirListesi::remove(const int &item)
{
    int index = indexOf(item);
    removeAt(index);
}
void SatirListesi::removeAt(int index)
{
    if (index < 0 || index >= size)
        throw "Index out of Range";
    SatirListesiNode *del;
    if (index == 0)
    {
        del = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        SatirListesiNode *prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    delete del;
}
bool SatirListesi::find(const int &item)
{
    for (SatirListesiNode *itr = head; itr != NULL; itr = itr->next)
    {
        if (itr->data == item)
            return true;
    }
    return false;
}
void SatirListesi::reverse()
{
    for (SatirListesiNode *itr = head; itr != NULL;)
    {
        SatirListesiNode *tmp = itr->next;
        itr->next = itr->prev;
        itr->prev = tmp;
        if (tmp == NULL)
        {
            head = itr;
            break;
        }
        itr = tmp;
    }
}
// siralama metodu-kucukten buyuge
void SatirListesi::swap(int index1, int index2)
{
    if (index1 + 1 < 0 || index1 >= size)
        throw "No Such Element";
    if (index2 + 1 < 0 || index2 >= size)
        throw "No Such Element";
    SatirListesiNode *tmp = new SatirListesiNode(0);

    SatirListesiNode *crnt1 = FindPreviousByPosition(index1 + 1);
    SatirListesiNode *crnt2 = FindPreviousByPosition(index2 + 1);
    // cout << crnt1->data << " " << crnt2->data << endl;
    tmp->data = crnt1->data;
    crnt1->data = crnt2->data;
    crnt2->data = tmp->data;
    // cout << crnt1->data << " " << crnt2->data << endl;
    delete tmp, crnt1, crnt2;
}
const int &SatirListesi::elementAt(int index)
{
    if (index < 0 || index >= size)
        throw "No Such Element";
    if (index == 0)
        return head->data;
    return FindPreviousByPosition(index)->next->data;
}
void SatirListesi::clear()
{
    while (!isEmpty())
        removeAt(0);
}

void SatirListesi::printNodesFromPositionInReverseOrder(int index)
{
    if (index < 0 || index >= size)
        throw "No Such Element";
    for (SatirListesiNode *itr = FindPreviousByPosition(index + 1); itr != NULL; itr = itr->prev)
    {
        cout << itr->data << " <-> ";
    }

    cout
        << endl;
}
void SatirListesi::printReverseOrder()
{
    printNodesFromPositionInReverseOrder(size - 1);
}
SatirListesi::~SatirListesi()
{
    clear();
}