#include "sort.h"

/**
 * shell_sort - Sorts like insertion more efficiently
 * @array: Array to be sorted.
 * @size: Array length.
 */

void shell_sort(int *array, size_t size)
{
	int temp_cont = 0;
	unsigned int gap, index, j;

	gap = index = j = 0;

	/* Incase of an empty array or 1 item array */
	if (array == NULL || size < 3)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (index = gap; index < size; index++)
		{
			temp_cont = array[index];
			for (j = index; j >= gap && array[j - gap] > temp_cont;
				 j -= gap)
			{
				if (array[j] != array[j - gap])
					array[j] = array[j - gap];
			}
			if (array[j] != temp_cont)
				array[j] = temp_cont;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
