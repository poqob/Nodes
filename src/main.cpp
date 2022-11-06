#include <iostream>
#include <iomanip>
#include "DoublyLinkedList.hpp"
using namespace std;

int main()
{
    string msg;
    DoublyLinkedList<int> *list = new DoublyLinkedList<int>();

    cout << *list;

    /*
        int index = 1;
        while (true)
        {
            // Her işlemden sonra ekran temizlenecek. Sadece windows işletim sisteminde çalışır.
            system("cls");
            // Daha sonra güncel görüntü ekrana çıkarılacak
            // setw istenilen sayıda boşluk bırakmak için kullanılabilir. cout << setw(index) << " "<<"^"<<endl;
            cout << setw(index) << " "
                 << "|" << endl;
            // Kullanıcı girişi okunacak.
            char ch;
            cin >> ch;
            // Kullanıcı girişine göre sisteme güncelleme yapılacak
            if (ch == 'a')
                index--;
            else if (ch == 'd')
                index++;
            cout << index;
        }*/
    return 0;
}