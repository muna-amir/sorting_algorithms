#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: First integer to swap
 * @b: Second integer to swap
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * partition - Partitions an array using the Lomuto partition scheme
 * @array: The array to be partitioned
 * @low: The starting index of the partition to be sorted
 * @high: The ending index of the partition to be sorted
 * @size: The size of the original array
 * Return: The index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1, j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            if (i != j)
                print_array(array, size);
        }
    }
    swap(&array[i + 1], &array[high]);
    if (i + 1 != high)
        print_array(array, size);
    return (i + 1);
}

/**
 * quicksort - Sorts an array of integers in ascending order using the Quick sort algorithm
 * @array: The array to be sorted
 * @low: The starting index of the partition to be sorted
 * @high: The ending index of the partition to be sorted
 * @size: The size of the original array
 */
void quicksort(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = partition(array, low, high, size);
        quicksort(array, low, pivot - 1, size);
        quicksort(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array to be sorted
 */
void quick_sort(int *array, size_t size)
{
    if (array && size > 1)
        quicksort(array, 0, size - 1, size);
}

