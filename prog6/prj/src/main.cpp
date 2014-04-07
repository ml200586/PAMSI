using namespace std;
#include "tab_asocjacyjna.hh"

/*!\mainpage
* Program wykonala Monika Litwin, nr indeksu 200586. 
* 
* Program realizuje tablicę asocjacyjną. W obiekcie typu vector przechowuje
* pary elementów - klucz typu string oraz wartość, która może być różnego 
* typu.
* 
\section etykieta-Wazne-cechy Najwazniejsze cechy
* Program zrealizowany został przy użyciu szablonów. Oznacza to, że możemy
* dopasowywać typ obiektu _value do aktualnych potrzeb. Program umożliwia 
* umieszczanie danych na tablicy, usuwanie ich z niej, wyszukiwanie konkretnych
* elementów oraz zamienianie ich, przeciążony został operator wyjścia, aby 
* umożliwić wypisanie całej tablicy.
*/

/*!
 * \file
 * \brief Modul zawierajacy definicje glownej funkcji programu.
 *										
 */
 /*!
 * \brief W funkcji main prezentowane jest użycie różnych funkcji 
 * zaimplementowanych w programie. Przedstawione zostało umieszczanie 
 * elementów w tablicy za pomocą funkcji DodajElement oraz z użyciem 
 * operatora, a także zamienianie i usuwanie elementów. Po każdej operacji 
 * tablica jest w całości wyświetlana.
 *										
 */
 
int main ()
{
	TabAsoc<int> tab;
	
	// Z uzyciem funkcji
	tab.DodajElement("pierwszy", 100);
	
	// Z uzyciem operatora
	tab["drugi"] = 300;
	
	tab["trzeci"] = 400;
	tab["czwarty"] = 250;
	tab["piaty"] = 700;
	cout<<"Całość: \n" << tab << endl;
	tab.ZamienElementy(1,2);
	cout<<"Całość po zamianie 2 i 3: \n" << tab << endl;
	tab.UsunElement("pierwszy");
	tab.UsunElement("piaty");
	cout<<"Całość po usunieciu 1 i 5: \n" << tab << endl;
}

/* 	
	char 'g'
	string "rfgrgr"
	int 1212	
*/
