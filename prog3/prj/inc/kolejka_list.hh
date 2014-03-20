#include <iostream>
#include "stos_list.hh"

/*!
 * \file
 * \brief Definicja klasy KolejkaList, deklaracje metod klasy.
 * 
 * Plik zawiera definicje klasy KolejkaList oraz deklaracje metod tej klasy.
 *  
*/

/*!
 *	\brief Klasa realizujaca strukture danych - kolejka - za pomoca listy.
 * 
 * Jej zadaniem jest wprowadzenie danych do kolejki oraz usuwanie ich. 
 * Umozliwia takze wypisywanie kolejki. Zawiera wewnetrzna strukture 
 * - Element.
*/

class KolejkaList
{   

/*!
 *	\brief Struktura definiujaca liste.
 * 
 * Zawiera dwa pola: element listy(typu int) oraz wskaznik na nastepny 
 * element.
*/  
	struct Element 
	{
		int wartosc;
		Element *next;  
	}
	
/*!
 * \brief Wskaznik na pierwszy element listy
 */
	*first;         
 
public:

/*!
 * \brief Konstruktor klasy KolejkaList
 * 
 * Tworzy obiekt klasy KolejkaList.
 */
	KolejkaList();
	
 /*!
 *\brief Dodawanie wektora do kolejki
 * 
 *\param Wektor wekt - wektor do umieszczenia w kolejce
 * 
 * Metoda odklada kolejno elementy wektora na koniec kolejki.
 * 
 */
	void Enqueue(Wektor wekt);
	
 /*!
 *\brief Zdejmowanie elementu z kolejki
 * 
 * Metoda usuwajaca element z poczatku kolejki. W przypadku, gdy kolejka 
 * jest pusta, wyswietla stosowny komunikat.
 * 
 */
	void Dequeue();
	
 /*!
 *\brief Wypisywanie kolejki
 * 
 * Metoda umozliwia wyswietlenie kolejki.
 * 
 */
	void Wypisz();
	
 /*!
 *\brief Sprawdzanie czy kolejka jest pusta
 * 
 * Metoda, wykorzystujac wskaznik na pierwszy element, sprawdza, czy kolejka 
 * jest pusta.
 * 
 *\return True - jesli kolejka jest pusta
 *\return False - jesli w kolejce cos sie znajduje 
 */
	bool Is_Empty();
	
/*!
 * \brief Destruktor klasy KolejkaList
 * 
 * Likwiduje obiekt klasy KolejkaList z pamieci komputera.
 */
	~KolejkaList();
};

