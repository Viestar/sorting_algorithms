#include "sort.h"

/**
 * bubble_sort - sorts the array by comparing two adjacent numbers
 * @array: Array to be sorted
 * @size: Size of the array to be sorted
 */
void bubble_sort(int *array, size_t size)
{
bool no_more_swaps;
size_t index, i;
int temp;

(void)no_more_swaps;
/* Check if the array is not empty */
if (array == NULL)
return;

for (i = 0; i < (size - 1); i++)
{
for (index = 0; index < (size - 1); index++)
{
if (array[index] > array[index + 1])
{
temp = array[index];
array[index] = array[index + 1];
array[index + 1] = temp;
print_array(array, size);
}
}
}
}
