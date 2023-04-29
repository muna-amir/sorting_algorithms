#include <stdio.h>

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */

void selection_sort(int *array, size_t size)
{
    size_t i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < size - 1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = array[i];
        array[i] = array[min_idx];
        array[min_idx] = temp;

        // Print the array after each swap
        for (size_t k = 0; k < size; k++) {
            printf("%d", array[k]);
            if (k < size - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}
