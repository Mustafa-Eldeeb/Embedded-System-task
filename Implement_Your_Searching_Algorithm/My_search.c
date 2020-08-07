#include "My_search.h"

// return 1 if array is sorted ascending
uint8_t Is_sort(uint32_t* arr, uint8_t size)
{
	int i;

	if (size == 1 || size == 0)
		return 1;
	for (i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return 0;
	}
	return 1;
}

void swap(uint32_t* x, uint32_t* y)
{
	uint32_t temp = *x;
	*x = *y;
	*y = temp;
}

void bubble_sort(uint32_t* arr, uint8_t size)
{
	uint8_t i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

uint8_t binary_search(uint32_t* arr, uint8_t size, uint32_t number)
{

	if (!Is_sort(arr, size))
		bubble_sort(arr, size);

	uint8_t left = 0;
	uint8_t right = size - 1;
	while (right > left)
	{
		uint8_t mid = left + (right - left) / 2;
		if (arr[mid] == number)
			return mid;

		if (arr[mid] > number)
		{
			right = mid - 1;
			mid = left + (right - left) / 2;
			if (arr[mid] == number)
				return mid;
		}
		if (arr[mid] < number)
			left = mid + 1;
		mid = left + (right - left) / 2;
		if (arr[mid] == number)
			return mid;
	}

	return -1;
}