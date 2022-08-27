#include "sort.h"
/**
 * selection_sort - function uses selection sort to sort array
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int stop = 0;

	while (stop == 0)
	{
		stop = sort_check(array, size);
		if (stop == 0)
			selection_sort_array(array, size);
	}
}
/**
 * sort_check - checks if array is sorted
 * @array: array to be sorted
 * @size: size of array
 * Return: 1 if array is sorted, 0 if otherwise
 */
int sort_check(int *array, size_t size)
{
	unsigned int element, stop = 0;

	for (element = 0; element < size; element++)
	{
		if ((element + 1) < size)
		{
			if (array[element] > array[element + 1])
				return (stop);
		}
	}
	stop = 1;
	return (stop);
}
/**
 * selection_sort_array - sorts array using selection sort
 * @array: array to be sorted
 * @size: size of array
 */
void selection_sort_array(int *array, size_t size)
{
	unsigned int idx, idx2, number_holder, swap_idx, swap = 0;
	int min_num;

	for (idx = 0; idx < size; idx++)
	{
		min_num = array[idx];

		for (idx2 = (idx + 1); idx2 < size; idx2++)
		{
			if (min_num > array[idx2])
			{
				min_num = array[idx2];
				swap_idx = idx2;
				swap = 1;
			}
		}
		if (swap == 1)
		{
			number_holder = array[idx];
			array[idx] = array[swap_idx];
			array[swap_idx] = number_holder;
			print_array(array, size);
			swap = 0;
		}
	}
}
