#include "sort.h"

/**
 * selection_sort - sorts an array of integers in
 * ascending order
 * @array: array that is to be sorted
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	unsigned int x, y, min_index;
	int tmp;

	for (x = 0; x < size - 1; x++)
	{
		min_index = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[min_index])
				min_index = y;
		}
		if (min_index != x)
		{
			tmp = array[x];
			array[x] = array[min_index];
			array[min_index] = tmp;
			print_array(array, size);
		}
	}
}
