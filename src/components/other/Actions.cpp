/*
 * @Actions.cpp
 * @cift yonlu bagli liste uygulamasi
 * @Veri Yapilari 1.Ogretim
 * @odev 1
 * @06.11.2022
 * @Mustafa BICER mustafa.bicer1@ogr.sakarya.edu.tr
 */
#include "Actions.hpp"

bool Actions::breakStatement = false; // it will break while loop when it has true value.
char Actions::tempChar = ' ';

// takes inputs as reference, via that reference controll method can access and controll our inputs.
void Actions::controll(char &ch, int &page, int &selection, int &maxSelectionOfCurrentPage, int &lastPage, bool &isLastPage, Content *content)
{
    // i used for loop to controll flow of the controll function. for loop turns only once.
    // the reason for i choose for loop to use 'break;' statement is to control 'k ' input.
    for (short i = 0; i < 1; i++)
    {
        // controll for walking around pages.
        // pressing and entering a-> go to previous page, d-> go to next page
        if (ch == 'a' && page != 1)
        {
            page--;
            selection = maxSelectionOfCurrentPage;
            isLastPage = false;
        }
        else if (ch == 'd')
        {
            if (page == lastPage)
            {
                isLastPage = true;
            }
            else
            {
                isLastPage = false;
                page++;
            }
            selection = 0;
        }
        // controll for current SatirListesi location .
        // pressing and entering c->next column, z->previous column
        if (ch == 'c' && selection != maxSelectionOfCurrentPage)
        {
            selection++;
        }
        else if (ch == 'z' && selection != 0)
        {
            selection--;
        }
        else if (ch == 'c' && selection == maxSelectionOfCurrentPage)
        {
            if (page != lastPage)
            {
                page++;
                selection = 0;
            }
        }
        else if (ch == 'z' && selection == 0)
        {
            if (page - 1 != 0)
            {
                page--;
                selection = maxSelectionOfCurrentPage;
            }
        }
        // updating current page's content number.
        maxSelectionOfCurrentPage = (content->YoneticiList->Count() - 8 * (page - 1) >= 7 ? 7 : (8 - abs(content->YoneticiList->Count() - 8 * page)) - 1);
        // controll for deleting operation in row-satirListesi
        // pressing and entering k-> delete random node from current SatirListesi,
        // p-> delete current SatirListesi and its parent YoneticiListesiNode form YoneticiListesi.
        // we expect that if the user press k only one time delete SatirListesiNode from current SaritListesi randomly.
        // if user have pressed second time the button, then delete SatirLsitesi object from YoneticiListesiNode-
        // second station applies for YoneticiListesiNode as well.
        if (ch == 'k')
        {
            // temporary variable- its purpose is prevent code repeating.
            YoneticiListesiNode yln = content->YoneticiList->elementAt((page - 1) * 8 + selection);
            // ZORT STATİON
            if (Actions::tempChar == ch)
            {
                if (yln.next == NULL && selection < maxSelectionOfCurrentPage)
                {
                    deleteNode(page, selection, content);
                    selection -= 1;
                }
                else if (yln.next == NULL && selection == 0 && page != 1)
                {
                    deleteNode(page, selection, content);
                    // selection -= 1;
                    page -= 1;
                }
                else if (yln.next == NULL && selection == maxSelectionOfCurrentPage) // BURADA kaldık UYKUM geldi
                {
                    /* code */
                }
                else
                    deleteNode(page, selection, content);

                // Runing Destructor.
                if (content->YoneticiList->isEmpty())
                {
                    system("cls");
                    std::cout << "*Listeler Bosaldi." << endl;
                    Actions::breakStatement = !Actions::breakStatement;
                }
                ch = ' ';
                Actions::tempChar = 'x';
                break;
            }

            srand(1);
            SatirListesi *cuurrent = yln.data; // temporary variable, its purpose is prevent code repeat.
            if (cuurrent->Count() <= 1)
            {
                if (yln.next == NULL && selection != 0)
                {
                    deleteNode(page, selection, content);
                    selection -= 1;
                }
                else if (yln.next == NULL && selection == 0 && page != 1)
                {
                    deleteNode(page, selection, content);
                    // selection -= 1;
                    page -= 1;
                }
                else if (yln.next != NULL)
                {
                    deleteNode(page, selection, content);
                }
            }
            else // deleting random satirListesiNode according to cuurrent.count
            {
                Actions::tempChar = 'x'; // we can pass anything but-except value 'k'
                cuurrent->removeAt(rand() % cuurrent->Count());
            }
            // Runing Destructor.
            if (content->YoneticiList->isEmpty())
            {
                system("cls");
                std::cout << "*Listeler Bosaldi." << endl;
                Actions::breakStatement = !Actions::breakStatement;
            }
        }
        // delete yoneticiListesiNode from yoneticiListesi
        if (ch == 'p')
        {
            int index = (page - 1) * 8 + selection;
            YoneticiListesiNode yln = content->YoneticiList->elementAt(index);
            if (yln.next == NULL && selection != 0)
            {
                deleteNode(page, selection, content);
                selection -= 1;
            }
            else if (yln.next == NULL && selection == 0 && yln.prev != NULL)
            {
                deleteNode(page, selection, content);
                // selection -= 1;
                page -= 1;
            }
            else if (yln.next == NULL && selection == maxSelectionOfCurrentPage) // BURADA kaldık UYKUM geldi
            {
                deleteNode(page, selection, content);
                page -= 1;
            }
            else
            {
                deleteNode(page, selection, content);
            }

            // Runing Destructor.
            if (content->YoneticiList->isEmpty())
            {
                system("cls");
                std::cout << "*Listeler Bosaldi." << endl;
                Actions::breakStatement = !Actions::breakStatement;
            }
        }
    }

    Actions::tempChar = ch;
}

void Actions::deleteNode(int &page, int &selection, Content *content)
{
    int index = (page - 1) * 8 + selection;
    content->YoneticiList->elementAt(index).data->~SatirListesi();
    content->YoneticiList->removeAt(index);
}
