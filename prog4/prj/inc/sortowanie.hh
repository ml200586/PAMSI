#include "kolejka.hh"

 /*!
 * \file
 * \brief Deklaracje funkcji sortowania Quick, Merge i Heap.
 *  
*/
 
 
/*!
*\brief Funkcja sortowania - Quicksort
* 
* \param Wektor &wekt - wektor, ktorego elementy mają być posortowane, 
* 						przekazywany przez referencje
* \param int lewy - numer pierwszego elementu z zakresu do posortowania
* \param int prawy - numer ostatniego elementu z zakresu do posortowania
* 
* Funkcja realizuje algorytm sortowania szybkiego. Ustala srodkowy
* element, nastepnie od poczatku wektora wyszukuje element wiekszy 
* od srodkowego, a od konca - mniejszy od niego. Jesli takie znajdzie 
* - zamienia je ze soba miejscami. Tak sie dzieje dopoki indeks zmienna 
* sluzaca do wyszukiwania mniejszego nie bedzie wieksza od tej sluzacej 
* do wyszukiwania wiekszego. Wtedy Quicksort zostaje wywolana ponownie 
* dla wektora bedacego pierwsza polowa i drugie wywolanie dla tego bedacego 
* druga polowa poczatkowego wektora do posortowania.
* 
*/
 void Quicksort (Wektor &wekt, int lewy, int prawy);

/*!
*\brief Funkcja sortowania - Mergesort
* 
* \param Wektor &we - wektor, ktorego elementy mają być posortowane, 
* 						przekazywany przez referencje
* \param Wektor pom - wektor pomocniczy
* \param int lewy - numer pierwszego elementu z zakresu do posortowania
* \param int prawy - numer ostatniego elementu z zakresu do posortowania
* 
* Funkcja realizuje algorytm sortowania przez scalanie. Ustala srodek 
* i wywoluje sie ponownie dwa razy, ze zmienionymi parametrami - dla nowych 
* wektorow: z tym samym poczatkiem i srodkiem poprzedniego jako koniec oraz 
* z tym samym koncem i srodkiem poprzedniego jako poczatek. Nastepnie wysyla
* wektor do funkcji Merge, w ktorej dokonuje sie faktyczne sortowanie.
* 
*/
 void Mergesort(Wektor &we, Wektor pom, int lewy, int prawy);
 
/*!
*\brief Funkcja pomocnicza sortowania Mergesort
* 
* \param Wektor &we - wektor, ktorego elementy mają być posortowane, 
* 						przekazywany przez referencje
* \param Wektor pom - wektor pomocniczy
* \param int lewy - numer pierwszego elementu z zakresu do posortowania
* \param int x - numer srodkowego elementu z zakresu do posortowania
* \param int prawy - numer ostatniego elementu z zakresu do posortowania
* 
* Funkcja realizuje sortowanie i scalanie wektorow powstalych z wektora 
* podzielonego wczesniej w funkcji Mergesort
* 
*/
 void Merge(Wektor &we, Wektor pom, int lewy, int x, int prawy);
 
/*!
*\brief Funkcja pomocnicza sortowania Heapsort
* 
* \param Wektor &we - wektor, ktorego elementy mają być posortowane, 
* 						przekazywany przez referencje
* \param int rozmiar - rozmiar wektora do posortowania
* \param int i - zmienna pomocnicza
* 
* Funkcja obslugujaca kopiec w algorytmie sortowania Heapsort. Tworzy 
* drzewo binarne, porownuje jego elementy i umieszcza w odpowiednich 
* miejscach.
* 
*/
 void Heapify (Wektor &wek, int rozmiar, int i);
 
/*!
*\brief Funkcja pomocnicza sortowania Heapsort
* 
* \param Wektor &we - wektor, ktorego elementy mają być posortowane, 
* 						przekazywany przez referencje
* \param int rozmiar - rozmiar wektora do posortowania
* 
* Funkcja pomocnicza w algorytmie sortowania przez kopcowanie. Wylicza 
* wartosc zmiennej pomocniczej i, a pozniej wysyla wektor do funkcji Heapify, 
* zadajac odpowiednie parametry. 
* 
*/
 void Heap_make(Wektor &wek, int rozmiar);
 
/*!
*\brief Funkcja sortowania - Heapsort
* 
* \param Wektor &we - wektor, ktorego elementy mają być posortowane, 
* 						przekazywany przez referencje
* \param int rozmiar - rozmiar wektora do posortowania
* 
* Funkcja realizuje algorytm sortowania przez kopcowanie.
* 
*/
 void Heapsort(Wektor &wek, int rozmiar);
