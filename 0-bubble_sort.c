#include "sort.h"
/**
 * bubble_sort - sorts array using bubble sort
 * @array: array to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	int stop = 0;

	while (stop == 0)
	{
		stop = sort_check(array, size);
		if (stop == 0)
			bubble_sort_array(array, size);
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
 * bubble_sort_array - bubble sorts the array
 * @array: array to be sorted
 * @size: size of array
 */
void bubble_sort_array(int *array, size_t size)
{
	unsigned int element, element_temp;

	for (element = 0; element < size; element++)
	{
		if ((element + 1) < size)
		{
			if (array[element] > array[element + 1])
			{
				element_temp = array[element];
				array[element] = array[element + 1];
				array[element + 1] = element_temp;
				print_array(array, size);
			}
		}
	}
}
