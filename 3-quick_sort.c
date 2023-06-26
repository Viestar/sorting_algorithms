#include "sort.h"

void quick_sorter(int *array, ssize_t lower_bound, ssize_t upper_bound);
ssize_t partitioner(int *array, ssize_t lower, ssize_t upper);

/**
 * quick_sort - partition a list using a pivot and recursively arranges all.
 * @array: list to be sorted
 * @size: length of the list/ array.
 */
void quick_sort(int *array, size_t size)
{
	ssize_t lower_bound = 0;
	ssize_t upper_bound = size - 1;

	if (array == NULL || size < 2)
		return;

	quick_sorter(array, lower_bound, upper_bound);
}

/**
 * partitioner - sorts
 * @array: list to sorted
 * @lower: lower bound
 * @upper: upper bound
 * Return: end
 */
ssize_t partitioner(int *array, ssize_t lower, ssize_t upper)
{
	int swap_cont, pivot = array[lower];
	ssize_t start = lower;
	ssize_t end = upper;

	while (start < end)
	{
		while (array[start] <= pivot && start <= upper)
			start++;
		while (array[end] > pivot && end >= lower)
			end--;
		if (start < end)
		{
			swap_cont = array[start];
			array[start] = array[end];
			array[end] = swap_cont;
			print_array(array, (upper) + 1);
		}
	}

	swap_cont = array[lower];
	array[lower] = array[end];
	array[end] = swap_cont;
	return end;
	print_array(array, (upper) + 1);
}

/**
 * quick_sorter - partitions and sorts
 * @array: list to be sorted
 * @lower_bound: lower
 * @upper_bound: upper
 */
void quick_sorter(int *array, ssize_t lower_bound, ssize_t upper_bound)
{
	if (lower_bound < upper_bound)
	{
		ssize_t mid_bound = partitioner(array, lower_bound, upper_bound);
		quick_sorter(array, lower_bound, mid_bound - 1);
		quick_sorter(array, mid_bound + 1, upper_bound);
	}
}
