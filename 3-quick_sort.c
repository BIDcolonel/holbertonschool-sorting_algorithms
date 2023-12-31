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
size_t lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, temp;
	int smallerIndex, CurrentIndex;

	pivot = array[high];
	smallerIndex = low - 1;

	for (CurrentIndex = low; CurrentIndex < high; CurrentIndex++)
	{
		if (array[CurrentIndex] < pivot)
		{
			smallerIndex++;
			if (smallerIndex != CurrentIndex)
			{
				temp = array[smallerIndex];
				array[smallerIndex] = array[CurrentIndex];
				array[CurrentIndex] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[high] < array[smallerIndex + 1])
	{
		temp = array[smallerIndex + 1];
		array[smallerIndex + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (smallerIndex + 1);
}

/**
 * quick_sort_recursive - Recursively sorts an array using Quick Sort.
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	size_t pivotIndex;

	if (low < high)
	{
		pivotIndex = lomuto_partition(array, low, high, size);
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
