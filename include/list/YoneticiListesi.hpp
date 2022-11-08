
#ifndef YONETICILISTESI
#define YONETICILISTESI

#include "YoneticiListesiNode.hpp"

class YoneticiListesi
{
private:
    YoneticiListesiNode *head;
    int size;

    YoneticiListesiNode *FindPreviousByPosition(int index)
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

public:
    YoneticiListesi()
    {
        head = NULL;
        size = 0;
    }
    int Count() const
    {
        return size;
    }
    bool isEmpty() const
    {
        return size == 0;
    }
    void add(SatirListesi *&item)
    {
        insert(size, item);
    }
    void insert(int index, SatirListesi *&item)
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
    SatirListesi *&first()
    {
        if (isEmpty())
            throw "No Such Element";
        return head->data;
    }
    SatirListesi *&last()
    {
        if (isEmpty())
            throw "No Such Element";
        return FindPreviousByPosition(size)->data;
    }
    int indexOf(const SatirListesi *&item)
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
    void remove(const SatirListesi *&item)
    {
        int index = indexOf(item);
        removeAt(index);
    }
    void removeAt(int index)
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
    bool find(const SatirListesi *&item)
    {
        for (YoneticiListesiNode *itr = head; itr != NULL; itr = itr->next)
        {
            if (itr->data == item)
                return true;
        }
        return false;
    }
    void reverse()
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
    void swap(int index1, int index2)
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
    YoneticiListesiNode elementAt(int index)
    {
        if (index < 0 || index >= size)
            throw "No Such Element";
        if (index == 0)
            return head->data;
        return FindPreviousByPosition(index)->next->data;
    }
    void clear()
    {
        while (!isEmpty())
            removeAt(0);
    }
    friend ostream &operator<<(ostream &screen, YoneticiListesi &rgt)
    {
        for (YoneticiListesiNode *itr = rgt.head; itr != NULL; itr = itr->next)
        {
            screen << itr->data << " <-> ";
        }
        screen << endl;
        return screen;
    }
    void printNodesFromPositionInReverseOrder(int index)
    {
        if (index < 0 || index >= size)
            throw "No Such Element";
        for (YoneticiListesiNode *itr = FindPreviousByPosition(index + 1); itr != NULL; itr = itr->prev)
        {
            cout << itr->data << " <-> ";
        }
        cout << endl;
    }
    void printReverseOrder()
    {
        printNodesFromPositionInReverseOrder(size - 1);
    }
    ~YoneticiListesi()
    {
        clear();
    }
};

#endif
