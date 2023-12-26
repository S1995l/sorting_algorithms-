#include "sort.h"

void swap(int *a, int *b, int *array, size_t size);
void sort_recursion(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
/**
 * quick_sort - quick sort algorithm
 * @array: pointer to an array
 * @size: size of the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	sort_recursion(array, 0, size - 1, size);
}

/**
 * sort_recursion - recursively sorts an array
 * @array: pointer to an array
 * @low: an integer
 * @high: an integer
 * @size: size of the array
 * Return: Nothing
 */
void sort_recursion(int *array, int low, int high, size_t size)
{
	int mid;

	if (low >= high)
		return;

	if (low < high)
	{
		mid = partition(array, low, high, size);

		sort_recursion(array, low, mid - 1, size);
		sort_recursion(array, mid + 1, high, size);
	}
}

/**
 * partition - partitions the array
 * @array: pointer to an array
 * @low: an integer
 * @high: an integer
 * @size: size of the array
 * Return: Returns an integer, point of partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1);
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j], array, size);
		}
	}
	swap(&array[i + 1], &array[high], array, size);

	return (i + 1);
}
/**
 * swap - swaps elements an an array
 * @b: an integer
 * @a: an integer
 * @array: pointer to an array
 * @size: size of the array
 * Return: Nothing
 */
void swap(int *a, int *b, int *array, size_t size)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	if (*a != *b)
	{
		print_array(array, size);
	}
}
