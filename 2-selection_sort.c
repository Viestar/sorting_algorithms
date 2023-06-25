#include "sort.h"

/**
 * selection_sort - Builds a sorted list by picking out the minimum.
 * @array: Array to be sorted
 * @size: length of the array
*/

void selection_sort(int *array, size_t size)
{
    size_t min, a, b, temp;

    /* Check if array is empty */
    if (array == NULL)
        return;

    /* Pre sorted array */
    if (size < 2)
        return;

    for (a = 0; a < (size - 1); a++)
    {
        min = a;
        for (b = (a + 1); b < size; b++)
        {
            if (array[b] < array[min])
            {
                /* Updating the minimum number */
                min = b;
            }

        }
        if (min != a)
        {
            /* swapping */
            temp = array[a];
            array[a] = array[min];
            array[min] = temp;
        }
        print_array(array, size);
    }
}