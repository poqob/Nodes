#include "../../include/other/actions.hpp"
// takes inputs as reference, via that reference controll method can access and controll our inputs.
void Actions::controll(char &ch, int &page, int &selection, int &maxSelectionOfCurrentPage, int &lastPage, bool &isLastPage, Content *content)
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
    if (ch == 'k')
    {
        srand(1);
        SatirListesi *cuurrent = content->YoneticiList->elementAt((page - 1) * 8 + selection).data;
        if (cuurrent->Count() <= 1)
        {
            content->YoneticiList->elementAt((page - 1) * 8 + selection).data->~SatirListesi();
            content->YoneticiList->removeAt((page - 1) * 8 + selection);
            if (content->YoneticiList->elementAt((page - 1) * 8 + selection).next == NULL && selection != 0)
                selection -= 1;
            if (content->YoneticiList->elementAt((page - 1) * 8 + selection).next == NULL && selection == 0 && page != 1)
            {
                selection -= 1;
                page -= 1;
            }
        }
        else
            cuurrent->removeAt(rand() % cuurrent->Count());
    }
    // delete yoneticiListesiNode from yoneticiListesi
    if (ch == 'p')
    {
        content->YoneticiList->elementAt((page - 1) * 8 + selection).data->~SatirListesi();
        content->YoneticiList->removeAt((page - 1) * 8 + selection);
        if (content->YoneticiList->elementAt((page - 1) * 8 + selection).next == NULL && selection != 0)
            selection -= 1;
        if (content->YoneticiList->elementAt((page - 1) * 8 + selection).next == NULL && selection == 0 && page != 1)
        {
            selection -= 1;
            page -= 1;
        }
    }
}