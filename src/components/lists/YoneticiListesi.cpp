/*
 * @YoneticiListesi.cpp
 * @cift yonlu bagli liste uygulamasi
 * @Veri Yapilari 1.Ogretim
 * @odev 1
 * @06.11.2022
 * @Mustafa BICER mustafa.bicer1@ogr.sakarya.edu.tr
 */
#include "../../../include/list/YoneticiListesi.hpp"
#include "YoneticiListesiNode.hpp"
#include <iostream>
using namespace std;
YoneticiListesi::YoneticiListesi()
{
    head = NULL;
    size = 0;
};

YoneticiListesiNode *YoneticiListesi::FindPreviousByPosition(int index)
{
    if (index < 0 || index > size)
        throw "No Such Element";
    YoneticiListesiNode *prv = head;
    int i = 1;
    for (YoneticiListesiNode *itr = head; itr->next != NULL && i != index; itr = itr->next, i++)
    {
        prv = prv->next;
    }
    return prv;
}

int YoneticiListesi::Count() const
{
    return size;
}

bool YoneticiListesi::isEmpty() const
{
    return size == 0;
}

void YoneticiListesi::add(SatirListesi *&item)
{
    insert(size, item);
}

void YoneticiListesi::insert(int index, SatirListesi *&item)
{
    if (index < 0 || index > size)
        throw "Index out of Range";
    if (index == 0)
    {
        head = new YoneticiListesiNode(item, head);
        if (head->next != NULL)
            head->next->prev = head;
    }
    else
    {
        YoneticiListesiNode *prv = FindPreviousByPosition(index);
        prv->next = new YoneticiListesiNode(item, prv->next, prv);
        if (prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}

SatirListesi *&YoneticiListesi::first()
{
    if (isEmpty())
        throw "No Such Element";
    return head->data;
}

SatirListesi *&YoneticiListesi::last()
{
    if (isEmpty())
        throw "No Such Element";
    return FindPreviousByPosition(size)->data;
}

int YoneticiListesi::indexOf(const SatirListesi *&item)
{
    int index = 0;
    for (YoneticiListesiNode *itr = head; itr != NULL; itr = itr->next)
    {
        if (itr->data == item)
            return index;
        index++;
    }
    throw "No Such Element";
}

void YoneticiListesi::remove(const SatirListesi *&item)
{
    int index = indexOf(item);
    removeAt(index);
}

void YoneticiListesi::removeAt(int index)
{
    if (index < 0 || index >= size)
        throw "Index out of Range";
    YoneticiListesiNode *del;
    if (index == 0)
    {
        del = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        YoneticiListesiNode *prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    delete del;
}

bool YoneticiListesi::find(const SatirListesi *&item)
{
    for (YoneticiListesiNode *itr = head; itr != NULL; itr = itr->next)
    {
        if (itr->data == item)
            return true;
    }
    return false;
}

void YoneticiListesi::reverse()
{
    for (YoneticiListesiNode *itr = head; itr != NULL;)
    {
        YoneticiListesiNode *tmp = itr->next;
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
void YoneticiListesi::swap(int index1, int index2)
{
    if (index1 + 1 < 0 || index1 >= size)
        throw "No Such Element";
    if (index2 + 1 < 0 || index2 >= size)
        throw "No Such Element";
    YoneticiListesiNode *tmp = new YoneticiListesiNode(0); // may it throws exception

    YoneticiListesiNode *crnt1 = FindPreviousByPosition(index1 + 1);
    YoneticiListesiNode *crnt2 = FindPreviousByPosition(index2 + 1);
    // cout << crnt1->data << " " << crnt2->data << endl;
    tmp->data = crnt1->data;
    crnt1->data = crnt2->data;
    crnt2->data = tmp->data;
    // cout << crnt1->data << " " << crnt2->data << endl;
    delete tmp, crnt1, crnt2;
}

YoneticiListesiNode YoneticiListesi::elementAt(int index)
{
    if (index < 0 || index >= size)
        throw "No Such Element";
    if (index == 0)
        return head->data;
    return FindPreviousByPosition(index)->next->data;
}

void YoneticiListesi::clear()
{
    while (!isEmpty())
        removeAt(0);
}

void YoneticiListesi::printNodesFromPositionInReverseOrder(int index)
{
    if (index < 0 || index >= size)
        throw "No Such Element";
    for (YoneticiListesiNode *itr = FindPreviousByPosition(index + 1); itr != NULL; itr = itr->prev)
    {
        cout << itr->data << " <-> ";
    }
    cout << endl;
}
void YoneticiListesi::printReverseOrder()
{
    printNodesFromPositionInReverseOrder(size - 1);
}

YoneticiListesi::~YoneticiListesi()
{
    clear();
}
