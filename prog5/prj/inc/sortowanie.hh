#include "funkcje.hh"

 /*!
 * \file
 * \brief Deklaracje funkcji sortowania typu Quick.
 *  
*/
 
 
/*!
*\brief Funkcja sortowania - Quicksort
* 
* \param Wektor wekt - wektor, ktorego elementy mają być posortowane
* \param int lewy - numer pierwszego elementu z zakresu do posortowania
* \param int prawy - numer ostatniego elementu z zakresu do posortowania
* 
* Funkcja realizuje algorytm sortowania szybkiego. Ustala srodkowy
* element, nastepnie od poczatku wektora wyszukuje element wiekszy 
* od srodkowego, a od konca - mniejszy od niego. Jesli takie znajdzie 
* - zamienia je ze soba miejscami. Tak sie dzieje dopoki zmienna 
* sluzaca do wyszukiwania mniejszego nie bedzie wieksza od tej sluzacej 
* do wyszukiwania wiekszego. Wtedy Quicksort zostaje wywolana ponownie 
* dla wektora bedacego pierwsza polowa i drugie wywolanie dla tego bedacego 
* druga polowa poczatkowego wektora do posortowania.
* 
* \return Wektor wekt - odpowiednio posortowany wektor
* 
*/
 Wektor Quicksort (Wektor wekt, int lewy, int prawy);
 
/*!
*\brief Funkcja sortowania - Quicksort z losowo wybieranym pivotem
* 
* \param Wektor wekt - wektor, ktorego elementy mają być posortowane
* \param int lewy - numer pierwszego elementu z zakresu do posortowania
* \param int prawy - numer ostatniego elementu z zakresu do posortowania
* 
* Funkcja realizuje algorytm sortowania szybkiego. Ustala srodkowy
* element - robi to losowo, z użyciem funkcji rand() - nastepnie 
* od poczatku wektora wyszukuje element wiekszy od srodkowego, a od konca 
* - mniejszy od niego. Jesli takie znajdzie - zamienia je ze soba miejscami. 
* Tak sie dzieje dopoki zmienna sluzaca do wyszukiwania mniejszego 
* nie bedzie wieksza od tej sluzacej do wyszukiwania wiekszego. Wtedy 
* Quicksort zostaje wywolana ponownie dla wektora bedacego pierwsza 
* polowa i drugie wywolanie dla tego bedacego druga polowa poczatkowego 
* wektora do posortowania.
* 
* * \return Wektor wekt - odpowiednio posortowany wektor
* 
*/
 Wektor QuicksortLosowo(Wektor wekt, int lewy, int prawy);
  
/*!
*\brief Funkcja sortowania - Quicksort
* 
* \param Wektor wekt - wektor, ktorego elementy mają być posortowane
* \param int lewy - numer pierwszego elementu z zakresu do posortowania
* \param int prawy - numer ostatniego elementu z zakresu do posortowania
* 
* Funkcja realizuje algorytm sortowania szybkiego. Ustala srodkowy
* element, nastepnie od poczatku wektora wyszukuje element mniejszy 
* od srodkowego, a od konca - weikszy od niego. Jesli takie znajdzie 
* - zamienia je ze soba miejscami. Tak sie dzieje dopoki zmienna 
* sluzaca do wyszukiwania mniejszego nie bedzie wieksza od tej sluzacej 
* do wyszukiwania wiekszego. Wtedy Quicksort zostaje wywolana ponownie 
* dla wektora bedacego pierwsza polowa i drugie wywolanie dla tego bedacego 
* druga polowa poczatkowego wektora do posortowania.
* 
* * \return Wektor wekt - odpowiednio posortowany wektor
* 
*/
 Wektor QuicksortOdwr(Wektor wekt, int lewy, int prawy);
