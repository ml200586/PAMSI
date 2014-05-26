#include <iostream>
#include <stdlib.h>
using namespace std;

 /*!
 * \file
 * \brief Zawiera definicje klasy BST i jej metody.
 */


class BST
{
    public:
    
        struct node
        {
           node* lewy;
           node* prawy;
		   string adres;
           string dane;
        };
        
        node* root;
    
    public:
    
		int _rozmiar;
		
        BST()
        {	root = NULL;
           _rozmiar = 0;}
       
        bool Puste() const;
        
        void wyswietl_kolejno();
        
        void kolejno(node* gal);
        
        void dodaj(string adres, string d);
        
        void usun(string adres);
        
        bool czy_jest(string adres);
};
