#include <iostream>
#include <stdlib.h>
#include "stos.hh"

/*!
 * \file
 * \brief Definicja klasy StosList, deklaracje metod klasy.
 * 
 * Plik zawiera definicje klasy StosList oraz deklaracje metod tej klasy.
 *  
*/

/*!
 *\brief Klasa realizujaca strukture danych - stos - za pomoca listy.
 * 
 * Jej zadaniem jest wprowadzenie danych na stos oraz usuwanie ich. 
 * Umozliwia takze wypisywanie stosu. Zawiera wewnetrzna strukture 
 * - Element.
*/
class StosList
{   
/*!
 *	\brief Struktura definiujaca liste.
 * 
 * Zawiera dwa pola: element listy(typu int) oraz wskaznik na poprzedni 
 * element.
*/ 
	struct Element 
	{
		int value;
		Element *prev; 
	}
/*!
 * \brief Wskaznik na ostatni element listy
 */
	*end;              
 
public:

/*!
 * \brief Konstruktor klasy StosList
 * 
 * Tworzy obiekt klasy StosList.
 */
	StosList();
	
 /*!
 *\brief Dodawanie wektora na stos
 * 
 *\param Wektor wekt - wektor do umieszczenia na stosie
 * 
 * Metoda odklada kolejno elementy wektora na wierzch stosu.
 * 
 */
	void Push(Wektor wekt);
	
 /*!
 *\brief Sprawdzanie czy stos jest pusty
 * 
 * Metoda, wykorzystujac wskaznik na ostatni element, sprawdza, czy stos 
 * jest pusty.
 * 
 *\return True - jesli stos jest pusty
 *\return False - jesli na stosie cos sie znajduje 
 */
	bool Is_Empty();
	
 /*!
 *\brief Zdejmowanie elementu ze stosu
 * 
 * Metoda usuwajaca element z gory stosu. W przypadku, gdy stos jest 
 * pusty, wyswietla stosowny komunikat.
 * 
 */
	void Pop();
	
 /*!
 *\brief Wypisywanie stosu
 * 
 * Metoda umozliwia wyswietlenie stosu.
 * 
 */
	void Wypisz();
	
/*!
 * \brief Destruktor klasy StosList
 * 
 * Likwiduje obiekt klasy StosList z pamieci komputera.
 */
	~StosList();
};



