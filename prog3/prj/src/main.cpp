#include "stos_list.hh"

/*!\mainpage
* Program wykonala Monika Litwin, nr indeksu 200586. Program pobiera 
* z pliku liczby, ktore następnie przypisuje do obiektu typu vector, 
* pozniej umieszcza je obiekcie ktorejs z klas: KolejkaTab, StosList, 
* KolejkaList, StosTab. Mierzy czas wykonania tej operacji i wyswietla go.
* 
\section etykieta-Wazne-cechy Najwazniejsze cechy
* Program wczytuje dane z pliku, podaje je odpowiednio sformatowane do algorytmu,
* ktory wykonuje okreslona ilosc razy, mierzy calkowity czas i wylicza sredni 
* czas wykonania jednego algorytmu. Otrzymane dane zapisuje do pliku .csv.
* Program sprawdza poprawnosc wykonania poszczegolnych krokow, w razie 
* wykrycia bledu, wyswietla stosowny komunikat.
*/

/*!
 * \file
 * \brief Modul zawierajacy definicje glownej funkcji programu.
 *										
 */
 /*!
 * \brief W funkcji main wywolywana jest funkcja, wczytujaca plik z liczbami.
 * Nastepnie wywolana zostaje funkcja Start, jako jej parametry przekazujemy
 * zadana liczbe powtorzen i wielkosc pliku oraz dane z pliku w formie wektora.
 * Funkcja ta zwraca czas wykonania, z ktorego nastepnie wyliczamy sredni 
 * czas wykonania pojedynczego algorytmu. Na koncu zapisujemy do pliku .csv
 * zadane parametry i wyliczony sredni czas.
 *										
 */
int main()
{
	Wektor liczby=liczby.Wczytywanie("plik.txt");
	int N, k;							//N-ilosc liczb w pliku, 
										//k-liczba powtorzen
										
	double t=Start(k=10, N=15000, liczby);//N musi być <=10 lub
										//wielokrotnoscia liczby 10
	
	double t_sr=t/k;
	cout << "Sredni czas wykonania algorytmu: " << t_sr << endl << endl;
	
	Zapis_do_csv(t_sr ,k ,N);
	return 0;
}
	
