#include "sort.h"

/**
 * lomuto_partition - Partitions an array using the Lomuto scheme.
 * @array: The array to be partitioned.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 *
 * Return: The index of the pivot element.
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot, temp;
	size_t smallerIndex, currentIndex;

	pivot = array[high];
	smallerIndex = low;

	for (currentIndex = low; currentIndex <= high - 1; currentIndex++)
	{
		if (array[currentIndex] < pivot)
		{
			if (smallerIndex != currentIndex)
			{
				temp = array[smallerIndex];
				array[smallerIndex] = array[currentIndex];
				array[currentIndex] = temp;
				print_array(array, size);
			}
			smallerIndex++;
		}
	}

	if (smallerIndex != high)
	{
		temp = array[smallerIndex];
		array[smallerIndex] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (smallerIndex);
}

/**
 * quick_sort_recursive - Recursively sorts an array using Quick Sort.
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
	size_t pivotIndex;

	if (low < high)
	{
		pivotIndex = lomuto_partition(array, low, high, size);

		if (pivotIndex > 0)
			quick_sort_recursive(array, low, pivotIndex - 1, size);
		quick_sort_recursive(array, pivotIndex + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using the Quick Sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
