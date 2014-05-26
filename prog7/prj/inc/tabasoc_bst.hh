#include "funkcje.hh"
#include "bst.hh"

class TabAsoc_BST
{
public:

BST drzewo;

int Rozmiar();

bool CzyJest(string adres);

bool DodajElement(string adres_dod, int dane);

bool UsunElement(string adres);
};
