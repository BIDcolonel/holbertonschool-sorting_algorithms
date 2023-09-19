#include "sort.h"

/**
 * selection_sort - Sorts an array of integers using the Selection
 * Sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t currentIndex, minimumIndex, nextIndex;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (currentIndex = 0; currentIndex < size - 1; currentIndex++)
	{
		minimumIndex = currentIndex;

		for (nextIndex = currentIndex + 1; nextIndex < size;
		nextIndex++)
		{
			if (array[nextIndex] < array[minimumIndex])
			minimumIndex = nextIndex;
		}

		if (minimumIndex != currentIndex)
		{
			temp = array[currentIndex];
			array[currentIndex] = array[minimumIndex];
			array[minimumIndex] = temp;
			print_array(array, size);
		}
	}
}
