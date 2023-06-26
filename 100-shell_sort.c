#include "sort.h"

/**
 * shell_sort - Sorts like insertion more efficiently
 * @array: Array to be sorted.
 * @size: Array length.
 */

void shell_sort(int *array, size_t size)
{
    unsigned int gap, index, j;
    int temp_cont = 0;

    gap = index = j = 0;

    /* Incase of an empty array or 1 item array */
    if (array == NULL || size < 2)
        return;

    while (gap < size / 2)
        gap = gap * 2 + 1;

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
        gap = (gap - 1) / 2;
    }
}