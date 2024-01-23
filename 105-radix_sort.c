#include "sort.h"

/**
* findmax - Finds the maximum value in an array
* @array: array to find max value of
* @size: Size of array
* Return: Largest value
*/

int findmax(int *array, size_t size)
{
	int i, max;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}

/**
* radix_sort - Sorts an array using radix sort algo
* @array: Array to sort
* @size: size of array
*/

void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}

/**
* counting_sort_r - sorts array using counting algorithm
* @array: Array to sort
* @size: Size of array
* @pos: Digit position value
* @out: Temp output array
* @ca: Count array
*/

void counting_sort_r(int *array, size_t size, int pos, int *out, int *ca)
{
	int i;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < 10; i++)
		ca[i] = 0;
	for (i = 0; i < (int)size; i++)
		ca[((array[i] / pos) % 10)] += 1;
	for (i = 0; i < 10; i++)
		ca[i] += ca[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		out[ca[((array[i] / pos) % 10)] - 1] = array[i];
		ca[((array[i] / pos) % 10)] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = out[i];
}
