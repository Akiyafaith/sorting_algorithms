#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using
 * the Shell sort algorithm, using the Knuth sequence
 * @array: the array to be sorted
 * @size: size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, j, k;
	int tmp;

	if (!array || size < 2)
		return;

	while (gap < size / 3)
		gap  = gap * 3 + 1;

	while (gap >= 1)
	{
		for (j = gap; j < size; j++)
		{
			tmp = array[j];
			for (k = j; k >= gap && array[k - gap] > tmp; k -= gap)
			{
				array[k] = array[k - gap];
			}
			array[k] = tmp;
		}
		gap /= 3;
		print_array(array, size);
	}
}
