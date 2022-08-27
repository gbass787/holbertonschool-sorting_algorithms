#include "sort.h"
/**
 * shell_sort - sort data of array using shell sort algorithym
 * @array: array to sorted
 * @size: size of array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, n, i;
	int number;

	while (gap < size)
		gap = 3 * gap + 1;
	gap /= 3;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			for (n = i; n >= gap && array[n] < array[n - gap]; n -= gap)
			{
				number = array[n];
				array[n] = array[n - gap];
				array[n - gap] = number;
			}
		}
		gap /= 3;
		print_array(array, size);
	}
}
