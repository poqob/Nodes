#include "iostream"
#include "iomanip"
#include "tabBar.hpp"
using namespace std;

int main()
{
    /*
        int index = 1;

        while (true)
        {
            system("cls");
            // setw istenilen sayıda boşluk bırakmak için kullanılabilir.
            cout << setw(index) << " "
                 << "^" << endl;
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
        }
    */
    int pageNum = 5;
    TabBar tabbar = TabBar();
    tabbar.draw(100, true);

    return 0;
}
