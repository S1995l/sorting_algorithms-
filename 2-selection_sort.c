#include "sort.h"

void swap(int *a, int *b);
/**
 * selection_sort - an algorithm that sorts an array through selection
 * @array: pointer to an array
 * @size: size of the array
 * Return: returns nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t k, j;
	size_t m;

	for (k = 0; k < size - 1; k++)
	{
		m = k;
		for (j = k + 1; j < size; j++)
		{
			if (array[j] < array[m])
			{
				m = j;
			}
		}
		if (m != k)
		{
			swap(&array[k], &array[m]);
			print_array(array, size);
		}
	}
}

/**
 * swap - swaps elements an an array
 * @b: an integer
 * @a: an integer
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
