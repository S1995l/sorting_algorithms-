#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge(int *array, size_t left_size, size_t right_size);
void merge_sort(int *array, size_t size);
/**
 * merge - Merge two sub-arrays into a sorted array.
 * @array: Pointer to the original array.
 * @left_size: Size of the left sub-array.
 * @right_size: Size of the right sub-array.
 */
void merge(int *array, size_t left_size, size_t right_size)
{
	size_t merged_size = left_size + right_size;
	int *merged_array = malloc(merged_size * sizeof(int));

	size_t i = 0, j = left_size, k = 0;
	size_t l = 0;
	size_t m = 0;

	/* Display merging steps */
	printf("Merging...\n[left]: ");
	for (; l < left_size; ++l)
	{
		printf("%d ", array[l]);
	}
	printf("\n[right]: ");
	for (l = left_size; l < merged_size; ++l)
	{
		printf("%d ", array[l]);
	}

	/* Merge the left and right sub-arrays into the merged array */
	while (i < left_size && j < merged_size)
	{
		if (array[i] <= array[j])
		{
			merged_array[k++] = array[i++];
		}
		else
		{
			merged_array[k++] = array[j++];
		}
	}

	/* Copy any remaining elements from the left sub-array */
	while (i < left_size)
	{
		merged_array[k++] = array[i++];
	}

	/* Copy any remaining elements from the right sub-array */
	while (j < merged_size)
	{
		merged_array[k++] = array[j++];
	}

	/* Copy the sorted merged array back to the original array */
	for (; m < merged_size; ++m)
	{
		array[m] = merged_array[m];
	}

	/* Display the sorted array after merging */
	printf("\n[Done]: ");
	for (m = 0; m < merged_size; ++m)
	{
		printf("%d ", merged_array[m]);
	}
	printf("\n");

	/* Free the memory allocated for the merged array */
	free(merged_array);
}

/**
 * merge_sort - Recursively divide and merge the array using Merge Sort.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	/* Base case: if the array has more than one element */
	if (size > 1)
	{
		/* Calculate the middle index of the array */
		size_t mid = size / 2;

		/* Recursively sort the left and right sub-arrays */
		merge_sort(array, mid);
		merge_sort(array + mid, size - mid);

		/* Merge the sorted left and right sub-arrays */
		merge(array, mid, size - mid);
	}
}
