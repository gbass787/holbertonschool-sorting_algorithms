#include "sort.h"
/**
 * quick_swap - swap function
 * @a: item a
 * @b: item b
 */
void quick_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * partition - partitions array into 2 sections based on our selected pivot
 * @array: array to partitioned
 * @first: beginning of array
 * @last: last index in our larger partition area
 * @size: size of array | index of pivot
 * Return: return index of partition
 */
int partition(int *array, int first, int last, size_t size)
{
	int idx, jdx, pivot;

	idx = first;
	pivot = array[last];

	for (jdx = first; jdx < last; jdx++)
	{
		if (array[jdx] <= pivot)
		{
			if (array[idx] != array[jdx])
			{
				quick_swap(&array[idx], &array[jdx]);
				print_array(array, size);
			}
			idx++;
		}
	}
	if (idx != last)
	{
		quick_swap(&array[idx], &array[last]);
		print_array(array, size);
	}
	return (idx);
}
/**
 * _quick_sort - recursive quick sort function with parameters to better
 * suit partition function
 * @array: array to quick sort
 * @first: beginning of array
 * @last: last index of partition area
 * @size: size of array
 */
void _quick_sort(int *array, int first, int last, size_t size)
{
	if (first < last)
	{
		int part = partition(array, first, last, size);

		_quick_sort(array, first, part - 1, size);
		_quick_sort(array, part + 1, last, size);
	}
}
/**
 * quick_sort - sorts array of integers in ascending order
 * using the quick sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;
	_quick_sort(array, 0, size - 1, size);
}
