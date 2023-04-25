#include "sort.h"

/**
 * quick_sort - using the quick sort algorithm,
 * sorts an array of integers in ascending order
 * @array: an array of integers to be sorted
 * @size: size of the array
 *
 * Return: void
 **/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, 0, size - 1, size);
}

/**
 * sort - using the quick sort algorithm with the Lomuto
 * partition scheme sort an array of integers in asc order
 * @array: the array of integer to be sorted
 * @lo: starting index partition to be sorted
 * @hi: ending index of the partition to be sorted
 * @size: size of the array
 *
 **/
void sort(int *array, int lo, int hi, size_t size)
{
	if (lo < hi)
	{
		int y = partition(array, lo, hi, size);

		sort(array, lo, y - 1, size);
		sort(array, y + 1, hi, size);
	}
}

/**
 * partition - partition the array of integers
 * @array: the array of integers to partition
 * @lo: starting index of the partition to be sorted
 * @hi: ending index of the partition to be sorted
 * @size: size pf the array
 *
 * Return: index of the pivot
 **/

int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int k = lo - 1;
	int l;

	for (l = lo; l < hi; l++)
	{
		if (array[l] <= pivot)
		{
			k++;
			if (k != l)
			{
				swap(&array[k], &array[l]);
				print_array(array, size);
			}
		}
	}

	if (k + 1 != hi)
	{
		swap(&array[k + 1], &array[hi]);
		print_array(array, size);
	}

	return (k + 1);
}

/**
 * swap - swaps two intergers in the array
 * @x: pointer to the first integer to swap
 * @y: pointer to the second integer to swap
 **/
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
