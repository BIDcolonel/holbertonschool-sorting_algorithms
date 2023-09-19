#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers using the Bubble Sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t currentElement, nextElement;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
		return;

	for (currentElement = 0; currentElement < size - 1; currentElement++)
	{
		swapped = 0;

		for (nextElement = 0; nextElement < size - currentElement - 1;
		nextElement++)
		{
			if (array[nextElement] > array[nextElement + 1])
			{
				temp = array[nextElement];
				array[nextElement] = array[nextElement + 1];
				array[nextElement + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}

		if (swapped == 0)
			break;
	}
}
