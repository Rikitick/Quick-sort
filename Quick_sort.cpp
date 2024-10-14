#include <iostream>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int t{*a};
	*a = *b;
	*b = t;
}

// сортировка по возрастанию
void sort_up(int* ar, int pivot, int wall)
{
	int s = 0;

	if (pivot <= wall)
		return;

	for (int i = wall; i < pivot; ++i) {
		if (ar[i] < ar[pivot]) {
			if (&ar[wall] != &ar[i]) 
				swap(&ar[wall], &ar[i]);
			wall++;
			s++;	
			}
	}

	if (&ar[wall] != &ar[pivot]) {
		swap(&ar[wall], &ar[pivot]);
	}
	sort_up(ar, wall-1, wall-s);
	sort_up(ar, pivot, wall+1);
}

// сортировка по убыванию
void sort_down(int* ar, int pivot, int wall)
{
	int s{0};

	if (pivot >= wall)
		return;

	for (int i = wall; i > pivot; --i) {
		if (ar[i] < ar[pivot]) {
			if (&ar[wall] != &ar[i]) 
				swap(&ar[wall], &ar[i]);
			wall--;
			s++;
		}	
	}

	if (&ar[wall] != &ar[pivot]) {
		swap(&ar[wall], &ar[pivot]);
	}
	sort_down(ar, wall+1, wall+s);
	sort_down(ar, pivot, wall-1);
}


void sort_up(int* ar, int len)
{
	sort_up(ar, len-1, 0);
}

void sort_down(int* ar, int len)
{
	sort_down(ar, 0, len-1);
}


int main(void)
{
	int len;
	std::cin >> len; std::cin.ignore();
	int ar[len];

	for (int i = 0; i < len; ++i) {
		std::cin >> ar[i]; std::cin.ignore();
	}

	// replace order you can here ↓ (sort_up(ar, len), sort_down(ar, len))
	sort_down(ar, len);

	for (int i = 0; i < len; ++i)
		std::cout << ar[i] << ' ';

	return 0;
}