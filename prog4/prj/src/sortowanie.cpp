#include "sortowanie.hh"

/*!
 * \file
 * \brief Modul zawierajacy definicje funkcji sortowania Quick, Merge i Heap.
 *										
 */
 
void Quicksort(Wektor &wekt, int lewy, int prawy)
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
	if(lewy<j) Quicksort(wekt,lewy,j);
	if(prawy>i) Quicksort(wekt,i,prawy);
}

void Mergesort(Wektor &we, Wektor pom, int lewy, int prawy)
{
	int x;
	if(lewy<prawy)
	{
		//x=(lewy+prawy)/2;
		x=(lewy+prawy)>>1;
		Mergesort(we,pom,lewy,x);
		Mergesort(we,pom,x+1,prawy);
		Merge(we,pom,lewy,x,prawy);
	}
}

void Merge(Wektor &we, Wektor pom, int lewy, int x, int prawy)
{
	int h,i,j,k;
	h=lewy;
	i=lewy;
	j=x+1;
	
	while((h<=x)&&(j<=prawy))
	{
		if(we._wektor[h]<=we._wektor[j])
		{
			pom._wektor[i]=we._wektor[h];
			h++;
		}
		else
		{
			pom._wektor[i]=we._wektor[j];
			j++;
		}
		i++;
	}
		if(h>x)
		{
			for(k=j; k<=prawy; k++)
			{
				pom._wektor[i]=we._wektor[k];
				i++;
			}
		}
		else
		{
			for(k=h; k<=x; k++)
			{
				pom._wektor[i]=we._wektor[k];
				i++;
			}
		}
		for(k=lewy; k<=prawy; k++) we._wektor[k]=pom._wektor[k];
}

void Heapify (Wektor &wek, int rozmiar, int i)
{
	int max, l, r;
	l=2*i;
	r=(2*i)+1;
	if (l<=rozmiar && wek._wektor[l]>wek._wektor[i]) max=l;
	else max=i;
	if (r<=rozmiar && wek._wektor[r]>wek._wektor[max]) max=r;
	if (max!=i)
	{
		wek.Zamien_elementy(wek,max,i);
		Heapify(wek,rozmiar,max);
	}
}

void Heap_make(Wektor &wek, int rozmiar)
{
	for (int i=rozmiar/2; i>0; i--)
		Heapify(wek,rozmiar, i);
}
 
void Heapsort(Wektor &wek, int rozmiar)
{
	Heap_make(wek, rozmiar);
	for (int i=rozmiar; i>1 ;i--)
	{
		wek.Zamien_elementy(wek,i,1);
		rozmiar--;
		Heapify(wek,rozmiar,1);
	}
}
