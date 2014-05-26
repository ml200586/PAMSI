#include "bst.hh"

 /*!
 * \file
 * \brief Definicje metod klasy BST.
 */

bool BST::Puste() const 
{ 
	return root==NULL;
}

void BST::dodaj(string adres, string d)
{
    node* t = new node;
    node* poprzedni;
    t->adres=adres;
    t->dane = d;
    t->lewy = NULL;
    t->prawy = NULL;
    poprzedni = NULL;
    
    if(Puste())
		root = t;
    else
    {
        node* obecny;
        obecny = root;
        while(obecny)
        {
           poprzedni = obecny;
           if(obecny->adres==adres)
           {
				obecny->dane=d;
				return;
		   }
           else if(t->adres > obecny->adres) 
				obecny = obecny->prawy;
           else 
				obecny = obecny->lewy;
        }
        if(t->adres < poprzedni->adres)
           poprzedni->lewy = t;
        else
           poprzedni->prawy = t;
    }
    _rozmiar++;
}

void BST::usun(string adres)
{
    bool znaleziono = false;
    if(Puste())
    {
        return;
    }
    
    node* obecny;
    node* poprzedni;
    obecny = root;
    
    while(obecny != NULL)
    {
         if(obecny->adres == adres)
         {
            znaleziono = true;
            break;
         }
         else
         {
             poprzedni = obecny;
             if(adres>obecny->adres) obecny = obecny->prawy;
             else obecny = obecny->lewy;
         }
    }
    if(!znaleziono)
    {
        return;
    }

    if((obecny->lewy == NULL && obecny->prawy != NULL)|| (obecny->lewy != NULL && obecny->prawy == NULL))
    {
       if(obecny->lewy == NULL && obecny->prawy != NULL)
       {
           if(poprzedni->lewy == obecny)
           {
             poprzedni->lewy = obecny->prawy;
             delete obecny;
           }
           else
           {
             poprzedni->prawy = obecny->prawy;
             delete obecny;
           }
       }
       else
       {
          if(poprzedni->lewy == obecny)
           {
             poprzedni->lewy = obecny->lewy;
             delete obecny;
           }
           else
           {
             poprzedni->prawy = obecny->lewy;
             delete obecny;
           }
       }
     _rozmiar--;
     return;
    }

		 if( obecny->lewy == NULL && obecny->prawy == NULL)
    {
        if(poprzedni->lewy == obecny) poprzedni->lewy = NULL;
        else poprzedni->prawy = NULL;
		 		 delete obecny;
		 		 _rozmiar--;
		 		 return;
    }

    if (obecny->lewy != NULL && obecny->prawy != NULL)
    {
        node* chkr;
        chkr = obecny->prawy;
        if((chkr->lewy == NULL) && (chkr->prawy == NULL))
        {
            obecny = chkr;
            delete chkr;
            _rozmiar--;
            obecny->prawy = NULL;
        }
        else
        {

            if((obecny->prawy)->lewy != NULL)
            {
                node* lobecny;
                node* lobecnyp;
                lobecnyp = obecny->prawy;
                lobecny = (obecny->prawy)->lewy;
                while(lobecny->lewy != NULL)
                {
                   lobecnyp = lobecny;
                   lobecny = lobecny->lewy;
                }
				obecny->adres = lobecny->adres;
                delete lobecny;
                _rozmiar--;
                lobecnyp->lewy = NULL;
           }
           else
           {
               node* tmp;
               tmp = obecny->prawy;
               obecny->dane = tmp->dane;
			   obecny->prawy = tmp->prawy;
               delete tmp;
           }

        }
		 _rozmiar--;
		 return;
    }

}

void BST::wyswietl_kolejno()
{
  kolejno(root);
}

void BST::kolejno(node* p)
{
    if(p != NULL)
    {
        if(p->lewy) 
			kolejno(p->lewy);
        cout<<" "<<p->dane<<endl;
        if(p->prawy) 
			kolejno(p->prawy);
    }
    else return;
}

bool BST::czy_jest(string adres)
{
	node* obecny;
    obecny = root;
	
	bool znaleziono = false;
    if(Puste())
        return false;
        
    while(obecny != NULL)
    {
         if(obecny->adres == adres)
         {
            znaleziono = true;
            break;
         }
         else
         {
             if(adres>obecny->adres) obecny = obecny->prawy;
             else obecny = obecny->lewy;
         }
    }
    if(!znaleziono)
    {
        return false;
    }
    return true;
}
