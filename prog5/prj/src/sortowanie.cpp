#include "sortowanie.hh"

/*!
 * \file
 * \brief Modul zawierajacy definicje funkcji sortowania Quick.
 *										
 */
 
Wektor Quicksort(Wektor wekt, int lewy, int prawy)
{
	int i=lewy;
	int j=prawy;
	int x=wekt._wektor[(lewy+prawy)>>1];
	do
	{
		while (wekt._wektor[i]<x) i++;
		while (wekt._wektor[j]>x) j--;
		if (i<=j)
		{
			wekt.Zamien_elementy(wekt,i,j);
			i++;
			j--;			
		}
	}
	while (i<=j);
	if(lewy<j) wekt=Quicksort(wekt,lewy,j);
	if(prawy>i) wekt=Quicksort(wekt,i,prawy);
	return wekt;
}

Wektor QuicksortOdwr(Wektor wekt, int lewy, int prawy)
{
	int i=lewy;
	int j=prawy;
	int x=wekt._wektor[(lewy+prawy)>>1];
	do
	{
		while (wekt._wektor[i]>x) i++;
		while (wekt._wektor[j]<x) j--;
		if (i<=j)
		{
			wekt.Zamien_elementy(wekt,i,j);
			i++;
			j--;			
		}
	}
	while (i<=j);
	if(lewy<j) wekt=QuicksortOdwr(wekt,lewy,j);
	if(prawy>i) wekt=QuicksortOdwr(wekt,i,prawy);
	return wekt;
}

Wektor QuicksortLosowo(Wektor wekt, int lewy, int prawy)
{
	int i=lewy;
	int j=prawy;
	int x=((rand()%10)+1);
	do
	{
		while (wekt._wektor[i]<x) i++;
		while (wekt._wektor[j]>x) j--;
		if (i<=j)
		{
			wekt.Zamien_elementy(wekt,i,j);
			i++;
			j--;			
		}
	}
	while (i<=j);
	if(lewy<j) wekt=QuicksortLosowo(wekt,lewy,j);
	if(prawy>i) wekt=QuicksortLosowo(wekt,i,prawy);
	return wekt;
}

